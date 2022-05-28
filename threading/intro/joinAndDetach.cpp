//
// Created by Frank Lin on 25/10/21.
//

// JOIN NOTES
//0. Once a thread is started we wait for this thread to finish by calling join()function on thread object
//1. Double join will result into program termination
//2. If needed we should check thread is joinable before joining. ( using joinable()function)

//
//join()函数是一个等待线程完成函数，主线程需要等待子线程运行结束了才可以结束:



//DETACH NOTES
//0. This is used to detach newly created thread from the parent thread
//1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and
//      double detach() will result into program termination
// 2. If we have detached thread and main function is returning then the detached thread execution is suspended

//detach()称为分离线程函数，使用detach()函数会让线程在后台运行，即说明主线程不会等待子线程运行结束才结束。
//通常称分离线程为守护线程(daemon threads),UNIX中守护线程是指，没有任何显式的用户接口，并在后台运行的线程。这种线程的特点就是长时间运行；
// 线程的生命周期可能会从某一个应用起始到结束，可能会在后台监视文件系统，还有可能对缓存进行清理，亦或对数据结构进行优化。
// 另一方面，分离线程的另一方面只能确定线程什么时候结束，发后即忘(fire andforget)的任务就使用到线程的这种方式。


// NOTES:
// Either join()or detach() should be called on thred object, otherwise during thread objects destructor it will
// terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program

#include <chrono>
#include <iostream>
#include <thread>
//void run(int x){
//    while(x-- >0){
//        cout << x<<" neo"<<endl;
//    }
//    std::this_thread::sleep_for(chrono::seconds(3));
//    cout<<"thread finished"<<endl;
//}
//
//int main(){
//    cout<<"main start()"<<endl;
//    std::thread t1(run ,10);
//    t1.join();
//    if(t1.joinable())
//          t1.join();
//    cout<< "main after()"<<endl;
//    return 0;
//}



void run(int x){
    while(x-- >0){
        std::cout << x<<" neo"<<std::endl;
    }

    std::cout<<"thread finished"<<std::endl;
}

int main(){
    std::cout<<"main start()"<<std::endl;
    std::thread t1(run ,10);
    t1.join();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<< "main after()"<<std::endl;
    return 0;
}
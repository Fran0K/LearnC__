//
// Created by Frank Lin on 18/8/21.
//

/*
 *
 *  vector预留空间
    功能描述：
        减少vector在动态扩展容量时的扩展次数

    使用场景：
        如果数据量大，可以一开始就把空间预留出来

    函数原型：
        reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
 * */

#include <iostream>
#include <vector>
using namespace std;


void vectorPrint(vector<int>&v){
    for(vector<int>::iterator it = v.begin(); it!= v.end(); it++){
        cout << *it <<" "<<endl;
    }
}

void test(){
    vector<int> v1;

    //利用reserve开辟空间
    //而且该空间开辟大小不够也可以，不够100000的话系统会自行再开辟空间
    v1.reserve(1000000);

    int num = 0;
    int *p = NULL;

    for(int i = 0; i<1000000 ;i++){
        v1.push_back(i);
        if(p != &v1[0]){
            p = &v1[0];
            num++;
        }
    }
    cout <<"num = "<< num<<endl;
}

int main(){
    test();
    return 0;
}

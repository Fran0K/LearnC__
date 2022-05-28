//
// Created by Frank Lin on 13/5/2022.
//
#include <iostream>
#include <cstring>

using namespace std;

struct Person{
    double salary;
    char * name;
};

class SalaryManager{
    Person *employ;//存放职工信息的数组
    int max;
    int n;
public:
    SalaryManager(int Max = 0){
        max = Max;
        n =0;
        employ = new Person[max];
    }

    double &operator[](char* name){
        //重载[]
        Person *p;
        for(p =employ;p<employ+n;p++){
            if(strcmp(name, p->name)==0){
                return p->salary;
            }
        }
        p = employ +n++;
        p->name = new char[strlen(name)+1];
        strcpy(p->name, name);
        p->salary =0;
        return p->salary;
    }
    void display(){
        for (int i = 0; i < n; ++i) {
            cout << employ[i].name << "   " << employ[i].salary << endl;
        }
    }

    ~SalaryManager(){
        delete[] employ;
    }
};
int main()
{
    SalaryManager s(3);
    s["张三"] = 2188.88;
    s["里斯"] = 1230.07;
    s["王无"] = 3200.97;
    cout << "张三\t" << s["张三"] << endl;
    cout << "里斯\t" << s["里斯"] << endl;
    cout << "王无\t" << s["王无"] << endl;

    cout << "-------下为display的输出--------\n\n";
    s.display();
}




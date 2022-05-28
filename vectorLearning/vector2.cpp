//
// Created by Frank Lin on 16/8/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
public:
    Person(string name, int age){
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

void printFunc(int x){
    cout << x << endl;
}

void test1(){
    //创建vector 容器 数组，类型为int
    vector<Person> p;

    Person p1("jack", 10);
    Person p2("john", 70);
    Person p3("wick", 50);
    Person p4("ken", 42);
    Person p5("ben", 23);

    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);

    //是用迭代器遍历数据
    for (vector<Person>::iterator k = p.begin(); k != p.end(); k++) {
        //cout<<"name: "<< k->m_name << " ,age: "<< k->m_age<<endl;
        // *k变成指针
        cout<<"name: "<< (*k).m_name << " ,age: "<< (*k).m_age<<endl;
    }
}



void test2(){
    //
    //Person*
    vector<Person *> p;

    Person p1("jack", 10);
    Person p2("john", 70);
    Person p3("wick", 50);
    Person p4("ken", 42);
    Person p5("ben", 23);

    p.push_back(&p1);
    p.push_back(&p2);
    p.push_back(&p3);
    p.push_back(&p4);
    p.push_back(&p5);

    //是用迭代器遍历数据
    for (vector<Person *>::iterator k = p.begin(); k != p.end(); k++) {
        //cout<<"name: "<< k->m_name << " ,age: "<< k->m_age<<endl;
        //
        //cout<<"name: "<< (*k)->m_name << " ,age: "<< (*k)->m_age<<endl;
        cout<<"name: "<< (*k)->m_name << " ,age: "<< (*k)->m_age<<endl;
    }
}


int main(){
    //test1();
    test2();
}
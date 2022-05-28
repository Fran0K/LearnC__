//
// Created by Frank Lin on 23/5/2022.
//
/*
某公司有经理、销售员、小时工等多类人员。经理按周计算薪金；销售员每月底薪800元，
然后加销售提成，每销售1件产品提取销售利润的5%；小时工按小时计算薪金。每类人员都有姓名和身份证号等数据。
为简化问题，把各类人员的共有信息抽象成基类Employee，其他人员则继承该类的功能。
*/

#include "iostream"

using namespace std;

class Employee{
public:
    Employee(string Name ,string id) : name(Name), Id(id){  }
    string getName() const { return name; }			        //返回姓名
    string getID() const { return Id; }//返回身份证号

    virtual float getSalary() const { return 0.0; }			//返回薪水
    virtual void print() const {		                    //输出姓名和身份证号
        cout<<"姓名: "<<name<<"\t\t 编号: "<<Id<<endl;
    }
    void getDD() const{
        cout<<"dd: "<<dd<<endl;
    }
private:
    string name;
    string Id;
    int dd =2;

};
//经理
class Manager:public Employee{
public:
    float salary;
    int week;
    Manager(string Name,string id,int w):Employee(Name, id),week(w){
        salary = 1000*week;
    }
    float getSalary ()const{
        return salary;
    }
    void print() const {		                    //输出姓名和身份证号
        cout<<"姓名: "<<getName()<<" 编号: "<<getID();
        cout<<" 工资: "<<getSalary ()<<endl;
    }

};
//销售员
class seller:public Employee{
public:
    float salary;
    int sold;
    seller(string Name,string id, int s):Employee(Name, id),sold(s){
        salary = 800+sold*0.05;
    }
    float getSalary ()const{
        return salary;
    }
    void print() const {		                    //输出姓名和身份证号
        cout<<"姓名: "<<getName()<<" 编号: "<<getID();
        cout<<" 工资: "<<getSalary ()<<endl;
    }
};

class hourlyWorker:public Employee{
public:
    float salary;
    int hour;
    hourlyWorker(string Name,string id, int h):Employee(Name, id),hour(h){
        salary = 100*hour;
    }
    float getSalary ()const{
        return salary;
    }
    void print() const {		                    //输出姓名和身份证号
        cout<<"姓名: "<<getName()<<" 编号: "<<getID();
        cout<<" 工资: "<<getSalary ()<<endl;
    }
};

int main(){

    Employee e1("fra","122");
    Manager m1("emma","222",4) , *ptr;
    ptr = &m1;

    Employee *p1 = new Employee("jusu","12222");
    p1->getDD();

    //派生类指针指向基类
    Employee *p2 = dynamic_cast<Employee*>(ptr);
    p2->print();

    Manager* m2 = dynamic_cast<Manager*>(p1);
    m2->print();

    e1.print();

}


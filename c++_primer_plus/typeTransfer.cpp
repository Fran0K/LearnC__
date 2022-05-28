//
// Created by Frank Lin on 13/5/2022.
//
/*
有一个类Circle，设计该类的类型转换函数，当将Circle对象转换成int型时，返回圆的半径；当将它转换成double型时，就返回圆的周长；当将它转换成float型时，就返回圆的面积。
*/

/*
类型转换函数没有参数。
类型转换函数没有返回类型。
类型转换函数必须返回将要转换成的type类型数据。
*/
#include <iostream>
using namespace std;
class Circle{
private:
    double x,y,r;
public:
    Circle(double x1,double y1,double r1){
        x=x1;
        y=y1;
        r=r1;
    }
    operator int(){
        return r;
    }
    operator double (){
        return 2*r*3.1415;
    }
    operator float (){
        return r*r*3.1415;
    }
};

int main(){
    Circle c(2.3, 3.4, 2.5);
    int r= c;
    double length=c;   //调用operator double()，转换成double
    float area=c;   //调用operator float()，将Circle类型转换成float
    double len=(double) c;	//将Cirlce类型对象强制转换成double
    cout<<r<<endl;
    cout<<length<<endl;
    cout<<len<<endl;
    cout<<area<<endl;
}
//
// Created by Frank Lin on 13/5/2022.
//
#include <string>

using namespace std;

string add(string &s1, string &s2){
    int n1 = s1.size() - 1;//s1的最低位下标
    int n2 = s2.size() - 1;//s2的最低位下标
    int carry = 0;
    string ans;

    while(n1 >= 0 || n2 >= 0 || carry > 0){
        int t1 = n1 >= 0 ? s1[n1--] - '0' : 0;
        int t2 = n2 >= 0 ? s2[n2--] - '0' : 0;
        ans += (t1 + t2 + carry) % 10 + '0';//最低位放在最前面
        carry = (t1 + t2 + carry) / 10;//进位：逢10进1
    }

    reverse(ans.begin(), ans.end());
    return ans;
}



string add2(string s1, string s2){
    int n1 = s1.size()-1;
    int n2 = s2.size()-1;
    string ans;
    //进位
    int carry =0;
    //
    while(n1>=0 || n2>=0 || carry>0){
        int t1 = n1>=0?s1[n1--]-'0':0;
        int t2 = n2>=0?s2[n2--]-'0':0;
        ans+=((t1+t2+carry)%10 + '0');
        carry = (t1+t2+carry)/10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s1="1000000000";
    string s2 = "123456789";
    add2(s1,s2);
}
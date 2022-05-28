//
// Created by Frank Lin on 30/11/21.
//

#include <vector>
#include <stack>
#include <string>
using namespace std;
//int calculate(string s) {
//    stack<int> myStack;
//    char sign = '+';
//    int res = 0, tmp = 0;
//    for (unsigned int i = 0; i < s.size(); i++) {
//        if (isdigit(s[i]))
//            tmp = 10*tmp + s[i]-'0';
//        if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1) {
//            if (sign == '-')
//                myStack.push(-tmp);
//            else if (sign == '+')
//                myStack.push(tmp);
//            else {
//                int num;
//                if (sign == '*' )
//                    num = myStack.top()*tmp;
//                else
//                    num = myStack.top()/tmp;
//                myStack.pop();
//                myStack.push(num);
//            }
//            sign = s[i];
//            tmp = 0;
//        }
//    }
//    while (!myStack.empty()) {
//        res += myStack.top();
//        myStack.pop();
//    }
//    return res;
//}

int calculate(string &s){

    stack<int> st;
    int temp =0;
    char sign = '+';
    int n = s.size();
    for(int i =0 ;i<n; i++){
        // 数字变换
        char gg = s[i];
        if(isdigit(s[i])){
            temp = temp*10 + s[i]-'0';
        }
        if(!isdigit(s[i]) && !isspace(s[i]) || i == n-1){
            if(sign == '+'){
                st.push(temp);
            } else if (sign == '-'){
                st.push(-temp);
            }else{
                int num;
                if(sign =='*'){
                    num = st.top() * temp;
                    st.pop();
                    st.push(num);
                }else if(sign =='/'){
                    num = st.top() / temp;
                    st.pop();
                    st.push(num);
                }
            }
            temp =0 ;
            sign = s[i];

        }

    }

    int sum = 0;
    while(!st.empty()){
        sum +=st.top();
        st.pop();
    }
    return sum;

}


int main(){
    string s  = "-3/2";
    int k = calculate(s);
    return 0;
}
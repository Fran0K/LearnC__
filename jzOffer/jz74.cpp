//
// Created by Frank Lin on 30/10/21.
//

#include <iostream>
#include <vector>

using namespace std;
//
//vector<vector<int> > FindContinuousSequence(int sum) {
//    vector<vector<int>> ans;
//    int sp =1, fp =2;
//    int kk=1;
//    while(sp<sum){
//        if(kk<sum){
//            fp++;
//            kk+=fp;
//        } else if (kk == sum){
//            vector<int> temp;
//            for(int i = sp; i<=fp;i++){
//                temp.push_back(i);
//            }
//            ans.push_back(temp);
//            kk = sp;
//        }else{
//            sp = fp;
//            fp++;
//            kk =sp;
//        }
//    }
//    return ans;
//
//}
int main(){
    //FindContinuousSequence(9);


    int kk[] = {1,2,3};
    int *p =kk ;

    cout<< "location "<<kk<<endl;
    cout<< *p<<endl;
    cout<<"add 1"<<endl;
    cout<< (*p)+2 <<endl;

    return 0;
}
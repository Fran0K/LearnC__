//
// Created by Frank Lin on 13/9/21.
//
#include <iostream>
using namespace std;

int main(){
    int n, k, t, x1, y1, x2, y2;
    cin >> n>> k>> t>> x1>> y1>> x2>> y2;

    int stay = 0;
    int count = 0;
    for (int i = 0 ;i < n; i++){
        int maxCount =0,tempCount = 0;
        for(int j =0; j< t; t++) {
            int tempx, tempy;
            cin >> tempx >> tempy;
//            tempCount = (tempx <x1 || tempx > x2 || tempy < y1 || tempy > y2) ? 0 :(tempCount+1);
            if (tempx < x1 && tempx > x2 && tempy < y1 && tempy > y2) {
                tempCount++;
            } else {


                if (maxCount < tempCount) {
                    maxCount = tempCount;
                }
                tempCount = 0;
            }
        }
        // absent
        if(maxCount > 0)count++;
        if(maxCount>=k)stay++;
    }
    cout << count <<endl;
    cout << stay;
    return 0;
}
//
//#include <iostream>
//
//using namespace std;
//int main(){
//    int n, k, t, x1, y1, x2, y2;
//    scanf("%d%d%d%d%d%d%d",&n,&k,&t,&x1,&y1,&x2,&y2);
//    //cin >> n>> k>> t>> x1>> y1>> x2>> y2;
//    int pass =0 ,stop =0;
//    for (int i = 0,x,y ;i < n; i++){
//        int maxCount =0,tempCount = 0;
//        for(int j =0; j< t; t++) {
//            scanf("%d%d",&x,&y);
//            //cin >> x >> y;
//            tempCount = (x < x1 || x > x2 || y < y1 || y > y2) ? 0 : (tempCount + 1);
//            if (tempCount > maxCount)maxCount = tempCount;
//        }
//        if(maxCount>0)pass++;
//        if(maxCount >= k)stop++;
//        continue;}
//    printf("%d\n%d",&pass,&stop);
//    //cout << pass<<endl<<stop;
//    return 0;
//
//
//
//    }

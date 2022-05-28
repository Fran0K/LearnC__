//
// Created by Frank Lin on 8/2/22.
//

#include <iostream>
#include <vector>

using namespace std;
class qs{

public:
    vector<int> quickSort(vector<int>& number){
        int n = number.size()-1;
        quick_sort(number,0, n);
        return number;
    }

    void quick_sort(vector<int>& number, int begin, int end){
        if(begin <end){
            int piv = partion(number, begin, end);
            quick_sort(number, begin, piv-1);
            quick_sort(number,piv+1, end);

        }
    }

    int partion(vector<int>& number, int begin,int end) {
        int piv = number[begin];

        int i = begin+1;
        int j = end;
        //注意这个while
        while(1){
            while(number[i] <= piv && i<=j){
                i++;
            }
            while(number[j]>=piv && i<=j){
                j--;
            }
            if(i>j){
                break;
            }
            exch(number,i,j);
        }
        exch(number,j,begin);
        return j;
    }

    void exch(vector<int>& number, int begin,int end){
        int t = number[begin];
        number[begin] = number[end];
        number[end] = t;
    }


};

int main(){
    vector<int> arr{5,2,3,1};
    vector<int> ans = qs().quickSort(arr);
    for(auto num:ans){
        cout<<num<<" ";
    }
}



//------------ok version----------//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//void printvec( const vector<int> &vec, const string &strbegin = "", const string &strend = "" )
//{
//    cout << strbegin << endl;
//    for ( auto val : vec )
//    {
//        cout << val << "\t";
//    }
//
//    cout << endl;
//    cout << strend << endl;
//}
//
//
//int partition( vector<int> & vec, int left, int right )
//{
//    if ( left >= right )
//    {
//        return left;
//    }
//
//    int base = vec[left];
//    while ( left < right )
//    {
//        while ( left < right && vec[right] >= base )
//        {
//            right--;
//        }
//        if ( left >= right )
//        {
//            break;
//        }
//
//        vec[left] = vec[right];
//
//        while ( left < right && vec[left] <= base )
//        {
//            left++;
//        }
//
//        if ( left >= right )
//        {
//            break;
//        }
//
//        vec[right] = vec[left];
//    }
//
//    vec[left] = base;
//    return left;
//}
//
//
//void quicksort( vector<int> & vec, int left, int right )
//{
//    if ( left >= right )
//    {
//        return;
//    }
//
//    int idx = partition( vec, left, right );
//    quicksort( vec, left, idx - 1 );
//    quicksort( vec, idx + 1, right );
//}
//
//
//int main( void )
//{
//    vector<int> vec = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//    printvec( vec );
//    quicksort( vec, 0, vec.size() - 1 );
//    printvec( vec, "after insert sort" );
//    return 0;
//}
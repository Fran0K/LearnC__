//
// Created by Frank Lin on 19/8/21.
//
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

vector<int> printListFromTailToHead(ListNode* head) {
    deque<int> d1;
    while (head != NULL) {
        d1.push_back(head->val);
        head = head->next;
    }
    vector<int> v1;
    for (deque<int>::iterator it = d1.end(); it != d1.begin(); --it) {
        v1.push_back(*it);
    }
    return v1;
}

int main(){
    ListNode l1 = {1,2,3};
    int ret =printListFromTailToHead(l1);
    cout<<"ret: "<<ret<<endl;
    return 0;
}

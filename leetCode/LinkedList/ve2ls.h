//
// Created by Frank Lin on 25/5/2022.
//

//#ifndef LEARNC___VE2LS_H
//#define LEARNC___VE2LS_H
using namespace std;
#include "vector"
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* vector2linkedList(vector<int> a);
//#endif //LEARNC___VE2LS_H

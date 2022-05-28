//
// Created by Frank Lin on 25/5/2022.
//


#include "ve2ls.h"

using namespace std;

ListNode* vector2linkedList(vector<int> a) {
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    for (int i = 0; i < a.size(); i++) {
        cur->next = new ListNode(a[i]);
        cur = cur->next;

    }
    return head->next;
}
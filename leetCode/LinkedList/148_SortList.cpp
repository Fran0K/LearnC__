//
// Created by Frank Lin on 26/5/2022.
//
#include "vector"

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* vector2linkedList(vector<int> a) {
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    for (int i = 0; i < a.size(); i++) {
        cur->next = new ListNode(a[i]);
        cur = cur->next;

    }
    return head->next;
}

class Solution {
public:
    static bool cmp(ListNode* head1, ListNode* head2){
        return head1->val < head2->val;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        vector<ListNode* > a;
        ListNode *cur = head;
        while(cur!= nullptr){
            a.push_back(cur);
            cur = cur->next;
        }
        sort(a.begin(), a.end(), cmp);

        ListNode* prev = new ListNode(0);
        ListNode* cc = prev;
        for(auto p: a){
            cc->next = p;
            cc=cc->next;
        }
        cc->next = nullptr;
        return prev->next;

    }
};

class Solution2{
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        // 2、找到链表中间节点并断开链表 & 递归下探
        ListNode* cur = head;
        ListNode* mid = findMiddle(cur);
        ListNode* right = mid->next;
        mid->next = nullptr;

        //
        ListNode* l = sortList(head);
        ListNode* r = sortList(right);

        return mergeSortList(l, r);

    }

    ListNode* findMiddle(ListNode* head){
        if(head== nullptr || head->next == nullptr){
            return head;
        }
        ListNode* t = new ListNode(0);
        t->next = head;
        ListNode* f = t;
        ListNode* s = t;
        while(f->next!= nullptr && f->next->next!= nullptr ){
            f= f->next->next;
            s = s->next;
        }
        return s;
    }

    ListNode* mergeSortList(ListNode* l1, ListNode* l2){
        ListNode* prev = new ListNode(0);
        ListNode* cur = prev;

        while(l1!=nullptr && l2!= nullptr){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1!=nullptr){
            cur->next = l1;
        }
        if(l2!=nullptr){
            cur->next = l2;
        }
        return prev->next;

    }
};

int main(){
    vector<int> a = {4,2,1,3};
    ListNode* p = vector2linkedList(a);
    Solution2().sortList(p);
}
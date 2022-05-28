//
// Created by Frank Lin on 25/5/2022.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include "string"
#include "vector"
#include "iostream"
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* f = pre;
        ListNode* s = pre;

        // 欧数
        // f->next!=nullptr
        // 奇数
        // && f->next->next!=nullptr

        while(f->next!=nullptr && f->next->next!=nullptr){
            f = f->next->next;
            s = s->next;
        }

        //why s->next;
        ListNode* rev = reverse(s->next);
        while(rev){
            if(rev->val!=head->val){
                return false;
            }
            rev = rev->next;
            head = head->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;

    }
};

int main(){
    vector<int>a= {1,2,3,3,2,1};
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    for(int i = 0;i<a.size();i++){
        cur->next = new ListNode(a[i]);
        cur=cur->next;
    }

    Solution().isPalindrome(head->next);

}
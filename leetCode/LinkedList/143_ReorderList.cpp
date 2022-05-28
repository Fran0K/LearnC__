//
// Created by Frank Lin on 25/5/2022.
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
    ListNode* reorderList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode* head1 = new ListNode(0);
        ListNode* cur1 = head;
        ListNode* head2 = new ListNode(0);
        ListNode* cur2 = head->next;
        while(cur1->next->next || cur2->next->next){
            if(cur2->next->next){
                cur2->next = cur2->next->next;
                cur2 =cur2->next;
            }
            if(cur1->next->next){
                cur1->next = cur1->next->next;
                cur1 = cur1->next;
            }
        }
        ListNode* t2 = reverse(head2->next);
        ListNode* ans = new ListNode(0);
        ListNode* cur = ans;

        while(head1!= nullptr&& t2!= nullptr){
            if(head1->val<t2->val){
                cur->next = head1;
                head1=head1->next;
            }else{
                cur->next = t2;
                t2=t2->next;
            }
            cur = cur->next;
        }
        if(head1!= nullptr){
            cur = head1;
        }
        if(t2!= nullptr){
            cur = t2;
        }
        return ans->next;
    }


    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* nex = head->next;
            cur->next = prev;
            prev =cur;
            cur =nex;
        }
        return prev;
    }
};

int main(){
    vector<int> nums={4,2,1,3};
    ListNode* head = vector2linkedList(nums);
    Solution().reorderList(head);
}

//
// Created by Frank Lin on 07/03/2022.
//
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode *next): val(x),next(next){}
};


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* mid =getMid(head);
        if(mid->next==nullptr){
            return mid;
        }

        ListNode* l2 = mid->next;
        mid->next =nullptr;
        return merge(sortList(l2), sortList(head));
    }

    ListNode* getMid(ListNode* head){
        head = new ListNode(0,head);
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* head =new ListNode(0);
        ListNode* cur = head;
        while(l1 && l2){
            if(l1->val >= l2->val){
                cur->next = l2;
                l2 = l2->next;
            }else{
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        if(l1){
            cur->next = l1;
        }
        if(l2){
            cur->next = l2;
        }
        return head->next;


    }
};

int main(){
    ListNode* l1 = new ListNode(4);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(1);
    l1->next->next->next = new ListNode(3);
    Solution().sortList(l1);

}

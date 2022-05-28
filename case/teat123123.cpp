//
// Created by Frank Lin on 13/2/22.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };
ListNode* deleteDuplicates(ListNode* head) {
    if(head ==NULL){
        return head;
    }
    ListNode* cur = head;
    ListNode* nex = cur->next;
    while(nex->next!=NULL){
        if(cur->val == nex->val){
            while(cur->val == nex->val && nex->next!= NULL){
                nex = nex->next;
            }
            if(nex->next== NULL){
                cur->next = nex->next;
                nex = nex->next;
            }else{
                cur->next = nex;
            }

        }else{
            cur = nex;
            nex = nex->next;
        }
    }
    return head;
}

int main(){
    ListNode *head = new ListNode(1);
    head->next =  new ListNode(1);
    head->next->next =  new ListNode(2);
    head->next->next->next =  new ListNode(3);
    head->next->next->next->next =  new ListNode(3);
    deleteDuplicates(head);
//    ["4","13","5","/","+"]
//    ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]};

}
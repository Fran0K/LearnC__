//
// Created by Frank Lin on 18/2/22.
//

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x): val(x), next(NULL);
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if(pHead1 ==NULL){
        return pHead2;
    }
    if(pHead2 ==NULL){
        return pHead1;
    }

    ListNode* head = new ListNode(-1);
    if(pHead1->val >pHead2->val){
        head->next = pHead2;
    }else{
        head->next = pHead1;
    }
    ListNode* link = head->next;
    while(pHead1 && pHead2){
        if(pHead1->val >pHead2->val){
            link->next = pHead2;
            pHead2 = pHead2->next;
        }else{
            link->next = pHead1;
            pHead1 = pHead1->next;
        }
        link = link->next;
    }
    if(pHead2){
        link->next = pHead2;
    }
    if(pHead1){
        link->next = pHead1;
    }
    return head->next;

}


int main()
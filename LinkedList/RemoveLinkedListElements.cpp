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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
       if(head==NULL)
         return NULL;
       while(head!=NULL&&head->val==val){
          head=head->next;
       }
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            if(temp->val==val){
            temp=temp->next;
            prev->next=temp;
             continue;
            }
             prev=temp;
             temp=temp->next;
        } 
        return head;
    }
};
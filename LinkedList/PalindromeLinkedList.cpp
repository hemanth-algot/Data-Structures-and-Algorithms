//Problem:Palindrome Linked List
//Platform:LeetCode 234
//Difficulty:Easy
//Time Complexity:O(n)
//Space Complexity:O(1)

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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        if(head==NULL|| head->next==NULL)
           return head;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast->next!=NULL&& fast->next->next!=NULL){
         slow=slow->next;
         fast=fast->next->next;
       }
       ListNode* newhead=reverse(slow->next);
       ListNode* first=head;
       ListNode* second=newhead;
       while(second!=NULL){
        if(first->val!=second->val){
            reverse(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
       }
       reverse(newhead);
       return true;
    }
};
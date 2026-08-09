//Problem:Remove Nth Node From End Of Linked List
//Platform:LeetCode 19
//Difficulty:Medium
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        ListNode* slow=head;
        while( fast!=NULL&& fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        if(fast==NULL){
            ListNode* newhead=head->next;
            delete head;
            return newhead;
        }
        ListNode* del=slow->next;
        slow->next=slow->next->next;
        delete del;
        return head;
    }
};
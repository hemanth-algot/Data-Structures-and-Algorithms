//Problem:Middle of Linked List
//Platform:LeetCode 876
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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL||head->next==NULL)
          return head;
        ListNode* first=head;
        ListNode* last=head;
        while(first!=NULL){
            if(first->next==NULL)
               return last;
           last=last->next;
           first=first->next->next;
         
        }
        return last;
    }
};
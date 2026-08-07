//Problem:Reverse a Linked List
//Platform:LeetCode 206
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
    ListNode* reverseList(ListNode* head) {
       ListNode* temp=head;
       ListNode* prev=NULL;
       while(temp!=NULL){
         ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
       }
       return prev;
    }
};

//Problem:Rotate List
//Platform:LeetCode 61
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)
           return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        if(k%len==0) return head;
        k=k%len;
        tail->next=head;
        int end=len-k;
        ListNode* temp=head;
        while(temp!=NULL){
           end--;
           if(end==0)
             break;
           temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};
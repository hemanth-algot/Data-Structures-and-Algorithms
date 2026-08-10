//Problem:Intersection Of Two Linked List
//Platform:LeetCode 160
//Difficulty:Easy
//Time Complexity:O(n1+n2)
//Space Complexity:O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)
           return NULL;
        ListNode* t1=headA;
        ListNode* t2=headB;
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
            if(t1==t2)
              return t1;
            if(t1==NULL)
              t1=headB;
            if(t2==NULL)
              t2=headA;
        }
        return t1;
    }
};
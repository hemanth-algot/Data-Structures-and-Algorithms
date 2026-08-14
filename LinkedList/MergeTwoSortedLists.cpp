//Problem:Merge Two Sorted Lists
//Platform:LeetCode 21
//Difficulty:Easy
//Time Complexity:O(n+m)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummynode=new ListNode(-1);
        ListNode* res=dummynode;
        while(list1!=NULL&&list2!=NULL){
            if(list1->val<list2->val){
                res->next=list1;
                res=list1;
                list1=list1->next;
            }
            else{
                res->next=list2;
                res=list2;
                list2=list2->next;
            }
        }
        if(list1) res->next=list1;
        else res->next=list2;
       return dummynode->next;
    }
};
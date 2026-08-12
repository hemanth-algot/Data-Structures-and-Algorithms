//TimeComplexity:O(n)
//SpaceComplexity:O(1)

/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {
        ListNode* temp=head;
        while(temp!=nullptr&&temp->next!=nullptr){
            ListNode* nextnode=temp->next;
            while(nextnode!=nullptr&&nextnode->val==temp->val){
                ListNode* duplicate=nextnode;
                nextnode=nextnode->next;
                delete duplicate;
            }
            temp->next=nextnode;
            if(nextnode) nextnode->prev=temp;
            temp=temp->next;
        }
       return head;
    }
};
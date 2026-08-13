//Time Complexity:O(n*m)
//Space Complexity:O(n)

/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
public:
  ListNode* merge(ListNode* list1,ListNode* list2){
    ListNode* dummynode=new ListNode(-1);
    ListNode* res=dummynode;
    while(list1!=nullptr&&list2!=nullptr){
        if(list1->val<list2->val){
            res->child=list1;
            res=list1;
            list1=list1->child;
        }
        else {
            res->child=list2;
            res=list2;
            list2=list2->child;
        }
        res->next=nullptr;
    }
    if(list1) res->child=list1;
    else res->child=list2;
    return dummynode->child;
  }
    ListNode* flattenLinkedList(ListNode* &head) {
      if(head==nullptr||head->next==nullptr)
         return head;
     ListNode* mergehead=flattenLinkedList(head->next);
     return merge(head,mergehead);
    }
};
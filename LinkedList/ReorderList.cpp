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
    void reorderList(ListNode* head) {
        deque<ListNode*>dq;
        ListNode* dummynode=new ListNode(-1);
        ListNode* res=dummynode;
        ListNode* temp=head;
        ListNode* front=NULL;
        while(temp->next!=NULL){
            front=temp->next;
            temp->next=NULL;
            dq.push_back(temp);
            temp=front;
        }
        dq.push_back(temp);
       while(!dq.empty()){
        ListNode* newnode=dq.front();
        dq.pop_front();
        res->next=newnode;
        res=res->next;
        if(dq.empty())
          break;
        newnode=dq.back();
        dq.pop_back();
        res->next=newnode;
        res=res->next;
       }
       res->next=NULL;
    }
};
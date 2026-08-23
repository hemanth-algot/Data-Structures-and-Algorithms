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
    ListNode* removeNodes(ListNode* head) {
        stack<int>st;
        ListNode* temp=head;
        while(temp!=NULL){
            while(!st.empty()&&temp->val>st.top())
              st.pop();
            st.push(temp->val);
            temp=temp->next;
        }
        vector<int>res;
        while(!st.empty()){
          res.push_back(st.top());
          st.pop();
        }
        ListNode* newhead=new ListNode(res[res.size()-1]);
         temp=newhead;
        for(int i=res.size()-2;i>=0;i--){
            ListNode* newnode=new ListNode(res[i]);
            temp->next=newnode;
            temp=temp->next;
        }
        return newhead;
    }
};
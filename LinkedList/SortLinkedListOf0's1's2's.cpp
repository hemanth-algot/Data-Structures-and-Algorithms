/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            //your code goes here
            ListNode* zerohead=new ListNode(-1);
            ListNode* onehead=new ListNode(-1);
            ListNode* twohead=new ListNode(-1);
            ListNode* zero=zerohead;
            ListNode* one=onehead;
            ListNode* two=twohead;
            ListNode* temp=head;
            while(temp!=nullptr){
                if(temp->data==0){
                    zero->next=temp;
                    zero=temp;
                  
                }
                else if(temp->data==1){
                    one->next=temp;
                    one=temp;
                 
                }
                else{
                    two->next=temp;
                    two=temp;
                   
                }
                 temp=temp->next;
            }
            zero->next=(onehead->next)?(onehead->next):(twohead->next);
            one->next=twohead->next;
            two->next=nullptr;
           
            return zerohead->next;
        }
};
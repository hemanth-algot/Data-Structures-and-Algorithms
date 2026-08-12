//Problem:Reverse Nodes In K-Group
//Platform:LeetCode 25
//Difficulty:Hard
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
  ListNode* reverse(ListNode* head){
    ListNode* temp=head;
    ListNode* prevnode=NULL;
    while(temp!=NULL){
        ListNode* nextnode=temp->next;
        temp->next=prevnode;
        prevnode=temp;
        temp=nextnode;
    }
    return prevnode;
  }
  ListNode* getKThNode(ListNode* temp,int k){
    k--;
    while(temp!=NULL&&k>0){
        k--;
        temp=temp->next;
    }
    return temp;
  }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevnode=NULL;
        while(temp!=NULL){
            ListNode* kThNode=getKThNode(temp,k);
            if(kThNode==NULL){
                if(prevnode) prevnode->next=temp;
                break;
            }
            ListNode* nextnode=kThNode->next;
            kThNode->next=NULL;
            reverse(temp);
            if(head==temp)
              head=kThNode;
            else{
                prevnode->next=kThNode;
            }
                prevnode=temp;
                temp=nextnode;
        }
        return head;
    }
};
//TimeComplexity:O(n)
//SpaceComplexity:O(1)

/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution {
public:
  ListNode* findtail(ListNode* head){
    ListNode* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    return temp;
  }
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        // Your code goes here
       vector<vector<int>>ans;
       ListNode* left=head;
       ListNode* right=findtail(head);
       while(left->val<right->val){
          if(left->val+right->val==target){
            ans.push_back({left->val,right->val});
            left=left->next;
            right=right->next;
          }
          else if(left->val+right->val<target){
            left=left->next;
          }
          else{
            right=right->prev;
          }
       }
       return ans;
    }
};
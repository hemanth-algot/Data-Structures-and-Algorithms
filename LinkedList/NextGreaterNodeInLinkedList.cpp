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
   int nge(int ind,vector<int>&ans){
    int maxi=ans[ind];
    for(int i=ind;i<ans.size();i++){
        if(maxi<ans[i]){
          maxi=ans[i];
            return maxi;
        }
    }
    return 0;
   }
    vector<int> nextLargerNodes(ListNode* head) {
       vector<int>ans;
       ListNode* temp=head;
       while(temp!=NULL){
        ans.push_back(temp->val);
        temp=temp->next;
       }
       vector<int>res;
       for(int i=0;i<ans.size();i++){
           int ele=nge(i,ans);
           ans[i]=ele;
       }
       return ans;
    }
};
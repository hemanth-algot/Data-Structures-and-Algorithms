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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            if (mpp.find(temp->val) != mpp.end()) {
                if (temp->next == NULL ||
                    mpp.find(temp->next->val) == mpp.end()) {
                    count++;
                }
            }
            temp=temp->next;
        }
        return count;
    }
};
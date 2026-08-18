//Problem:Next Greater Element I
//LeetCode:496
//Difficulty:Easy

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       int n=nums2.size();
       stack<int>st;
       vector<int>ans(n);
       int i=n-1;
       while(i>=0){
          while(!st.empty()&&nums2[i]>=st.top()){
            st.pop();
          }
          if(st.empty()){
            ans[i]=-1;
          }
          else{
          ans[i]=st.top();
          }
          st.push(nums2[i]);
          i--;
       }
       vector<int>res;
       for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            if(nums1[i]==nums2[j]){
             res.push_back(ans[j]);
             break;
            }
        }
       }
       return res;
    }
};
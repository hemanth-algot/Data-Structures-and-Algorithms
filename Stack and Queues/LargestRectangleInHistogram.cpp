//Problem:Largest Rectangle In Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxarea=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int element=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxarea=max(maxarea,(nse-pse-1)*heights[element]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int element=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxarea=max(maxarea,(nse-pse-1)*heights[element]);
        }
        return maxarea;
    }
};
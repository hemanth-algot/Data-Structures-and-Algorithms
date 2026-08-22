//Problem:Maximal Rectangle

class Solution {
public:
    int maxheight(vector<int>&arr){
        int maxarea=0;
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
           while(!st.empty()&&arr[st.top()]>arr[i]){
            int element=st.top();
            st.pop();
            int nse=i;
            int pse=st.empty()?-1:st.top();
            maxarea=max(maxarea,arr[element]*(nse-pse-1));
           }
           st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int element=st.top();
            st.pop();
             int pse=st.empty()?-1:st.top();
              maxarea=max(maxarea,arr[element]*(nse-pse-1));
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxarea=0;
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')
                   height[j]++;
                else
                  height[j]=0;
            }
            int area=maxheight(height);
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        vector<string>v;
        string ans="";
        for(int i=0;i<n;i++)
        {
          if(s[i]!=' ')
             ans+=s[i];
          else{
              if(!ans.empty()){
               v.push_back(ans);
                ans="";
              }
          }
        }
        if(!ans.empty())
           v.push_back(ans);
        string res="";
        for(int i=v.size()-1;i>=0;i--){
            if(i>0){
              res+=v[i];
              res+=' ';
            }
            else
               res+=v[i];
        }
        return res;
    }
};
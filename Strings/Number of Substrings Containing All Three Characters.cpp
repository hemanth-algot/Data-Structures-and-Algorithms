class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0,r=0;
        int cnt=0;
        int hash[3]={-1,-1,-1};
        while(r<n){
              hash[s[r]-'a']=r;
              if(hash[0]!=-1&&hash[1]!=-1&&hash[2]!=-1)
                 cnt+=1+min(hash[0],min(hash[1],hash[2]));
              r++;
        }
        return cnt;
    }
};
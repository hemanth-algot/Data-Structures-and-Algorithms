//Problem:Infix To Prefix

class Solution {
public:
  string reverse(string s){
    int j=s.size()-1;
    string ans="";
    while(j>=0){
        ans+=s[j];
        j--;
    }
    return ans;
  }
    int priority(char ch){
        if(ch=='^')
          return 3;
        else if(ch=='*'||ch=='/')
           return 2;
        else if(ch=='+'||ch=='-')
          return 1;
        else 
         return -1;
    }
    string infixToPrefix( string& s) {
        // Your code goes here
        s=reverse(s);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
               s[i]=')';
            else if(s[i]==')')
               s[i]='(';
        }
        string ans="";
        stack<char>st;
        int i=0;
        while(i<s.size()){
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))
              ans+=s[i];
            else if(s[i]=='(')
              st.push(s[i]);
            else if(s[i]==')'){
                while(!st.empty()&&st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                  st.pop();
            }
            else {
             if (s[i] == '^') {
                while (!st.empty() &&
               st.top() != '(' &&
           priority(s[i]) <= priority(st.top())) {
            ans += st.top();
           st.pop();
            }
          }
    else {
       while (!st.empty() &&
           st.top() != '(' &&
           priority(s[i]) < priority(st.top())) {
        ans += st.top();
        st.pop();
    }
   }
    st.push(s[i]);
        }
            i++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        ans=reverse(ans);
        return ans;
    }
};

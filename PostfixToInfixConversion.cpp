//Problem:Postfix To Infix Conversion

class Solution {
public:
    string postToInfix(string s) {
        // Your code goes here
        int i=0;
        stack<string>st;
        while(i<s.size()){
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))
              st.push(string(1,s[i]));
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string ans="("+t2+s[i]+t1+")";
                st.push(ans);
            }
            i++;
        }
        return st.top();
    }
};

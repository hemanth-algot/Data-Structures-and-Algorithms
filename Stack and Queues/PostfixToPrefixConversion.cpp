//Problem:Postfix To Prefix Conversion

class Solution {
public:
    string postToPre(string postfix) {
        // Your code goes here
        stack<string>st;
        int i=0;
        while(i<s.size()){
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
             st.push(string(1,s[i]));
            }
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                st.push(s[i]+t2+t1);
            }
            i++;
        }
        return st.top();
    }
};
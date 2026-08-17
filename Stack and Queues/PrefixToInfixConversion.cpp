//Problem:Prefix To Infix Convesion

class Solution {
public:
    string prefixToInfix(string s) {
        // Your code goes here
        stack<string>st;
        int i=s.size()-1;
        while(i>=0){
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
             st.push(string(1,s[i]));
            }
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string con='('+t1+s[i]+t2+')';
                st.push(con);

            }
            i--;
        }
        return st.top();
    }
};
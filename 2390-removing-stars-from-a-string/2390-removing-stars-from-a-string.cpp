class Solution {
public:
    string removeStars(string s) {
        int i=0;
        stack<char> st;
        while(i<s.length()){
            if(s[i]=='*'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            string temp = string(1,st.top());
            ans+=temp;
            st.pop();
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
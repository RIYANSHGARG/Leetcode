class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='/')   continue;
            
            string temp="";
            while(i<s.length() && s[i]!='/'){
                temp+=s[i];
                i++;
            }
            
            if(temp==".")   continue;
            else if(temp==".."){
                if(!st.empty()) st.pop();
            }
            else    st.push(temp);   
        }
        
        string ans="";
        while(!st.empty())  {ans="/"+st.top()+ans;st.pop();}
        if(ans.size()==0)   return "/";
        return ans;
    }
};
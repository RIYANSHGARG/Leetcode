class Solution {
public:
    
    bool valid(string s){
        stack<char> st;
        int i=0;
        while(i<s.length()){
            if(s[i]=='(')   st.push('(');
            else if(s[i]==')' && st.top()=='(') st.pop();
            else    return false;
            i++;
        }
        // cout<<1;
        return st.size()==0;
    }
    
    void helper(vector<string> &ans, string s,int count,int l){
        if(s.length()==l){
            if(valid(s)){ans.push_back(s);}
            return ;
        }
        
        if(count<0) return ;
        
        helper(ans,s+"(",count+1,l);
        helper(ans,s+")",count-1,l);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans; 
        string s;
        int count=0;
        helper(ans,s,count,n*2);
        return ans;
    }
};
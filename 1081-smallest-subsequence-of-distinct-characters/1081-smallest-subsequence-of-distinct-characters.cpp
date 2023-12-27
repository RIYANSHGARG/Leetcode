class Solution {
public:
    string smallestSubsequence(string s) {
//         monotonic stack + frequency track + tracking elements included
        
        stack<char> st;
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++)   m[s[i]]++;
        set<char> s1;
        
        for(int i=0;i<s.size();i++){
            m[s[i]]--;
            
            if(s1.find(s[i])!=s1.end()) continue;
            
            while(!s1.empty() && m[st.top()] > 0 && st.top() > s[i]){
                s1.erase(st.top());
                st.pop();
            }
            
            st.push(s[i]);
            s1.insert(s[i]);
        }
        
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
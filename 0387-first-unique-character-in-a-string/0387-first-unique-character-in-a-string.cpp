class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> m;
        set<char> st;
        for(int i=0;i<s.length();i++){
            if(st.find(s[i]) !=st.end() ){
                continue;
            }else if(m.find(s[i])!=m.end()){
                st.insert(s[i]);
                m.erase(s[i]);
            }
            else{
                m[s[i]]=i;
            }
        }
        if(m.size()==0) return -1;
        int ans=INT_MAX;
        for(auto i:m){
            ans=min(ans,i.second);
        }
        return ans;
    }
};
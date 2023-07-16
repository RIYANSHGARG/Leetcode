class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())    return false;
        unordered_map<char,int> m;
        for(int i=0;i<t.length();i++){
            m[t[i]]++;
        }
        
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])==m.end())   return false;
            if(m[s[i]]==0)  return false;
            m[s[i]]--;
        }
        return true;
    }
};
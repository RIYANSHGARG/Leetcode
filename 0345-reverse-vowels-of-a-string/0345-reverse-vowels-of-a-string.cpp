class Solution {
public:
    string reverseVowels(string s) {
        int j=0;
        set<char> vowels= {'a','A','e','E','i','I','o','O','u','U'};
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(vowels.find(s[i]) != vowels.end())  st.push(s[i]);
        }
        if(st.empty()) return s;
        for(int i=0;i<s.length();i++){
            if(vowels.find(s[i]) != vowels.end()){s[i]=st.top();st.pop();}
        }
        return s;
    }
};
class Solution {
public:
    bool palindrome(string s){
        string temp = s;
        reverse(s.begin(),s.end());
        return (s==temp);
    }
    
    void subseq(int i,string temp,string &s, set<string> &st, set<string> &dp){
        if(i>=s.length() || temp.length()==3){
            dp.insert(temp);
            if(temp.length()==3 && palindrome(temp)){
                st.insert(temp);
            }
            return ;
        }
        
        if(dp.find(temp)!=dp.end()) return ;
        
        temp.push_back(s[i]);
        subseq(i+1,temp,s,st,dp);
        temp.pop_back();
        subseq(i+1,temp,s,st,dp);
    }
    
    bool exist(string s1,string s){
        int j,k;
        for(int i=0;i<s.length()-2;i++){
            if(s[i]==s1[0]){
                j=i+1;k=s.length()-1;
                while(j<k){
                    if(s[j]!=s1[1]) j++;
                    else if(s[k]!=s1[2])    k--;
                    else    break;   
                }
                if(j<k) return true;
            }
        }
        
        return false;
    }
    
    bool sub(const string& pattern, const string& text) {
        int i, j;
        for(i = 0, j = 0; i < text.size() && j < 3; ++i) {
            if(text[i] == pattern[j])
                ++j;
        }
        return j == 3;
    }
    
    int countPalindromicSubsequence(string s) {
        // set<string> st;
        // set<string> dp;
        // string temp="";
        // subseq(0,temp,s,st,dp);
        // return st.size();
        
        int ans=0;
        for(char i='a';i<='z';i++){
            for(char j='a';j<='z';j++){
                string temp="";
                temp+=i;
                temp+=j;
                temp+=i;
                // if(exist(temp,s)){ans++;}
                if(sub(temp,s)){ans++;}
            }
        }
        return ans;
    }
};
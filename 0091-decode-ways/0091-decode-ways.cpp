class Solution {
public:
    void rec(int i, string &s, int &count,unordered_map<int,char> &m,vector<int> &dp){
        if(i>=s.length()){
            count++;
            return ;
        }
        if(dp[i]!=-1){
            count+=dp[i];
            return ;
        }
        if(s[i]=='0')   return ;
        
        if(m.find(s[i]-'0') !=m.end()){
            rec(i+1,s,count,m,dp);
            dp[i]=count;
        }
        if(i!=s.length()-1 && m.find(stoi(s.substr(i,2))) != m.end() ){
            rec(i+2,s,count,m,dp);
            dp[i]=count;
        }
    }
    
    
    int numDecodings(string s) {
        unordered_map<int,char> m;
        for(char i='a';i<='z';i++){
            m[i-'a'+1]=i;
        }
        vector<int> dp(s.length()+1,-1); 
        int count=0;
        rec(0,s,count,m,dp);
        return count;
    }
};
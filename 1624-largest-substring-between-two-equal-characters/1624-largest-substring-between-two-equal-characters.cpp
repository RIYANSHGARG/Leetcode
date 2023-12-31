class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> start(26,-1),end(26,-1);
        for(int i=0;i<s.length();i++){
            if(start[s[i]-'a']==-1){
                start[s[i]-'a']=i;
            }else{
                end[s[i]-'a']=i;
            }
        }
        int ans=-1;
        for(int i=0;i<26;i++){
            if(start[i]!=-1&& end[i]!=-1){
                ans=max(ans,end[i]-start[i]-1);
            }
        }
        return ans;
    }
};
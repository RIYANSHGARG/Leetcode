class Solution {
public:
    int countHomogenous(string s) {
        const unsigned int M = 1000000007;
        int ans=0;
        pair<char,int> p;
        p={'0',0};
        for(int i=0;i<s.length();i++){
            if(s[i]==p.first){
                int count=p.second;
                count++;
                ans=((ans)%M+count)%M;
                p.second=count;
            }else{
                p.first=s[i];
                ans+=1;
                p.second=1;
            }
        }
        return ans;
    }
};
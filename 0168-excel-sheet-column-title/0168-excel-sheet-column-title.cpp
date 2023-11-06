class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber!=0){
            int n=(columnNumber-1)%26;
            char nxt = n+'A';
            ans+=nxt;
            columnNumber=(columnNumber-1)/26;
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
class Solution {
public:
    
    int count_operations(string s){
        int count=0;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                count++;
                if(s[i]=='1')   s[i]='0';
                else    s[i]='1';
            }
        }
        return count;
    }
    
    int minOperations(string s) {
        int ans=INT_MAX;
        
        string temp = s;
        ans = min(ans,count_operations(temp));
        
        reverse(s.begin(),s.end());
        ans = min(ans,count_operations(s));
        
        int count=1;
        if(temp[0]=='1')   temp[0]='0';
        else    temp[0]='1';
        count+= count_operations(temp);
        ans = min(ans,count);
        
        count=1;
        if(s[0]=='1')   s[0]='0';
        else    s[0]='1';
        count+= count_operations(temp);
        ans = min(ans,count);
        
        return ans;
    }
};
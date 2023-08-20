class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int count=32;
        string s="";
        while(count--){
            if(n&1){s+="1";}
            else{s+="0";}
            n>>=1;
        }
        cout<<s;
        uint32_t ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                ans+=pow(2,(31-i) );    
            }
        }
        return ans;
    }
};
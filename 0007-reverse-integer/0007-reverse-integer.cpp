class Solution {
public:
    int reverse(int x) {
        bool neg=(x<0)?true:false;
        x=abs(x);
        if(x>pow(2,31)-1 || x<(-1)*pow(2,31) )   return 0;
        long long int ans=0;
        while(x>0){
            ans=ans*10+x%10;
            if(ans>pow(2,31)-1 || ans<(-1)*pow(2,31) )   return 0;
            x/=10;
        }
        if(neg==true)   return (int)(-1)*ans;
        return (int)ans;
    }
};
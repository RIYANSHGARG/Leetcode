class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)    return false;
        int count=0;
        while(n>1){
            if(n&1) return false;
            count++;
            n>>=1;
        }
        if(count%2==0)  return true;
        return false;
    }
};
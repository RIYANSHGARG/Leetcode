class Solution {
public:
    int rec(int i){
        if(i==0 || i==1)    return i;
        
        return rec(i-1)+rec(i-2);
    }
    int fib(int n) {
        int ans=rec(n);
        return ans;
    }
};
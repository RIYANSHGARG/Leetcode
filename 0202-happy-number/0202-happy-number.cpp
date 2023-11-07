class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        
        while( s.find(n)==s.end() ){
            s.insert(n);
            int a=0;
            while(n){
                a=a+pow((n%10),2);
                n/=10;
            }
            if(a==1)    return true;
            n=a;
        }
        return false;
    }
};
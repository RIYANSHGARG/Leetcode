class Solution {
public:
    int tribonacci(int n) {
        vector<int> tribonnaci;
        tribonnaci.push_back(0);
        tribonnaci.push_back(1);
        tribonnaci.push_back(1);
        
        for(int i=3;i<=n;i++){
            tribonnaci.push_back(tribonnaci[i-1]+tribonnaci[i-2]+tribonnaci[i-3]);
        }
        return tribonnaci[n];
    }
};
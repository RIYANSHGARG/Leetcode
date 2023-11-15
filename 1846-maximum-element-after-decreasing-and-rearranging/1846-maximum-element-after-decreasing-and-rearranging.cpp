class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // int maxi = *max_element(arr.begin(),arr.end()) , mod = 1e5;
        // if(maxi<arr.size()) return maxi%mod;
        // return arr.size()%mod;
        
        sort(arr.begin(),arr.end());        
        int prev = 0;
        for(int a: arr) if(a>prev) prev++;
        return prev;

    }
};
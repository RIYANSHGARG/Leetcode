//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // code here
        // return int(sqrt(N-1));
        
        long long low=1,high=N;
        while(low<=high){
            long long  mid=(low+high)/2;
            if(mid*mid > N) high=mid-1;
            else    low=mid+1;
        }
        return (high*high==N)?high-1:high;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
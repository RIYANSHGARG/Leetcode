//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> v;
        for(auto i:Mat){
            for(auto j:i){
                v.push_back(j);
            }
        }
        int j=0,k=0;
        sort(v.begin(),v.end());
        
        // above Part Can Be done using min heap also.
        
        for(int i:v){
            if(k==N){
                j++;k=0;
            }
            Mat[j][k++]=i;
        }
        return Mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
  int MaxAreaOfHistogram(vector<int> heights){
        int ans=INT_MIN;
        stack<int> s;
        for(int i=0;i<=heights.size();i++){
            while(!s.empty() && (i==heights.size() || heights[i]<heights[s.top()]) ){
                int findArea=s.top();
                s.pop();
                if(s.empty())   ans=max(ans,heights[findArea]*(i-0));
                else    ans=max(ans,heights[findArea]*(i-s.top()-1));
            }
            s.push(i);
        }
        return ans;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int ans=0;
        vector<int> v(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0) v[j]=0;
                else    v[j]++;
            }
            ans=max(ans,MaxAreaOfHistogram(v));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
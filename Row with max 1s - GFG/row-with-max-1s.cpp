//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int indexOfOne(vector<int> v){
        int low=0,high=v.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(v[mid]==1)   high=mid-1;
            else    low=mid+1;
        }
        return v.size()-low;
    }

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    
	    // Method 1 : Better Approach Direct Done (Using Binary Search on each Row)
	   // int ans=-1,count=0;
	   // for(int i=0;i<arr.size();i++){
	   //     int row=indexOfOne(arr[i]);
	   //     if(row==arr[0].size())  return i;
	   //     if(row>count){count=row;ans=i;}
	   // }
	   // return ans;
	    
	   // Method 2 : Logical Approach
	   int i=0,j=arr[0].size()-1,ans=-1;
	   while(i<n && j>=0){
	       if(arr[i][j]==1) {ans=i;j--;}
	       else i++;
	   }
	   return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
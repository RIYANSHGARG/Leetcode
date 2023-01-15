//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        int dif,ans=INT_MAX;
        // for(int i=m;i<=n;i++){
        //     dif=*max_element(a.begin()+i-m, a.begin()+i)-*min_element(a.begin()+i-m, a.begin()+i);
        //     ans=(dif<ans)?dif:ans;
        // }
        
        for(int i=m;i<=n;i++){
            dif=a[i-1]-a[i-m];
            ans=min(ans,dif);
        }
        return ans;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends
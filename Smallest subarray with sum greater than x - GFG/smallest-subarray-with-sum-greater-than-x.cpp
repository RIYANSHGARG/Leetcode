//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Mehthod 1 : O(N^2)
        // int ans=INT_MAX,sum=0,count=0;
        // for(int i=0;i<n;i++){
        //     sum=arr[i];count=1;
        //     if(arr[i]>x)   return 1;
        //     for(int j=i+1;j<n;j++){
        //         sum+=arr[j];count++;
        //         if(sum>x)  {ans=min(count,ans);break;}
        //     }
        // }
        // return (ans<INT_MAX)?ans:0;
        
        
        // method 2 : Variable lengthed sliding window. 
        
        int ans=INT_MAX,i=0,j=0,sum=arr[j];
        while(i<n&&j<n){
            if(sum>x){
                ans=min(ans,j-i+1);
                sum-=arr[i];
                i++;
            }else{
                sum+=arr[++j];
            }
        }
        return (ans<INT_MAX)?ans:0;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        // Brute force : traversing both side from the point and checking leftmax and rightmax 
        // to findout max water store in that box.
        // long long int area=0;
        // for(int i=0;i<n;i++){
        //     int j=i,leftMax=0,rightMax=0;
        //     while(j>=0) leftMax=max(arr[j--],leftMax);
        //     j=i;
        //     while(j<n)  rightMax=max(arr[j++],rightMax);
        //     area+= min(leftMax,rightMax)-arr[i];
        // }
        // return area;
        
        // Method 2 : Storing all the leftmax and rightmax in array
        long long ans=0;
        int lmax=arr[0],rmax=arr[n-1];
        vector<int> LMA(n),RMA(n);
        for(int i=0;i<n;i++)    {LMA[i]=max(arr[i],lmax);lmax=max(arr[i],lmax);}
        for(int i=n-1;i>=0;i--)    {RMA[i]=max(arr[i],rmax);rmax=max(arr[i],rmax);}
        for(int i=0;i<n;i++){ans+=(min(LMA[i],RMA[i])-arr[i]);}
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int t) {
        // sort(arr,arr+n);
        // int ans=0;
        // int k=n/t,count=1,i;
        // for(i=1;i<n;i++){
        //     if(arr[i]==arr[i-1])  count++;
        //     else{if(count>k){ans++;}count=1;}
        // }
        // if(count>k)    ans++;
        // return ans;
        
        int count=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)  m[arr[i]]++;
        for(auto i:m)   if(i.second>n/t) count++;
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    if(n==1)    return;
        vector<int> v1,v2;
        for(int i=0;i<n;i++){
            if(arr[i]<0)    v2.push_back(arr[i]);
            else    v1.push_back(arr[i]);
        }
        int n1=v1.size(),n2=v2.size(),i=0,j=0,k=0;
        // cout<<n1<<" "<<n2;
        while(j<n1 && k<n2){
            if(i%2==0){
                arr[i]=v1[j];
                j++;
            }
            else{
                arr[i]=v2[k];
                k++;
            }
            i++;
        }
         while(j<n1){
            arr[i]=v1[j];
            i++;j++;
        }
        while(k<n2){
            arr[i]=v2[k];
            i++;k++;
        }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // Method 1 : Dirrect sorting
        // sort(a,a+n);
        
        // Method 2: using maps; // last case TLE
        // unordered_map<int,int> m;
        // for(int i=0;i<n;i++){
        //     m[a[i]]++;
        // }
        // for(int i=0;i<n;i++){
        //     if(m[0]!=0){a[i]=0;m[0]--;}
        //     else if(m[1]!=0){a[i]=1;m[1]--;}
        //     else{a[i]=2;m[2]--;}
        // }
        
        // Method 3 using dutch national flag algorithm
        
        int low=0,mid=0,high=n-1;
        for(int i=0;i<n;i++){
            if(a[mid]==0){
                swap(a[mid],a[low]);
                low++;mid++;
            }
            else if(a[mid]==1)   mid++;
            else{
                swap(a[mid],a[high]);
                high--;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends
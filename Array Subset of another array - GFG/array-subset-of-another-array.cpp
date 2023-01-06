//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    
    // Method 1 : naive approach
    // pickibg up element and searching in the array   -> O(nm)
    
    // Method 2 : sorting main array and applying binary search for each and every element for arr2 in arr1.
    
    // method 3 : sorting arr1 and then finding every element of arr2 using two pointer approach
    
    // method 4 : using hashing
    if(m>n)     return "No";
    string ans;
    unordered_map<int,int> s;
    for(int i=0;i<n;i++)    s[a1[i]]++;
    for(int i=0;i<m;i++)    if(s[a2[i]]--){ans="Yes";}else{ans="No";break;}
    return ans;
}
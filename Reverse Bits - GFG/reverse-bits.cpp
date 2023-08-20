//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        
        int count=32;
        string s="";
        while(count--){
            if(X&1){s+="1";}
            else{s+="0";}
            X>>=1;
        }
        // cout<<s;
        long long int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                ans+=pow(2,(31-i) );    
            }
        }
        return ans;
        
        // long long result= 0;
        // for(int i=0; i<32; i++)
        //     result = (result<<1) + (X>>i &1);
        
        // return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
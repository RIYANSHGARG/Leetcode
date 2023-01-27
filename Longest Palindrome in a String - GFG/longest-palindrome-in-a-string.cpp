//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool isPalin(string a){
        string b=a;
        reverse(a.begin(),a.end());
        return a==b;
    }
    string longestPalin (string S) {
        // code here
        // O(n^3)
        // string ans="";
        // for(int i=0;i<S.length();i++){
        //     string temp="";
        //     for(int j=i;j<S.length();j++){
        //         temp+=S[j];
        //         if(isPalin(temp) && temp.length()>ans.length())    ans=temp;
        //     }
        // }
        // return ans;
        
        // O(n^2)
        //   even            odd
        // aaaabbaa        aaabaaa
        //  ( <--> )      (  <->  )
        
        string ans;
        // Edge Case
        if(S.length()<=1)   return S;
        if(S.length()==2)   return (S[0]==S[1])?S:ans+=S[0];
        
        // Even
        int i=0;
        while(i<S.length()-1){
            int l=i,r=i+1,count=0;
            while(l>=0 and r<S.length()){
                if(S[l]==S[r])  {l--;r++;count+=2;}
                else    break;
            }
            if(count>ans.length())  ans=S.substr(l+1,r-l-1);
            i++;
        }
        // Odd
        i=0;
        while(i<S.length()-1){
            int l=i,r=i,count=-1;
            while(l>=0 and r<S.length()){
                if(S[l]==S[r]){l--;r++;count+=2;}
                else{break;}
            }
            if(count>ans.length())  ans=S.substr(l+1,r-l-1);
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
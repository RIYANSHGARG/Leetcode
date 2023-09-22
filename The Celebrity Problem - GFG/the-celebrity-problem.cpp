//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    bool knows(int a,int b,vector<vector<int>> &v){
        if(v[a][b]) return true;
        return false;
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i=0;i<n;i++)    s.push(i);
        while(s.size()!=1){
            int a=s.top();s.pop();
            int b=s.top();s.pop();
            if(knows(a,b,M))  s.push(b);
            else    s.push(a);
        }
        int el=s.top(),count=0;
        for(int i=0;i<n;i++){
            if(M[el][i]==1) return -1;
        }
        for(int i=0;i<n;i++){
            if(M[i][el]==1) count++;
        }
        // cout<<count<<" "<<el;
        if(count==n-1)  return el;
        return -1;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/
#include <bits/stdc++.h>
class Solution {
public:
    bool CheckPalindrome(int a){
        string s=to_string(a);
        string s1=s;
        reverse(s.begin(),s.end());
        if(s==s1)   return 1;
        else return 0;
    }

    int PalinArray(int a[], int n)
    {
        for(int i=0;i<n;i++)    if(!CheckPalindrome(a[i]))  return 0;
        return 1;
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
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends
//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/
#include <bits/stdc++.h>
class Solution {
public:
    bool CheckPalindrome1(int a){
        string s=to_string(a);
        string s1=s;
        reverse(s.begin(),s.end());
        return (s==s1);
    }
    
    bool CheckPalindrome2(int a){
        int b=0,c=a;
        while(a!=0){
            b=b*10+a%10;
            a/=10;
        }
        return (b==c);
    }

    int PalinArray(int a[], int n)
    {
        for(int i=0;i<n;i++){if(!CheckPalindrome2(a[i])){return 0;}}
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
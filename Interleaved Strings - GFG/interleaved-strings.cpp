//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  unordered_map<string,bool> m;
    bool checkMemo(string s1,string s2,string s3,int len1,int len2,int len3,int p1,int p2,int p3){
        if(p3==len3)    return (p1==len1 and p2==len2)?true:false;

        string key=to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
        if(m.find(key)!=m.end())    return m[key];
        
        // 3 cases
        // Case : 1 (if string 1 is completed)
        if(p1==len1){return m[key]=(s2[p2]==s3[p3])?checkMemo(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1):false;}
        // Case : 2 (if string 2 is completed)
        if(p2==len2){return m[key]=(s1[p1]==s3[p3])?checkMemo(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1):false;}
        // Case : 3
        bool one=false,two=false;
        if(s1[p1]==s3[p3])  one=checkMemo(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1);
        if(s2[p2]==s3[p3])  two=checkMemo(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1);
        return m[key]=(one||two);
    }
    /*You are required to complete this method */
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.length()+s2.length()!=s3.length())    return false;
        return checkMemo(s1,s2,s3,s1.length(),s2.length(),s3.length(),0,0,0);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends
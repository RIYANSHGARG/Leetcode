//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
	
	    void recursion(string s,int i,vector<string> &ans,string temp){
	        if(i==s.length()){
	            if(temp=="")    return ;
	            ans.push_back(temp);
	            return ;
	        }
	        temp+=s[i];
	        recursion(s,i+1,ans,temp);
	        temp.pop_back();
	        recursion(s,i+1,ans,temp);
	    }
	
		vector<string> AllPossibleStrings(string s){
		  //  vector<string> ans;
		  //  for(int i=1;i<(1<<s.length());i++){
		  //      string temp="";
		  //      for(int j=0;j<s.length();j++){
		  //          if(i&(1<<j))    temp+=s[j];
		  //      }
		  //      ans.push_back(temp);
		  //  }
		  //  sort(ans.begin(),ans.end());
		  //  return ans;
		  
		  // Method 2 : Recursion
		  string temp;
		  vector<string> ans;
		  recursion(s,0,ans,temp);
		  sort(ans.begin(),ans.end());
		  return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
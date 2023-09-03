#include<bits/stdc++.h> 

class Solution {
public:
    void inserting(vector<string> &ans, string s){
        vector<string> dummy;
        if(ans.size()==0){
            for(int i=0;i<s.length();i++){
                string s1;
                s1+=s[i];
                dummy.push_back(s1);
            }
        }else{
            for(int i=0;i<s.length();i++){
                for(int j=0;j<ans.size();j++){
                    dummy.push_back(ans[j]+s[i]);
                }
            }
        }
        ans=dummy;
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> v= {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits=="")  return {};
        vector<string> ans;
        for(int i=0;i<digits.length();i++){
            cout<<v[digits[i]-'0'];
            inserting(ans,v[digits[i]-'0']);
        }
        
        return ans;
    }
};
class Solution {
public:
    string getString(char x)
    {
        string s(1, x);
        return s;  
    }
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string ans;
        while(i<word1.length() && j<word2.length()){
            ans+=getString(word1[i])+getString(word2[j]);
            i++;j++;
        }
        while(i<word1.length()) ans+=word1[i++];
        while(j<word2.length()) ans+=word2[j++];
        return ans;
    }
};
class Solution {
public:
    string reversePrefix(string word, char ch) {
        string reversed="";
        int i=0;
        for(i=0;i<word.size();i++){if(word[i]==ch){break;}}
        if(i==word.size())  return word;
        reverse(word.begin(),word.begin()+i+1);
        return word;
    }
};
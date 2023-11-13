class Solution {
public:
    string sortVowels(string s) {
        set<char> vowel = {'A','E','I','O','U','a','e','i','o','u'};
        vector<char> strV;
        for(int i=0;i<s.length();i++){
            if(vowel.find(s[i]) != vowel.end() ){
                strV.push_back(s[i]);
            }
        }
        int j=0;
        sort(strV.begin(),strV.end());
        for(int i=0;i<s.length();i++){
            if(vowel.find(s[i]) != vowel.end() ){
                s[i]=strV[j];
                j++;
            }
        }
        return s;
    }
};
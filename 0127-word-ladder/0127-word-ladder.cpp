class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans=0;
        unordered_set<string> s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==endWord)   {ans=level;}
            for(int i=0;i<word.length();i++){
                char original=word[i];
                for(char j='a';j<='z';j++){
                    if(word[i]==j)  continue;
                    word[i]=j;
                    if(s.find(word)!=s.end()){
                        q.push({word,level+1});
                        s.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }
};
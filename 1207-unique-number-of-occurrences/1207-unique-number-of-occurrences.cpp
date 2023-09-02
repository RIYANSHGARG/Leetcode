class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> s;
        unordered_map<int,int> m;
        for(auto i:arr) m[i]++;
        for(auto i:m){
            if(s.find(i.second)!=s.end() )  return false;
            s.insert(i.second);
        }
        return true;
    }
};
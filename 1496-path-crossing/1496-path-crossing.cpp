class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
        unordered_map<char,pair<int,int>> m;
        m['N']={0,1};
        m['E']={1,0};
        m['W']={-1,0};
        m['S']={0,-1};
        set<pair<int,int>> s;
        s.insert({0,0});
        for(int i=0;i<path.length();i++){
            x+=m[path[i]].first;
            y+=m[path[i]].second;
            
            if(s.find({x,y}) != s.end() ){
                return true;
            }
            s.insert({x,y});
        }
        return false;
    }
};
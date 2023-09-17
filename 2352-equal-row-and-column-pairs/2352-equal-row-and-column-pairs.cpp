class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;
        multiset<vector<int>> s;
        for(int i=0;i<grid.size();i++){
            vector<int> temp;
            for(int j=0;j<grid.size();j++)  temp.push_back(grid[i][j]);
            s.insert(temp);
        }
        
        for(int i=0;i<grid.size();i++){
            vector<int> temp;
            for(int j=0;j<grid.size();j++)  temp.push_back(grid[j][i]);
            if(s.find(temp)!=s.end())   count+=s.count(temp);
        }
        return count;
    }
};
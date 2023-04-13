class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int ,int> map;
        for(int i=0;i<2;i++){
            map[edges[i][0]]++;
            map[edges[i][1]]++;
        }
        
        int ans;
        for(auto &[x,y]:map)
            if(y==2)ans =x;
        
        return ans;
    }
};
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = 0;
        int center = edges[0][0];
        if(edges[1][0] != center && edges[1][1] != center)
            center = edges[0][1];
        return center; 
    }
};
class Solution {
public:
    void dfs(int i,vector<vector<int>> &rooms, vector<int> &vis){
        vis[i]=1;
        for(auto j:rooms[i]){
            if(!vis[j])  dfs(j,rooms,vis);
        }
        return ;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        dfs(0,rooms,vis);
        for(int i=0;i<rooms.size();i++){
            if(vis[i]==0)   return false;
        }
        return true;
    }
};
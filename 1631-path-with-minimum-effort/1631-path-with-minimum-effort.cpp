class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        
        vector<vector<int>> nrc={{-1,0},{0,-1},{0,1},{1,0}};
        
        priority_queue< pair<int,pair<int,int>> ,
        vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int effort=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            if(row==n-1 && col==m-1)  return effort;
            
            for(int i=0;i<4;i++){
                int newrow = row+nrc[i][0];
                int newcol = col+nrc[i][1];
                
                if(newrow>=0 && newrow<n && newcol>=0 && newcol <m){
                    int newEffort = max(effort,abs(heights[row][col]-heights[newrow][newcol]));
                    if(newEffort < dist[newrow][newcol]){
                        dist[newrow][newcol]=newEffort;
                        pq.push({newEffort,{newrow,newcol}});   
                    }
                    
                }
            }
        }
        
        return 0;
    }
};
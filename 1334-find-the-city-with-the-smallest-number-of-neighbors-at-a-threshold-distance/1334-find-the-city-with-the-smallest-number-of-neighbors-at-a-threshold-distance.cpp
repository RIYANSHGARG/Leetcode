class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // Created a Distance matrix(adj matrix)
        vector<vector<long long>> dist(n,vector<long long>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            dist[edges[i][0]][edges[i][1]]=edges[i][2];
            dist[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        // Marking all Diagonals zero
        for(int i=0;i<dist.size();i++){
            dist[i][i]=0;
        }
        
        // Applying Flloyd Warshell to calculating min distance between all nodes
        for(int k=0;k<n;k++){
            for(int i=0;i<dist.size();i++){
                for(int j=0;j<dist[0].size();j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        
        // Traversing dist matrix and calulating all node which have least thershold and highest node.
        int count=0,ans=-1,mincount=INT_MAX;
        for(int i=0;i<dist.size();i++){
            for(int j=0;j<dist[0].size();j++){
                if(dist[i][j]<=distanceThreshold)    count++;
            }
            if(count<=mincount && i>ans){mincount=count;ans=i;}
            count=0;
        }
        return ans;
    }
};
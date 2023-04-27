class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        vector<int> adj[N];
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
	    }
	    vector<int> topo,indegree(N,0);
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        for(auto j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    for(int i=0;i<N;i++)    if(indegree[i]==0)  q.push(i);
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto i:adj[node]){
	            indegree[i]--;
	            if(indegree[i]==0)  q.push(i);
	        }
	    }
	    return (topo.size()==N);
    }
};
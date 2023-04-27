//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
class Solution
{
    public:
        int countPaths(int n, vector<vector < int>> &roads)
        {
            int mod=(int)(1e9+7);
            vector<pair<long long, long long>> adj[n];
            for (auto it: roads)
            {
                adj[it[0]].push_back({ it[1],it[2] });
                adj[it[1]].push_back({ it[0],it[2] });
            }
            vector<long long> ways(n, 0), dist(n, LLONG_MAX);
            priority_queue<pair<long long, long long>, vector< pair<long long, long long>>, greater<pair<long long, long long>>> pq;
           	// dist, node
            pq.push({0,0});
            dist[0] = 0;
            ways[0] = 1;
            while (!pq.empty())
            {
                long long int dis = pq.top().first;
                long long int node = pq.top().second;
                pq.pop();

                for (auto i: adj[node])
                {
                    long long adjnode = i.first;
                    long long int newdis = (dis + i.second);

                    if (newdis < dist[adjnode])
                    {
                        dist[adjnode] = newdis;
                        pq.push({ newdis,adjnode });
                        ways[adjnode] = ways[node];
                    }
                    else if (newdis == dist[adjnode])
                    {
                        ways[adjnode] =(ways[adjnode]+ ways[node])%mod;
                    }
                }
            }
            return ways[n - 1]%mod;
        }
};
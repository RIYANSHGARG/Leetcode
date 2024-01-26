class Solution {
public:
    
   class myComparator {
    public:
    bool operator() (pair<int,string> p1, pair<int,string> p2){
        if(p1.first==p2.first)  return p1.second<p2.second;
        return p1.first>p2.first;
    }
   };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
         map<string,int> m;
        priority_queue<pair<int,string>, vector<pair<int,string>>, myComparator> pq;
        
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        for(auto i:m){
            pq.push({i.second,i.first});
            if(pq.size() > k)   pq.pop();
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
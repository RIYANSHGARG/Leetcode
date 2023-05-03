//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // Catch of this question is figuring out size of dist vector
        // vector<int> dist(99999,INT_MAX);
        // dist[start % 100000]=0;
        // queue<pair<int,int>> q;
        // // steps , node
        // q.push({0,start % 100000});
        // while(!q.empty()){
        //     int dis=q.front().first;
        //     int node = q.front().second;
        //     q.pop();
            
        //     for(int i=0;i<arr.size();i++){
        //         int element=(node*arr[i])%100000;
        //         if(element==end)    return dis+1;
        //         q.push({dis+1,element});
        //         dist[element]=dis+1;
        //     }
        // }
        // return -1;
        
        // Striver 
        vector<int> dist(99999,INT_MAX);
        dist[start % 100000]=0;
        queue<pair<int,int>> q;
        // node , step
        // We need to find node as main priority and corresponding step will always be min because it is increasing by 1 every time
        q.push({start,0});
        while(!q.empty()){
            int node = q.front().first;
            int dis=q.front().second;
            q.pop();
            
            for(int i=0;i<arr.size();i++){
                int element=(node*arr[i])%100000;
                if(dis+1 < dist[element]){
                    if(element==end)    return dis+1;
                    q.push({element,dis+1});
                    dist[element]=dis+1;    
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
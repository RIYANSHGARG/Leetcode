//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int CalculateNoLessEqual(vector<int> v,int element){
        int low=0,high=v.size()-1;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(v[mid]<=element)  low=mid+1;
            else    high=mid-1;
        }
        return low;
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        // code here      
        
        // Naive Approach
        // vector<int> v;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         v.push_back(matrix[i][j]);
        //     }
        // }
        // sort(v.begin(),v.end());
        // return v[v.size()/2];
        
        // Best Approach : Binary Search
        
        int low=0,high=10e6;
        while(low<=high){
            int mid=low+((high-low)/2);
            int count=0;
            for(int i=0;i<R;i++){
                count+=CalculateNoLessEqual(matrix[i],mid);
            }
            if(count>(R*C)/2)  high=mid-1;
            else    low=mid+1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends
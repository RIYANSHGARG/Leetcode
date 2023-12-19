class Solution {
public:
    
    void findSum(int row,int col, int &sum , int &count, vector<vector<int>> &img){
        
        for(int i=row-1;i<=row+1;i++){
            for(int j=col-1;j<=col+1;j++){
                if(i<0 || i>=img.size() || j<0 || j>=img[0].size()) continue;
                sum+=img[i][j];
                count++;
            }
        }
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(),m=img[0].size();
        vector<vector<int>> ans(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=0 , count=0;
                findSum(i,j,sum,count,img);
                
                ans[i][j] = sum/count;
            }
        }
        return ans;
    }
};
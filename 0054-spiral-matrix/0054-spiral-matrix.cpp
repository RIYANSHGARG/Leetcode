class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0,j=0,n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<int> ans;
        while(ans.size()<matrix.size()*matrix[0].size()){
            for(i;i<matrix[0].size();i++){
                if(visited[j][i]==1){break;}
                ans.push_back(matrix[j][i]);
                visited[j][i]=1;
            }
            i=i-1;j=j+1;
            for(j;j<matrix.size();j++){
                if(visited[j][i]==1){break;}
                ans.push_back(matrix[j][i]);
                visited[j][i]=1;
            }
            j=j-1;i=i-1;
            for(i;i>=0;i--){
                if(visited[j][i]==1){break;}
                ans.push_back(matrix[j][i]);
                visited[j][i]=1;
            }
            i=i+1;j=j-1;
            for(j;j>=0;j--){
                if(visited[j][i]==1){break;}
                ans.push_back(matrix[j][i]);
                visited[j][i]=1;
            }
            i=i+1;j=j+1;
        }
        return ans;
    }
};
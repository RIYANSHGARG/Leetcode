class Solution {
public:
    
    void bfs(vector<vector<int>>& image, int i, int j,int val, int newColor,int delrow[],int delcol[]){
        image[i][j]=newColor;
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int newrow= r+delrow[i];
                int newcol= c+delcol[i];
                
                if(newrow>=0 && newrow <image.size() && newcol>=0 && newcol <image[0].size() && image[newrow][newcol]==val && image[newrow][newcol]!=newColor){
                    image[newrow][newcol]=newColor;
                    q.push({newrow,newcol});
                }
            }
        }
    }
    
    void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor)
    {
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val)
        {
            return;
        }
        image[i][j] = newColor;
        dfs(image,i-1,j,val,newColor);
        dfs(image,i+1,j,val,newColor);
        dfs(image,i,j-1,val,newColor);
        dfs(image,i,j+1,val,newColor); 
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int val = image[sr][sc];
        // dfs(image,sr,sc,val,newColor);
        
        int delrow[4]={-1,0,0,1};
        int delcol[4]={0,-1,1,0};
        bfs(image,sr,sc,val,newColor,delrow,delcol);
        return image;
    }
};
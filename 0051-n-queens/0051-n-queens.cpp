class Solution {
public:
    
    bool canfill(int row,int col,vector<string> board, int n){
        int i=row,j=col;
        for(int k=0;k<n;k++)    if(board[row][k]=='Q')  return false;
        for(int k=0;k<n;k++)    if(board[k][col]=='Q')  return false;
        
        while(i>=0 && i<n && j>=0 && j<n){
            if(board[i--][j--]=='Q')    return false;
        }
        i=row,j=col;
        while(i>=0 && i<n && j>=0 && j<n){
            if(board[i++][j--]=='Q')    return false;
        }
        return true;
    }
    
    void func(int col,int n,vector<string> &board,vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
                return ;
        }
        
        for(int row=0;row<n;row++){
            if(canfill(row,col,board, n)){
                board[row][col]='Q';
                func(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> temp(n,s); 
        vector<vector<string>>  ans;
        func(0,n,temp,ans);
        return ans;
    }
};
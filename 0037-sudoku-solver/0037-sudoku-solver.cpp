class Solution {
public:
    
    bool check(vector<vector<char>> &board, int i,int j,char k){
        for(int l=0;l<9;l++){
            if(board[i][l]==k)  return false;
            if(board[l][j]==k)  return false;
            if(board[3*(i/3) + l/3][3*(j/3)+l%3]==k)    return false;
        }
        
        // Error (Find It)
        // vector<vector<int>> box={{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
        // int st=3*i/3+3*j/3;
        // for(int m=box[st][0] ;m<box[st][0]+3 ; m++){
        //     for(int n=box[st][1] ; n<box[st][1]+3;n++){
        //         if(board[m][n]==k)  return false;
        //     }
        // }
        return true;
    }
    
    bool solve(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(check(board,i,j,k)){
                            board[i][j]=k;
                            if(solve(board))    return true;
                            else    board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
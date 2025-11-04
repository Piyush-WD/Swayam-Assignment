class Solution {
public:
    bool check(vector<string>&board, int i, int j){ //diagonal checking
        //Upper left
        int row = i;
        int col = j;
        while(row>-1&&col>-1){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row = i;
        col = j;
        while(row>-1&&col<board.size()){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col++;
        }
        return true;
    }

    void find(int i, int n, vector<vector<string>>&ans, vector<string>&board, vector<bool>col){
        //base
        if(i==n){
            ans.push_back(board);
        }

        for(int j=0;j<n;j++){
            if(col[j]==false&&check(board, i, j)){
                col[j]=true;
                board[i][j]='Q';
                find(i+1, n, ans, board, col);
                col[j]=false;
                board[i][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i].push_back('.');
            }
        }

        vector<bool>col(n, false); //for keeping check of each column

        find(0, n, ans, board, col); //helper function  

        return ans;
    }
};
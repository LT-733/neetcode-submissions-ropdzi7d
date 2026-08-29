class Solution {
public:
    // vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> safe;
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size()) return;
        if(safe[i][j]) return;
        if(board[i][j] == 'X') return;
        safe[i][j] = true;
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
    void solve(vector<vector<char>>& board) {
        safe.resize(board.size(), vector<bool> (board[0].size(), false));
        for(int i = 0; i < board.size(); ++i){
            dfs(board, i, 0);
            dfs(board, i, board[0].size()-1);
        }
        for(int j = 0; j < board[0].size(); ++j){
            dfs(board, 0, j);
            dfs(board, board.size()-1, j);
        }
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(!safe[i][j]) board[i][j] = 'X';
            }
        } return;
    }
};

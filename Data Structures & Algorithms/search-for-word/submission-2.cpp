class Solution {
private:
    vector<vector<bool>> seen;
    bool track(vector<vector<char>>& board, int i, int j, string word, int curidx){
        if(curidx == word.size()) return true;
        if(i >= board.size() or j >= board[0].size() or i < 0 or j < 0 or seen[i][j] == true or board[i][j] != word[curidx]) return false;
        seen[i][j] = true;
        bool result = track(board, i+1, j, word, curidx+1) or track(board, i, j+1, word, curidx+1) or track(board, i-1, j, word, curidx+1) or track(board, i, j-1, word, curidx+1);
        seen[i][j] = false;
        return result;
    }
public:
    int r, c;
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        r = board.size();
        c = board[0].size();
        seen = vector<vector<bool>> (r, vector<bool> (c, false));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(track(board, i, j, word, 0)) return true;
            }
        }
        return found;
    }
};

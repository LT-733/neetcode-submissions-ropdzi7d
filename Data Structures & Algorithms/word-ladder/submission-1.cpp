class Solution {
public:
    unordered_set<string> visited;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 0;
        queue<pair<string, int>> tovisit; // the word to visit and which iteration it was added
        int iteration = 0, wordsize = beginWord.size();
        int res = INT_MAX;
        bool canfind = false;
        tovisit.push({beginWord, iteration});
        visited.insert(beginWord);
        while(!tovisit.empty()){
            auto cur = tovisit.front();
            tovisit.pop();
            if(cur.first == endWord){
                canfind = true;
                res = min(res, cur.second+1);
            }
            for(int i = 0; i < wordList.size(); ++i){
                int numdiff = 0;
                for(int j = 0; j < wordsize; ++j){
                    if(wordList[i][j] != cur.first[j]) ++numdiff;
                }
                if(numdiff == 1 and !visited.count(wordList[i])){
                    tovisit.push({wordList[i], cur.second+1});
                    visited.insert(wordList[i]);
                }
                // if(numdiff == 1 and wordlist[i] == endWord){
                //     res = min(res, iteration);
                // }
            }
            iteration += 1;
        }
        if(!canfind) return 0;
        else return res;
    }
};

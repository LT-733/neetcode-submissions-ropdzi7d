class Solution {
public:
    string longestPalindrome(string s) {
        int resultidx = 0, resultLen = 1;
        for(int i = 0; i < s.size(); ++i){
            int j = i-1, k = i+1;
            while((j >= 0 and k < s.size()) and (s[k] == s[j])){
                // l = j, r = k;
            if(k - j + 1 > resultLen){
                resultidx = j, resultLen = k-j+1;
            }
                ++k;
                --j;
            }
            j = i, k = i+1;
            while((j >= 0 and k < s.size()) and (s[j] == s[k])){
            if(k - j + 1 > resultLen){
                resultidx = j, resultLen = k-j+1;
            }
                ++k;
                --j;
            }
        }
        return s.substr(resultidx, resultLen);
    }
};

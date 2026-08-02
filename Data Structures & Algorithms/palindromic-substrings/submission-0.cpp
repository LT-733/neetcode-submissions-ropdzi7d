class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); ++i){
            // odd
            ++res; // hey one character is also a pali
            int j = i-1, k = i+1;
            while((j >= 0 and k < s.size()) and (s[j] == s[k])){
                ++res;
                ++k;
                --j;
            }
            j = i, k = i+1;
            // even
            while((j >= 0 and k < s.size()) and (s[j] == s[k])){
                ++res;
                ++k;
                --j;
            }
        }
        return res;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = left;
        int maxlen = 0, curmax = 0, maxfrequency = 0;
        map<char, int> seen;
        while(right < s.length()){
            seen[s[right]]++;
            maxfrequency = max(maxfrequency, seen[s[right]]);
            while((right - left +1) - maxfrequency > k){
                --seen[s[left]];
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
            ++right;
        }
        return maxlen;
    }
};

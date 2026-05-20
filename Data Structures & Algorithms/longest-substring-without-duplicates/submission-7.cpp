class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> seen;
        int l = 0;
        seen.insert(s[l]);
        int r = 1;
        int maxlen = 1;
        while(r < s.length()){
            while(seen.find(s[r]) != seen.end()){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            // cout<<"s[l]: "<<s[l]<<" s[r]: "<<s[r]<<endl;
            // cout<<"maxlen: "<<maxlen<<" r-l+1: "<<(r-l+1)<<endl;
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // int reverseidx = 31;
        string s = "";
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                s += '1';
            } else {
                s += '0';
            }
        }
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            if (s[31-i] == '1') {
                res |= (1 << i);
            }
        }
        return res;
    }
};

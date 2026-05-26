class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0, r = s1.size()-1;
        map<char, int> s1Chars;
        for(char c : s1){
            s1Chars[c]++;
        }
        for(auto x : s1Chars){
            cout<<x.first<<" ";
        }cout<<endl;
        map<char, int> windowChars;
        for(int i = l; i <= r; ++i){
            windowChars[s2[i]]++;
        }
        while(r < s2.size()){
            if(windowChars != s1Chars){
                // clearly this isn't the correct window
                for(auto x : windowChars){
                    cout<<x.first<<" ";
                }cout<<endl;
                // cout<<windowChars[s2[l]]<<endl;
                windowChars[s2[l]]--;
                if(windowChars[s2[l]] == 0){
                    windowChars.erase(s2[l]);
                }
                ++l;
                ++r;
                windowChars[s2[r]]++;
                for(auto x : windowChars){
                    cout<<x.first<<" ";
                }cout<<endl;
                // slide the window
            } else{
                return true;
            }
        }
        if(windowChars != s1Chars) return false;
        else return true;
    }
};

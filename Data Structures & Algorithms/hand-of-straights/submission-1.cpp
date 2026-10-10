class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false;
        // sort(hand.begin(), hand.end());
        unordered_map<int, int> storage;
        for(int h : hand){
            storage[h]++;
        }
        int streak = 0;
        for(int h : hand){
            // if(storage[h] == 0) continue;
            // --storage[h];
            // if(streak < groupSize-1 and storage[h+1] == 0) return false;
            // --storage[h+1];
            // ++streak;
            // if(streak == groupSize) streak = 0;
            int start = h;
            while(storage[start -1] > 0) --start; // while we still have room to back off we keep backing off
            while(start <= h){
                while(storage[start] > 0){
                    for(int i = start; i < start + groupSize; ++i){
                        if(storage[i] == 0) return false;
                        --storage[i];
                    }
                }
                ++start;
            }
        }
        return true;
    }
};

#include <float.h>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int k = INT_MAX;
        double diff = DBL_MAX; // Tracks our minimum positive difference
        
        while(l <= r){
            int mid = (l + r) / 2;
            double curtime = 0;
            
            for(int i = 0; i < piles.size(); ++i){
                // Koko takes whole hours per pile, so we round up
                double ptime = ceil((double)piles.at(i) / (double)mid);
                curtime += ptime;
            }
            
            // Your logic: We want to minimize (h - curtime)
            double curdiff = (double)h - curtime;
            
            // Condition 1: It's a valid speed (curtime <= h, meaning curdiff >= 0)
            if (curdiff >= 0) {
                
                // If this is a strictly BETTER (smaller) difference than before
                if (curdiff < diff) {
                    diff = curdiff;
                    k = mid; // Update to this better speed
                } 
                // TIE BREAKER: If the difference is the EXACT SAME, 
                // we want the smaller eating speed (mid)
                else if (curdiff == diff) {
                    k = min(k, mid); 
                }
            }
            
            // Binary Search direction logic
            if (curtime > h) {
                l = mid + 1;   // Too slow, we need to eat faster
            } else {
                r = mid - 1;   // Valid speed, but let's look left for smaller speeds
            }
        }
        return k;
    }
};

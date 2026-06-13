#include <float.h>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int k = INT_MAX;
        double diff = DBL_MAX;
        while(l <= r){
            int mid = (l+r)/2;
            double curtime = 0;
            for(int i = 0; i < piles.size(); ++i){
                double ptime = ceil((double)piles.at(i) / (double)mid);
                if(piles.at(i) < mid) ptime = 1;
                curtime += ptime;
            }
            double curdiff = ((double)h - (double)curtime);
            if(curdiff == diff) k = min(k, mid);
            // cout<<curdiff<<endl;
            if(curdiff < diff and curdiff >= 0){
                diff = curdiff;
                // cout<<"changed"<<endl;
                k = mid;
                // cout<<"k: "<<k<<endl;
            }
            if(curtime > h){
                l = mid+1;
            } else if(curtime <= h){
                r = mid-1;
            }
        }
        return k;
    }
};

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int k = INT_MAX, diff = INT_MAX;
        while(l <= r){
            int mid = (l+r)/2;
            int curtime = 0;
            for(int i = 0; i < piles.size(); ++i){
                int ptime = (piles.at(i)%mid == 0) ? piles.at(i)/mid : (piles.at(i)/mid+1);
                curtime += ptime;
            }
            // int curdiff = h - curtime;
            // if(curdiff == 0) return mid;
            // // cout<<curdiff<<endl;
            // if(curdiff < diff and curdiff > 0){
            //     diff = curdiff;
            //     // cout<<"changed"<<endl;
            //     k = mid;
            //     // cout<<"k: "<<k<<endl;
            // }
            if(curtime > h){
                l = mid+1;
            } else if(curtime <= h){
                k = mid;
                r = mid-1;
            }
        }
        return k;
    }
};

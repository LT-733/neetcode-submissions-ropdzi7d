class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target > matrix[matrix.size()-1][matrix[0].size()-1] || target < matrix[0][0]) return false;
        int l = 0, r = matrix[0].size() * matrix.size();
        while(l <= r){
            int mid = l + (r-l)/2;
            int found = matrix[mid/(matrix[0].size())][mid%(matrix[0].size())];
            cout<<found<<endl;
            if(found < target){
                l = mid+1;
            }else if(found > target){
                r = mid - 1;
            }else{
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxVal = 0;
        
        for (int j = 1; j < n - 1; j++) {
            int maxLeft = 0, maxRight = 0;
            
            for (int i = 0; i < j; i++) {
                maxLeft = max(maxLeft, nums[i] - nums[j]);
            }
            
            for (int k = j + 1; k < n; k++) {
                maxRight = max(maxRight, nums[k]);
            }
            
            maxVal = max(maxVal, static_cast<long long>(maxLeft) * maxRight);
        }
        
        return maxVal;
    }
};
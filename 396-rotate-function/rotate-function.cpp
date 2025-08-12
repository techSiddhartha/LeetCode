class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;    // Sum of all elements
        int f = 0;      // F(0)
        
        // Calculate sum and F(0)
        for(int i = 0; i < n; i++){
            sum += nums[i];
            f += i * nums[i];
        }
        
        int maxVal = f;
        
        // Calculate F(1), F(2), ... F(n-1) using formula
        for(int k = 1; k < n; k++){
            f = f + sum - n * nums[n - k];
            maxVal = max(maxVal, f);
        }
        
        return maxVal;
    }
};
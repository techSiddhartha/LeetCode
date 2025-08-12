class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        vector<int> temp(n);
        
        // Place each element at its new position
        for(int i = 0; i < n; i++){
            temp[(i + k) % n] = nums[i];
        }
        
        // Copy back
        nums = temp;
    }
};
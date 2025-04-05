class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }

private:
    int dfs(vector<int>& nums, int index, int currentXOR) {
        if (index == nums.size()) {
            return currentXOR;
        }

        // Include nums[index] in XOR
        int with = dfs(nums, index + 1, currentXOR ^ nums[index]);

        // Exclude nums[index]
        int without = dfs(nums, index + 1, currentXOR);

        return with + without;
    }
};

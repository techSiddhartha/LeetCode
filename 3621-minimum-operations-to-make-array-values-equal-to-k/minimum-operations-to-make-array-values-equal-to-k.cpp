class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int x : nums) {
            if (x < k) return -1;
        }

        unordered_map<int, int> freq;
        for (int x : nums) {
            if (x > k) freq[x]++;
        }

        return freq.size();
    }
};
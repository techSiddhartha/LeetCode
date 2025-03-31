class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1 || n == k) return 0;
        
        vector<int> pair_sums;
        for (int i = 0; i < n - 1; i++) {
            pair_sums.push_back(weights[i] + weights[i + 1]);
        }
        
        sort(pair_sums.begin(), pair_sums.end());
        
        long long minScore = 0, maxScore = 0;
        for (int i = 0; i < k - 1; i++) {
            minScore += pair_sums[i];
            maxScore += pair_sums[n - 2 - i];
        }
        
        return maxScore - minScore;
    }
};

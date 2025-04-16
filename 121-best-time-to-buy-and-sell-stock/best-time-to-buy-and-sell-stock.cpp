class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp1= prices[0];
        int dp2 = 0;
        for(int i =0;i<prices.size();i++){
            dp1=min(dp1,prices[i]);
            dp2=max(dp2,prices[i]-dp1);
        }
        return dp2;
    
    }
};
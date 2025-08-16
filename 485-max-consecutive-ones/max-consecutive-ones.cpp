class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0;
        int j=0;
        int m=0;
        int n = nums.size();

        for(int z=0;z<n;z++){
            if(nums[i]==1 && nums[j]==1){
                j++;
            }else{
                m = max(j-i,m);
                j++;
                i=j;
            }
        }
        m = max(j-i,m);
        return m;
    }
};
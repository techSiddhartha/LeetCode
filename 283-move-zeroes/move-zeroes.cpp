class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int o = 0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[o]=nums[i];
                o++;
            }
        }
        while(o<n){
            nums[o]=0;
            o++;
        }
    }
};
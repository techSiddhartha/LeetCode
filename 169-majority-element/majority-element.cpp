/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        //int m= n/2;
        for(int i=0;i<n;i++){
             int c =0;
            for(int j=0;j<n;j++){
                if(nums[j]==nums[i]){
                    c++;
                }
            }
            if(c > n/2){
                return nums[i];
            }
               
        }
        return -1;
    }        
};*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }
        return candidate;
    }
};

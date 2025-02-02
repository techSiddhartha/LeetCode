class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> ts_nums;

        for(int i=0;i<nums.size();i++)
        {
            ts_nums.push_back({nums[i],i});
        }

        sort(ts_nums.begin(),ts_nums.end());

        int i=0, j=nums.size()-1;
        
        while(i<j)
        {
            int sum= ts_nums[i].first + ts_nums[j].first;

            if(sum<target) i++;

            if(sum>target) j--;

            if(sum == target) return {ts_nums[i].second,ts_nums[j].second};
        }

        return {};
    }
};

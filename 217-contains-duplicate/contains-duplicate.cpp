class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        set<int> uniqueElements;
        for (int num : nums) {
            auto result = uniqueElements.insert(num);
            if (!result.second) {
                return true;
            }
        }
        return false;
    }
};

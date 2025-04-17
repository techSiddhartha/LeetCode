class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort by units per box in descending order
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        int totalUnits = 0;

        for (const auto& box : boxTypes) {
            int count = min(box[0], truckSize); // how many boxes to take
            totalUnits += count * box[1];
            truckSize -= count;

            if (truckSize == 0) break; // stop if the truck is full
        }

        return totalUnits;
    }
};


    
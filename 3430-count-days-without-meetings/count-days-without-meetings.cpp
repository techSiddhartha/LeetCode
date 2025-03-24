class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int covered_days = 0;
        int last_end = 0; // Keep track of the last meeting's end day

        // Step 2: Merge intervals and count covered days
        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            if (start > last_end + 1) {
                // Gap found, increase count of available days
                covered_days += (end - start + 1);
            } else {
                // Merge intervals
                covered_days += max(0, end - last_end);
            }

            last_end = max(last_end, end);
        }

        // Step 3: Compute available days
        return days - covered_days;
    }
};
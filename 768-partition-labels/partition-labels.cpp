class Solution {
public:
    vector<int> partitionLabels(string s) {
      vector<int> lastIndex(26, 0);  // Store last occurrence of each letter
        vector<int> result;

        // Step 1: Fill lastIndex array with last occurrences
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        // Step 2: Create partitions
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastIndex[s[i] - 'a']);  // Expand partition boundary
            
            if (i == end) {  // If current index matches partition boundary
                result.push_back(end - start + 1);  // Add partition size
                start = i + 1;  // Move to next partition
            }
        }

        return result;  
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false; 
        
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = rows * cols - 1; 
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_value = matrix[mid / cols][mid % cols]; 
            
            if (mid_value == target) return true;
            else if (mid_value < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return false; 
    }
};
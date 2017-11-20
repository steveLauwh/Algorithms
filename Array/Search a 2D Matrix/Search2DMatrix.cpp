class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int N = matrix.size(), M = matrix[0].size();
        int mid;
        int left = 0, right = N * M - 1;
        int row, col;
        
        while(left <= right) {
            mid = (left + right) / 2;
            row = mid / M, col = mid % M;
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        
        const size_t m = matrix.size();
        
        const size_t n = matrix.front().size();
        
        int first = 0;
        
        int end = m * n;
        
        while (first < end) {
            int middle = first + (end - first) / 2;
        
            int middleValue = matrix[middle/n][middle%n];
            
            if (middleValue == target) {
                return true;
            } else if (middleValue < target) {
                first = middle + 1;
            } else {
                end = middle;
            }
        }
        
        return false;
    }
};

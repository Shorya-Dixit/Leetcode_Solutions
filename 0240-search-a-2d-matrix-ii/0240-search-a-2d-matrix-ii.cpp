class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int target, int row) {
        int m = matrix[0].size();
        int low = 0, high =m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(binarySearch(matrix,target,i)) return true;
        }
        return false;
    }
};
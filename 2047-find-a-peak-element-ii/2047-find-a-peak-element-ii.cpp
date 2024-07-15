class Solution {
public:
    int findMaxEle(int mid, vector<vector<int>>& mat, int rowSize, int colSize) {
        int maxi = INT_MIN;
        int index=0;
        for (int i = 0; i < rowSize; i++) {
            if(maxi<mat[i][mid])
            {
                maxi=mat[i][mid];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0;
        int e = m - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int row = findMaxEle(mid, mat, n, m);
            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < m ? mat[row][mid + 1] : -1;
            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            } else if (mat[row][mid] < left) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return {-1, -1};
    }
};
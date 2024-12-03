class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l, int r,int isFirstOccur) {
        int idx = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                idx = m;
                if (isFirstOccur)
                    r = m - 1;
                else
                    l = m + 1;
            } else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstindex = binarySearch(nums, target, 0, nums.size() - 1, 1);
        int lastindex = binarySearch(nums, target, 0, nums.size() - 1, 0);
        return {firstindex, lastindex};
    }
};
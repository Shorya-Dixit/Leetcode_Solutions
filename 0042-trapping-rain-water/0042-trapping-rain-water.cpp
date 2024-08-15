class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int res = 0;
        int maxLeft = 0, maxRight = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
            if (height[left] >= maxLeft) {
                maxLeft = height[left];
            } else {
                res += maxLeft - height[left];
            }
            left++;
            } else {
            if (height[right] >= maxRight) {
                maxRight = height[right];
            } else {
                res += maxRight - height[right];
            }
            right--;
            }
        }
        return res;
    }
};
// Intuition: We need a minimum of leftMax and rightMax.So if we take the case when 
// height[l]<=height[r] we increase l++, so we can surely say that there is a block with a height
// more than height[l] to the right of l. And for the same reason when height[r]<=height[l] 
// we can surely say that there is a block to the left of r which is at least of height[r]. 
// TC- O(N), SC- O(1)
// check previous solution too TC- O(3N), SC- O(2N)
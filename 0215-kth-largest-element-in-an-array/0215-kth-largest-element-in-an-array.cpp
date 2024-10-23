class Solution {
public:
    void MaxHeapify(vector<int>& nums,int i, int heapSize){
        int left=2*i+1;
        int right=2*i+2;
        int largest=i;
        if(left<heapSize && nums[largest]<nums[left]) largest=left;
        if(right<heapSize && nums[largest]<nums[right]) largest=right;
        if(largest!=i){
            swap(nums[largest],nums[i]);
            MaxHeapify(nums,largest,heapSize);
        }
    }
    void removeTop(vector<int>& nums){
        nums[0]=nums[nums.size()-1];
        nums.pop_back();
        MaxHeapify(nums,0,nums.size());
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i = (n - 2) / 2; i >= 0; i--) //only this looping is good
        { 
            MaxHeapify(nums,i,n);
        }
        for(int i = 0; i<k-1; i++){
            removeTop(nums);
        }
        return nums[0];
    }
};
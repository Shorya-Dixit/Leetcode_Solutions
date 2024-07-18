class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left=0,right=cardPoints.size()-k-1;
        int windowSum=0;
        int total=0;
        for(int i=0;i<cardPoints.size();i++){
            if(i<cardPoints.size()-k) windowSum+=cardPoints[i];
            total+=cardPoints[i];
        }
        int minWindowSum=windowSum;
        right++;
        while(right<cardPoints.size()){
            windowSum+=cardPoints[right];
            windowSum-=cardPoints[left];
            minWindowSum=min(minWindowSum,windowSum);
            right++;
            left++;
        }
        return (total-minWindowSum);
    }
};
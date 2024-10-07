class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff=x^y;
        int temp=diff;
        int cnt=0;
        while(temp>0){
            temp/=2;
            if(diff&1) cnt++;
            diff=diff>>1;
        }
        return cnt;
    }
};
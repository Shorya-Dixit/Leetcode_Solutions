class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff=start^goal;
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
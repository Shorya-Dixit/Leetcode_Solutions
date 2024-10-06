class Solution {
public:
    int divide(int dividend, int divisor) {   
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;   
        //Converting divisors and dividend to their positive values
        long n = abs(dividend), d = abs(divisor);   
        int quotient=0;
        while(d<=n) {
            long count=0;
            while(n>=(d<<(count+1))) {
                count++;
            }
            quotient+=1<<count;
            n-=d<<count;
        }    
        if((dividend<0&&divisor>0) || (dividend>0&&divisor<0)) return -quotient;    
        return quotient;     
    }
};
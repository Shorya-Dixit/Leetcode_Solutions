class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int ans=1;
        while(n)
        {
            if(n-3>=2)
            {
                ans*=3;
                n-=3;
            }
            else 
            {
                ans*=n;
                n-=n;
            }
        }
        return ans;
    }
};
// check last submitted solution too. used dp in that
// we can infer that if we break numbers into 2 and 3. product will be maximum then.
// as all numbers can be prime factorized and evry prime factor other that 2 and 3 can be 
//split such that the product of splitted numbers is greater than that particular prime factor
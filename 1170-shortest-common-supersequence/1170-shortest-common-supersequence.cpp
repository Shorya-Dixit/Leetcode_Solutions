class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
            if (str1[ind1 - 1] == str2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
        string ans="";
        while(n>0 && m>0){
            if(str1[n-1]==str2[m-1]) {
                ans+= str1[n-1];
                n--;
                m--;
            }
            else {
                if(dp[n][m-1]>=dp[n-1][m]){
                    ans+= str2[m-1];
                    m--;
                }
                else {
                    ans+= str1[n-1];
                    n--;
                }
            }
        }
        while(n>0){
            ans+=str1[n-1];
            n--;
        }
        while(m>0){
            ans+=str2[m-1];
            m--;
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
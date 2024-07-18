class Solution {
public:
    int characterReplacement(string s, int k) {
       
        int l = 0;
        int r = 0;
        int ans = 0;
        vector <int> arr(26,0);
        int maxFreq = 0;
        while(r < s.length()){
            arr[s[r]-'A']++;
            maxFreq = max(maxFreq , arr[s[r]-'A']);       
            if( (r-l+1)-maxFreq > k ){
                arr[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxFreq <= k){
                ans = max(ans , r-l+1);
            }
            r++;
        } 
        return ans;
    }
};
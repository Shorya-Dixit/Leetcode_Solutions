class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int count=0;
        int left=0;
        int right=0;  
        while(right<s.size()){
            mp[s[right]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                count+=s.size()-right;
                mp[s[left]]--;
                left++;
            }
            right++;
        }
        return count;
    }
};

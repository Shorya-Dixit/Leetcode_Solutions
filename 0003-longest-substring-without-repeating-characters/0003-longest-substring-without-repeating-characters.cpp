class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int left=0;int right=0;
        unordered_map<char,int>mp;
        while(left<=right && right<s.size()){
            mp[s[right]]++;
            if(mp[s[right]]>1){
                while(mp[s[right]]>1){
                    mp[s[left]]--;
                    left++;            
                }
            }
            else{
                len=max(len,right-left+1);
            }
            right++;
        }
        return len;
    }
};
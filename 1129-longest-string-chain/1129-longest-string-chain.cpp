class Solution {
public:

    bool check(string& word, string& prev){
        if(word.size() != prev.size() + 1) return false;
        int first = 0;
        int second = 0;  
        while(first < word.size()){
            if(second < prev.size() && word[first] == prev[second]){
                first ++;
                second ++;
            }
            else first ++;
        }
        if(first == word.size() && second == prev.size()) return true;
        else return false; 
    }

    static bool comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n,1);
        int ans=1;
        sort(words.begin(), words.end(), comp);
        for(int i=1;i<words.size();i++){
            for(int prev=0;prev<i;prev++){
                if(check(words[i],words[prev])) dp[i]=max(dp[i],1+dp[prev]);
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    } 
};
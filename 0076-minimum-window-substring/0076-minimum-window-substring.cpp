class Solution {
public:
    string minWindow(string s, string t) {      
        int n = t.size();
        int m = s.size();
        int r=0,l=0,minl=INT_MAX;
        int count = 0;
        int sindex = -1;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[t[i]]++;
        }
        while(r<m){
            mp[s[r]]--;
            if(mp[s[r]]>=0){
                count++;
            } 
            while(count == n){
                if(r-l+1 < minl){
                    minl = r-l+1;
                    sindex = l;
                }
                mp[s[l]]++;  
                if(mp[s[l]]>0){
                    count-- ;
                }
                l++;
            }
            r++;
        }
        return sindex==-1?"":s.substr(sindex,minl);
    }
};
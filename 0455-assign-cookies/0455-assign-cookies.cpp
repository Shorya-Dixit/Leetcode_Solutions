class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size()==0 || s.size()==0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=g.size()-1;
        int j=s.size()-1;
        int count=0;
        while(i>=0 && j>=0){
            if(s[j]>=g[i]){
                i--;
                j--;
                count++;
            }
            else{
                i--;
            }
        }
        return count;
    }
};
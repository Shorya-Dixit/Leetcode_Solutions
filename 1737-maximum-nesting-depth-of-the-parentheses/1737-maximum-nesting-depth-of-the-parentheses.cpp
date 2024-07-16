class Solution {
public:
    int maxDepth(string s) {
        int balance=0;
        int maxDepth=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') balance++;
            if(s[i]==')') balance--;
            maxDepth=max(maxDepth,balance);
        }
        return maxDepth;
    }
};
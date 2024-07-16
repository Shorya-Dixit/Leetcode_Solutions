class Solution {
public:
    bool rotateString(string s, string goal) {   
        int len=s.length();
        s=s+s;
        for(int i=0;i<len;i++)
        {
            string sub=s.substr(i+1,len);
            if(sub==goal)
            {
                return true;
            }
        }
        return false;
    }
};
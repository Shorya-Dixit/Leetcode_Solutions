class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lowr=0,highr=matrix.size()-1;
        int midr=-1;
        while(highr>=0 && lowr<=highr){
            midr=(lowr+highr)/2;
            if(matrix[midr][matrix[0].size()-1]==target) return true;
            else if(matrix[midr][matrix[0].size()-1]<target) lowr=midr+1;
            else highr=midr-1;
        }
        if(target>matrix[midr][matrix[0].size()-1] and (midr+1)<matrix.size()) midr++;
        int lowc=0,highc=matrix[0].size()-1;
        int midc=(lowc+highc)/2;
        while(lowc<=highc){
            int midc=(lowc+highc)/2;
            if(matrix[midr][midc]==target) return true;
            else if(matrix[midr][midc]<target) lowc=midc+1;
            else highc=midc-1;
        }
        return false;
    }
};
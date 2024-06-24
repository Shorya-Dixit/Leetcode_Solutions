class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<=2) return true;
        int dyi=coordinates[1][1]-coordinates[0][1];
        int dxi=coordinates[1][0]-coordinates[0][0];
        for(int i=2;i<coordinates.size();i++)
        {
            int dy=coordinates[i][1]-coordinates[0][1];
            int dx=coordinates[i][0]-coordinates[0][0];
            if(dyi*dx!=dy*dxi) return false;
        }
        return true;
    }
};
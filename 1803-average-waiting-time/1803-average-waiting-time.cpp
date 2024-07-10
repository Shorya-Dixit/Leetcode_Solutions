class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int t=0;
        double waitTotal=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i][0]>=t){
                t+=customers[i][0]-t;
                waitTotal+=customers[i][1];
                t+=customers[i][1];
            }
            else if(customers[i][0]<t){
                waitTotal+=customers[i][1]+t-customers[i][0];
                t+=customers[i][1];
            }
        }
        double avg=waitTotal/customers.size();
        return avg;
    }
};
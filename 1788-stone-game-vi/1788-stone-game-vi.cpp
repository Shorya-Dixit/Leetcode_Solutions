class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({aliceValues[i]+bobValues[i],i});
        }
        int alicePoints=0, bobPoints=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                alicePoints+=aliceValues[pq.top().second];
            }
            else bobPoints+=bobValues[pq.top().second];
            pq.pop();
        }
        if(alicePoints>bobPoints) return 1;
        else if(alicePoints<bobPoints) return -1;
        else return 0;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int minTime=-1;
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto it : times)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> time(n+1, 1e9);
        time[k] = 0;
        pq.push({0,k});
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int t = it.first;
            int node = it.second;         
            for (auto it:adj[node])
            {
                int nt=it.second+t;
                if(time[it.first]>nt){
                    time[it.first]=nt;
                    pq.push({nt,it.first});
                }
            }
        }
        for(int i=1;i<n+1;i++){
            if(time[i]==1e9) return -1;
            minTime=max(minTime,time[i]);
        }
        return minTime;
    }
};
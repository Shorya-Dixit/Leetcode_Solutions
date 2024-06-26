class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>mp;
        for(auto val:arr) mp[val]++;
        priority_queue<int>pq;
        for(auto [val,count]:mp) pq.push(count);
        int x=arr.size()/2;
        int size=0;
        while(x>0){
            x-=pq.top();
            pq.pop();
            size++;
        }
        return size;

    }
};
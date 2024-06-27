class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>nodes(edges.size()+2,0);
        for(int i=0;i<edges.size();i++){
            nodes[edges[i][0]]++;
            nodes[edges[i][1]]++;
            if(nodes[edges[i][0]]>1) return edges[i][0];
            if(nodes[edges[i][1]]>1) return edges[i][1];
        }
        return 0;
    }
};
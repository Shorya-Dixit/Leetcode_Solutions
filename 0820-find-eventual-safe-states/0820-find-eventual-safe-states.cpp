class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>revGraph(V);
        vector<int>indegree(V,0);
		for (int i = 0; i < V; i++) {
			for (auto it : graph[i]) {
                revGraph[it].push_back(i);
				indegree[i]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> safeNodes;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			safeNodes.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : revGraph[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}
        sort(safeNodes.begin(),safeNodes.end());
		return safeNodes;
    }
};
//if a node is a part of a cicle, its not safe
//check last submission too.
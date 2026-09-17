class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<vector<int>> graph(n);

        for(auto p : paths) {
            int u = p[0] - 1;
            int v = p[1] - 1;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> color(n, 0);

        for(int i = 0; i < n; i++) {

            for(int c = 1; c <= 4; c++) {

                bool safe = true;

                for(int neighbor : graph[i]) {
                    if(color[neighbor] == c) {
                        safe = false;
                        break;
                    }
                }

                if(safe) {
                    color[i] = c;
                    break;
                }
            }
        }

        return color;
    }
};
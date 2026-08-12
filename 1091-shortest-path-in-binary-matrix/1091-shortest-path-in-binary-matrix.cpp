class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {

        int n = g.size();

        if(g[0][0] != 0 || g[n-1][n-1] != 0) return -1;
        if(g[0][0] == 0 && n ==1) return 1;

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});

        vector<int> dr = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dc = {-1, 0, 1, 1, 1, 0, -1, -1};

        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;

            int dist = q.front().second;

            q.pop();

            for(int i=0; i<8; i++){

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >=0 && nc < n && g[nr][nc] == 0){
                    
                    if(nr == n-1 && nc == n-1) return dist + 1;
                    q.push({{nr, nc}, dist + 1});
                    g[nr][nc] = 1;

                }
            }
        }

        return -1;

    }
};
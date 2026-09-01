#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_r = -1, start_c = -1;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        int litter_count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_r = i;
                    start_c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = litter_count++;
                }
            }
        }
        
        if (litter_count == 0) return 0;
        int target_mask = (1 << litter_count) - 1;
        
        // best_energy[r][c][mask] stores the maximum energy recorded
        // Dimensions: 20 x 20 x 1024
        vector<vector<vector<int>>> best_energy(
            m, vector<vector<int>>(n, vector<int>(1 << litter_count, -1))
        );
        
        // Queue stores: {r, c, mask, energy, steps}
        queue<tuple<int, int, int, int, int>> q;
        q.push({start_r, start_c, 0, energy, 0});
        best_energy[start_r][start_c][0] = energy;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [r, c, mask, e, steps] = q.front();
            q.pop();
            
            if (mask == target_mask) {
                return steps;
            }
            
            // If energy is 0 and not at 'R', cannot make further moves
            if (e == 0 && classroom[r][c] != 'R') {
                continue;
            }
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int ne = e - 1;
                    if (ne < 0) continue; // Not enough energy to enter
                    
                    if (classroom[nr][nc] == 'R') {
                        ne = energy; // Reset energy to full capacity
                    }
                    
                    int nmask = mask;
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << litter_id[nr][nc]);
                    }
                    
                    if (ne > best_energy[nr][nc][nmask]) {
                        best_energy[nr][nc][nmask] = ne;
                        q.push({nr, nc, nmask, ne, steps + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};
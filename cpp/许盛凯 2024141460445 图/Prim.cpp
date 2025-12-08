#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int prim(vector<vector<int>>& points, int start) {
        const int n = points.size();
        if (n <= 1) {
            return 0;
        }

        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                g[i][j] = g[j][i] = dist;
            }
        }

        vector<int> lowCost(n, INT_MAX);
        vector<char> used(n, 0);

        used[start] = 1;
        for (int i = 0; i < n; ++i) {
            if (i == start) continue;
            lowCost[i] = g[i][start];
        }

        int res = 0;
        for (int cnt = 1; cnt < n; ++cnt) {
            int minIdx = -1;
            int minVal = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && lowCost[j] < minVal) {
                    minVal = lowCost[j];
                    minIdx = j;
                }
            }

            if (minIdx == -1) {
                return -1; // Graph is disconnected.
            }

            used[minIdx] = 1;
            res += minVal;

            for (int j = 0; j < n; ++j) {
                if (!used[j] && g[j][minIdx] < lowCost[j]) {
                    lowCost[j] = g[j][minIdx];
                }
            }
        }
        return res;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        return prim(points, 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution sol;
    cout << sol.minCostConnectPoints(points) << '\n';
    return 0;
}

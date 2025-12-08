#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>

using namespace std;

class DisjointSet {
public:
    explicit DisjointSet(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) {
            return false;
        }
        if (rank[rootA] < rank[rootB]) {
            swap(rootA, rootB);
        }
        parent[rootB] = rootA;
        if (rank[rootA] == rank[rootB]) {
            ++rank[rootA];
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

struct Edge {
    int u;
    int v;
    int w;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        if (n <= 1) {
            return 0;
        }

        vector<Edge> edges;
        edges.reserve(n * (n - 1) / 2);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, cost});
            }
        }

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.w < b.w;
        });

        DisjointSet dsu(n);
        long long totalCost = 0;
        int edgesUsed = 0;

        for (const auto& edge : edges) {
            if (dsu.unite(edge.u, edge.v)) {
                totalCost += edge.w;
                ++edgesUsed;
                if (edgesUsed == n - 1) {
                    break;
                }
            }
        }

        return static_cast<int>(totalCost);
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

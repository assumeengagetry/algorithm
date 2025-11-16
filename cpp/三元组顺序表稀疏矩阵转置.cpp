#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Triple {
    int row;
    int col;
    int val;
    Triple(int r=0, int c=0, int v=0) : row(r), col(c), val(v) {}
};


vector<Triple> transposeSimple(int rows, int cols, const vector<Triple>& triples) {
    vector<Triple> result;
    result.reserve(triples.size());


    for (const auto &t : triples) {
        result.emplace_back(t.col, t.row, t.val);
    }


    sort(result.begin(), result.end(), [](const Triple &a, const Triple &b){
        if (a.row != b.row) return a.row < b.row;
        return a.col < b.col;
    });

    return result;
}


void printTripleList(const vector<Triple>& triples) {
    cout << "row\tcol\tval\n";
    for (const auto& t : triples) {
        cout << t.row << "\t" << t.col << "\t" << t.val << "\n";
    }
}

int main() {

    int rows = 4, cols = 5;
    vector<Triple> triples = {
        {1, 2, 10},
        {1, 4, 12},
        {2, 3, 5},
        {3, 1, 91},
        {4, 2, 28},
        {4, 5, 17}
    };

    cout << "原矩阵三元组：\n";
    printTripleList(triples);


    auto transposed = transposeSimple(rows, cols, triples);

    cout << "\n简单转置后：\n";
    printTripleList(transposed);

    return 0;
}

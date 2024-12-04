#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

template<typename T>
vector<vector<T>> parseGrid() {
    vector<vector<T>> grid;
    string line;
    while (getline(cin, line) && !line.empty()) {
        vector<T> row;
        for (char c : line) row.push_back(c);
        grid.push_back(row);
    }
    return grid;
}

template<typename T>
inline T manhattan(pair<T,T> a, pair<T,T> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}


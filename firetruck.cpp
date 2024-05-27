#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adjList; 
vector<int> path; 
vector<vector<int>> allPaths; 
int destination;

void dfs(int node) {
    path.push_back(node); 

    if (node == destination) { 
        allPaths.push_back(path);
    } else {
        for (int next : adjList[node]) { 
            if (find(path.begin(), path.end(), next) == path.end()) { 
                dfs(next);
            }
        }
    }

    path.pop_back(); 
}

int main() {
    int u, v;
    int testCase = 0;

    while (cin >> u >> v) {
        adjList.assign(21, vector<int>()); 

        
        while (u != 0 && v != 0) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            cin >> u >> v;
        }

        destination = 2; 
        allPaths.clear(); 
        path.clear(); 

        dfs(1); 

       
        sort(allPaths.begin(), allPaths.end());

       
        cout << "CASE " << ++testCase << ":\n";
        for (const auto& p : allPaths) {
            for (size_t i = 0; i < p.size(); ++i) {
                if (i > 0) cout << " ";
                cout << p[i];
            }
            cout << endl;
        }
    }

    return 0;
}

//creating an adjacency list in this code file & implementing DFS & BFS on it
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void dfs(vector<int> adjacency_list[], int vertex, vector<bool>& visited_Vertex){
    visited_Vertex[vertex] = true;
    cout << vertex << " ";

    for(const auto &neigh : adjacency_list[vertex]){
        if(!visited_Vertex[neigh]){
            dfs(adjacency_list, neigh, visited_Vertex);
        }
    }
}

void bfs(vector<int> adjacency_list[], int start, vector<bool>& visited_Vertex){
    queue<int> q;
    q.push(start);
    visited_Vertex[start] = true;

    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for(const auto &neigh : adjacency_list[vertex]){
            if(!visited_Vertex[neigh]){
                q.push(neigh);
                visited_Vertex[neigh] = true;
            }
        }
    }
}

int main(){
    int n, m; 
    cout << "Enter the number of vertices:" << endl;
    cin >> n;
    cout << "Enter the number of edges:" << endl;
    cin >> m;

    vector<int> adjacency_list[n + 1];
    for (int i = 0; i < m; i++) {
        int v, w = 0;
        cout << "Enter edge " << i + 1 << endl;
        cin >> v >> w;

        adjacency_list[v].push_back(w);
        adjacency_list[w].push_back(v);
    }

    cout << "Adjacency list: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Vertex " << i << ":";
        for(const auto &neigh : adjacency_list[i]){
            cout << " " << neigh;
        }
        cout << endl;
    }

    vector<bool> visited_Vertex(n + 1, false);

    cout << "DFS starting from vertex 1: ";
    dfs(adjacency_list, 1, visited_Vertex);
    cout << endl;

    fill(visited_Vertex.begin(), visited_Vertex.end(), false); 

    cout << "BFS starting from vertex 1: ";
    bfs(adjacency_list, 1, visited_Vertex);
    cout << endl;

    return 0;
}

//TIME complexity - O(n + m) for building adjacecny list & same for bfs & dfs traversals as well
//SPACE complexity - O(n + m) overall
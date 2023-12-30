//creating an adjacency mstrix in this code file & implementing DFS & BFS on it
#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>

using namespace std;

void dfs(int adjacency_matrix[][100], int n, int start, bool visited_Vertex[]){
    cout << start << " ";
    visited_Vertex[start] = true;

    for(int i = 0; i < n; ++i){
        if(adjacency_matrix[start][i] == 1 && !visited_Vertex[i]){
            dfs(adjacency_matrix, n, i, visited_Vertex);
        }
    }
}

void bfs(int adjacency_matrix[][100], int n, int start, bool visited_Vertex[]){
    queue<int> q;
    q.push(start);
    visited_Vertex[start] = true;

    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for(int i = 0; i < n; ++i){
            if(adjacency_matrix[vertex][i] == 1 && !visited_Vertex[i]){
                q.push(i);
                visited_Vertex[i] = true;
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

    int adjacency_matrix[100][100] = {0};

    for(int i = 0; i < m; i++){
        int v, w = 0;
        cout << "Enter edge " << i + 1 << endl;
        cin >> v >> w;

        adjacency_matrix[v][w] = 1;
        adjacency_matrix[w][v] = 1;
    }

    cout << "Adjacency matrix: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }

    bool visited_Vertex[100] = {false};

    cout << "DFS : ";
    dfs(adjacency_matrix, n, 0, visited_Vertex);
    cout << endl;

    fill(visited_Vertex, visited_Vertex + n, false);

    cout << "BFS : ";
    bfs(adjacency_matrix, n, 0, visited_Vertex);
    cout << endl;

    return 0;
}

//TIME complexity - O(n x m) ; O(n + m) for bfs & dfs traversals
//SPACE complexity - O(n x m)
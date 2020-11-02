#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
void dfsUtil(int u, int node, bool visited[], 
             vector<pair<int, int> > road_used, int parent, int it) 
{ 
    int c = 0;
    for (int i = 0; i < node; i++) 
        if (visited[i]) 
            c++;
    if (c == node) 
        return;
    visited[u] = true;
    road_used.push_back({ parent, u });
    cout << u << " "; 
    for (int x : adj[u]) {
        if (!visited[x]) 
            dfsUtil(x, node, visited, road_used, u, it + 1); 
    }
    for (auto y : road_used) 
        if (y.second == u) 
            dfsUtil(y.first, node, visited, 
                    road_used, u, it + 1); 
} 
  

void dfs(int node,int start) 
{ 
    bool visited[node]; 
    vector<pair<int, int> > road_used;
    for (int i = 0; i < node; i++){
        if(i==start){
            visited[i]=true;
        }
        else{
            visited[i]=false;
        }
    }
    dfsUtil(0, node, visited, road_used, -1, 0); 
}

void insertEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
}
  

int main() 
{
    int vertices,edge,i,e1,e2,start;
    cout << "Enter the nodes : ";
    cin >> vertices;
    cout << "Enter the number of edges : ";
    cin >> edge;
    for(i=1;i<=edge;i++){
      cout << "Enter starting edge : ";
      cin >> e1;
      cout << "Enter ending edge : ";
      cin >> e2;
      insertEdge(e1,e2);  
    }
    cout << "Enter starting vertex : ";
    cin >> start;
    dfs(vertices,start);
    return 0; 
} 
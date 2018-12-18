//
// Created by zfzhou on 2018/12/15.
//

#include "graphAdjacenylist.h"

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const static int n = 5;
vector<int> adj[MAXN];

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void static DFSUtil(int v, bool visited[]) {
    visited[v] = true;  //设置v已经被访问
    cout  << v << " ";

    //递归访问与v邻接且未被访问的结点u
    for(int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];
        // 如果u未被访问，且v可到达u
        if(visited[u] == false) {
            DFSUtil(u, visited);    //访问u
        }
    }
}

void static DFS(int v) {
    bool visited[n] = {false};

    DFSUtil(v, visited);
}


void static BFS(int v)
{
    bool visited[n] = {false};
    queue<int> q;
    q.push(v);      //初始点v入队
    visited[v] = true;  //设置v已经入过队列

    while(!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();

        // 遍历u的所有邻接点v，如果一个邻接点未被访问，
        // 将其入队，并标记被访问
        for(int i = 0; i < adj[u].size(); i++) { //注意规范
            int v = adj[u][i];
            if(visited[v] == false) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}


int main()
{
//    int V = 5;
//    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    cout << adj[0][0] << endl;
    DFS(0);
    printf("\n");
    BFS(0);
    return 0;
}


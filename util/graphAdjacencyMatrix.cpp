//
// Created by zfzhou on 2018/12/15.
//

#include <bits/stdc++.h>
using namespace std;

#include "graphAdjacencyMatrix.h"

const int MAXV = 1000; //max vertices

const static int n = 5;   //顶点数
int G[MAXV][MAXV] = {{0, 1 ,0, 0, 1},
                     {1, 0, 1, 1, 1},
                     {0, 1, 0, 1, 0},
                     {0, 1, 1, 0, 1},
                     {1, 1, 0, 1, 0}};
//bool visited[MAXV] = {false};

void DFSUtil(int v, bool visited[]) {
    visited[v] = true;  //设置v已经被访问
    cout  << v << " ";

    //访问与v邻接且未被访问的结点u
    for(int u = 0; u < n; u++) {    //对每个顶点u
        // 如果u未被访问，且v可到达u
        if(visited[u] == false && G[v][u] != 0) {
            DFSUtil(u, visited);    //访问u
        }
    }
}

void DFS(int v) {
    bool visited[n] = {false};

    DFSUtil(v, visited);
}


void BFSUtil(int v, bool visited[]) {
    queue<int> q;
    q.push(v);
    visited[v] = true;  //设置v已经被访问过

    while(!q.empty()) {
        int temp = q.front();
        cout << temp << " ";
        q.pop();

        for(int i = 0; i < n; i++) {
            if(visited[i] == false && G[temp][i] != 0) {
                q.push(i);
                visited[i] = true;  //设置i已经被访问过
            }
        }
    }
}

void BFS(int v) {
    bool visited[n] = {false};

    BFSUtil(v, visited);
}

/*
int main()
{
    DFS(4);
    printf("\n");
    BFS(4);
    return 0;
}
*/

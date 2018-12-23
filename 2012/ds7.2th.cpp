//
// Created by zfzhou on 12/19/2018.
//
#include <bits/stdc++.h>
using namespace std;

/*
 * 已知一个无向图的邻接表（此图有五个顶点），写一函数判断此
 * 无向图是否连通图。
 *
 * 由于是无向图，我们能从任一顶点DFS和BFS并检查所有顶点是否能到达。
 * 如果所有顶点都能到达，图是连通的，否则不连通。
 */

const int MAXV = 1000; //max vertices

const static int n = 5;   //顶点数
int G[MAXV][MAXV] = {{0, 1 ,0, 0, 1},
                     {1, 0, 1, 1, 1},
                     {0, 1, 0, 1, 0},
                     {0, 1, 1, 0, 1},
                     {1, 1, 0, 1, 0}};

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

void DFSUtil1(int v, bool visited[]) {
    visited[v] = true;  //设置v已经被访问
    //cout  << v << " ";

    //访问与v邻接且未被访问的结点u
    for(int u = 0; u < n; u++) {    //对每个顶点u
        // 如果u未被访问，且v可到达u
        if(visited[u] == false && G[v][u] != 0) {
            DFSUtil1(u, visited);    //访问u
        }
    }
}

//检查图是否连通
bool check(int v) {
    bool visited[n] = {false};

    DFSUtil1(v, visited);

    for(int i = 0; i < n; i++) {    //DFS完检查是否每个结点都遍历到
        if(!visited[i])
            return false;
    }
    return true;
}

/*
int main()
{
    DFS(0);
    printf("\n");

    if(check(1)) {
        printf("The graph is connected!\n");
    } else {
        printf("The graph is unconnected!\n");
    }
}
*/



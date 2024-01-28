#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000

int n; //定义节点个数
int A[MAXN][MAXN], P[MAXN][MAXN]; //定义邻接矩阵A和可达矩阵P
int vis[MAXN]; //定义访问数组vis

void find_reachable_matrix() { //求可达矩阵的子程序
    for (int k = 0; k < n; ++k) { //使用Floyd-Warshall算法，遍历所有中间节点k
        for (int i = 0; i < n; ++i) { //遍历所有起始节点i
            for (int j = 0; j < n; ++j) { //遍历所有终止节点j
                if (P[i][k] && P[k][j]) { //如果i到k和k到j都有路径
                P[i][j] = 1; //则i到j也有路径，更新可达矩阵
                }
            }
        }
    }
}

int check_strongly_connected() { //检查是否为强连通的子程序
    for (int i = 0; i < n; ++i) { //遍历所有节点
        for (int j = 0; j < n; ++j) { //遍历所有节点
            if (!P[i][j]) { //如果存在两个节点之间没有路径
                return 0; //则不是强连通的，返回0
            }
        }
    }
    return 1; //否则是强连通的，返回1
}

int check_unilaterally_connected() { //检查是否为单向连通的子程序
    for (int i = 0; i < n; ++i) { //遍历所有节点
        int out_degree = 0, in_degree = 0; //定义出度和入度为0
        for (int j = 0; j < n; ++j) { //遍历所有节点
            if (A[i][j]) { //如果i到j有边
                out_degree++; //则i的出度加一
            }
        if (A[j][i]) { //如果j到i有边
            in_degree++; //则i的入度加一
        }
    }
    if (out_degree != 1 || in_degree != 1) { //如果存在某个节点的出度或入度不为1
        return 0; //则不是单向连通的，返回0
    }
 }
    return 1; //否则是单向连通的，返回1
}

void transform_matrix() { //改造邻接矩阵的子程序，使其变为无向图的邻接矩阵
    for (int i = 0; i < n; ++i) { //遍历所有节点
        for (int j = i + 1; j < n; ++j) { //遍历所有节点（只需考虑上三角部分）
            if (P[i][j] || P[j][i]) { //如果i和j之间有路径（无论方向）
                A[i][j] = A[j][i] = 1; //则将邻接矩阵中对应位置置为1，表示无向边存在
            }
        }
    }
}

void dfs(int u) { //深度优先搜索，用于判断无向图是否连通
    vis[u] = 1; //标记u已访问
    for (int v = 0; v < n; ++v) { //遍历u的所有邻居
        if (A[u][v] && !vis[v]) { //如果u到v有边且v未访问过
            dfs(v); //递归访问v
        }
    }
}

int check_weakly_connected() { //检查是否为弱连通的子程序，即改造后的无向图是否连通
    memset(vis, 0, sizeof(vis)); //初始化访问数组为全0
    int cnt = 0; //定义连通分量个数为0
    for (int i = 0; i < n; ++i) { //遍历所有节点
        if (!vis[i]) { //如果i未访问过
            dfs(i); //深度优先搜索i，找出一个连通分量
            cnt++; //连通分量个数加一
        }
    }
    if (cnt == 1) { //如果连通分量个数为1，说明无向图是连通的，即原图是弱连通的
        return 1;
    } else {
        return 0;
    }
}

int main() {
    
    scanf("%d", &n); //输入节点个数n
    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < n; ++j) {
            scanf("%d", &A[i][j]); 
            P[i][j] = A[i][j]; 
        }
    }
    find_reachable_matrix(); 
    if (check_strongly_connected()) {
        printf("Strongly connected\n");
    } else if (check_unilaterally_connected()) {
        printf("Unilaterally connected\n");
    } else {
    transform_matrix();
        if (check_weakly_connected()) {
            printf("Weakly connected\n");
        } else {
            printf("Not connected\n");
        }
    }
    return 0;
}

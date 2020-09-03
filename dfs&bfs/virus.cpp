#include<queue>
#include<vector>
#include<iostream>

using namespace std;

int cnt;
int visit[110];
int c_num, c_edges;
vector<vector<int>> edge(110);

void v_dfs(int n_idx)
{
    cnt += 1;
    visit[n_idx] = 1;
    for(auto&iter: edge[n_idx])
    {
        if(!visit[iter])
        {
            v_dfs(iter);
        }
    }
}

void v_bfs()
{
    int idx=0;
    queue<int> q;
    q.push(idx);
    visit[idx] = 1;
    while(!q.empty())
    {
        idx = q.front();
        q.pop();

        cnt += 1;
        for(auto&iter: edge[idx])
        {
            if(!visit[iter])
            {
                visit[iter] = 1;
                q.push(iter);
            }
        }
    }
}

int main()
{
    scanf("%d", &c_num);
    scanf("%d", &c_edges);

    int s, e;
    while(c_edges--)
    {
        scanf("%d %d", &s, &e);
        edge[s-1].push_back(e-1);
        edge[e-1].push_back(s-1);
    }
    // DFS
    v_dfs(0);

    // BFS
    // v_bfs();
    
    printf("%d", cnt-1);
    return 0;
}

#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int visit[2000];
int N, M, start;
vector<vector<int>> edge;
void dfs(int node)
{
    visit[node] = 1;
    printf("%d ", node+1);
    for(auto&iter: edge[node])
    {
        if(!visit[iter])
        {
            dfs(iter);
        }
    }
}

void bfs(int idx)
{
    queue<int> q;
    q.push(idx);

    for(int i=0; i<N; i++)
        visit[i] = 0;
    visit[idx] = 1;

    while(!q.empty())
    {
        idx = q.front();
        q.pop();
        printf("%d ", idx+1);
        for(auto&next:edge[idx])
        {
            if(!visit[next])
            {
                visit[next] = 1;
                q.push(next);
            }
        }
    }
} 

int main()
{
    scanf("%d %d %d", &N, &M, &start);
    edge = vector<vector<int>>(N);
    while(M--){
        int u, v;
        scanf("%d %d",&u,&v);
        edge[u-1].push_back(v-1);
        edge[v-1].push_back(u-1);
    }

    for(auto&iter: edge)
    {
        sort(iter.begin(), iter.end());
    }

    dfs(start-1);
    printf("\n");
    bfs(start-1);
    
    return 0;
}

#include<vector>
#include<utility>
#include<iostream>
#include<algorithm>

using namespace std;

int N;
int map[30][30];
vector<int> cnt;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int numbering(int r, int c)
{
    int total=0;
    map[r][c] = 0;
    for(int i=0; i<4; i++)
    {
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(nr >=0 && nc >=0 && nr<N && nc<N)
        {
            if(map[nr][nc])
            {
                total += numbering(nr, nc);
            }
        }
    }
    return 1+total;
}

int main()
{
    scanf("%d", &N);
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<N; c++)
        {
            scanf("%1d", &map[r][c]);
        }
    }
    
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<N; c++)
        {
            if(map[r][c])
            {
                cnt.push_back(numbering(r, c));
            }
        }
    }

    sort(cnt.begin(), cnt.end());
    printf("%d\n", cnt.size());
    for(auto&c: cnt)
        printf("%d\n", c);

    return 0;
}

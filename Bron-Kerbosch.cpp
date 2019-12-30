//https://blog.csdn.net/yo_bc/article/details/77453478

#include <iostream>
#include <memory.h>
using namespace std;

#define LOCAL

const int MAXN = 750 + 10;
const int MAXM = 250000 + 10;

bool mp[MAXN][MAXN];
int best, num[MAXN];
int N, M;

bool dfs(int *adj, int total, int cnt)
{
    int t[MAXN], k;
    if (total == 0)
    {
        if (cnt > best)
        {
            best = cnt;
            return true; //剪枝4
        }
        return false;
    }
    for (int i = 0; i < total; ++i)
    {
        if (cnt + total - i <= best)
            return false; //剪枝1
        if (cnt + num[adj[i]] <= best)
            return false; //剪枝3
        k = 0;
        for (int j = i + 1; j < total; ++j)
            if (mp[adj[i]][adj[j]])
                t[k++] = adj[j];
        //扫描与u相连的顶点中与当前要选中的adj[i]相连的顶点adj[j]并存储到数组t[]中，数量为k
        if (dfs(t, k, cnt + 1))
            return true;
    }
    return false;
}
int MaximumClique()
{
    int adj[MAXN], k;
    best = 0;
    for (int i = N; i >= 1; --i)
    {
        k = 0;
        for (int j = i + 1; j <= N; ++j)
            if (mp[i][j])
                adj[k++] = j;
        //得到当前点i的所有相邻点存入adj
        dfs(adj, k, 1); //每次dfs相当于必选当前i点看是否能更新best
        num[i] = best;
    }
    // 扫描与u相连的顶点中与当前要选中的adj[i]相连的顶点adj[j]并存储到数组t[]中，数量为k
    return best;
}

int main()
{

#ifdef LOCAL
    freopen("./samples/frb30.txt", "r", stdin);
    freopen("./result.txt", "w", stdout);
#endif

    while (scanf("%d%d", &N, &M)!=EOF)
    {
        memset(mp, 0, sizeof(mp));
        for (int i = 1; i <= N; i++)
        {
            mp[i][i] = true;
        }
        int a, b;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &a, &b);
            mp[a][b] = true;
            mp[b][a] = true;
        }

        printf("TEST CASE N=%d\tM=%d\n", N,M);
        cout << MaximumClique() << endl;
        printf("-----TEST CASE END-----\n");
    }
}
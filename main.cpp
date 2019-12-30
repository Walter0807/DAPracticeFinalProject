#include <iostream>
#include <memory.h>

using namespace std;

#define LOCAL

const int MAXN = 750 + 10;
const int MAXM = 250000 + 10;

int N, M;

bool mp[MAXN][MAXN];

int MaximumClique()
{
    return 0;
}

int main()
{

#ifdef LOCAL
    freopen("./samples/frb30.txt", "r", stdin);
#endif

    while (scanf("%d%d", &N, &M))
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
        int result = MaximumClique();
        cout << result << endl;
        
        //printf all numbers
    }
}
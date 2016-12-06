#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

// i人目まで決定、合計j分
int dp[201][20001]={};

int main()
{
    int CASE;
    cin >>CASE;
    while(CASE--)
    {
        int SUM = 0;

        int N;
        cin >>N;
        vector<int> M(N);
        for(int i=0; i<N; i++)
        {
            cin >>M[i];
            SUM += M[i];
        }

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i=0; i<N; i++)for(int j=0; j<=20000; j++)if(dp[i][j])
        {
            dp[i+1][j+M[i]] = 1;
            dp[i+1][j] = 1;
        }

        int ans = 20000;
        for(int i=0; i<=20000; i++)
        {
            if(dp[N][i])
            {
                int diff = abs(i - (SUM - i));
                ans = min(ans, diff);
            }
        }

        cout << ans << endl;
    }
    return 0;
}

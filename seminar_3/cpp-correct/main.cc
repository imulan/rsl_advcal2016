#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int solve(int A, int border)
{
    if(A>=border) return 0;
    if(border==100000) return -1;
    return border+1;
}

int main() {
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

        // 0~A-1 と A~N-1 の2グループに分ける
        int A = N / 2;
        int B = N - A;

        vector<int> sum;
        for(int mask=0; mask<(1<<A); mask++)
        {
            int group_sum = 0;
            for(int i=0; i<A; i++)if(mask>>i&1) group_sum += M[i];
            sum.push_back(group_sum);
        }

        // ソートして重複除去
        sort(sum.begin(), sum.end());
        sum.erase(unique(sum.begin(), sum.end()), sum.end());

        int ans = 1000000000;
        for(int mask=0; mask<(1<<B); mask++)
        {
            int group_sum = 0;
            for(int i=0; i<B; i++)if(mask>>i&1) group_sum += M[A+i];

            int index = lower_bound(sum.begin(), sum.end(), SUM/2 - group_sum) - sum.begin();

            // 境界の前後をチェック
            for(int i=-1; i<=1; i++)
            {
                int s_idx = index+i;
                if(0 <= s_idx && s_idx < sum.size())
                {
                    int total = group_sum + sum[s_idx];
                    int diff = abs(total - (SUM-total));
                    ans = min(ans, diff);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}

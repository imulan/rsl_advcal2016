#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int A, int border)
{
    if(A>=border) return 0;
    if(border==100000) return -1;
    return border+1;
}

int main()
{
    int CASE;
    cin >>CASE;
    while(CASE--)
    {
        int N,M,A;
        cin >>N >>M >>A;

        bool myscore=false;
        vector<int> S;
        for(int i=0; i<M; i++)
        {
            int t;
            cin >>t;

            if(!myscore && t==A) myscore=true;
            else S.push_back(t);
        }

        sort(S.begin(),S.end(),greater<int>());
        int border=S[N-1];

        cout << solve(A,border) << endl;
    }
    return 0;
}

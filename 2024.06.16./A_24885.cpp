#include <bits/stdc++.h>

using namespace std;

int p[11];

int main()
{
    int n, k, i;
    long long m, loan=0, x, ans, before_m;

    cin >> n >> m >> k;
    for(i=0; i<n; i++) cin >> p[i];

    ans = m;
    for(i=0; i<n; i++){
        if(p[i] <= m * (k+1)){     // 구매 가능한 경우
            before_m = m;
            
            // 대출
            loan = m * k;
            m += loan;
            
            // x개 매입
            x = m / p[i];
            m += x * (p[i+1] - p[i]);
            ans = max(ans, m);
            
            // 대출금 상환
            m -= loan;
            
            // 이득인 경우만 남김
            m = max(m, before_m);
        }
    }
    
    cout << ans;

    return 0;
}

#include <stdio.h>
#include <algorithm>

#define MAXN 500

using namespace std;

int S[MAXN+1], dp[MAXN+1][MAXN+1];

int main()
{
	int T, n, i, j, k, mini;
	
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(i=1;i<=n;i++){
			scanf("%d", &S[i]);
			S[i] += S[i-1];
		}
		
		for(j=2;j<=n;j++){
			for(i=j-1;i>=1;i--){
				mini = 0x7fffffff;
				for(k=i;k<j;k++){
					mini = min(mini, dp[i][k] + dp[k+1][j]);
				}
				dp[i][j] = mini + S[j]-S[i-1];
			}
		}
		
		printf("%d\n", dp[1][n]);
	}
	
	return 0;
}

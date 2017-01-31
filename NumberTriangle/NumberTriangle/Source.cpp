#include <stdio.h>
#include <stdlib.h>
#include <algorithm>


int sum(int n) {
	int res=0;
	for (int i = 1; i <= n; i++) {
		res += i;
	}
	return res;
}
int main() {
	int height;
	scanf("%d", &height);
	int dp[501][501];
	int input;
	scanf("%d", &input);
	dp[1][0] = input;
	for (int i = 2; i <= height; i++) {
		for (int j = 0; j < i; j++) {
			//시작노드
			scanf("%d", &input);
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + input;
			}
			//끝노드
			else if (j == i - 1) {
				dp[i][j] = dp[i - 1][j-1] + input;
			}
			//중간노드
			else {
				dp[i][j] = std::max(dp[i - 1][j - 1], dp[i - 1][j]) + input;
			}

		}		
	}
	int res = 0;
	for (int i = 0; i < height; i++) {
		if (dp[height][i] > res) {
			res = dp[height][i];
		}
	}
	printf("%d", res);
}
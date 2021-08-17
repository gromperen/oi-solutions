#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int INF = 0x3f3f3f3f;
//const int INF = 998244353;

int n, m, A, B, C;
int dp[100020][1020];

int calc(int t) {
	return A*t*t + B*t + C;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> A >> B >> C;
	vector<tuple<int,int,int,int>> trains(m);
	int maxtime = 0;
	for (int i = 0; i < m; ++i) {
		int x, y, p, q; cin >> x >> y >> p >> q;
		trains[i] = {p,q,x,y};
		maxtime = max(maxtime, q);
	}
	sort(trains.begin(), trains.end());

	memset(dp, INF, sizeof(dp));
	cout << dp[1][0]<<endl;
	dp[1][0] = 0;
	for (int i = 0; i < m; ++i) {
		int x,y,p,q;
		tie(p,q,x,y) = trains[i];
		for (int j = 0; j <= p; ++j) {
			if (dp[x][j] == INF) continue;
			dp[y][q] = min(dp[y][q], dp[x][j] + calc(p - j));
		}
	}

	int ans = INF;
	for (int i = 0; i <= maxtime+1; ++i) {
		ans = min(ans, dp[n][i]+i);
	}
	cout << ans << "\n";

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	int s = -1, c = 0; 
	for (int i = 0; i < 2*n; ++i) {
		if (s == -1) s = i%n;
		c += a[i%n] - 10;
		if (c < 0) c = 0, s = -1;
	}
	cout << s + 1 << "\n";

	return 0;
}


#include <bits/stdc++.h>
#define ll long long
#define md 1000000007
using namespace std;

int N;
ll comb[105][105];

void print() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			cout << comb[i][j] << "\t";
		}
		cout << endl;
	}
}

ll C(int n, int k) {
	if (n < k) return 0;

	if (comb[n][k] == 0) {
		if (n == k or k == 0) comb[n][k] = 1;
		else
			comb[n][k] = (C(n - 1, k - 1) + C(n - 1, k)) % md;
	}

	comb[n][n - k] = comb[n][k];
	return comb[n][k];
}

int main() {
	int Q;
	cin >> Q;

	while (Q--) {
		int a, b; cin >> a >> b;
		cout << C(a, b) << endl;
	}
}
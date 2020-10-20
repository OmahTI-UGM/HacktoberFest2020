#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>

#define ll long long
#define md 1000000007

#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define REPP(i, a, b) for(int i = (a); i < (b); i++)
#define RREP(i, a, b) for(int i = (a); i >= (b); i--)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.end(), a.begin()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(RALL(v))

#define ii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define vii vector<ii>
#define append push_back
#define si set<int>
#define mii map<int, int>
#define msi map<string, int>
#define pi priority_queue<int>

#define vl vector<ll>
#define mat vector<vl>

using namespace std;

mat F;
int N;

void print(mat A) {
	// print matrix
	REPP(i, 0, A.size()) {
		REPP(j, 0, A[0].size()) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

mat build(int N, int M) {
	// bikin matriks kosong A ukuran N x M
	mat A(N);
	REPP(i, 0, N) {
		A[i].clear();
		A[i].resize(M);
	}

	return A;
}

mat mm_mul(mat A, mat B) {
	/*
		Buat menghitung matriks A x matriks B
		size A = N x M
		size B = M x P
		hasilnya matriks ukuran N x P
	*/

	int N = A.size();
	int M = A[0].size();
	int P = B[0].size();
	mat C = build(N, P);

	REPP(i, 0, N) {
		REPP(j, 0, P) {
			REPP(k, 0, M) {
				ll t = (A[i][k] * B[k][j]) % md;
				C[i][j] = (C[i][j] + t) % md;
			}
		}
	}

	return C;
}

ll vv_mul(vl u, vl v) {
	/*
		Buat menghitung vektor u x vektor v
		sizenya harus sama, hasilnya ll
	*/
	ll ret = 0;
	REPP(i, 0, u.size()) {
		ret = (ret + (u[i] * v[i]) % md) % md;
	}
	return ret;
}

vl mv_mul(mat A, vl v) {
	/*
		Buat menghitung matrix A x vektor v
		size A = N x M
		size v = M x 1
		hasilnya vektor ukuran N x 1
	*/

	int N = A.size();
	int M = v.size();
	vl ret(N);

	REPP(i, 0, N) {
		ret[i] = vv_mul(A[i], v);
	}

	return ret;
}

mat pangkat(mat A, int N) {
	// buat menghitung matriks A^N
	if (N == 0) {
		// return identity matrix;
		int k = A.size();
		mat I = build(k, k);
		REPP(i, 0, k) {
			REPP(j, 0, k) {
				I[i][j] = (i == j);
			}
		}
		return I;
	}
	if (N == 1) return A;
	mat c = pangkat(A, N / 2);
	c = mm_mul(c, c);

	if (N % 2 == 0) return c;
	else return mm_mul(A, c);
}

int main() {
	cin >> N;
	mat A = build(N, N);
	
	REPP(i, 0, N) {
		REPP(j, 0, N) {
			cin >> A[i][j];
		}
	}

	vl v(N);
	REPP(i, 0, N) {
		cin >> v[i];
	}

	int Q; cin >> Q;
	while (Q--) {
		int n; cin >> n;
		mat An = pangkat(A, n - 1);
		vl ret = mv_mul(An, v);
		cout << ret[0] << "\n";
	}

	return 0;
}

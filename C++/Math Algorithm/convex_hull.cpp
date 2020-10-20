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
#define ld long double
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

void fast() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

struct point { ld x, y; };
point pivot = {0, 0};
ld EPS = 1e-9;

ld dist(point A, point B) {
	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

struct vec {
	double x, y; 
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
	// convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}

bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool angleCmp(point a, point b) {
	if (collinear(pivot, a, b)) // special case
		return dist(pivot, a) < dist(pivot, b);
		// check which one is closer
	
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> P) {
	// the content of P may be reshuffled
	int i, j, n = (int)P.size();

	if (n <= 3) {
		if (!(P[0].x == P[n-1].x and P[0].y == P[n-1].y))
			P.push_back(P[0]);
		
		return P;
	}

	// first, find P0 = point with lowest Y
	// and if tie: rightmost X
	int P0 = 0;
	for (i = 1; i < n; i++)
		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
			P0 = i;
		
	point temp = P[0];
	P[0] = P[P0];
	P[P0] = temp;

	// second, sort points by angle w.r.t. pivot P0
	pivot = P[0];
	// use this global variable as reference
	
	sort(++P.begin(), P.end(), angleCmp);
	// we do not sort P[0]

	// third, the ccw tests
	vector<point> S;
	
	S.push_back(P[n-1]);
	S.push_back(P[0]);
	S.push_back(P[1]);

	i = 2; // then, we check the rest
	while (i < n) {
		// note: N must be >= 3 for this method to work
		j = (int)S.size()-1;
		if (ccw(S[j-1], S[j], P[i]))
			S.push_back(P[i++]);
		// left turn, accept
		else S.pop_back();
		// or pop the top of S until we have a left turn
	}
	
	return S;
}


int main() {
	int N;
	cin >> N;
	vector<point> P;
	REP(i, 1, N) {
		point A; cin >> A.x >> A.y;
		P.append(A);
	}

	vector<point> S = CH(P);
	REPP(i, 0, S.size()) {
		cout << S[i].x << " " << S[i].y << endl;
	}

	return 0;
}

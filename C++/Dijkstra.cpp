#include <bits/stdc++.h>
#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>
#define vv vector<vi>
#define mp make_pair
#define inf 10000000
#define loop(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int V, E; 				// declare the number of vertices and edges
int AM[3010][3010];		// adjacency matrix
bool pernah[3010]; 		// buat nandain vertex udah pernah dikunjungi atau belum
int dist[3010]; 		// array buat nyimpan jarak dari vertex source (awal) ke tiap vertex lain
queue<int> temp; 		// queue buat dijkstranya

// daftar fungsi-fungsinya, kodingannya liat di paling bawah
void sort_AL(vi &AL);
void add_to_AL(vv &AL, int a, int b);
void reset();
void reset_AM(int V);
void BFS(int v, vv &AL, vi &ans);

/*

Contoh input (make graf dari soal UTS Jarkom ilkomp A):

1		<-- banyak grafnya cuma 1
6 10	<-- banyak vertex 6, edge 10
1 2 2	<-- vertex 1 ke vertex 2 jaraknya 2,
1 3 5	<-- vertex 1 ke vertex 3 jaraknya 5, dst
1 4 1
2 3 3
2 4 2
3 6 3
3 4 2
3 5 1
4 5 1
5 6 2
1		<-- vertex sourcenya



output : 0 2 3 1 2 4

explanation :
jarak minimum dari vertex 1 ke vertex 1, 2, 3, 4, 5, dan 6
berturut-turut adalah 0, 2, 3, 1, 2, 4

*/

int main() {
	int T;
	cin >> T;
	// input banyak graf
	
	while(T--) {
		cin >> V >> E; // input banyak vertex sama edge
		vector<vi> AL(V+1);	// adj list
		reset();
		reset_AM(V+1);
			
		loop(i, 0, E) {
			// input edge-list, formatnya : vertex1, vertex2, bobot
			int a, b, w;
			cin >> a >> b >> w;
			add_to_AL(AL, a, b);
			AM[a][b] = w;
			AM[b][a] = w;
		}
		
		// c adalah vertex awal
		int c;
		cin >> c;
		dist[c] = 0;
		vector<int> ans;
		
		// Mulai menghitung Dijkstra dari sini
		BFS(c, AL, ans);
		
		
		// print jarak minimum tiap vertex jika dijangkau dari c, outputnya 'inf' kalo ga bisa dijangkau
		loop(i, 1, V+1) {
			if(i == c) cout << "0";
			else if(dist[i] == inf) cout << "inf";
			else cout << dist[i];
			
			if(i < V) cout << " ";
			else cout << endl;
		}
	}
}

/*

	Kodingan fungsi-fungsinya

*/

void sort_AL(vi &AL) {
	int pos = AL.size()-1;
	
	int temp = AL[pos];
	while(pos >= 1 and AL[pos-1] > temp) {
		AL[pos] = AL[pos-1];
		pos--;
	}
	
	AL[pos] = temp;
}

void add_to_AL(vv &AL, int a, int b) {
	AL[a].push_back(b);
	sort_AL(AL[a]);
	AL[b].push_back(a);
	sort_AL(AL[b]);
}

void reset() {
	loop(i, 0, 3010) {
		pernah[i] = false;
		dist[i] = inf;
	}
}

void reset_AM(int V) {
	loop(i, 0, V) {
		loop(j, 0, V) {
			AM[i][j] = inf;
		}
	}
}

void BFS(int v, vv &AL, vi &ans) {
	temp.push(v);
	ans.push_back(v);
	pernah[v] = true;
	
	while(!temp.empty()) {
		int f = temp.front();
			
		loop(i, 0, AL[f].size()) {
			int alfi = AL[f][i];
			
			if(!pernah[alfi]) {
				temp.push(alfi);
				ans.push_back(alfi);
				pernah[alfi] = true;
			}
			
			dist[alfi] = min(dist[alfi], dist[f]+AM[f][alfi]);		
		}
			
		temp.pop();
	}	
}

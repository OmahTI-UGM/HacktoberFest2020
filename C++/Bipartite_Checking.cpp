#include <bits/stdc++.h>
#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>
#define vv vector<vi>
#define mp make_pair
#define loop(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int AM[110][110];
int label[110];
vv AL(110);
vector<ii> EL;
bool bipartite = true;

void add_to_AM(int a, int b);
void sort_AL(int V);
void add_to_AL(int a, int b);
void sort_EL();
void add_to_EL(int a, int b);

void check(int v) {
	
	loop(i, 0, AL[v].size()) {
		if(label[AL[v][i]] == -1) {
			label[AL[v][i]] = 1-label[v];
			check(AL[v][i]);
		}
		else if(label[AL[v][i]] == label[v])
			bipartite = false;
	}
}

/*
	This is main
*/

int main(){
	int V, E;
	cin >> V >> E;
	loop(i, 0, V) label[i] = -1;
	
	loop(i, 0, E) {
		int a, b;
		cin >> a >> b;
		
		add_to_AM(a, b);
		add_to_AL(a, b);
		add_to_EL(a, b);
	}
	
	label[0] = 1;
	loop(i, 0, V) {
		if(label[i] != -1) {
			label[i] = 1;
			check(i);
		}
	}
	
	if(bipartite) cout << "YA" << endl;
	else cout << "TIDAK" << endl;
}

/*
	End of main
*/

void add_to_AM(int a, int b) {
	AM[a][b] = 1;
	AM[b][a] = 1;
}

void sort_AL(int V) {
	int pos = AL[V].size()-1;
	
	int temp = AL[V][pos];
	while(pos >= 1 and AL[V][pos-1] > temp) {
		AL[V][pos] = AL[V][pos-1];
		pos--;
	}
	AL[V][pos] = temp;
}

void add_to_AL(int a, int b) {
	AL[a].push_back(b);
	sort_AL(a);
	AL[b].push_back(a);
	sort_AL(b);
}

void sort_EL() {
	int pos = EL.size()-1;
	
	ii temp = EL[pos];
	while(pos >= 1 and EL[pos-1].first > temp.first) {
		EL[pos] = EL[pos-1];
		pos--;
	}
	EL[pos] = temp;
	
	temp = EL[pos];
	while(	pos >= 1 and 
			EL[pos-1].second > temp.second and 
			EL[pos-1].first == temp.first
		 )
	{
		EL[pos] = EL[pos-1];
		pos--;
	}
	EL[pos] = temp;
}

void add_to_EL(int a, int b) {
	EL.push_back(mp(a,b));
	sort_EL();
	EL.push_back(mp(b,a));
	sort_EL();
}

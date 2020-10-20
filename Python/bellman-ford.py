V, E = map(int, input().strip().split())

inf = float('inf')
EL = []
dist = [inf]*(V+1)
pred = [-1]*(V+1)

for i in range(E):
	u, v, w = map(int, input().strip().split())
	EL.append((u, v, w))

src = int(input().strip())
dist[src] = 0

for i in range(1, V):
	for edge in EL:
		u, v, w = edge[0], edge[1], edge[2]
		if dist[u] + w < dist[v]:
			dist[v] = dist[u]+w
			pred[v] = u

for edge in EL:
	u, v, w = edge[0], edge[1], edge[2]
	if dist[u] + w < dist[v]:
		print('Shortest path from {} to {} doesnt exist.'.format(u, v))

'''
5 7
0 1 2
0 2 3
0 4 2
1 3 3
2 3 2
3 0 3
4 1 3
'''
graf = {
    1: [2, 3, 4],
    2: [1, 5],
    3: [1, 5, 6, 7],
    4: [1, 8],
    5: [2, 3],
    6: [3, 13],
    7: [3, 9, 10],
    8: [4, 11],
    9: [7, 10, 13],
    10: [7, 9, 12],
    11: [8, 12],
    12: [10, 11],
    13: [6, 9, 14, 15],
    14: [13],
    15: [13, 16, 19],
    16: [15, 17],
    17: [16, 18],
    18: [17],
    19: [15, 20],
    20: [19] 
}
kota = ["","Arad","Zerind","Sibiu","Timisoara","Oradea",
        "Fagaras","Rimnicu Vilcea","Lugoj","Pitesti",
        "Craiova","Mehadia","Dobreta","Bucharest","Giurgiu",
        "Urziceni","Vaslui","Lasi","Neamt","Hirsova","Eforie"]

def bfs(data, awal, akhir):
    queue = [[awal]]
    sdh_lwt = set()
    while queue:
        jalur = queue.pop(0)
        vertex = jalur[-1]
        if vertex == akhir:
            return jalur
        elif vertex not in sdh_lwt:
            for tetangga in data.get(vertex, []):
                jalur_baru = list(jalur)
                jalur_baru.append(tetangga)
                queue.append(jalur_baru)
            sdh_lwt.add(vertex)
            
awal = input("\nMasukan Kota Awal : ")
akhir = input("Masukkan Kota Tujuan : ")
for x in range(1,21):
    if awal == kota[x]:
        index_awal = x
    elif akhir == kota[x]:
        index_akhir = x
       
print("\nRute Terbaik dengan BFS adalah : ")
hasil_vertex = bfs(graf, index_awal, index_akhir)

for x in hasil_vertex:
    if x == hasil_vertex[-1]:
        print(kota[x],end='.',flush=True)
    else:
        print(kota[x],end=' -> ',flush=True)

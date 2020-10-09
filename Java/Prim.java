//package prim;

public class Prim {

    private static final int V = 12;

    int minKey(int key[], Boolean mstSet[]) {
        int min = Integer.MAX_VALUE, min_index = -1;

        for (int v = 0; v < V; v++) {
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }

        return min_index;
    }

    void printMST(int parent[], int graph[][]) {
        System.out.println("Edge \tWeight");
        for (int i = 1; i < V; i++) {
            System.out.println((char) (parent[i] + 65) + " - " + (char) (i + 65) + "\t" + graph[i][parent[i]]);
        }
    }

    void primMST(int graph[][]) {
        int parent[] = new int[V];

        int key[] = new int[V];

        Boolean mstSet[] = new Boolean[V];

        for (int i = 0; i < V; i++) {
            key[i] = Integer.MAX_VALUE;
            mstSet[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);

            mstSet[u] = true;

            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        printMST(parent, graph);
    }

    public static void main(String[] args) {
        Prim t = new Prim();
        int graph[][] = new int[][]{
            // A, B, C, D, E, F, G, H, I, J, K, L
            /*A*/{0, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0},
            /*B*/ {6, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0},
            /*C*/ {6, 1, 0, 2, 7, 0, 2, 0, 0, 0, 0, 0},
            /*D*/ {6, 0, 2, 0, 0, 0, 0, 0, 0, 18, 0, 0},
            /*E*/ {0, 2, 7, 0, 0, 4, 0, 0, 0, 0, 0, 0},
            /*F*/ {0, 0, 0, 0, 4, 0, 11, 10, 0, 0, 0, 0},
            /*G*/ {0, 0, 2, 0, 0, 11, 0, 22, 2, 0, 0, 0},
            /*H*/ {0, 0, 0, 0, 0, 10, 22, 0, 12, 0, 25, 0},
            /*I*/ {0, 0, 0, 0, 0, 0, 2, 12, 0, 1, 16, 0},
            /*J*/ {0, 0, 0, 18, 0, 0, 0, 0, 1, 0, 0, 8},
            /*K*/ {0, 0, 0, 0, 0, 0, 0, 25, 16, 0, 0, 3},
            /*L*/ {0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 3, 0}};

        t.primMST(graph);
    }
} 

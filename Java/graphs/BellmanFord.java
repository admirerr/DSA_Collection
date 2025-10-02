//Bellman Ford Algorithm

//-----REFERENCES-----
//
//Wikipedia: https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
//GeeksforGeeks: https://www.geeksforgeeks.org/dsa/bellman-ford-algorithm-dp-23



import java.util.*;

// Edge representation
class Edge {
    int src, dest, weight;
    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        weight = w;
    }
}

public class BellmanFord {
    int V, E;       // Number of vertices & edges
    List<Edge> edges;

    BellmanFord(int v, int e) {
        V = v;
        E = e;
        edges = new ArrayList<>();
    }

    void addEdge(int u, int v, int w) {
        edges.add(new Edge(u, v, w));
    }

    void bellmanFord(int src) {
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        // Step 1: Relax all edges V-1 times
        for (int i = 1; i < V; i++) {
            for (Edge edge : edges) {
                if (dist[edge.src] != Integer.MAX_VALUE &&
                        dist[edge.src] + edge.weight < dist[edge.dest]) {
                    dist[edge.dest] = dist[edge.src] + edge.weight;
                }
            }
        }

        // Step 2: Check for negative weight cycles
        for (Edge edge : edges) {
            if (dist[edge.src] != Integer.MAX_VALUE &&
                    dist[edge.src] + edge.weight < dist[edge.dest]) {
                System.out.println("Graph contains a negative weight cycle!");
                return;
            }
        }

        // Step 3: Print distances
        printSolution(dist, src);
    }

    void printSolution(int[] dist, int src) {
        System.out.println("Vertex\tDistance from Source " + src);
        for (int i = 0; i < V; i++) {
            if (dist[i] == Integer.MAX_VALUE)
                System.out.println(i + "\tINF");
            else
                System.out.println(i + "\t" + dist[i]);
        }
    }

    // Driver
    public static void main(String[] args) {
        int V = 5;  // vertices
        int E = 8;  // edges

        BellmanFord graph = new BellmanFord(V, E);

        // Adding edges (src, dest, weight)
        graph.addEdge(0, 1, -1);
        graph.addEdge(0, 2, 4);
        graph.addEdge(1, 2, 3);
        graph.addEdge(1, 3, 2);
        graph.addEdge(1, 4, 2);
        graph.addEdge(3, 2, 5);
        graph.addEdge(3, 1, 1);
        graph.addEdge(4, 3, -3);

        graph.bellmanFord(0);
    }
}


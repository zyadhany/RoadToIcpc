import java.util.*;
import java.io.*;

public class Main {
    static final long MODE = (long)1e9 + 7;
    static long mn, m;

    static class Graph {
        int size;
        boolean[] vis;
        ArrayList<ArrayList<Pair>> adj;

        public Graph(int n) {
            size = n;
            vis = new boolean[n + 1];
            adj = new ArrayList<>();
            for (int i = 0; i <= n; i++) {
                adj.add(new ArrayList<>());
            }
        }

        public void addEdge(int u, int v, int w) {
            adj.get(u).add(new Pair(v, w));
        }

        public Pair DFS(int n, int p, long w, ) {
            int ps = adj.get(n).size(), at = 0;
            ArrayList<Pair> Z = new ArrayList<>(Collections.nCopies(ps + 1, null));

            for (int i = 0; i < adj.get(n).size(); i++) {
                Z.set(i, DFS(adj.get(n).get(i).first, n, w + adj.get(n).get(i).second));
                if (Z.get(i).pq.size() > Z.get(at).pq.size()) at = i;
            }

            for (int i = 0; i < Z.size(); i++) {
                if (i == at) continue;
                while (!Z.get(i).pq.isEmpty()) {
                    Z.get(at).pq.offer(Z.get(i).pq.poll());
                }
                Z.get(at).sum += Z.get(i).sum;
            }
            while (Z.get(at).pq.size() > m) {
                Z.get(at).sum -= Z.get(at).pq.poll();
            }

            if (Z.get(at).pq.size() == m) mn = Math.min(mn, Z.get(at).sum - m * w);

            Z.get(at).pq.offer(w);
            Z.get(at).sum += w;
            return Z.get(at);
        }
    }

    static class Pair {
        PriorityQueue<Long> pq;
        long sum;

        public Pair() {
            pq = new PriorityQueue<>(Collections.reverseOrder());
            sum = 0;
        }
    }

    public static void solve(int tc, Scanner sc, PrintWriter out) {
        int n = sc.nextInt();
        int k = sc.nextInt();

        mn = Long.MAX_VALUE;
        m = k - 1;
        Graph gr = new Graph(n);
        int[] X = new int[n + 1];
        Arrays.fill(X, 0);

        for (int i = 0; i < n - 1; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            int w = sc.nextInt();
            gr.addEdge(l, r, w);
            X[r] = 1;
        }

        int src = 0;
        for (int i = 1; i <= n; i++) {
            if (X[i] == 0) {
                src = i;
                break;
            }
        }

        if (n == 1) mn = 0;
        else gr.DFS(src, 0, 0);

        out.println(mn);
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int size = sc.nextInt();

        for (int i = 1; i <= size; i++) {
            solve(i, sc, out);
        }

        out.flush();
        out.close();
    }
}

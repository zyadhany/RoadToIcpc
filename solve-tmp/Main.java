import java.io.*;
import java.util.*;

public class Main {

    static final int MODE = (int) 1e9 + 7;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int t = sc.nextInt();
        while (t-- > 0) {
            solve(sc, out);
        }
        out.close();
    }

    static void solve(FastScanner sc, PrintWriter out) {
        int n = sc.nextInt();
        long[] X = new long[n];
        long sum = 0;

        for (int i = 0; i < n; i++) {
            X[i] = sc.nextLong();
            sum += X[i];
        }

        Arrays.sort(X);
        long res = 0;
        for (int i = 0; i < n; i++) {
            sum -= X[i];
            if (X[i] <= 1 || res == 0) {
                res = (res + sum) % MODE;
            } else {
                res = (res * X[i]) % MODE;
            }
        }

        out.println(res);
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }
    }
}

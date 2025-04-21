
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        
        int t = sc.nextInt();
        for (int tc = 0; tc < t; tc++) {   
            Long n = sc.nextLong();
            Long k = sc.nextLong();
            long at = 1;
            for (int i = 0; i < n; i++) {
                at <<= 1;
                if (i % 2 == 1) {
                    at |= 1;
                }
                if (at > k) {
                    System.out.println("NO");
                    return;
                }
            }        
            System.out.println("YES");
        }
    }


    static class FastScanner {
        BufferedReader in;
        StringTokenizer st;
 
        public FastScanner() {
 
            this.in = new BufferedReader(new InputStreamReader(System.in));
 
        }
 
        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }
    }
}
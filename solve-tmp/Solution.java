import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt(); // number of test cases
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            int ans = 0;
            int who = 0; // 0 = first brother, 1 = second, 2 = third
            int i = 0;

            while (i < n) {
                if (who == 0) {
                    ans++;
                }

                while (i + 1 < n && a[i] - a[i + 1] == 1) {
                    i++;
                }

                i++; // move to next brother
                who = (who + 1) % 3;
            }

            System.out.println(ans);
        }
    }
}

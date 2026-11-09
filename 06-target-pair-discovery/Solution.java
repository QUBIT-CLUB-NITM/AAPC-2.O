import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long target = sc.nextLong();

        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }

        // Map each value to a list of its 1-based indices
        HashMap<Long, ArrayList<Integer>> pos = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (!pos.containsKey(a[i])) {
                pos.put(a[i], new ArrayList<>());
            }
            pos.get(a[i]).add(i + 1);
        }

        // Check each index i (from 1 to n)
        for (int i = 0; i < n; i++) {
            long needed = target - a[i];

            if (pos.containsKey(needed)) {
                for (int j : pos.get(needed)) {
                    if (j > i + 1) {
                        System.out.println((i + 1) + " " + j);
                        sc.close();
                        return;
                    }
                }
            }
        }

        System.out.println("-1 -1");
        sc.close();
    }
}

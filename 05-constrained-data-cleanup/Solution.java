import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        long maxVal = -1;
        int maxIdx = -1;

        for (int i = 0; i < n; i++) {
            long val = sc.nextLong();
            if (val > maxVal) {
                maxVal = val;
                maxIdx = i;
            }
        }

        int l = maxIdx;
        int r = n - 1 - maxIdx;

        int opsL = (l > 0) ? (l + k - 1) / k : 0;
        int opsR = (r > 0) ? (r + k - 1) / k : 0;

        System.out.println(opsL + opsR);
        sc.close();
    }
}

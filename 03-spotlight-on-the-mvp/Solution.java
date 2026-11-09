import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        long maxVal = -1;
        int maxIdx = -1;

        for (int i = 0; i < n; i++) {
            long val = sc.nextLong();
            if (val > maxVal) {
                maxVal = val;
                maxIdx = i;
            }
        }

        int leftCount = maxIdx;
        int rightCount = n - 1 - maxIdx;

        System.out.println(leftCount + " " + rightCount);
        sc.close();
    }
}

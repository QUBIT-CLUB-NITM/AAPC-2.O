import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();

        int lateCount = 0;
        for (int i = 0; i < n; i++) {
            int arrival = sc.nextInt();
            if (arrival > t) {
                lateCount++;
            }
        }

        System.out.println(lateCount);
        sc.close();
    }
}

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[][] scores = new int[3][n];
        boolean[] validJudge = new boolean[3];

        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < n; i++) {
                scores[j][i] = sc.nextInt();
                if (scores[j][i] != -1) {
                    validJudge[j] = true;
                }
            }
        }

        int bestTeam = 1;
        long bestSum = 0;
        long bestCnt = 0;

        for (int i = 0; i < n; i++) {
            long sum = 0;
            long cnt = 0;

            for (int j = 0; j < 3; j++) {
                if (validJudge[j] && scores[j][i] != -1) {
                    sum += scores[j][i];
                    cnt++;
                }
            }

            if (cnt > 0) {
                if (bestCnt == 0 || sum * bestCnt > bestSum * cnt) {
                    bestSum = sum;
                    bestCnt = cnt;
                    bestTeam = i + 1;
                }
            }
        }

        System.out.println(bestTeam);
        sc.close();
    }
}

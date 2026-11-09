import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        boolean found = false;
        for (int i = 0; i < n; i++) {
            int code = sc.nextInt();
            if (code == 404) {
                found = true;
            }
        }

        if (found) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }

        sc.close();
    }
}

import java.util.*;
// https://leetcode.com/problems/generate-parentheses/

public class GenParens {

    public void parens(int leftCount, int rightCount, String ans) {
        if (leftCount == 0 && rightCount == 0) {
            System.out.println(ans);
            return;
        }
        if (rightCount > 0)
            parens(leftCount, rightCount - 1, ans.concat(")"));
        if (leftCount > 0)
            parens(leftCount - 1, rightCount + 1, ans.concat("("));
    }

    public static void main(String arg[]) {
        Scanner scan = new Scanner(System.in);
        int n = Integer.parseInt(scan.next());

        GenParens solver = new GenParens();
        solver.parens(n, 0, "");
        scan.close();
    }
}
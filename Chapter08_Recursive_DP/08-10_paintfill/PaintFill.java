import java.util.ArrayList;
// 塗りつぶしする
// DFS / BFS 深さ優先 幅優先


class PaintFill {
    private enum Color {Black, White, Red};
    int [][] memo;

    // DFS 
    public void dfsFill (int x, int y, Color target, Color original, Color[][] sc) {
        // stop 
        if (x < 0 || y < 0 || x >= sc[0].length || y >= sc.length) return;
        if (sc[y][x] != original) return;
        sc[y][x] = target;

        dfsFill(x, y-1, target, original, sc); // top
        dfsFill(x, y+1, target, original, sc); // down
        dfsFill(x-1, y, target, original, sc); // left
        dfsFill(x+1, y, target, original, sc); // right 
    }

    public void paintFill (int x, int y, Color target, Color[][] sc) {
        if (target == sc[y][x]) return;
        dfsFill(x, y, target, sc[y][x], sc);
    }

    public static void main (String[] args) {
        PaintFill pf = new PaintFill();
        // 座標 (x, y) screen[][]
        Color[][] screen =  {
            {Color.White, Color.White, Color.White, Color.White, Color.White},
            {Color.White, Color.Black, Color.Black, Color.Black, Color.Black},
            {Color.White, Color.White, Color.Red, Color.Red, Color.White},
            {Color.Red, Color.Black, Color.Red, Color.Red, Color.White},
            {Color.White, Color.Red, Color.White, Color.Black, Color.White}
        };

        int x = 0;
        int y = 0;
        Color targetColor = Color.Red;
        pf.paintFill(x, y, targetColor, screen);

        // i = y j = x
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(screen[i][j] + " ");
            }
            System.out.println();
        }
    }
}
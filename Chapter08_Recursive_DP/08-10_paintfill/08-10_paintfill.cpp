#include <iostream>
#include <vector>

using namespace std;
enum class Color {
    Black,
    White,
    Red
};
string toString(Color c) {
    if (c == Color::Black) return "Black";
    if (c == Color::White) return "White";
    if (c == Color::Red) return "Red";
    return "";
}
void dfsFill(int x, int y, Color target, Color original, vector<vector<Color>>& sc)
{
    // stop
    if (x < 0 || y < 0 || x >= sc[0].size() || y >= sc.size())
        return;
    if (sc[y][x] != original)
        return;
    sc[y][x] = target;

    dfsFill(x, y - 1, target, original, sc); // top
    dfsFill(x, y + 1, target, original, sc); // down
    dfsFill(x - 1, y, target, original, sc); // left
    dfsFill(x + 1, y, target, original, sc); // right
}

void paintFill(int x, int y, Color target, vector<vector<Color>>& sc)
{
    if (target == sc[y][x])
        return;
    dfsFill(x, y, target, sc[y][x], sc);
}

int main()
{
    vector<vector<Color>> screen =  {
            {Color::White, Color::White, Color::White, Color::White, Color::White},
            {Color::White, Color::Black, Color::Black, Color::Black, Color::Black},
            {Color::White, Color::White, Color::Red, Color::Red, Color::White},
            {Color::Red, Color::Black, Color::Red, Color::Red, Color::White},
            {Color::White, Color::Red, Color::White, Color::Black, Color::White}
        };

        int x = 0;
        int y = 0;
        Color targetColor = Color::Red;
        paintFill(x, y, targetColor, screen);

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << toString(screen[i][j]) << " ";
            }
            cout << endl;
        }
}
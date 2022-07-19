#include<iostream>
#include<stack>
#include<vector>

using namespace std;
class Tower {
private:
    stack<int> disks;
    int index;
public:
    Tower(int i) :index(i){};

    void addDisks(int d) {
        // 逆順に積むのを防ぐためのエラー
        if (!disks.empty() && disks.top() <= d) {
            throw "error";
        }
        disks.push(d);
    }

    // 自タワーのトップのdiskをdestタワーに積む
    void moveTopTo(Tower* dest) {
        int top = disks.top();
        disks.pop();
        dest->addDisks(top);
    }

    // 自タワーのn個の皿をbuffを経由して正しい順番にdestタワーへ移動する
    void moveDisks(int n, Tower* dest, Tower* buff) {
        if (n == 0) return;
        moveDisks(n - 1, buff, dest);
        moveTopTo(dest);
        buff->moveDisks(n - 1, dest, this);
    }

};

int main () {
    int n = 3;
    vector<Tower> towers;
    for (int i = 0; i < n; i++) {
        towers.push_back(Tower(i));
    }

    for (int i = n - 1; i >= 0; i--) {
        towers[0].addDisks(i);
    }
    towers[0].moveDisks(n, &towers[2], &towers[1]);
}
#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include <functional>
using namespace std;

class Array {
public:
    Array() {
        std::random_device seed_gen;
        std::mt19937 engine(seed_gen());

        length = engine() % 10000;
        arr = vector<int>(length);
        for (int i = 0; i < length; i++) {
            arr[i] = engine() % 10000;
        }
        sort(arr.begin(), arr.end());
    }

    int elementAt(int i) {
        if (i >= length) return -1;
        return arr[i];
    }
    void show() {
        int limit = min(10, length);
        for (int i = 0; i < limit; i++) {
            cout << arr[i] << endl;
        }
    }
private:
    vector<int> arr;
    int length;
};


int find(Array* l, int target) {
    int size = 1;

    while(l->elementAt(size) != -1 && l->elementAt(size) < target) { // targetの位置を探すことに固執して。
        size *= 2;
    }

    int left = size / 2; // 前半部分に出現しないことは確定しているため
    int right = size;
    while (left <= right) {
        int mid = (left + right) / 2;
        int mid_val = l->elementAt(mid);
        if (target == mid_val) return mid;
        if (target < mid_val || mid_val == -1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main () {
    Array* arr = new Array();
    arr->show();
    cout << find(arr, 3) << endl;
}
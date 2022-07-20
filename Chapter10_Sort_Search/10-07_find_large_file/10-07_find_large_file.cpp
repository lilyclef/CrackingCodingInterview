// 1GBのメモリが使用できて、40億個の非負整数 => ビットベクトルを使うと収まる場合
// 収まらない場合はP447
#include <iostream>
#include <fstream> // std::ifstream
#include <algorithm>
using namespace std;

int main () {
    ifstream ifs("data.txt");
    if (ifs.fail()) {
        cerr << "error to open file" << endl;
        exit(1);
    }
    string buf;
    long numberOfInts = ((long) INT8_MAX) + 1;
    vector<unsigned long int> bitvector((int) (numberOfInts / 8), 0);
    while (getline(ifs, buf)) {
        int target = stoi(buf);
        bitvector[target / 8] |= 1 << (target % 8); // 8で割った商とあまりでマッピングしている
    }

    for (int i = 0; i < bitvector.size(); i++) {
        for (int j = 0; j < 8; j++) {
            if ((bitvector[i] & (1 << j)) == 0) {
                cout << i * 8 + j << endl;
                return 0;
            }
        }
    }
}
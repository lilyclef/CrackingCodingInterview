#include<iostream>
#include<fstream>
#include<memory>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using psi = pair<string, int>;

// ifstreamはコピーコンストラクタが存在するか？
// ->ifstream is not copyable
// ポインタが必要になる。
// ヒープに置く
void merge_files(vector<unique_ptr<ifstream>>& files, ofstream& ofs) {

    priority_queue<psi, vector<psi>, greater<psi>> pq;

    for (int i = 0; i < files.size(); i++) {
        auto tmp_ifs = files[i].get();
        string tmp_str;
        if (getline(*tmp_ifs, tmp_str)) {
            pq.push({tmp_str, i});
        }
    }

    while(!pq.empty()) {
        auto [curr_str, curr_i] = pq.top();
        pq.pop();
        ofs << curr_str << endl;
        auto tmp_ifs = files[curr_i].get();
        string tmp_str;
        if (getline(*tmp_ifs, tmp_str)) {
            pq.push({tmp_str, curr_i});
        }
    }
}


int main () {
    // 9.0M -> 1.0M 8splits
    int number_of_file = 8;
    vector<unique_ptr<ifstream>> files;
    for (int i = 0; i < number_of_file; i++) {
        ifstream tmp_ifs("data/split_data" + to_string(i));
        ofstream tmp_ofs("data/sorted_data" + to_string(i));
        string tmp_str;
        vector<string> tmp_vec;
        while (getline(tmp_ifs, tmp_str)) {
            tmp_vec.push_back(tmp_str);
        }
        sort(tmp_vec.begin(), tmp_vec.end());
        for (string& tv : tmp_vec) {
            tmp_ofs << tv << endl;
        }
        tmp_ofs.close();
        tmp_ifs.close();
        files.push_back(move(unique_ptr<ifstream> (new ifstream("data/sorted_data" + to_string(i)))));
    }
    ofstream output("data/sorted_data_all.txt");
    merge_files(files, output);

    // ヒープ上のファイルディスクリプタを止める。
    for (auto& file : files) {
        file.get()->close();
    }
    output.close();
}
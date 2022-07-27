#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<tuple>

using namespace std;


class LRUCache {
public:
  LRUCache(int size) {
    this->size = size;
  }
  int size;
  list<int> order_list;
  unordered_map<int, pair<int, list<int>::iterator>> mp; // key val, iter

  void put(int key, int val) {
    if (mp.find(key) != mp.end()) {
      auto [data, iter] = mp[key];
      order_list.erase(iter);
    } else if( order_list.size() >= size) {
      int delete_key = order_list.front();
      order_list.pop_front();
      mp.erase(delete_key);
    }
      order_list.push_back(key);
      mp[key] = {val, --order_list.end()};
  }

  int get(int key) {
    if (mp.find(key) == mp.end()) return -1;
    auto [data, iter] = mp[key];
    order_list.erase(iter);
    order_list.push_back(key);
    mp[key] = {data, --order_list.end()};
    return data;
  }

};

int main() {
  LRUCache cache(2);
  cache.put(1, 1); // cache is {1=1}
  cache.put(2, 2); // cache is {1=1, 2=2}
  cout << cache.get(1) << endl;    // return 1
  cache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  cout << cache.get(2) << endl;    // returns -1 (not found)
  cache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  cout << cache.get(1) << endl;    // return -1 (not found)
  cout << cache.get(3) << endl;    // return 3
  cout << cache.get(4) << endl;    // return 4
}
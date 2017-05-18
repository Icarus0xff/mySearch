#include "kv.h"
#include "include/json.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

namespace kv_store {
using namespace std;
using namespace nlohmann;

void Kv::store(string word, vector<int64_t> ids) { kv[word] = ids; };
void Kv::add(string word, int64_t id) { kv[word].push_back(id); };

int Kv::persistent() {
  json j;
  for (auto &&w : kv) {
    j[w.first] = w.second;
  }
  string s = j.dump();
  cout << s << endl;

  ofstream o("data.json");
  o << s;
  o.close();
  return 0;
};
}

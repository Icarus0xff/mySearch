#include "include/cppjieba/Jieba.hpp"
#include "include/json.hpp"
#include "kv.h"
#include "include/leveldb/db.h"
#include <iostream>
#include <string>

using namespace std;
using namespace kv_store;
using namespace nlohmann;

const char *const DICT_PATH = "dict/jieba.dict.utf8";
const char *const HMM_PATH = "dict/hmm_model.utf8";
const char *const USER_DICT_PATH = "dict/user.dict.utf8";
const char *const IDF_PATH = "dict/idf.utf8";
const char *const STOP_WORD_PATH = "dict/stop_words.utf8";

int main(int argc, char *argv[]) {
  Kv kv;
  int64_t id(15);
  string s = "test";

  kv.add(s, id);
  kv.persistent();

  json j2 = {{"pi", 3.141},
             {"happy", true},
             {"name", "Niels"},
             {"nothing", nullptr},
             {"answer", {{"everything", 42}}},
             {"list", {1, 0, 2}},
             {"object", {{"currency", "USD"}, {"value", 42.99}}}};

  for (json::iterator it = j2.begin(); it != j2.end(); ++it) {
    cout << it.key() << it.value() << endl;
  }

  string ss = "测试";
  for (auto &i : ss) {
    cout << i << endl;
  }

  cppjieba::Jieba jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH,
                        STOP_WORD_PATH);

  ss = "what a fucking crazy thing!";
  cout << ss << endl;
  vector<string> words;
  jieba.Cut(ss, words, true);

  auto count = 0;
  for (auto &i : words) {
    cout << ++count << " " << i << endl;
  }

  return 0;
}

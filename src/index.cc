#include "include/index.h"
#include "include/cppjieba/Jieba.hpp"
#include "include/document_type.h"
#include "include/json/json.hpp"
#include "include/leveldb/db.h"

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <set>
#include <vector>

namespace nsindex {
using namespace nlohmann;
using namespace std;
using namespace nsdocument;

void Index::index(uint64_t id, nsdocument::Document &doc) {
  // convert doc to json
  json j;
  j["id"] = doc.get_id();
  j["content"] = doc.get_content();
  j["timestamp"] = doc.get_timestamp();

  // save to storage
  leveldb::DB *db;
  leveldb::Options options;
  options.create_if_missing = true;

  leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);

  if (false == status.ok()) {
    cerr << "Unable to open/create test database './testdb'" << endl;
    cerr << status.ToString() << endl;
  }

  ostringstream key, value;
  key << doc.get_id();
  value << j;

  leveldb::WriteOptions writeOptions;
  db->Put(writeOptions, key.str(), value.str());

  // analyze content
  const char *const DICT_PATH = "dict/jieba.dict.utf8";
  const char *const HMM_PATH = "dict/hmm_model.utf8";
  const char *const USER_DICT_PATH = "dict/user.dict.utf8";
  const char *const IDF_PATH = "dict/idf.utf8";
  const char *const STOP_WORD_PATH = "dict/stop_words.utf8";

  cppjieba::Jieba jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH,
                        STOP_WORD_PATH);

  vector<string> words;
  jieba.Cut(doc.get_content(), words, true);

  status = leveldb::DB::Open(options, "./invert_index", &db);
  if (false == status.ok()) {
    cerr << "Unable to open/create test database './testdb'" << endl;
    cerr << status.ToString() << endl;
  }

  auto count = 0;
  for (auto &i : words) {
    string v;
    db->Get(leveldb::ReadOptions(), i, &v);

    vector<string> strs;

    boost::split(strs, v, boost::is_any_of(","));
    strs.push_back(key.str());

    set<string> tset;
    for (auto &i : strs) {
      if (i == "") {
        continue;
      }
      tset.insert(i);
    }

    v = boost::join(tset, ",");
    cout << v << endl;
    db->Put(writeOptions, i, v);
  }
  // Close the database
  delete db;
}
} // nsindex

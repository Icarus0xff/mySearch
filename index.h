
#ifndef INDEX_H
#define INDEX_H

#include "include/json.hpp"
#include "kv.h"
#include <string>

namespace nsindex {
using namespace kv_store;
using namespace nlohmann;

class Index {
  int64_t id;
  string name;
  string path;
  vector<int64_t> document_ids;
  kv_store::Kv inverted_index;

public:
  Index(){};
  virtual ~Index(){};

  void index(uint64_t, json &);
};
}

#endif /* INDEX_H */

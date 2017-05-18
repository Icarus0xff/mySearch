#include <map>
#include <vector>

namespace kv_store {
using namespace std;

class Kv {
  map<string, vector<int64_t>> kv;

public:
  Kv(){};
  void store(string, vector<int64_t>);
  void add(string, int64_t);
  int persistent();
  virtual ~Kv(){};
};
}

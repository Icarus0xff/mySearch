
#ifndef INDEX_H
#define INDEX_H

#include "document_type.h"
#include <string>

namespace nsindex {
using namespace std;
using namespace nsdocument;

class Index {
  string path;
public:
  Index():path("./temp.db"){};
  Index(string path):path(path){};
  virtual ~Index(){};

  void index(uint64_t, Document &);
};

} // nsindex
#endif /* INDEX_H */

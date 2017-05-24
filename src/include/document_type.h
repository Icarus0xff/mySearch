#ifndef DOCUMENT_TYPE_H
#define DOCUMENT_TYPE_H

#include "json/json.hpp"
#include <cstdint>
#include <string>

namespace nsdocument {

using namespace std;
using namespace nlohmann;

class Document {
  uint64_t id;
  string content;
  uint64_t timestamp;

public:
  Document(){};
  Document(uint64_t id, string content, uint64_t time)
      : id(id), content(content), timestamp(time){};
  virtual ~Document(){};

  uint64_t get_id() const;
  string get_content() const;
  uint64_t get_timestamp() const;
};


} // nsdocument

#endif /* DOCUMENT_TYPE_H */

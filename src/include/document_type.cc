#include "document_type.h"
#include "json/json.hpp"

namespace nsdocument {
using namespace nlohmann;

string Document::get_content() const { return content; };

uint64_t Document::get_id() const { return id; };

uint64_t Document::get_timestamp() const { return timestamp; }

void to_json(json &j, const Document &doc) {
  j = json{{"id", doc.get_id()},
           {"content", doc.get_content()},
           {"timestamp", doc.get_timestamp()}};
}

void from_json(const json &j, Document &doc) {
  // p.name = j.at("name").get<std::string>();
  // p.address = j.at("address").get<std::string>();
  // p.age = j.at("age").get<int>();
}
} // nsdocument

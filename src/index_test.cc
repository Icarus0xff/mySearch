#include "include/cppjieba/Jieba.hpp"
#include "include/document_type.h"
#include "include/index.h"
#include <iostream>

using namespace nsindex;
using namespace nsdocument;

const char *const DICT_PATH = "dict/jieba.dict.utf8";
const char *const HMM_PATH = "dict/hmm_model.utf8";
const char *const USER_DICT_PATH = "dict/user.dict.utf8";
const char *const IDF_PATH = "dict/idf.utf8";
const char *const STOP_WORD_PATH = "dict/stop_words.utf8";

int main(int argc, char *argv[]) {

  Index idx("./test.db");
  Document doc{2, "test my document", 1024};
  idx.index(doc.get_id(), doc);

  return 0;
}

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "include/cppjieba/Jieba.hpp"
#include <string>

namespace nstokenizer {
using namespace std;
using namespace cppjieba;

const char *const DICT_PATH = "dict/jieba.dict.utf8";
const char *const HMM_PATH = "dict/hmm_model.utf8";
const char *const USER_DICT_PATH = "dict/user.dict.utf8";
const char *const IDF_PATH = "dict/idf.utf8";
const char *const STOP_WORD_PATH = "dict/stop_words.utf8";

class Tokenizer {
  Jieba jieba;

public:
  Tokenizer()
      : jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORD_PATH){};
  virtual ~Tokenizer();

  vector<string> tokenize(string &);
};

} // nstokenizer

#endif /* TOKENIZER_H */

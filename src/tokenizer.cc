#include "tokenizer.h"
#include "include/cppjieba/Jieba.hpp"

namespace nstokenizer {
using namespace std;

vector<string> Tokenizer::tokenize(string &in) {
  vector<string> words;
  jieba.Cut(in, words, true);
  return words;
};
} // nstokenizer

//
//  IOPack.cpp
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//

#include "IOPack.hpp"
using namespace Sample;
void IOPack::Initialize(v8::Isolate* isolate) {}

IOPack::~IOPack() {}

IOPack* IOPack::New(v8::Isolate* isolate) {
  IOPack* iop = new IOPack();
  iop->Initialize(isolate);
  return iop;
}

char* IOPack::readFile(const char* path) {
  FILE* file = fopen(path, "r");
  if (!file) {
    std::perror("File opening failed");
    return NULL;
  }
  fseek(file, 0, SEEK_END);
  size_t size = ftell(file);
  rewind(file);
  char* chars = new char[size + 1];
  for (size_t i = 0; i < size;) {
    i += fread(&chars[i], 1, size - i, file);
    fclose(file);
  }
  return chars;
}

//
//  IOPack.cpp
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//

#include "IOPack.hpp"
#include <codecvt>

using namespace Sample;

void IOPack::readFile(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::String::Utf8Value str(args.GetIsolate(), args[0]);
    const char* path = *str;
    FILE* file = fopen(path, "r");
    if (!file) {
      std::perror("File opening failed");
        args.GetReturnValue().Set(v8::String::NewFromUtf8(args.GetIsolate(), "").ToLocalChecked());
    }
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);
    char* chars = new char[size + 1];
    for (size_t i = 0; i < size;) {
      i += fread(&chars[i], 1, size - i, file);
      fclose(file);
    }
    args.GetReturnValue().Set(v8::String::NewFromUtf8(args.GetIsolate(), chars).ToLocalChecked());
}

void IOPack::writeFile(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::String::Utf8Value pathstr(args.GetIsolate(), args[0]);
    const char* path = *pathstr;
    v8::String::Utf8Value strs(args.GetIsolate(), args[1]);
    const char* str = *strs;
    FILE* file = fopen(path, "w+");
    fseek(file, 0, SEEK_END);
    fwrite(str, 1, strs.length(),  file);
    fclose(file);
}

//--------------------------- public ---------------------------

void IOPack::Initialize(v8::Isolate* isolate) {
  v8::Local<v8::ObjectTemplate> ioObj = v8::ObjectTemplate::New(isolate);
  ioObj->Set(isolate, "readFile",
             v8::FunctionTemplate::New(isolate, IOPack::readFile));
  ioObj->Set(isolate, "writeFile",
             v8::FunctionTemplate::New(isolate, IOPack::writeFile));

  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  context->Global()->Set(
      context, v8::String::NewFromUtf8(isolate, "io").ToLocalChecked(),
      ioObj->NewInstance(context).ToLocalChecked());
}

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

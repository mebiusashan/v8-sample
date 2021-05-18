//
//  GlobalPack.cpp
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//

#include "GlobalPack.hpp"
#include <iostream>
#include "Macro.h"

using namespace Sample;

// void GlobalPack::version(const v8::FunctionCallbackInfo<v8::Value>& args) {
//  //  std::cout << SVERSION << std::endl;
//  args.GetReturnValue().Set(
//      v8::String::NewFromUtf8(args.GetIsolate(), SVERSION).ToLocalChecked());
//}
//
// void GlobalPack::v8version(const v8::FunctionCallbackInfo<v8::Value>& args) {
//  //  std::cout << v8::V8::GetVersion() << std::endl;
//  args.GetReturnValue().Set(
//      v8::String::NewFromUtf8(args.GetIsolate(), v8::V8::GetVersion())
//          .ToLocalChecked());
//}

//--------------------------- public ---------------------------

void GlobalPack::Initialize(v8::Isolate* isolate) {
  global = v8::ObjectTemplate::New(isolate);
  global->Set(isolate, "version", v8::Number::New(isolate, 1.0));
  //              v8::String::NewFromUtf8(isolate, SVERSION).ToLocalChecked());
  global->Set(
      isolate, "v8version",
      v8::String::NewFromUtf8(isolate, v8::V8::GetVersion()).ToLocalChecked());
}

GlobalPack::~GlobalPack() {}

GlobalPack* GlobalPack::New(v8::Isolate* isolate) {
  GlobalPack* globalp = new GlobalPack();
  globalp->Initialize(isolate);
  return globalp;
}

v8::Local<v8::ObjectTemplate> GlobalPack::GetGlobalObject() {
  return global;
}

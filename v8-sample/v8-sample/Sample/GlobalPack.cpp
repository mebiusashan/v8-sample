//
//  GlobalPack.cpp
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//

#include "GlobalPack.hpp"

using namespace Sample;

void GlobalPack::version(const v8::FunctionCallbackInfo<v8::Value>& args) {}

//--------------------------- public ---------------------------

void GlobalPack::Initialize(v8::Isolate* isolate) {
  global = v8::ObjectTemplate::New(isolate);
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

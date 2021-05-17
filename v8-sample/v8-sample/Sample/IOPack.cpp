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

//
//  GlobalPack.hpp
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//

#ifndef GlobalPack_hpp
#define GlobalPack_hpp

#include "BasePack.h"

namespace Sample {
class GlobalPack : public BasePack {
 private:
  v8::Local<v8::ObjectTemplate> global;
  void version(const v8::FunctionCallbackInfo<v8::Value>& args);
  void v8version(const v8::FunctionCallbackInfo<v8::Value>& args);
  void print();

 public:
  virtual void Initialize(v8::Isolate* isolate);
  ~GlobalPack();

  static GlobalPack* New(v8::Isolate* isolate);

  v8::Local<v8::ObjectTemplate> GetGlobalObject();
};
}  // namespace Sample

#endif /* GlobalPack_hpp */

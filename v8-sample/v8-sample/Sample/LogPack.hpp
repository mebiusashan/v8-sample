//
//  LogPack.hpp
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//

#ifndef LogPack_hpp
#define LogPack_hpp

#include <stdio.h>

#include "BasePack.h"

namespace Sample {
class LogPack : public BasePack {
 private:
  v8::Local<v8::ObjectTemplate> logObj;
  static void infoV(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void logV(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void debugV(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void errorV(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void warnV(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void succV(const v8::FunctionCallbackInfo<v8::Value>& args);

 public:
  virtual void Initialize(v8::Isolate* isolate);
  static LogPack* New(v8::Isolate* isolate);

  void info(char* str);
  void log(char* str);
  void debug(char* str);
  void error(char* str);
  void warn(char* str);
  void succ(char* str);

  v8::Local<v8::ObjectTemplate> GetLogObject();
};
}  // namespace Sample

#endif /* LogPack_hpp */

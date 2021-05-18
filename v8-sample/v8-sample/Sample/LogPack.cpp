//
//  LogPack.cpp
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//
#include <iostream>

#include "LogPack.hpp"
#include "PackageManager.hpp"

using namespace Sample;

void LogPack::infoV(const v8::FunctionCallbackInfo<v8::Value>& args) {
  bool first = true;
  int len = args.Length();
  for (int i = 0; i < len; i++) {
    if (first) {
      first = false;
    } else {
      PackageManager::GetInstance()->GetLogPack()->info(" ");
    }
    v8::String::Utf8Value str(args.GetIsolate(), args[i]);
    PackageManager::GetInstance()->GetLogPack()->info(*str);
  }
  std::cout << std::endl;
}

void LogPack::logV(const v8::FunctionCallbackInfo<v8::Value>& args) {
  bool first = true;
  int len = args.Length();
  for (int i = 0; i < len; i++) {
    if (first) {
      first = false;
    } else {
      PackageManager::GetInstance()->GetLogPack()->log(" ");
    }
    v8::String::Utf8Value str(args.GetIsolate(), args[i]);
    PackageManager::GetInstance()->GetLogPack()->log(*str);
  }
  std::cout << std::endl;
}

void LogPack::debugV(const v8::FunctionCallbackInfo<v8::Value>& args) {
  bool first = true;
  int len = args.Length();
  for (int i = 0; i < len; i++) {
    if (first) {
      first = false;
    } else {
      PackageManager::GetInstance()->GetLogPack()->debug(" ");
    }
    v8::String::Utf8Value str(args.GetIsolate(), args[i]);
    PackageManager::GetInstance()->GetLogPack()->debug(*str);
  }
  std::cout << std::endl;
}

void LogPack::errorV(const v8::FunctionCallbackInfo<v8::Value>& args) {
  bool first = true;
  int len = args.Length();
  for (int i = 0; i < len; i++) {
    if (first) {
      first = false;
    } else {
      PackageManager::GetInstance()->GetLogPack()->error(" ");
    }
    v8::String::Utf8Value str(args.GetIsolate(), args[i]);
    PackageManager::GetInstance()->GetLogPack()->error(*str);
  }
  std::cout << std::endl;
}

void LogPack::warnV(const v8::FunctionCallbackInfo<v8::Value>& args) {
  bool first = true;
  int len = args.Length();
  for (int i = 0; i < len; i++) {
    if (first) {
      first = false;
    } else {
      PackageManager::GetInstance()->GetLogPack()->warn(" ");
    }
    v8::String::Utf8Value str(args.GetIsolate(), args[i]);
    PackageManager::GetInstance()->GetLogPack()->warn(*str);
  }
  std::cout << std::endl;
}

void LogPack::succV(const v8::FunctionCallbackInfo<v8::Value>& args) {
  bool first = true;
  int len = args.Length();
  for (int i = 0; i < len; i++) {
    if (first) {
      first = false;
    } else {
      PackageManager::GetInstance()->GetLogPack()->succ(" ");
    }
    v8::String::Utf8Value str(args.GetIsolate(), args[i]);
    PackageManager::GetInstance()->GetLogPack()->succ(*str);
  }
  std::cout << std::endl;
}

//--------------------------- public ---------------------------
void LogPack::info(char* str) {
  std::cout << "\033[36m" << str << "\033[0m";
}

void LogPack::log(char* str) {
  std::cout << str;
}

void LogPack::debug(char* str) {
  std::cout << "\033[35m" << str << "\033[0m";
}

void LogPack::error(char* str) {
  std::cout << "\033[31m" << str << "\033[0m";
}

void LogPack::warn(char* str) {
  std::cout << "\033[33m" << str << "\033[0m";
}

void LogPack::succ(char* str) {
  std::cout << "\033[32m" << str << "\033[0m";
}

void LogPack::Initialize(v8::Isolate* isolate) {
  logObj = v8::ObjectTemplate::New(isolate);
  logObj->Set(isolate, "info",
              v8::FunctionTemplate::New(isolate, LogPack::infoV));
  logObj->Set(isolate, "log",
              v8::FunctionTemplate::New(isolate, LogPack::logV));
  logObj->Set(isolate, "debug",
              v8::FunctionTemplate::New(isolate, LogPack::debugV));
  logObj->Set(isolate, "error",
              v8::FunctionTemplate::New(isolate, LogPack::errorV));
  logObj->Set(isolate, "warn",
              v8::FunctionTemplate::New(isolate, LogPack::warnV));
  logObj->Set(isolate, "succ",
              v8::FunctionTemplate::New(isolate, LogPack::succV));

  v8::Local<v8::Context> context = isolate->GetCurrentContext();
  context->Global()->Set(
      context, v8::String::NewFromUtf8(isolate, "log").ToLocalChecked(),
      logObj->NewInstance(context).ToLocalChecked());
}

LogPack* LogPack::New(v8::Isolate* isolate) {
  LogPack* logp = new LogPack();
  logp->Initialize(isolate);
  return logp;
}

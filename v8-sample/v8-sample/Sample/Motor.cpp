//
//  Motor.cpp
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//

#include "Motor.hpp"
#include <stdlib.h>
#include <iostream>
#include "Macro.h"
#include "PackageManager.hpp"
#include "v8.h"

using namespace Sample;

void Motor::PrintInfo() {
  std::cout << SNAME << std::endl;
  std::cout << SVERSION << std::endl;
  std::cout << "Usage: sample [ script.js ]" << std::endl;
  std::cout << "\nVM's info" << std::endl;
  //    std::cout << "\tstack limit: " << params.constraints.stack_limit()
  //    <<
  //    std::endl;
  std::cout << "\tcode range size in bytes: "
            << create_params.constraints.code_range_size() << std::endl;
  std::cout << "\tmax old generation size in bytes: "
            << create_params.constraints.max_old_generation_size_in_bytes()
            << std::endl;
  std::cout << "\tmax young generation size in bytes: "
            << create_params.constraints.max_young_generation_size_in_bytes()
            << std::endl;
  std::cout << "\tinitial old generation size in bytes"
            << create_params.constraints.initial_old_generation_size_in_bytes()
            << std::endl;
  std::cout
      << "\tinitial young generation size in bytes: "
      << create_params.constraints.initial_young_generation_size_in_bytes()
      << std::endl;
}

void Motor::RunScript(const char* jsFilePath) {
  char* js = PackageManager::GetInstance()->GetIOPack()->readFile(jsFilePath);
  if (js == NULL) {
    return;
  }
  auto global = GlobalPack::New(isolate);
  v8::Local<v8::Context> context =
      v8::Context::New(isolate, NULL, global->GetGlobalObject());
  v8::Context::Scope context_scope(context);

  PackageManager::GetInstance()->SetGlobalPack(global);
  PackageManager::GetInstance()->SetIOPack(IOPack::New(isolate));
  PackageManager::GetInstance()->SetLogPack(LogPack::New(isolate));

  v8::Local<v8::String> source =
      v8::String::NewFromUtf8(isolate, js, v8::NewStringType::kNormal)
          .ToLocalChecked();

  v8::Local<v8::Script> script =
      v8::Script::Compile(context, source).ToLocalChecked();

  v8::TryCatch trycatch(isolate);
  v8::MaybeLocal<v8::Value> v = script->Run(context);
  if (v.IsEmpty()) {
    v8::Local<v8::Value> exception = trycatch.Exception();
    v8::String::Utf8Value exception_str(isolate, exception);
    std::cout << *exception_str << std::endl;
  }
}

//--------------------------- public ---------------------------

void Motor::Initialize(const char* icuExecPath,
                       const char* startupDirPath,
                       v8::Platform* platform,
                       const char* icuDataFile,
                       const char* snapshot_blob) {
  v8::V8::InitializeICUDefaultLocation(icuExecPath, icuDataFile);

  if (snapshot_blob == nullptr) {
    v8::V8::InitializeExternalStartupData(startupDirPath);
  } else {
    v8::V8::InitializeExternalStartupDataFromFile(snapshot_blob);
  }

  if (platform == nullptr) {
    platformPtr = v8::platform::NewDefaultPlatform();
    v8::V8::InitializePlatform(platformPtr.get());
  } else {
    v8::V8::InitializePlatform(platform);
  }
  v8::V8::Initialize();
}

void Motor::Startup(int argc, char* argv[]) {
  if (argc <= 1) {
    PrintInfo();
    return;
  }

  create_params.array_buffer_allocator =
      v8::ArrayBuffer::Allocator::NewDefaultAllocator();

  isolate = v8::Isolate::New(create_params);

  v8::Isolate::Scope isolate_scope(isolate);
  v8::HandleScope handle_scope(isolate);
  RunScript(argv[1]);
  return;
}

void Motor::Shutdown() {
  isolate->Dispose();
  v8::V8::Dispose();
  v8::V8::ShutdownPlatform();
  //  delete create_params.array_buffer_allocator;
}

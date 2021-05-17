//
//  Motor.hpp
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//

#ifndef Motor_hpp
#define Motor_hpp

#include "libplatform/libplatform.h"
#include "v8.h"

namespace Sample {

class Motor {
 private:
  v8::Isolate* isolate;
  v8::Isolate::CreateParams params;
  //  std::vector<BasePack*> packs;
  void PrintInfo();
  void InitPack();
  void RunScript(const char* jsFilePath);

 public:
  void Initialize(const char* icuExecPath,
                  const char* startupDirPath,
                  v8::Platform* platform = nullptr,
                  const char* icuDataFile = nullptr,
                  const char* snapshot_blob = nullptr);
  void Startup(int argc, char* argv[]);
  void Shutdown();
};

}  // namespace Sample

#endif /* Motor_hpp */

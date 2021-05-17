//
//  PackageManager.h
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//

#ifndef PackageManager_hpp
#define PackageManager_hpp

#include "Packages.h"

namespace Sample {

class PackageManager {
 private:
  static PackageManager* m_pInstance;
  GlobalPack* globalP;
  IOPack* ioP;
  LogPack* logP;

 public:
  static PackageManager* GetInstance();
  GlobalPack* GetGlobalPack();
  void SetGlobalPack(GlobalPack* pack);
  IOPack* GetIOPack();
  void SetIOPack(IOPack* pack);
  LogPack* GetLogPack();
  void SetLogPack(LogPack* pack);
};
}  // namespace Sample

#endif /* PackageManager_h */

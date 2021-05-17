//
//  PackageManager.cpp
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//

#include <stdio.h>

#include "PackageManager.hpp"

using namespace Sample;

PackageManager* PackageManager::m_pInstance = NULL;

PackageManager* PackageManager::GetInstance() {
  if (PackageManager::m_pInstance == NULL)
    PackageManager::m_pInstance = new PackageManager();
  return PackageManager::m_pInstance;
};

GlobalPack* PackageManager::GetGlobalPack() {
  return globalP;
};
void PackageManager::SetGlobalPack(GlobalPack* pack) {
  globalP = pack;
}
IOPack* PackageManager::GetIOPack() {
  return ioP;
};
void PackageManager::SetIOPack(IOPack* pack) {
  ioP = pack;
};
LogPack* PackageManager::GetLogPack() {
  return logP;
};
void PackageManager::SetLogPack(LogPack* pack) {
  logP = pack;
};

//
//  IOPack.hpp
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//

#ifndef IOPack_hpp
#define IOPack_hpp

#include <v8.h>
#include <cstdio>
#include "BasePack.h"

namespace Sample {
class IOPack : public BasePack {
 public:
  virtual void Initialize(v8::Isolate* isolate);
  ~IOPack();

  static IOPack* New(v8::Isolate* isolate);

  char* readFile(const char* path);
};

}  // namespace Sample

#endif /* IOPack_hpp */

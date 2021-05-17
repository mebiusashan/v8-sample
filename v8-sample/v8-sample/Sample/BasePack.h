//
//  BasePack.h
//  v8-sample
//
//  Created by ashan on 2021/5/17.
//

#ifndef BasePack_h
#define BasePack_h

#include "v8.h"

namespace Sample {
class BasePack {
 public:
  virtual void Initialize(v8::Isolate* isolate) = 0;
};
}  // namespace Sample

#endif /* BasePack_h */

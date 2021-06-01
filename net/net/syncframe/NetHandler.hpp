//
//  NetHandler.hpp
//  net
//
//  Created by ashan on 2021/5/28.
//

#ifndef NetHandler_hpp
#define NetHandler_hpp

namespace syncframe {

struct NetHandlerCallbackInfo {};

typedef void (*NetHandlerCallback)(const NetHandlerCallbackInfo& info);

class NetHandler {
 private:
  NetHandlerCallback NetErrorCallback;
  NetHandlerCallback LoginCallback;
  NetHandlerCallback MatchCallback;
  NetHandlerCallback ReconnectRoomCallback;
  NetHandlerCallback NetConnectCallback;
  NetHandlerCallback NetCloseCallback;

 public:
  void SetNetErrorCallback(NetHandlerCallback callback = nullptr);
  void SetLoginCallback(NetHandlerCallback callback = nullptr);
  void SetMatchCallback(NetHandlerCallback callback = nullptr);
  void SetReconnectRoomCallback(NetHandlerCallback callback = nullptr);
  void SetNetConnectCallback(NetHandlerCallback callback = nullptr);
  void SetNetCloseCallback(NetHandlerCallback callback = nullptr);
};
}  // namespace syncframe

#endif /* NetHandler_hpp */

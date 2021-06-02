//
//  Context.hpp
//  net
//
//  Created by ashan on 2021/5/28.
//

#ifndef Context_hpp
#define Context_hpp

#include "NetHandler.hpp"
#include "asio.hpp"

namespace syncframe {

struct ContextConfig {
  const char* protocol;
  const char* host;
  const char* port;
};

struct RoomInfo {};

class Context {
 private:
  int _uid;
  ContextConfig _config;
  NetHandler* netHandler;
  asio::io_context ioServer;
  void getServer();
  void getAPIList();
  void getToken();

 public:
  Context(int uid, const ContextConfig& config);
  ~Context();

  void SetNetHandler(NetHandler* handler);
  void Init();
  void Login();
  void MatchSign();
  void MatchSignCancel();
  void ReconnectRoom();

  void Close();
};

}  // namespace syncframe

#endif /* Context_hpp */

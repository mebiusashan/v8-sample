//
//  Context.cpp
//  net
//
//  Created by ashan on 2021/5/28.
//

#include "Context.hpp"
#include "message.pb.h"

#include "Macros.h"

#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include "NetHelper.hpp"
#include "asio.hpp"
#include "asio/ssl.hpp"

using namespace syncframe;

Context::Context(int uid, const ContextConfig& config) {
  if (uid < SF_MIN_UID || uid > SF_MAX_UID) {
    //    std::cout << "Illegal user ID" << std::endl;
    throw "Illegal user ID";
    return;
  }
  _uid = uid;
  _config = config;
}

Context::~Context() {
  // TODO
}

void Context::SetNetHandler(NetHandler* handler) {
  netHandler = handler;
}

void Context::Init() {
  std::string get_server_reponse_data;

  int rel =
      NetHelper::RequestGet(_config.host, _config.port, SF_NET_ROUTE_GETSERVER,
                            "format=proto", get_server_reponse_data);
  if (rel != 0) {
    std::cerr << "server error code: " << rel << std::endl;
  } else {
    CfgServer data;
    if(!data.ParseFromString(get_server_reponse_data)){
        std::cout << "protobuf data parse faild." << std::endl;
        return;
    }else{
        std::cout << data.listenip() << " " << data.wsuri() << std::endl;
        //   TODO 处理 getserver 数据
    }

  }


  std::string apilist_repose_data;
  rel = NetHelper::RequestGet(_config.host, _config.port, SF_NET_ROUTE_APILIST,
                              "format=proto", apilist_repose_data);
  if (rel != 0) {
    std::cerr << "server error code: " << rel << std::endl;
  } else {
      CfgProtocolActions actions;
      if(!actions.ParseFromString(apilist_repose_data)){
          std::cout << "protobuf data parse faild." << std::endl;
          return;
      }else {
          std::cout << actions.client().size() << std::endl;
          // TODO 处理 apilist 数据
      }

  }
}

void Context::Login() {}

void Context::MatchSign() {}

void Context::MatchSignCancel() {}

void Context::ReconnectRoom() {}

void Context::Close() {}

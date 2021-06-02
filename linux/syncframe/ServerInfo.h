//
//  ServerInfo.h
//  net
//
//  Created by ashan on 2021/5/28.
//

#ifndef ServerInfo_h
#define ServerInfo_h

namespace syncframe {
struct ServerInfo {
  char* ListenIp;
  char* OutIp;
  char* Port;
  char* UdpPort;
  // Mylog
  int Protocol;
  char* WsUri;
  int ContentType;

  char* LoginAuthType;
  char* LoginAuthSecretKey;

  int MaxClientConnNum;
  int MsgContentMax;
  long int IOTimeout;
  // Cxt
  int MainChan;
  int ConnTimeout;

  int MapSize;
  int RoomPeople;
  int RoomTimeout;
  int OffLineWaitTime;

  int LockMode;
  int FPS;
  int RoomReadyTimeout;
  int Store;
};
}  // namespace syncframe

#endif /* ServerInfo_h */


#include "syncframe/SyncFrame.h"

using namespace syncframe;
int main(int argc, const char* argv[]) {
  ContextConfig config;
  config.host = "39.106.65.76";
  config.port = "3333";
  Context context(11, config);
  context.Init();

  return 0;
}

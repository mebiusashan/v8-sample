#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Sample/sample.h"
#include "libplatform/libplatform.h"
#include "v8.h"

int main(int argc, char* argv[]) {
  Sample::Motor* motor = new Sample::Motor();
  motor->Initialize(argv[0], argv[0]);
  motor->Startup(argc, argv);
  return 0;
}

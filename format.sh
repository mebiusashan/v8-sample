#! /bin/bash

find ./v8-sample/v8-sample -name "*.hpp" | xargs clang-format #--style=Chromium -i
find ./v8-sample/v8-sample -name "*.cpp" | xargs clang-format #--style=Chromium -i
find ./v8-sample/v8-sample -name "*.h" | xargs clang-format #--style=Chromium -i

#find ./net/net -name "*.hpp" | xargs clang-format --style=Chromium -i
#find ./net/net -name "*.cpp" | xargs clang-format --style=Chromium -i
#find ./net/net -name "*.h" | xargs clang-format --style=Chromium -i

#find ./linux -name "*.hpp" | xargs clang-format --style-Chromium -i
#find ./linux -name "*.cpp" | xargs clang-format --style-Chromium -i
#find ./linux -name "*.h" | xargs clang-format --style-Chromium -i

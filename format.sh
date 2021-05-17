#! /bin/bash

find ./v8-sample/v8-sample -name "*.hpp" | xargs clang-format --style=Chromium -i
find ./v8-sample/v8-sample -name "*.cpp" | xargs clang-format --style=Chromium -i
find ./v8-sample/v8-sample -name "*.h" | xargs clang-format --style=Chromium -i

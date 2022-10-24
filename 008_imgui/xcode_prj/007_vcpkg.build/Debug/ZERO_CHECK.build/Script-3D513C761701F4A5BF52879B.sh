#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/kenlee/workspace/cpp/cmake/008_imgui/xcode_prj
  make -f /Users/kenlee/workspace/cpp/cmake/008_imgui/xcode_prj/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/kenlee/workspace/cpp/cmake/008_imgui/xcode_prj
  make -f /Users/kenlee/workspace/cpp/cmake/008_imgui/xcode_prj/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/kenlee/workspace/cpp/cmake/008_imgui/xcode_prj
  make -f /Users/kenlee/workspace/cpp/cmake/008_imgui/xcode_prj/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/kenlee/workspace/cpp/cmake/008_imgui/xcode_prj
  make -f /Users/kenlee/workspace/cpp/cmake/008_imgui/xcode_prj/CMakeScripts/ReRunCMake.make
fi


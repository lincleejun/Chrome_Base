// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_EVENT_TYPES_H
#define BASE_EVENT_TYPES_H
#pragma once

#include "build/build_config.h"

#if defined(OS_WIN)
#include <windows.h>
#elif defined(USE_WAYLAND)
namespace base {
namespace wayland {
union WaylandEvent;
}
}
#elif defined(USE_X11)
typedef union _XEvent XEvent;
#endif

namespace base {

typedef MSG NativeEvent;


} // namespace base

#endif  // BASE_EVENT_TYPES_H

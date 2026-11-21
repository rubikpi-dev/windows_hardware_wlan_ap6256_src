/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once
#if defined(AP6256_ENABLE_WDI) || !defined(AP6256_ALLOW_STUB_NETADAPTER)
#error "Select the explicit diagnostic configuration in the build."
#endif
#include <wdf.h>

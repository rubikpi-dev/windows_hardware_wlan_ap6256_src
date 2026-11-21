/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once
#include "ap6256.h"

_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS Ap6256PnoPrepareInitialDelay(_In_ PAP6256_DEVICE_CONTEXT Ctx,
    _Inout_updates_bytes_(Length) PUCHAR Image, _In_ ULONG Length,
    _Out_ BOOLEAN* Applied);

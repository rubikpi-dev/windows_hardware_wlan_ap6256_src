/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once
#include "osal.h"

#define AP6256_WATCHDOG_IDLE_MS 250u
#define AP6256_WATCHDOG_ACTIVE_MS 25u
#define AP6256_WATCHDOG_ACTIVE_WINDOW 10000000ull

typedef struct _AP6256_WATCHDOG {
    AP6256_TIMER Timer;
    KSPIN_LOCK Lock;
    BOOLEAN Enabled;
    ULONG DeviceId;
    LONG LastIsr;
    volatile LONG PollRequested;
    volatile LONG PollIsr;
    volatile LONGLONG LastRecovery;
    volatile LONGLONG Polls;
    volatile LONGLONG Recoveries;
    volatile LONGLONG ReadFailures;
    ULONG ConsecutiveFailures;
} AP6256_WATCHDOG;

struct _AP6256_DEVICE_CONTEXT;
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS Ap6256WatchdogCreate(_In_ struct _AP6256_DEVICE_CONTEXT* Ctx);
_IRQL_requires_max_(PASSIVE_LEVEL)
VOID Ap6256WatchdogStart(_In_ struct _AP6256_DEVICE_CONTEXT* Ctx);
_IRQL_requires_max_(PASSIVE_LEVEL)
VOID Ap6256WatchdogStop(_In_ struct _AP6256_DEVICE_CONTEXT* Ctx);
_IRQL_requires_max_(PASSIVE_LEVEL)
VOID Ap6256WatchdogDestroy(_In_ struct _AP6256_DEVICE_CONTEXT* Ctx);
_IRQL_requires_max_(PASSIVE_LEVEL)
BOOLEAN Ap6256WatchdogCheckPending(_In_ struct _AP6256_DEVICE_CONTEXT* Ctx);

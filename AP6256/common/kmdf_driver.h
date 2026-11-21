/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once
#include "ap6256.h"

EVT_WDF_DRIVER_DEVICE_ADD Ap6256EvtDeviceAdd;
EVT_WDF_DEVICE_PREPARE_HARDWARE Ap6256EvtPrepareHardware;
EVT_WDF_DEVICE_RELEASE_HARDWARE Ap6256EvtReleaseHardware;
EVT_WDF_DEVICE_D0_ENTRY Ap6256EvtD0Entry;
EVT_WDF_DEVICE_D0_EXIT Ap6256EvtD0Exit;

_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS Ap6256ModelDeviceInitConfig(_In_ PWDFDEVICE_INIT DeviceInit);

_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS Ap6256ModelDeviceCreateAdapter(_In_ PAP6256_DEVICE_CONTEXT Ctx);

EVT_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED Ap6256EvtD0EntryPostInterruptsEnabled;
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS Ap6256ModelHardwareReady(_In_ PAP6256_DEVICE_CONTEXT Ctx);

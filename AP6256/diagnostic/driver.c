/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#include "kmdf_driver.h"

_Use_decl_annotations_
NTSTATUS Ap6256ModelDeviceInitConfig(PWDFDEVICE_INIT DeviceInit)
{
    UNREFERENCED_PARAMETER(DeviceInit);
    return STATUS_SUCCESS;
}

_Use_decl_annotations_
NTSTATUS Ap6256ModelDeviceCreateAdapter(PAP6256_DEVICE_CONTEXT Ctx)
{
    UNREFERENCED_PARAMETER(Ctx);
    return STATUS_SUCCESS;
}

_Use_decl_annotations_
NTSTATUS Ap6256ModelHardwareReady(PAP6256_DEVICE_CONTEXT Ctx)
{
    UNREFERENCED_PARAMETER(Ctx);
    return STATUS_SUCCESS;
}

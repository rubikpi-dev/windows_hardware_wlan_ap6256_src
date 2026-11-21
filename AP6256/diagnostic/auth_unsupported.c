/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#include "ft_firmware.h"

_Use_decl_annotations_
NTSTATUS Ap6256PrepareFt(PAP6256_DEVICE_CONTEXT Ctx,
    PUCHAR* Image, PULONG Length, BOOLEAN* Applied)
{
    *Applied = FALSE;
    UNREFERENCED_PARAMETER(Ctx);
    UNREFERENCED_PARAMETER(Image);
    UNREFERENCED_PARAMETER(Length);
    return STATUS_SUCCESS;
}

#include "owe_firmware.h"

_Use_decl_annotations_
NTSTATUS Ap6256PrepareOwe(PAP6256_DEVICE_CONTEXT Ctx,
    PUCHAR* Image, PULONG Length, BOOLEAN* Applied)
{
    *Applied = FALSE;
    UNREFERENCED_PARAMETER(Ctx);
    UNREFERENCED_PARAMETER(Image);
    UNREFERENCED_PARAMETER(Length);
    return STATUS_SUCCESS;
}

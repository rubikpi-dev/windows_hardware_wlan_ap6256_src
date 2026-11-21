/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once
#include "ap6256.h"

_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS Ap6256PrepareNativeManagement(_In_ PAP6256_DEVICE_CONTEXT Ctx,
    _Inout_updates_bytes_(Length) PUCHAR Image, _In_ ULONG Length,
    _Out_ BOOLEAN* Applied);

static __inline BOOLEAN Ap6256OwnsManagementFrame(
    _In_ PAP6256_DEVICE_CONTEXT Ctx,
    _In_reads_bytes_opt_(Length) const UCHAR* Body, _In_ ULONG Length,
    _In_ BOOLEAN Response)
{
    if (!Ctx->FirmwareNativeManagement || Body == NULL || Length < 2)
        return FALSE;
    return Body[0] == 5 && Body[1] == (Response ? 1 : 0);
}

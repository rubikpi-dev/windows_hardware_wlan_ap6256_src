/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once
#include <ntddk.h>

_When_(PoolType == PagedPool, _IRQL_requires_max_(APC_LEVEL))
_When_(PoolType != PagedPool, _IRQL_requires_max_(DISPATCH_LEVEL))
_Must_inspect_result_
static __forceinline PVOID Ap6256AllocatePool(
    _In_ POOL_TYPE PoolType, _In_ SIZE_T NumberOfBytes, _In_ ULONG Tag)
{
    PVOID buffer = ExAllocatePoolWithTag(PoolType, NumberOfBytes, Tag);
    if (buffer != NULL) {
        RtlZeroMemory(buffer, NumberOfBytes);
    }
    return buffer;
}

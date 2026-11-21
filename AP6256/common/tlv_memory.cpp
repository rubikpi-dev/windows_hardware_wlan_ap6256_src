/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#include <ntddk.h>
#include "pool.h"

static const ULONG AP6256_TLV_POOL_TAG = 0x74353641u;

void* __cdecl operator new(size_t Size) noexcept
{
    return Ap6256AllocatePool(NonPagedPoolNx, Size, AP6256_TLV_POOL_TAG);
}

void* __cdecl operator new(size_t Size, ULONG_PTR AllocationContext) noexcept
{

    UNREFERENCED_PARAMETER(AllocationContext);
    return operator new(Size);
}

void __cdecl operator delete(void* Buffer) noexcept
{
    if (Buffer != nullptr) {
        ExFreePoolWithTag(Buffer, AP6256_TLV_POOL_TAG);
    }
}

void __cdecl operator delete[](void* Buffer) noexcept
{
    operator delete(Buffer);
}

void __cdecl operator delete(void* Buffer, size_t Size) noexcept
{

    UNREFERENCED_PARAMETER(Size);
    operator delete(Buffer);
}

void __cdecl operator delete[](void* Buffer, size_t Size) noexcept
{
    operator delete(Buffer, Size);
}

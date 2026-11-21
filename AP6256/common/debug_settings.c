/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#include "osal.h"
#include "trace.h"

_Use_decl_annotations_
VOID Ap6256TraceLoadDebugSettings(PDEVICE_OBJECT Pdo)
{
    union { ULONG Dword; WCHAR String[2]; } value = {0};
    ULONG length = 0, type = REG_NONE, level = AP6256_DEBUG_LOG_DISABLED;
    NTSTATUS status;
    if (Pdo != NULL) {
        status = Ap6256RegQueryValue(Pdo, L"DebugLogLevel", sizeof(value),
                                     &value, &length, &type);
        if (NT_SUCCESS(status) && length == sizeof(value)) {
            if (type == REG_DWORD && value.Dword <= AP6256_DEBUG_LOG_VERBOSE)
                level = value.Dword;
            else if (type == REG_SZ && value.String[0] >= L'0' &&
                     value.String[0] <= L'4' && value.String[1] == L'\0')
                level = (ULONG)(value.String[0] - L'0');
        }
    }
    Ap6256TraceSetDebugLevel(level);
}

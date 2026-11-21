/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#include "model.h"

BOOLEAN Ap6256ModelRouteAuthEvent(PAP6256_DEVICE_CONTEXT Ctx, const BRCMF_EVENT_MSG* evt,
                                  UINT32 eventType, UINT32 status, const UCHAR* eventBody,
                                  ULONG eventBodyLen)
{
    UNREFERENCED_PARAMETER(Ctx);
    UNREFERENCED_PARAMETER(evt);
    UNREFERENCED_PARAMETER(eventType);
    UNREFERENCED_PARAMETER(status);
    UNREFERENCED_PARAMETER(eventBody);
    UNREFERENCED_PARAMETER(eventBodyLen);

    return FALSE;
}

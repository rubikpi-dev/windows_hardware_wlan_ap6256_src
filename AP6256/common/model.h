/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once
#include "ap6256.h"

NTSTATUS Ap6256ModelPrepareConcurrent(PAP6256_DEVICE_CONTEXT Ctx);
BOOLEAN Ap6256ModelRouteGroupEvent(PAP6256_DEVICE_CONTEXT Ctx, const BRCMF_EVENT_MSG* evt,
                                   UINT32 eventType, UINT32 status, const UCHAR* eventBody,
                                   ULONG eventBodyLen);
BOOLEAN Ap6256ModelRouteAuthEvent(PAP6256_DEVICE_CONTEXT Ctx, const BRCMF_EVENT_MSG* evt,
                                  UINT32 eventType, UINT32 status, const UCHAR* eventBody,
                                  ULONG eventBodyLen);
VOID Ap6256ModelAssociationEvent(PAP6256_DEVICE_CONTEXT Ctx, const BRCMF_EVENT_MSG* evt,
                                 UINT32 eventType, const UCHAR* eventBody, ULONG eventBodyLen);
VOID Ap6256ModelDfsStopEvent(PAP6256_DEVICE_CONTEXT Ctx, const BRCMF_EVENT_MSG* evt,
                             UINT32 eventType, UINT32 status, const UCHAR* eventBody,
                             ULONG eventBodyLen);
VOID Ap6256ModelWlfcAbortProgress(PAP6256_DEVICE_CONTEXT Ctx);
VOID Ap6256ModelRecordFirmwareCrash(PAP6256_DEVICE_CONTEXT Ctx);

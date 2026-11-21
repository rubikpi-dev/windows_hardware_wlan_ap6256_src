/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once

#define AP6256_ASSOC_FAILURE_MAX 2048u

typedef struct _AP6256_ASSOC_FAILURE {
    LONG ConnectGeneration;
    UINT32 FirmwareGeneration;
    ULONG Length;
    BOOLEAN ReAssociation;
    UCHAR Peer[6];
    UCHAR Response[AP6256_ASSOC_FAILURE_MAX];
} AP6256_ASSOC_FAILURE;

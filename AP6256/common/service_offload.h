/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once
#include "service_wire.h"
#define AP6256_SERVICE_PEER_MAX 8u
typedef struct _AP6256_SERVICE_STATE {
    BOOLEAN Active, QueryPending, ScanFinished, HashIeInstalled;
    BOOLEAN QueryDone, QueryFailed;
    ULONG QueryCount, PeerCount, PeerIndex, QueryIndex, Generation, NextGeneration;
    AP6256_SERVICE_ENTRY Queries[AP6256_SERVICE_MAX];
    AP6256_BSS Peers[AP6256_SERVICE_PEER_MAX];
    UCHAR Response[AP6256_SERVICE_RESPONSE_MAX], Dialog, Fragment;
    ULONG ResponseLength;
    ULONGLONG Deadline, QueryDeadline;
    ULONG AdvertisementCount, AdvertisementUpdate;
    AP6256_SERVICE_ENTRY Advertisements[AP6256_SERVICE_MAX];
} AP6256_SERVICE_STATE;

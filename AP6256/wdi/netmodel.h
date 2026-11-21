/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once
#if !defined(AP6256_ENABLE_WDI)
#error "Select exactly the WDI frontend in the build."
#endif
#include <ndis.h>
#include <dot11wdi.h>

#include <wditypes.hpp>

#ifdef AP6256_WLAN_LEGACY_TLV
/* These wire values were unnamed in the older WLAN headers. */
#define WDI_AUTH_ALGO_UNKNOWN ((WDI_AUTH_ALGORITHM)0)
#define WDI_SCAN_TRIGGER_BEACON_REQUEST ((WDI_SCAN_TRIGGER)8)
#endif

#ifdef AP6256_WLAN_18362_TLV
/* Recognize newer wire values without advertising them to an older peer. */
#define WDI_AUTH_ALGO_WPA3_ENT_192 WDI_AUTH_ALGO_WPA3
#define WDI_AUTH_ALGO_OWE ((WDI_AUTH_ALGORITHM)10)
#define WDI_AUTH_ALGO_WPA3_ENT ((WDI_AUTH_ALGORITHM)11)
#define WDI_CIPHER_ALGO_GCMP_256 ((WDI_CIPHER_ALGORITHM)0x09)
#define WDI_CIPHER_ALGO_BIP_GMAC_256 ((WDI_CIPHER_ALGORITHM)0x0c)
#define WDI_VERSION_1_1_9 ((1 << 16) | (1 << 8) | 9)
#define WDI_VERSION_1_1_10 ((1 << 16) | (1 << 8) | 10)
#define WDI_SCAN_TRIGGER_FTM ((WDI_SCAN_TRIGGER)7)
#define AP6256_WDI_SAE_VERSION WDI_VERSION_1_1_8
#else
#define AP6256_WDI_SAE_VERSION WDI_VERSION_1_1_10
#endif

typedef struct _MLO_LINK_INFO {
    UINT32 LinkID;
    WDI_MAC_ADDRESS StaLinkAddress;
    WDI_MAC_ADDRESS APLinkAddress;
} MLO_LINK_INFO, *PMLO_LINK_INFO;

C_ASSERT(sizeof(MLO_LINK_INFO) == sizeof(UINT32) + 2 * sizeof(WDI_MAC_ADDRESS));
#include "wdi_tal.h"

#include "sae_wdi.h"

typedef PNDIS_OID_REQUEST AP6256_REQUEST;

_IRQL_requires_max_(DISPATCH_LEVEL)
UINT16 Ap6256RequestGetMessageId(_In_ AP6256_REQUEST Request);

typedef AP6256_TIMER AP6256_TIMER_OBJ;
typedef AP6256_WORKITEM AP6256_WORKITEM_OBJ;

#define AP6256_TIMER_OK(t) Ap6256TimerValid(&(t))
#define AP6256_TIMER_START(t, ms) Ap6256TimerStart(&(t), (ms))
#define AP6256_TIMER_STOP(t, wait) Ap6256TimerStop(&(t), (wait))
#define AP6256_CMDQ_KICK(w) Ap6256WorkItemEnqueue(&(w)->CommandWorkItem)
#define AP6256_CMDQ_OK(w) Ap6256WorkItemValid(&(w)->CommandWorkItem)
#define AP6256_LINKQ_KICK(w) Ap6256WorkItemEnqueue(&(w)->LinkWorkItem)
#define AP6256_LINKQ_OK(w) Ap6256WorkItemValid(&(w)->LinkWorkItem)
#define AP6256_ACTIONFRAME_COMPLETE_KICK(w) Ap6256WorkItemEnqueue(&(w)->ActionFrameCompleteWorker)

#ifndef AP6256_WDI_VERSION
#define AP6256_WDI_VERSION WDI_VERSION_LATEST
#endif

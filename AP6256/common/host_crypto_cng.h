/*
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) rubikpi-dev Authors. All Rights Reserved.
 * See ../LICENSES/BSD-3-Clause.txt.
 */

#pragma once
#include "host_cipher_frame.h"

long Ap6256HostCryptoOpen(void** Provider, AP6256_HC_U32* KeyObjectBytes);
long Ap6256HostCryptoClose(void* Provider);

long Ap6256HostCryptoFingerprint(const AP6256_HC_U8 Key[32], AP6256_HC_U8 Digest[32]);
long Ap6256HostCryptoCreateKey(void* Provider, const AP6256_HC_U8 Key[32],
    AP6256_HC_U8* Object, AP6256_HC_U32 ObjectBytes, void** Handle);
long Ap6256HostCryptoDestroyKey(void* Handle, AP6256_HC_U8* Object,
    AP6256_HC_U32 ObjectBytes);
int Ap6256HostCryptoCrypt(void* Context, int Encrypt,
    const AP6256_HC_U8 Nonce[12], const AP6256_HC_U8* Aad,
    AP6256_HC_U32 AadLength, const AP6256_HC_U8* Input,
    AP6256_HC_U32 InputLength, AP6256_HC_U8* Output, AP6256_HC_U8 Tag[16]);

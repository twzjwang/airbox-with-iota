/*
 * Copyright (c) 2018 IOTA Stiftung
 * https://github.com/iotaledger/entangled
 *
 * Refer to the LICENSE file for licensing information
 * 
 * Modifications copyright (c) Zan-Jun Wang
 */

#ifndef __ISS_H_
#define __ISS_H_

#include <string.h>
#include "add.h"
#include "trit.h"
#define HASH_STATE Curl
#define HASH_LENGTH 243
#define HASH_PREFIX curl

#define ISS_FRAGMENTS 27
#define ISS_KEY_LENGTH HASH_LENGTH *ISS_FRAGMENTS

#define CAT(A, ...) _CAT(A, __VA_ARGS__)
#define _CAT(A, ...) A##__VA_ARGS__

#define _ISS_PREFIX(A) CAT(CAT(CAT(iss_, HASH_PREFIX), _), A)

#ifdef __cplusplus
extern "C" {
#endif

int _ISS_PREFIX(subseed)(trit_t const *const seed, trit_t *const out,
                         int64_t const index, HASH_STATE *const c);

int _ISS_PREFIX(key)(trit_t const *const subseed, trit_t *key,
                     size_t const key_length, HASH_STATE *const c);

int _ISS_PREFIX(key_digest)(trit_t *key, trit_t *const digest,
                            size_t const key_length, HASH_STATE *const c);

int _ISS_PREFIX(address)(trit_t *const address, trit_t const *const digest,
                         size_t const length, HASH_STATE *const c);

int _ISS_PREFIX(signature)(trit_t *sig, trit_t const *const hash,
                           size_t const start_offset, trit_t const *const key,
                           size_t const key_len, HASH_STATE *const c);

int _ISS_PREFIX(sig_digest)(trit_t *dig, trit_t const *const hash,
                            size_t const offset, trit_t *sig,
                            size_t const sig_len, HASH_STATE *const c);

int signed_window(trit_t const *hash);

#ifdef __cplusplus
}
#endif

#undef _ISS_PREFIX
#undef CAT
#undef _CAT

#endif

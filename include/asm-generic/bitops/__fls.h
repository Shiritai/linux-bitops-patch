/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_GENERIC_BITOPS___FLS_H_
#define _ASM_GENERIC_BITOPS___FLS_H_

#include <asm/types.h>

#include <asm-generic/bitops/ffls_gen.h>

#define __unsigned_long unsigned long
/**
 * __fls - find last (most-significant) set bit in a long word
 * @word: the word to search
 *
 * Undefined if no set bit exists, so code should check against 0 first.
 */
gen_fls(__unsigned_long, __unsigned_long, __FFLS_START_INDEX_FROM_ZERO, __fls);
#undef __unsigned_long

#endif /* _ASM_GENERIC_BITOPS___FLS_H_ */

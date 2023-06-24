/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_GENERIC_BITOPS_FLS64_H_
#define _ASM_GENERIC_BITOPS_FLS64_H_

#include <asm/types.h>
#include <asm-generic/bitops/ffls_gen.h>

/**
 * fls64 - find last set bit in a 64-bit word
 * @x: the word to search
 *
 * This is defined in a similar way as the libc and compiler builtin
 * ffsll, but returns the position of the most significant set bit.
 *
 * fls64(value) returns 0 if value is 0 or the position of the last
 * set bit if value is nonzero. The last (most significant) bit is
 * at position 64.
 */
#ifdef BITS_PER_LONG
gen_fls(__u64, int, __FFLS_START_INDEX_FROM_ONE, fls64);
#else
#error BITS_PER_LONG not 32 or 64
#endif

#endif /* _ASM_GENERIC_BITOPS_FLS64_H_ */

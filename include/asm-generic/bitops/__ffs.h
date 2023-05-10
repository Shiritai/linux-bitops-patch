/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_GENERIC_BITOPS___FFS_H_
#define _ASM_GENERIC_BITOPS___FFS_H_

#include <asm/types.h>

#include <asm-generic/bitops/ffls_gen.h>

/**
 * __ffs - find first bit in word.
 * @word: The word to search
 *
 * Undefined if no bit exists, so code should check against 0 first.
 */
gen_ffs(unsigned long, unsigned long, __FFLS_START_INDEX_FROM_ZERO, __ffs);

#endif /* _ASM_GENERIC_BITOPS___FFS_H_ */

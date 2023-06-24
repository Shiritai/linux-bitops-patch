/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_GENERIC_BITOPS_FLS_H_
#define _ASM_GENERIC_BITOPS_FLS_H_

#include <asm-generic/bitops/ffls_gen.h>

/**
 * fls - find last (most-significant) bit set
 * @x: the word to search
 *
 * This is defined the same way as ffs.
 * Note fls(0) = 0, fls(1) = 1, fls(0x80000000) = 32.
 */
gen_fls(unsigned int, int, __FFLS_START_INDEX_FROM_ONE, fls);

#endif /* _ASM_GENERIC_BITOPS_FLS_H_ */

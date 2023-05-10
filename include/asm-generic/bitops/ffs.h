/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_GENERIC_BITOPS_FFS_H_
#define _ASM_GENERIC_BITOPS_FFS_H_

#include <asm-generic/bitops/ffls_gen.h>

/**
 * ffs - find first bit set
 * @x: the word to search
 *
 * This is defined the same way as
 * the libc and compiler builtin ffs routines, therefore
 * differs in spirit from ffz (man ffs).
 */
gen_ffs(unsigned int, int, __FFLS_START_INDEX_FROM_ONE, ffs);

#endif /* _ASM_GENERIC_BITOPS_FFS_H_ */

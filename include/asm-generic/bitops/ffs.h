/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_GENERIC_BITOPS_FFS_H_
#define _ASM_GENERIC_BITOPS_FFS_H_

#include <asm-generic/bitops/ffls_gen.h>

#define __unsigned_int unsigned int
/**
 * ffs - find first bit set
 * @x: the word to search
 *
 * This is defined the same way as
 * the libc and compiler builtin ffs routines, therefore
 * differs in spirit from ffz (man ffs).
 */
gen_ffs(__unsigned_int, int, __FFLS_START_INDEX_FROM_ONE, ffs);
#undef __unsigned_int

#endif /* _ASM_GENERIC_BITOPS_FFS_H_ */

#ifndef _ASM_GENERIC_BITOPS_SOFTWARE_FFS_FLS_GEN_H_
#define _ASM_GENERIC_BITOPS_SOFTWARE_FFS_FLS_GEN_H_

#include <asm/types.h>

/**
 * Software implementation of Find {first/last} set function series.
 *
 * Context: Generate all functions with consistent implementation without
 *          undefine behavior (all input range are considered and implemented). It is
 *          aimed to remove all magic numbers and bad smells of fls function series since
 *          original implementation in files: __fls.h, fls.h, fls64.h, bitops.h are
 *          almost the duplicates of each others.
 *          Current implementation is suitable for input type within 64 bits.
 */

#define __FFLS_START_INDEX_FROM_ZERO 0
#define __FFLS_START_INDEX_FROM_ONE 1

/**
 * Hidden generator of ffs to hide evaluation of size of type
 */
#define __gen_ffs(in_type, out_type, start_from, fn_name, bit_len) \
    static __always_inline out_type fn_name(in_type x)             \
    {                                                              \
        int bits, shift;                                           \
        in_type mask;                                              \
        if (!x)                                                    \
            return 0;                                              \
        bits = start_from;                                         \
        shift = bit_len >> 1;                                      \
        mask = (in_type) ~(0xFFFFFFFFFFFFFFFF << shift);           \
        /* unroll 6 times for 64 bits input */                     \
        /* no side effect if exceed possible unroll time */        \
        _Pragma("GCC unroll 6")                                    \
        do {                                                       \
            if (!(x & mask)) {                                     \
                bits += shift;                                     \
                x >>= shift;                                       \
            }                                                      \
            shift >>= 1;                                           \
            mask >>= shift;                                        \
        } while (shift);                                           \
        return bits;                                               \
    }

/**
 * gen_ffs() - Macro to generate function series of
 * ffs series - find first (least-significant) bit set.
 *
 * Generated function parameter:
 * @x: the object to search
 *
 * Macro arguments:
 * @in_type: input type of ffs
 * @out_type: output type of ffs
 * @start_from: starting index of generated ffs to generate both
 *              ffs series (return 1 ~ 64) and __ffs series (return 0 ~ 63)
 *
 *              Note if:
 *              start_from is __FFLS_START_INDEX_FROM_ZERO, then ffs(0) = 0,
 *                  ffs(1) = 0, ffs(object leads with 1) = sizeof object - 1.
 *              start_from is __FFLS_START_INDEX_FROM_ONE, then ffs(0) = 0,
 *                  ffs(1) = 1, ffs(object leads with 1) = sizeof object.
 * @fn_name: Function name to be generated
 */
#define gen_ffs(in_type, out_type, start_from, fn_name) \
    __gen_ffs(in_type, out_type, start_from, fn_name, (sizeof(in_type) * 8))

/**
 * Hidden generator of fls to hide evaluation of size of type
 */
#define __gen_fls(in_type, out_type, start_from, fn_name, bit_len) \
    static __always_inline out_type fn_name(in_type x)             \
    {                                                              \
        int bits, shift;                                           \
        in_type mask;                                              \
        if (!x)                                                    \
            return 0;                                              \
        shift = bit_len >> 1;                                      \
        bits = bit_len - 1 + start_from;                           \
        mask = (in_type) (0xFFFFFFFFFFFFFFFF << shift);            \
        /* unroll 6 times for 64 bits input */                     \
        /* no side effect if exceed possible unroll time */        \
        _Pragma("GCC unroll 6")                                    \
        do {                                                       \
            if (!(x & mask)) {                                     \
                bits -= shift;                                     \
                x <<= shift;                                       \
            }                                                      \
            shift >>= 1;                                           \
            mask <<= shift;                                        \
        } while (shift);                                           \
        return bits;                                               \
    }

/**
 * gen_fls() - Macro to generate function series of
 * fls series - find last (most-significant) bit set.
 *
 * Generated function parameter:
 * @x: the object to search
 *
 * Macro arguments:
 * @in_type: input type of fls
 * @out_type: output type of fls
 * @start_from: starting index of generated fls to generate both
 *              fls series (return 1 ~ 64) and __fls series (return 0 ~ 63)
 *
 *              Note if:
 *              start_from is __FFLS_START_INDEX_FROM_ZERO, then fls(0) = 0,
 *                  fls(1) = 0, fls(object leads with 1) = sizeof object - 1.
 *              start_from is __FFLS_START_INDEX_FROM_ONE, then fls(0) = 0,
 *                  fls(1) = 1, fls(object leads with 1) = sizeof object.
 * @fn_name: Function name to be generated
 */
#define gen_fls(in_type, out_type, start_from, fn_name) \
    __gen_fls(in_type, out_type, start_from, fn_name, (sizeof(in_type) * 8))

#endif /* _ASM_GENERIC_BITOPS_SOFTWARE_FFS_FLS_GEN_H_ */
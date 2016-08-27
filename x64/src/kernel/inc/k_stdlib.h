/* Copyright 2016 secXsQuared
 * Distributed under GPL license
 * See COPYING under root for details
 */

#ifndef _STD_LIB_H_
#define _STD_LIB_H_

#include "g_abi.h"
#include "g_type.h"

uint32_t KAPI rand( void );

void KAPI srand(uint32_t _seed );

void KAPI mrand(uint32_t max);

uint64_t KAPI ke_str_len(char const *str);

uint64_t KAPI ke_str_cmp(char const *str1, char const *str2);

void KAPI ke_mem_copy(void *src, void *dst, uint64_t size);

void KAPI ke_mem_move(void *src, void *dst, uint64_t size);

void KAPI ke_mem_set(void *src, int8_t const val, uint64_t size);

static inline uint64_t KAPI ke_align_down(uint64_t val, uint64_t alignment)
{
    return (val / alignment) * alignment;
}

static inline uint64_t KAPI ke_align_up(uint64_t val, uint64_t alignment)
{
    return ((((val) % (alignment)) == 0) ? (((val) / (alignment)) * (alignment)) : (
            (((val) / (alignment)) * (alignment)) + 1));
}

static inline uint64_t KAPI ke_is_overlap(uint64_t x1, uint64_t x2, uint64_t y1, uint64_t y2)
{
    return ((x1 <= y2) && (y1 <= x2)) ? 1 : 0;
}


static inline int64_t KAPI ke_max_64(int64_t a, int64_t b)
{
    return (a) > (b) ? a : b;
}

static inline int64_t KAPI ke_min_64(int64_t a, int64_t b)
{
    return (a) < (b) ? a : b;
}

static inline int32_t KAPI ke_max_32(int32_t a, int32_t b)
{
    return (a) > (b) ? a : b;
}

static inline int32_t KAPI ke_min_32(int32_t a, int32_t b)
{
    return (a) < (b) ? a : b;
}

//static inline uint64_t KAPI round_up_power_of_2(uint64_t num)
//{
//    num--;
//    num |= num >> 1;
//    num |= num >> 2;
//    num |= num >> 4;
//    num |= num >> 8;
//    num |= num >> 16;
//    num |= num >> 32;
//    num++;
//    return (uint64_t)num;
//}
//
//static inline uint32_t KAPI log_base_2(uint64_t num)
//{
//    uint32_t result = 0;
//
//    while (num >>= 1)
//    {
//        result++;
//    }
//
//    return result;
//}

#define OBTAIN_STRUCT_ADDR(member_addr, struct_name, member_name) ((struct_name*)((void*)(member_addr)-(void*)(&(((struct_name*)0)->member_name))))

static inline uint64_t KAPI ke_bit_mask(uint32_t bit)
{
    return (uint64_t)1 << bit;
}

static inline uint64_t KAPI ke_bit_field_mask(uint32_t low, uint32_t high)
{
    return ~(~(uint64_t)0 << high << 1) << low;
}

static inline void KAPI ke_bit_map_set(void *bit_map, uint64_t bit)
{
    if(bit_map != NULL)
    {
        uint64_t quot = bit >> 3;
        uint32_t rmd = (uint32_t)(bit & ke_bit_field_mask(0, 2));

        *((uint8_t*)(bit_map) + quot) |= (uint8_t) ke_bit_mask(rmd);
    }
}

static inline void KAPI ke_bit_map_clear(void *bit_map, uint64_t bit)
{
    if(bit_map != NULL)
    {
        uint64_t quot = bit >> 3;
        uint32_t rmd = (uint32_t)(bit & ke_bit_field_mask(0, 2));

        *((uint8_t*)(bit_map) + quot) &= ~(uint8_t) ke_bit_mask(rmd);
    }
}

static inline uint32_t KAPI ke_bit_map_read(void *bit_map, uint64_t bit)
{
    if(bit_map != NULL)
    {
        uint64_t quot = bit >> 3;
        uint32_t rmd = (uint32_t)(bit & ke_bit_field_mask(0, 2));

        return (*((uint8_t*)(bit_map) + quot) & (uint8_t) ke_bit_mask(rmd)) == 0 ? 0 : 1;
    }
    return 0;
}

#endif
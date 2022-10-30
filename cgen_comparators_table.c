#include "lib/cgen_generated.h"

static int32_t __cgen_compare_int8_asc__(const int8_t x1, const int8_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
static int32_t __cgen_compare_int8_desc__(const int8_t x1, const int8_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
static int32_t __cgen_compare_int16_asc__(const int16_t x1, const int16_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
static int32_t __cgen_compare_int16_desc__(const int16_t x1, const int16_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
static int32_t __cgen_compare_int32_asc__(const int32_t x1, const int32_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
static int32_t __cgen_compare_int32_desc__(const int32_t x1, const int32_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
static int32_t __cgen_compare_int64_asc__(const int64_t x1, const int64_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
static int32_t __cgen_compare_int64_desc__(const int64_t x1, const int64_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
static int32_t __cgen_compare_uint8_asc__(const uint8_t x1, const uint8_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
static int32_t __cgen_compare_uint8_desc__(const uint8_t x1, const uint8_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
static int32_t __cgen_compare_uint16_asc__(const uint16_t x1, const uint16_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
static int32_t __cgen_compare_uint16_desc__(const uint16_t x1, const uint16_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
static int32_t __cgen_compare_uint32_asc__(const uint32_t x1, const uint32_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
static int32_t __cgen_compare_uint32_desc__(const uint32_t x1, const uint32_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
static int32_t __cgen_compare_uint64_asc__(const uint64_t x1, const uint64_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
static int32_t __cgen_compare_uint64_desc__(const uint64_t x1, const uint64_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
static int32_t __cgen_compare_short_asc__(const short x1, const short x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
static int32_t __cgen_compare_short_desc__(const short x1, const short x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
static int32_t __cgen_compare_float_asc__(const float x1, const float x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
static int32_t __cgen_compare_float_desc__(const float x1, const float x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
static int32_t __cgen_compare_double_asc__(const double x1, const double x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
static int32_t __cgen_compare_double_desc__(const double x1, const double x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
static int32_t __cgen_compare_str_asc__(const char *x1, const char *x2)
{
    return strcmp(x1, x2);
}
static int32_t __cgen_compare_str_desc__(const char *x1, const char *x2)
{
    return -strcmp(x1, x2);
}

const comparators_table CGen_Comparators = {
    .compare_int8_asc = __cgen_compare_int8_asc__,
    .compare_int8_desc = __cgen_compare_int8_desc__,
    .compare_int16_asc = __cgen_compare_int16_asc__,
    .compare_int16_desc = __cgen_compare_int16_desc__,
    .compare_int32_asc = __cgen_compare_int32_asc__,
    .compare_int32_desc = __cgen_compare_int32_desc__,
    .compare_int64_asc = __cgen_compare_int64_asc__,
    .compare_int64_desc = __cgen_compare_int64_desc__,
    .compare_uint8_asc = __cgen_compare_uint8_asc__,
    .compare_uint8_desc = __cgen_compare_uint8_desc__,
    .compare_uint16_asc = __cgen_compare_uint16_asc__,
    .compare_uint16_desc = __cgen_compare_uint16_desc__,
    .compare_uint32_asc = __cgen_compare_uint32_asc__,
    .compare_uint32_desc = __cgen_compare_uint32_desc__,
    .compare_uint64_asc = __cgen_compare_uint64_asc__,
    .compare_uint64_desc = __cgen_compare_uint64_desc__,
    .compare_short_asc = __cgen_compare_short_asc__,
    .compare_short_desc = __cgen_compare_short_desc__,
    .compare_float_asc = __cgen_compare_float_asc__,
    .compare_float_desc = __cgen_compare_float_desc__,
    .compare_double_asc = __cgen_compare_double_asc__,
    .compare_double_desc = __cgen_compare_double_desc__,
    .compare_str_asc = __cgen_compare_str_asc__,
    .compare_str_desc = __cgen_compare_str_desc__
};
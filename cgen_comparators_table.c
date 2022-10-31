#include <ctype.h>
#include "lib/cgen_generated.h"

int32_t cgen_compare_int8_asc(const int8_t x1, const int8_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
int32_t cgen_compare_int8_desc(const int8_t x1, const int8_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
int32_t cgen_compare_int16_asc(const int16_t x1, const int16_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
int32_t cgen_compare_int16_desc(const int16_t x1, const int16_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
int32_t cgen_compare_int32_asc(const int32_t x1, const int32_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
int32_t cgen_compare_int32_desc(const int32_t x1, const int32_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
int32_t cgen_compare_int64_asc(const int64_t x1, const int64_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
int32_t cgen_compare_int64_desc(const int64_t x1, const int64_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
int32_t cgen_compare_uint8_asc(const uint8_t x1, const uint8_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
int32_t cgen_compare_uint8_desc(const uint8_t x1, const uint8_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
int32_t cgen_compare_uint16_asc(const uint16_t x1, const uint16_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
int32_t cgen_compare_uint16_desc(const uint16_t x1, const uint16_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
int32_t cgen_compare_uint32_asc(const uint32_t x1, const uint32_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
int32_t cgen_compare_uint32_desc(const uint32_t x1, const uint32_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
int32_t cgen_compare_uint64_asc(const uint64_t x1, const uint64_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
int32_t cgen_compare_uint64_desc(const uint64_t x1, const uint64_t x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
int32_t cgen_compare_short_asc(const short x1, const short x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
int32_t cgen_compare_short_desc(const short x1, const short x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
int32_t cgen_compare_float_asc(const float x1, const float x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
int32_t cgen_compare_float_desc(const float x1, const float x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
int32_t cgen_compare_double_asc(const double x1, const double x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? -1 : 1;
}
int32_t cgen_compare_double_desc(const double x1, const double x2)
{
    return x1 == x2 ? 0 : x1 < x2 ? 1 : -1;
}
int32_t cgen_compare_str_asc(char *x1, char *x2)
{
    return strcmp(x1, x2);
}
int32_t cgen_compare_str_desc(char *x1, char *x2)
{
    return -strcmp(x1, x2);
}
int32_t cgen_compare_str_case_insensitive_asc(char *x1, char *x2)
{
    unsigned char c1, c2;
    do
    {
        c1 = tolower(*x1++);
        c2 = tolower(*x2++);
        if (c1 == '\0')
        {
            return c1 - c2;
        }
    }
    while (c1 == c2);
    return c1 - c2;
}
int32_t cgen_compare_str_case_insensitive_desc(char *x1, char *x2)
{
    unsigned char c1, c2;
    do
    {
        c1 = tolower(*x1++);
        c2 = tolower(*x2++);
        if (c1 == '\0')
        {
            return c2 - c1;
        }
    }
    while (c1 == c2);
    return c2 - c1;
}

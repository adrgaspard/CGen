#ifndef __TUPLE_H__
#define __TUPLE_H__

#define INCLUDE_TUPLE2(type1, type2)                                                               \
typedef struct tuple_##type1##_##type2                                                             \
{                                                                                                  \
    type1 item1;                                                                                   \
    type2 item2;                                                                                   \
} tuple_##type1##_##type2;
#define INCLUDE_TUPLE3(type1, type2, type3)                                                        \
typedef struct tuple_##type1##_##type2##_##type3                                                   \
{                                                                                                  \
    type1 item1;                                                                                   \
    type2 item2;                                                                                   \
    type3 item3;                                                                                   \
} tuple_##type1##_##type2##_##type3;
#define INCLUDE_TUPLE4(type1, type2, type3, type4)                                                 \
typedef struct tuple_##type1##_##type2##_##type3##_##type4                                         \
{                                                                                                  \
    type1 item1;                                                                                   \
    type2 item2;                                                                                   \
    type3 item3;                                                                                   \
    type4 item4;                                                                                   \
} tuple_##type1##_##type2##_##type3##_##type4;
#define INCLUDE_TUPLE5(type1, type2, type3, type4, type5)                                          \
typedef struct tuple_##type1##_##type2##_##type3##_##type4##_##type5                               \
{                                                                                                  \
    type1 item1;                                                                                   \
    type2 item2;                                                                                   \
    type3 item3;                                                                                   \
    type4 item4;                                                                                   \
    type5 item5;                                                                                   \
} tuple_##type1##_##type2##_##type3##_##type4##_##type5;
#define INCLUDE_TUPLE6(type1, type2, type3, type4, type5, type6)                                   \
typedef struct tuple_##type1##_##type2##_##type3##_##type4##_##type5##_##type6                     \
{                                                                                                  \
    type1 item1;                                                                                   \
    type2 item2;                                                                                   \
    type3 item3;                                                                                   \
    type4 item4;                                                                                   \
    type5 item5;                                                                                   \
    type6 item6;                                                                                   \
} tuple_##type1##_##type2##_##type3##_##type4##_##type5##_##type6;
#define INCLUDE_TUPLE7(type1, type2, type3, type4, type5, type6, type7)                            \
typedef struct tuple_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7           \
{                                                                                                  \
    type1 item1;                                                                                   \
    type2 item2;                                                                                   \
    type3 item3;                                                                                   \
    type4 item4;                                                                                   \
    type5 item5;                                                                                   \
    type6 item6;                                                                                   \
    type7 item7;                                                                                   \
} tuple_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7;
#define INCLUDE_TUPLE8(type1, type2, type3, type4, type5, type6, type7, type8)                     \
typedef struct tuple_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8 \
{                                                                                                  \
    type1 item1;                                                                                   \
    type2 item2;                                                                                   \
    type3 item3;                                                                                   \
    type4 item4;                                                                                   \
    type5 item5;                                                                                   \
    type6 item6;                                                                                   \
    type7 item7;                                                                                   \
    type8 item8;                                                                                   \
} tuple_##type1##_##type2##_##type3##_##type4##_##type5##_##type6##_##type7##_##type8;

#endif
/* FAM2: threshold searches.  Each counts the leading entries of the table at
 * +0x4c whose float key (first field of a STRIDE-byte entry) is below x; the
 * table is terminated by a key that is not below any queried value. */
#define TS4_FLOAT_BRACKET(A, STRIDE) \
typedef struct Ts4FloatKey_##A { float key; char pad[STRIDE - 4]; } Ts4FloatKey_##A; \
typedef struct Ts4FloatTable_##A { char pad[0x4c]; Ts4FloatKey_##A *t; } Ts4FloatTable_##A; \
int ts4_float_bracket_##A(Ts4FloatTable_##A *self, float x) \
{ \
    int i = 0; \
    while (self->t[i].key < x) \
        i++; \
    return i; \
}

TS4_FLOAT_BRACKET(88274370, 0x28)
TS4_FLOAT_BRACKET(88274FE8, 0x8)
TS4_FLOAT_BRACKET(882757F8, 0x10)
TS4_FLOAT_BRACKET(88275A18, 0x20)

/* Interval lookups over tables of {float key; ... T value; ...} entries:
 * _PREV starts at entry 1 and copies out the value of the entry before the
 * first key not below x; _AT starts at entry 0 and copies that entry's own
 * value.  PRE/POST pad the entry around the value. */
typedef struct Ts4Vec3f { float x, y, z; } Ts4Vec3f;

#define TS4_INTERVAL_TYPES(A, T, PRE, POST) \
typedef struct Ts4IntervalKey_##A { float key; PRE T value; POST } Ts4IntervalKey_##A; \
typedef struct Ts4IntervalTable_##A { char pad[0x4c]; Ts4IntervalKey_##A *t; } Ts4IntervalTable_##A;

#define TS4_FLOAT_INTERVAL_PREV_VP(A, T, PRE, POST, COPY) \
TS4_INTERVAL_TYPES(A, T, PRE, POST) \
void ts4_float_interval_prev_##A(Ts4IntervalTable_##A *self, float x, T *out) \
{ \
    int i = 1; \
    const T *v; \
    while (self->t[i].key < x) \
        i++; \
    v = &self->t[i - 1].value; \
    COPY; \
}

#define TS4_FLOAT_INTERVAL_PREV(A, T, PRE, POST) \
TS4_INTERVAL_TYPES(A, T, PRE, POST) \
void ts4_float_interval_prev_##A(Ts4IntervalTable_##A *self, float x, T *out) \
{ \
    int i = 1; \
    while (self->t[i].key < x) \
        i++; \
    *out = self->t[i - 1].value; \
}

#define TS4_FLOAT_INTERVAL_AT_VP(A, T, PRE, POST, COPY) \
TS4_INTERVAL_TYPES(A, T, PRE, POST) \
void ts4_float_interval_at_##A(Ts4IntervalTable_##A *self, float x, T *out) \
{ \
    int i = 0; \
    const T *v; \
    while (self->t[i].key < x) \
        i++; \
    v = &self->t[i].value; \
    COPY; \
}

#define TS4_FLOAT_INTERVAL_AT(A, T, PRE, POST) \
TS4_INTERVAL_TYPES(A, T, PRE, POST) \
void ts4_float_interval_at_##A(Ts4IntervalTable_##A *self, float x, T *out) \
{ \
    int i = 0; \
    while (self->t[i].key < x) \
        i++; \
    *out = self->t[i].value; \
}

#define TS4_NOPAD
#define TS4_COPY3(d, s) ((d)->x = (s)->x, (d)->y = (s)->y, (d)->z = (s)->z)

TS4_FLOAT_INTERVAL_PREV(88274C70, float, TS4_NOPAD, char pad[8];)
TS4_FLOAT_INTERVAL_AT(88274CB0, float, TS4_NOPAD, char pad[8];)
TS4_FLOAT_INTERVAL_PREV(88274F68, float, TS4_NOPAD, TS4_NOPAD)
TS4_FLOAT_INTERVAL_AT(88274FA8, float, TS4_NOPAD, TS4_NOPAD)
TS4_FLOAT_INTERVAL_PREV_VP(882742B0, Ts4Vec3f, TS4_NOPAD, char pad[0x18];, TS4_COPY3(out, v))
TS4_FLOAT_INTERVAL_AT_VP(88274310, Ts4Vec3f, TS4_NOPAD, char pad[0x18];, TS4_COPY3(out, v))

/* Swing_DLL.xex 0x881877A8-0x8826C818, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Rec_881877A8 { u8 pad[24]; u32 key; u8 pad2[16]; } Rec_881877A8;
typedef struct Table_881877A8 { int data_offset; int count; } Table_881877A8;

/* Linear search of a table of 44-byte records for the one whose key (at +0x18) matches *key. */
void *ts4_find_record_by_key_881877A8(Table_881877A8 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881877A8 *r = (Rec_881877A8 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_88187800 { u32 key; u8 pad2[48]; } Rec_88187800;
typedef struct Table_88187800 { int data_offset; int count; } Table_88187800;

/* Linear search of a table of 52-byte records for the one whose key (at +0x0) matches *key. */
void *ts4_find_record_by_key_88187800(Table_88187800 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_88187800 *r = (Rec_88187800 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881AC720 { u8 pad[36]; u32 key; u8 pad2[4]; } Rec_881AC720;
typedef struct Table_881AC720 { int data_offset; int count; } Table_881AC720;

/* Linear search of a table of 44-byte records for the one whose key (at +0x24) matches *key. */
void *ts4_find_record_by_key_881AC720(Table_881AC720 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881AC720 *r = (Rec_881AC720 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881AC778 { u32 key; u8 pad2[4]; } Rec_881AC778;
typedef struct Table_881AC778 { int data_offset; int count; } Table_881AC778;

/* Linear search of a table of 8-byte records for the one whose key (at +0x0) matches *key. */
void *ts4_find_record_by_key_881AC778(Table_881AC778 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881AC778 *r = (Rec_881AC778 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881ACBA8 { u32 key; u8 pad2[16]; } Rec_881ACBA8;
typedef struct Table_881ACBA8 { int data_offset; int count; } Table_881ACBA8;

/* Linear search of a table of 20-byte records for the one whose key (at +0x0) matches *key. */
void *ts4_find_record_by_key_881ACBA8(Table_881ACBA8 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881ACBA8 *r = (Rec_881ACBA8 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881ACC88 { u32 key; u8 pad2[24]; } Rec_881ACC88;
typedef struct Table_881ACC88 { int data_offset; int count; } Table_881ACC88;

/* Linear search of a table of 28-byte records for the one whose key (at +0x0) matches *key. */
void *ts4_find_record_by_key_881ACC88(Table_881ACC88 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881ACC88 *r = (Rec_881ACC88 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881ACCE0 { u8 pad[12]; u32 key; u8 pad2[4]; } Rec_881ACCE0;
typedef struct Table_881ACCE0 { int data_offset; int count; } Table_881ACCE0;

/* Linear search of a table of 20-byte records for the one whose key (at +0xc) matches *key. */
void *ts4_find_record_by_key_881ACCE0(Table_881ACCE0 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881ACCE0 *r = (Rec_881ACCE0 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881ACD38 { u32 key; u8 pad2[20]; } Rec_881ACD38;
typedef struct Table_881ACD38 { int data_offset; int count; } Table_881ACD38;

/* Linear search of a table of 24-byte records for the one whose key (at +0x0) matches *key. */
void *ts4_find_record_by_key_881ACD38(Table_881ACD38 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881ACD38 *r = (Rec_881ACD38 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881ACD90 { u8 pad[20]; u32 key; u8 pad2[8]; } Rec_881ACD90;
typedef struct Table_881ACD90 { int data_offset; int count; } Table_881ACD90;

/* Linear search of a table of 32-byte records for the one whose key (at +0x14) matches *key. */
void *ts4_find_record_by_key_881ACD90(Table_881ACD90 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881ACD90 *r = (Rec_881ACD90 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881ACE10 { u8 pad[4]; u32 key; u8 pad2[12]; } Rec_881ACE10;
typedef struct Table_881ACE10 { int data_offset; int count; } Table_881ACE10;

/* Linear search of a table of 20-byte records for the one whose key (at +0x4) matches *key. */
void *ts4_find_record_by_key_881ACE10(Table_881ACE10 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881ACE10 *r = (Rec_881ACE10 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881ACE68 { u8 pad[56]; u32 key; u8 pad2[28]; } Rec_881ACE68;
typedef struct Table_881ACE68 { int data_offset; int count; } Table_881ACE68;

/* Linear search of a table of 88-byte records for the one whose key (at +0x38) matches *key. */
void *ts4_find_record_by_key_881ACE68(Table_881ACE68 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881ACE68 *r = (Rec_881ACE68 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881ACEC0 { u8 pad[60]; u32 key; u8 pad2[20]; } Rec_881ACEC0;
typedef struct Table_881ACEC0 { int data_offset; int count; } Table_881ACEC0;

/* Linear search of a table of 84-byte records for the one whose key (at +0x3c) matches *key. */
void *ts4_find_record_by_key_881ACEC0(Table_881ACEC0 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881ACEC0 *r = (Rec_881ACEC0 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881ACF18 { u8 pad[12]; u32 key; u8 pad2[8]; } Rec_881ACF18;
typedef struct Table_881ACF18 { int data_offset; int count; } Table_881ACF18;

/* Linear search of a table of 24-byte records for the one whose key (at +0xc) matches *key. */
void *ts4_find_record_by_key_881ACF18(Table_881ACF18 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881ACF18 *r = (Rec_881ACF18 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881ACF70 { u8 pad[32]; u32 key; u8 pad2[28]; } Rec_881ACF70;
typedef struct Table_881ACF70 { int data_offset; int count; } Table_881ACF70;

/* Linear search of a table of 64-byte records for the one whose key (at +0x20) matches *key. */
void *ts4_find_record_by_key_881ACF70(Table_881ACF70 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881ACF70 *r = (Rec_881ACF70 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881ACFC8 { u8 pad[12]; u32 key; u8 pad2[12]; } Rec_881ACFC8;
typedef struct Table_881ACFC8 { int data_offset; int count; } Table_881ACFC8;

/* Linear search of a table of 28-byte records for the one whose key (at +0xc) matches *key. */
void *ts4_find_record_by_key_881ACFC8(Table_881ACFC8 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881ACFC8 *r = (Rec_881ACFC8 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881AD020 { u32 key; u8 pad2[56]; } Rec_881AD020;
typedef struct Table_881AD020 { int data_offset; int count; } Table_881AD020;

/* Linear search of a table of 60-byte records for the one whose key (at +0x0) matches *key. */
void *ts4_find_record_by_key_881AD020(Table_881AD020 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881AD020 *r = (Rec_881AD020 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881AD0A8 { u32 key; u8 pad2[28]; } Rec_881AD0A8;
typedef struct Table_881AD0A8 { int data_offset; int count; } Table_881AD0A8;

/* Linear search of a table of 32-byte records for the one whose key (at +0x0) matches *key. */
void *ts4_find_record_by_key_881AD0A8(Table_881AD0A8 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881AD0A8 *r = (Rec_881AD0A8 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881AD100 { u8 pad[88]; u32 key; u8 pad2[32]; } Rec_881AD100;
typedef struct Table_881AD100 { int data_offset; int count; } Table_881AD100;

/* Linear search of a table of 124-byte records for the one whose key (at +0x58) matches *key. */
void *ts4_find_record_by_key_881AD100(Table_881AD100 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881AD100 *r = (Rec_881AD100 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881AD158 { u32 key; u8 pad2[8]; } Rec_881AD158;
typedef struct Table_881AD158 { int data_offset; int count; } Table_881AD158;

/* Linear search of a table of 12-byte records for the one whose key (at +0x0) matches *key. */
void *ts4_find_record_by_key_881AD158(Table_881AD158 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881AD158 *r = (Rec_881AD158 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881AD1B0 { u8 pad[4]; u32 key; u8 pad2[16]; } Rec_881AD1B0;
typedef struct Table_881AD1B0 { int data_offset; int count; } Table_881AD1B0;

/* Linear search of a table of 24-byte records for the one whose key (at +0x4) matches *key. */
void *ts4_find_record_by_key_881AD1B0(Table_881AD1B0 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881AD1B0 *r = (Rec_881AD1B0 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881AD208 { u8 pad[32]; u32 key; u8 pad2[20]; } Rec_881AD208;
typedef struct Table_881AD208 { int data_offset; int count; } Table_881AD208;

/* Linear search of a table of 56-byte records for the one whose key (at +0x20) matches *key. */
void *ts4_find_record_by_key_881AD208(Table_881AD208 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881AD208 *r = (Rec_881AD208 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881AD3A0 { u8 pad[24]; u32 key; u8 pad2[304]; } Rec_881AD3A0;
typedef struct Table_881AD3A0 { int data_offset; int count; } Table_881AD3A0;

/* Linear search of a table of 332-byte records for the one whose key (at +0x18) matches *key. */
void *ts4_find_record_by_key_881AD3A0(Table_881AD3A0 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881AD3A0 *r = (Rec_881AD3A0 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_881BBFF8 { u8 pad[12]; u32 key; } Rec_881BBFF8;
typedef struct Table_881BBFF8 { int data_offset; int count; } Table_881BBFF8;

/* Linear search of a table of 16-byte records for the one whose key (at +0xc) matches *key. */
void *ts4_find_record_by_key_881BBFF8(Table_881BBFF8 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_881BBFF8 *r = (Rec_881BBFF8 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_8825DF30 { u8 pad[16]; u32 key; } Rec_8825DF30;
typedef struct Table_8825DF30 { int data_offset; int count; } Table_8825DF30;

/* Linear search of a table of 20-byte records for the one whose key (at +0x10) matches *key. */
void *ts4_find_record_by_key_8825DF30(Table_8825DF30 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_8825DF30 *r = (Rec_8825DF30 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_8825DF88 { u8 pad[64]; u32 key; u8 pad2[12]; } Rec_8825DF88;
typedef struct Table_8825DF88 { int data_offset; int count; } Table_8825DF88;

/* Linear search of a table of 80-byte records for the one whose key (at +0x40) matches *key. */
void *ts4_find_record_by_key_8825DF88(Table_8825DF88 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_8825DF88 *r = (Rec_8825DF88 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_88265440 { u32 key; u8 pad2[12]; } Rec_88265440;
typedef struct Table_88265440 { int data_offset; int count; } Table_88265440;

/* Linear search of a table of 16-byte records for the one whose key (at +0x0) matches *key. */
void *ts4_find_record_by_key_88265440(Table_88265440 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_88265440 *r = (Rec_88265440 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

typedef struct Rec_8826C818 { u32 key; } Rec_8826C818;
typedef struct Table_8826C818 { int data_offset; int count; } Table_8826C818;

/* Linear search of a table of 4-byte records for the one whose key (at +0x0) matches *key. */
void *ts4_find_record_by_key_8826C818(Table_8826C818 *self, const u32 *key)
{
    void *result = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        Rec_8826C818 *r = (Rec_8826C818 *)((char *)self + self->data_offset) + i;
        if (r->key == *key) {
            result = r;
            break;
        }
    }
    return result;
}

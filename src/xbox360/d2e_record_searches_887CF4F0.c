/* Swing_DLL.xex 0x887CF4F0-0x8886527C, executable version 0.0.0.3. */
typedef unsigned short ts4_u16;

typedef struct Ts4Record1C { unsigned char reserved[0xC]; unsigned int key; unsigned char tail[0xC]; } Ts4Record1C;
typedef struct Ts4Range1C { Ts4Record1C *begin; Ts4Record1C *end; } Ts4Range1C;

typedef struct Ts4Record5C { unsigned int key; unsigned char tail[0x58]; } Ts4Record5C;
typedef struct Ts4Range5C { unsigned char reserved[0x5C]; Ts4Record5C *begin; Ts4Record5C *end; } Ts4Range5C;

/* Linear search of 0x1C-byte records for the one whose key equals *key; null when absent. */
Ts4Record1C *ts4_find_record_1c_887CF4F0(Ts4Range1C *range, const unsigned int *key)
{
    Ts4Record1C *record = range->begin;
    Ts4Record1C *end = range->end;
    for (; record != end; ++record) {
        if (*key == record->key) {
            return record;
        }
    }
    return 0;
}

/* Linear search of 0x5C-byte records for the one with the given key; returns the end pointer when absent. */
Ts4Record5C *ts4_find_record_5c_88865270(Ts4Range5C *range, unsigned int key)
{
    Ts4Record5C *record = range->begin;
    Ts4Record5C *end = range->end;
    for (; record != end; ++record) {
        if (record->key == key) {
            return record;
        }
    }
    return record;
}

/* Finds the first UTF-16 unit equal to ch within count units; null when absent. */
const ts4_u16 *ts4_find_wide_char_8882F0F8(const ts4_u16 *text, ts4_u16 ch, unsigned int count)
{
    for (; count != 0; --count, ++text) {
        if (*text == ch) {
            return text;
        }
    }
    return 0;
}

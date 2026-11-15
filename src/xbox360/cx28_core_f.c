/* CX28 batch f: compare-and-release helpers (Swing_DLL.xex). */
typedef unsigned char cx28_u8;

#ifdef _MSC_VER
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
#else
#include <string.h>
#endif

extern unsigned char lbl_880C1320[];
cx28_u8 fn_8822BF98(void *, void *);
cx28_u8 fn_88162C60(void *, void *);
cx28_u8 fn_8815E798(void *, void *);
void *ts4_call_seq_u32_off0_8815ED78(void *out, void *src);
void ts4_call_seq_u32_off48_8815EBE0(void *obj);
void ts4_destroy_owned_object(void *);

typedef struct cx28_tmp {
    int w[12];
} cx28_tmp;

/* Swing_DLL.xex 0x8815EC38: compare two records (name member, three ints), then release the second */
cx28_u8 ts4_cx28_record_equal_release_8815EC38(char *a, char *b)
{
    char *p = a + 0x3c;
    int res;
    cx28_tmp tmp;
    if (!fn_8822BF98(lbl_880C1320, p)) {
        if (!fn_88162C60(p, b + 0x3c)) {
            ts4_call_seq_u32_off48_8815EBE0(b);
            return 0;
        }
    }
    if (*(int *)(a + 0x5c) != *(int *)(b + 0x5c) || *(int *)(a + 0x54) != *(int *)(b + 0x54)
        || *(int *)(a + 0x58) != *(int *)(b + 0x58))
        goto zero;
    if (!fn_8815E798(a, ts4_call_seq_u32_off0_8815ED78(&tmp, b))) {
    zero:
        res = 0;
    } else {
        res = 1;
    }
    ts4_call_seq_u32_off48_8815EBE0(b);
    return res;
}

/* Swing_DLL.xex 0x8815EDE8: compare two records (name string, two ints), then destroy the second's members */
cx28_u8 ts4_cx28_record_equal_destroy_8815EDE8(char *a, char *b)
{
    int res;
    cx28_tmp tmp;
    if (strcmp(*(char **)(a + 0x3c), *(char **)(b + 0x3c)) != 0 || *(int *)(a + 0x4c) != *(int *)(b + 0x4c)
        || *(int *)(a + 0x50) != *(int *)(b + 0x50))
        goto zero;
    if (!fn_8815E798(a, ts4_call_seq_u32_off0_8815ED78(&tmp, b))) {
    zero:
        res = 0;
    } else {
        res = 1;
    }
    ts4_destroy_owned_object(*(void **)(b + 0x3c));
    ts4_destroy_owned_object(*(void **)(b + 0x30));
    ts4_destroy_owned_object(*(void **)(b + 0x18));
    ts4_destroy_owned_object(*(void **)(b + 0xc));
    ts4_destroy_owned_object(*(void **)b);
    return res;
}

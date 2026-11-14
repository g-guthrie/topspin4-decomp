/* Loader_DLL.xex 0x8313D8C0-0x83159018, executable version 0.0.0.3. */

#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#define TS4L_HIGHBIT 0x8000000000000000ui64
#else
#define __forceinline inline
typedef unsigned long long ts4l_u64;
#define TS4L_HIGHBIT 0x8000000000000000ULL
#endif

typedef struct ts4l_rc_obj {
    char pad[0x28];
    int refs;
} ts4l_rc_obj;

void ts4l_if_call_seq_u32_off24_8313D0C0(ts4l_rc_obj *o);
int fn_83120540(ts4l_rc_obj *o);

/* Drop one reference; on zero run the teardown sequence and release. */
void ts4l_rc_release_8313D8C0(ts4l_rc_obj *o)
{
    if (--o->refs == 0) {
        ts4l_if_call_seq_u32_off24_8313D0C0(o);
        fn_83120540(o);
    }
}

typedef struct ts4l_float_value {
    int type;
    float f;
} ts4l_float_value;

void ts4l_if_call_seq_u32_off0_83140430(ts4l_float_value *o);

/* Initialise a tagged float value (type 4). */
void ts4l_float_value_init_83140578(ts4l_float_value *o, float v)
{
    ts4l_if_call_seq_u32_off0_83140430(o);
    o->type = 4;
    o->f = v;
}

typedef struct ts4l_mul_add { int mul; int add; } ts4l_mul_add;
extern ts4l_mul_add lbl_83085FC0[];
void ts4l_if_call_seq_fn_830E1140_830E1610(void *ctx, int idx, int val);

/* Forward a table-scaled value (table[idx].mul * n + table[idx].add). */
int ts4l_table_call_83159018(void *ctx, int idx, int n)
{
    ts4l_if_call_seq_fn_830E1140_830E1610(ctx, idx, lbl_83085FC0[idx].mul * n + lbl_83085FC0[idx].add);
    return 0;
}

typedef unsigned int u32;
typedef struct Vtbl { void *slot0; u32 (*slot1)(void *); } Vtbl;
typedef struct Handler { Vtbl *vtbl; } Handler;
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B6180(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B6600(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B6450(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B62A0(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B6210(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B60F0(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B67B0(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B6008(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B63C0(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B6720(void);
u32 fn_881B5EA8(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B5E18(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B6098(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B6690(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B5CF8(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B6570(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B5D88(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B5F58(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B64E0(void);
u32 ts4_if_call_seq_u32_lbl_88D45B38_881B6330(void);
extern Handler *lbl_88D45B20;
Handler *fn_8816D220(Handler *owner, u32 hash);

/* Dispatches a 32-bit name hash to one of 20 handler functions; unknown
   hashes fall back to the default handler object's virtual slot 1.
   Swing_DLL.xex 0x887FC940. */
u32 ts4_dispatch_by_name_hash_887FC940(u32 hash)
{
    Handler *fallback;
    switch (hash) {
    case 0x0D7C010E: return ts4_if_call_seq_u32_lbl_88D45B38_881B6180();
    case 0x0BF76C86: return ts4_if_call_seq_u32_lbl_88D45B38_881B6600();
    case 0x157736BD: return ts4_if_call_seq_u32_lbl_88D45B38_881B6450();
    case 0x213E4EFB: return ts4_if_call_seq_u32_lbl_88D45B38_881B62A0();
    case 0x1A8750A5: return ts4_if_call_seq_u32_lbl_88D45B38_881B6210();
    case 0x31713E57: return ts4_if_call_seq_u32_lbl_88D45B38_881B60F0();
    case 0x504833DA: return ts4_if_call_seq_u32_lbl_88D45B38_881B67B0();
    case 0x3BE08B6B: return ts4_if_call_seq_u32_lbl_88D45B38_881B6008();
    case 0x56DA68D7: return ts4_if_call_seq_u32_lbl_88D45B38_881B63C0();
    case 0x64BA8393: return ts4_if_call_seq_u32_lbl_88D45B38_881B6720();
    case 0x6B081491: return fn_881B5EA8();
    case 0x8E635CBB: return ts4_if_call_seq_u32_lbl_88D45B38_881B5E18();
    case 0x87AD70EC: return ts4_if_call_seq_u32_lbl_88D45B38_881B6098();
    case 0x90DCE917: return ts4_if_call_seq_u32_lbl_88D45B38_881B6690();
    case 0xB5C1A64B: return ts4_if_call_seq_u32_lbl_88D45B38_881B5CF8();
    case 0xB6C9385C: return ts4_if_call_seq_u32_lbl_88D45B38_881B6570();
    case 0xD06AC102: return ts4_if_call_seq_u32_lbl_88D45B38_881B5D88();
    case 0xC608396B: return ts4_if_call_seq_u32_lbl_88D45B38_881B5F58();
    case 0xD86CD997: return ts4_if_call_seq_u32_lbl_88D45B38_881B64E0();
    case 0xFA9A6031: return ts4_if_call_seq_u32_lbl_88D45B38_881B6330();
    default:
        fallback = fn_8816D220(lbl_88D45B20, hash);
        if (fallback == 0) {
            return 0;
        }
        return fallback->vtbl->slot1(fallback);
    }
}

/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char ts4_fn_888A09C0[];
extern char fn_888A0C10[];
extern char ts4_if_addr_fn_888A0DD8_888A0D60[];
extern char fn_888A0F08[];
extern char fn_888A1178[];
extern char fn_888A1200[];
extern char ts4_if_addr_fn_888A15C0_888A1540[];
extern char ts4_prolog_element_content_spec_888A1858[];
extern char fn_888A19F0[];
extern char fn_888A1AF8[];
extern char fn_888A1C68[];
extern char fn_888A1DB0[];
extern char ts4_if_get_u32_off10_888A1E30[];
extern char ts4_prolog_entity_external_or_value_888A1EF0[];
extern char fn_888A2068[];
extern char ts4_if_get_u32_off10_888A2150[];
extern char ts4_prolog_entity_external_or_value_888A2210[];
extern char ts4_if_get_u32_off10_888A2320[];
extern char fn_888A2458[];
extern char ts4_if_addr_fn_888A1178_888A2680[];
extern char fn_888A27C0[];
extern char ts4_token_classify_888A2AC8[];
extern char g_ts4_script_constants[];
extern char lbl_880C9748[];
extern char lbl_880CF7F8[];
extern char lbl_880D0830[];
extern char lbl_880D0934[];
extern char lbl_880D0938[];
extern char lbl_880D19F0[];
extern char lbl_880D1CE0[];
extern char lbl_880D49CC[];
extern char lbl_880D6B70[];
extern char lbl_880D7074[];
extern char lbl_880D75C4[];
extern char lbl_880D75FC[];
extern char lbl_880D7604[];
extern char lbl_880D7608[];
extern char lbl_880D91F4[];
extern char lbl_880D9874[];
extern char lbl_880D9888[];
extern char lbl_880D98A4[];
extern char lbl_880D98B8[];
extern char lbl_880D9AA4[];
extern char lbl_880D9AB8[];
extern char lbl_880D9B50[];
extern char lbl_880DA718[];
extern char lbl_880DB200[];
extern char lbl_880DB228[];
extern char lbl_880DB2A4[];
extern char lbl_880DB2C8[];
extern char lbl_880DB2D8[];
extern char lbl_880DB350[];
extern char lbl_880DB370[];
extern char lbl_880DB3C0[];
extern char lbl_880DB408[];
extern char lbl_880DB490[];
extern char lbl_880DB530[];
extern char lbl_880DB580[];
extern char lbl_880DB5F8[];
extern char lbl_880DB744[];
extern char lbl_880DB794[];
extern char lbl_880DB7E4[];
extern char lbl_880DB80C[];
extern char lbl_880DB8DC[];
extern char lbl_880DBC30[];
extern char lbl_880DBCDC[];
extern char lbl_880DBD58[];
extern char lbl_880DBD80[];
extern char lbl_880DBEB8[];
extern char lbl_880DC550[];
extern char lbl_880DC5DC[];
extern char lbl_880DC614[];
extern char lbl_880DC6B8[];
extern char lbl_880DC810[];
extern char lbl_880DCE3C[];
extern char lbl_880DF260[];
extern char lbl_880DFC6C[];
extern char lbl_880E0728[];
extern char lbl_880E1048[];
extern char lbl_880E2FBC[];
extern char lbl_880E2FD4[];
extern char lbl_880E3004[];
extern char lbl_880E3018[];
extern char lbl_880E3638[];
extern char lbl_880E3644[];
extern char lbl_880E3E74[];
extern char lbl_880F7F38[];
extern char lbl_8814B440[];
extern char lbl_88C46F6A[];
extern char lbl_88C6ADAC[];
extern char lbl_88C6ADC8[];
extern char lbl_88C6B8F4[];
extern char lbl_88C6B90C[];
extern char lbl_88C6B918[];
extern char lbl_88C6B924[];
extern char lbl_88C6BE68[];
extern char lbl_88D45908[];
extern char lbl_88D4591C[];
extern char lbl_88D45948[];
extern char lbl_88D45954[];
extern char lbl_88D459B8[];
extern char lbl_88D459C8[];
extern char lbl_88D459D4[];
extern char lbl_88D459DC[];
extern char lbl_88D45A04[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
extern char lbl_88D45CC0[];
ts4_word ts4_loop_call_seq_u32_off0_88150378();
ts4_word fn_881609C8();
ts4_word fn_881640A8();
ts4_word fn_8816CAA0();
ts4_word ts4_if_call_seq_u32_off0_8816D140();
ts4_word fn_88178AA8();
ts4_word ts4_call_seq_u32_off0_8817B998();
ts4_word fn_8817DF90();
ts4_word fn_8817E150();
ts4_word ts4_if_call_seq_u32_off4_8817E430();
ts4_word fn_8817EA90();
ts4_word fn_8817EE38();
ts4_word ts4_loop_call_seq_u32_off40_881815A8();
ts4_word ts4_loop_call_seq_u32_0x4_88181670();
ts4_word fn_88187AB8();
ts4_word fn_8819AE68();
ts4_word fn_8819C190();
ts4_word fn_881A6A00();
ts4_word fn_881A7A20();
ts4_word fn_881A9BE8();
ts4_word fn_881AB108();
ts4_word fn_881B19A0();
ts4_word fn_881B9148();
ts4_word ts4_if_atomic_interlocked_dec_88288530();
ts4_word fn_882908C0();
ts4_word fn_88290C68();
ts4_word fn_882C7288();
ts4_word ts4_forward_to_fn_8841B5E0();
ts4_word ts4_tailcall_fn_885827E0_88563110();
ts4_word fn_88564F40();
ts4_word fn_885651F8();
ts4_word ts4_crt_nh_malloc_88565258();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word ts4_tailcall_XamEnumerate_8857A1C8();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word ts4_tailcall_XamContentDelete_8857B2D0();
ts4_word ts4_tailcall_XamContentClose_8857B2D8();
ts4_word ts4_tailcall_XamContentCreateEnumerator_8857B2F0();
ts4_word fn_8857B388();
ts4_word fn_8857B4C8();
ts4_word ts4_get_u32__imp_KeTimeStampBundle_8857B830();
ts4_word ts4_tailcall_fn_88582660_8857B840();
ts4_word fn_8857C1F8();
ts4_word fn_88581AF0();
ts4_word fn_88581B70();
ts4_word fn_8860BBD8();
ts4_word fn_88613350();
ts4_word fn_88614938();
ts4_word ts4_if_call_seq_lbl_880F7EE4_88617D28();
ts4_word fn_88617D88();
ts4_word fn_88619E50();
ts4_word fn_8861AB88();
ts4_word fn_88622E88();
ts4_word fn_8862A1F0();
ts4_word fn_8862C0E8();
ts4_word fn_88631048();
ts4_word fn_88636CF0();
ts4_word fn_887D9C90();
ts4_word ts4_if_call_seq_u32_offc_887E6550();
ts4_word fn_887EB4A0();
ts4_word ts4_if_call_seq_lbl_880E3E3C_887FC130();
ts4_word ts4_call_seq_fn_88832F70_88806570();
ts4_word fn_88814BB8();
ts4_word ts4_if_call_seq_u32_off10_88815520();
ts4_word fn_888216D0();
ts4_word fn_88821878();
ts4_word ts4_call_seq_u32_off0_88832F70();
ts4_word fn_888368B0();
ts4_word ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
ts4_word fn_88864E48();
ts4_word fn_88865AB0();
ts4_word fn_88866980();
ts4_word fn_88866DA0();
ts4_word fn_88867E68();
ts4_word ts4_hash_lookup_null_888689A8();
ts4_word fn_88868B48();
ts4_word fn_888690F0();
ts4_word fn_88869530();
ts4_word fn_8886B1B0();
ts4_word ts4_if_call_seq_u32_lbl_88D45B1C_8886B520();
ts4_word fn_8886B5C0();
ts4_word fn_8886F9A0();
ts4_word ts4_if_call_seq_u32_off48_88871778();
ts4_word fn_888719E0();
ts4_word ts4_crc32_big_88878408();
ts4_word ts4_adler32_88878A90();
ts4_word fn_88882868();
ts4_word fn_88884FD0();
ts4_word fn_888860A0();
ts4_word fn_8888A4E8();
ts4_word fn_88891310();
ts4_word fn_888A10A0();
ts4_word ts4_xml_pool_grow_888A2F00();
ts4_word ts4_if_get_u8_offec_888A8610();
ts4_word fn_888AA228();
ts4_word fn_888AA328();
ts4_word ts4_if_get_u32_lbl_88D45B1C_888C0198();
ts4_word fn_888C3768();
ts4_word fn_888C7718();
ts4_word fn_888C93E8();
ts4_word fn_888C9A68();
ts4_word fn_888CCFF0();
ts4_word fn_888CD190();
ts4_word fn_888CD2B8();
ts4_word fn_888CE8D0();
ts4_word fn_888CF650();
ts4_word fn_888D3648();
ts4_word fn_888D7920();
ts4_word fn_888D84B8();
ts4_word ts4_if_call_seq_fn_8817EA90_888D85B0();
ts4_word fn_888DD008();
ts4_word fn_888E7720();
ts4_word fn_888EC548();
ts4_word fn_888F1170();
ts4_word fn_888F1B30();
ts4_word ts4_call_seq_u32_off1c_888F5D50();
ts4_word fn_888F69A0();
ts4_word fn_888F7160();
ts4_word fn_889006D8();
ts4_word fn_88901010();
ts4_word fn_88907570();
ts4_word fn_88908B38();
ts4_word ts4_net_update_slots_88908B80();
ts4_word fn_8890A1F0();
ts4_word fn_8890CB18();
ts4_word fn_8890F370();
ts4_word fn_8890F428();
ts4_word fn_88914A70();
ts4_word fn_88929E70();
ts4_word ts4_loop_call_seq_lbl_880D6268_8892AF80();
ts4_word ts4_call_seq_fn_88617D88_8892AFF0();
ts4_word ts4_if_get_u32_off0_8892FE20();
ts4_word fn_88B08168();
ts4_word fn_88B083F8();
ts4_word fn_88B085A8();
ts4_word fn_88B09368();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_memset();
ts4_word ts4_object_finalize();
ts4_word ts4_profile_internal_activate();

/* Swing_DLL.xex 0x888A0DD8: if_get u32@0x10, ts4_if_addr_fn_888A0DD8_888A0D60, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A0DD8(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 18) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_if_addr_fn_888A0DD8_888A0D60;
        return 32;
    }
    return 33;
}

/* Swing_DLL.xex 0x888A15C0: if_get u32@0x10, ts4_if_addr_fn_888A15C0_888A1540, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A15C0(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 18 && (int)a1 != 41) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_if_addr_fn_888A15C0_888A1540;
        return 51;
    }
    return 39;
}

/* Swing_DLL.xex 0x888A1E90: if_get u32@0x10, ts4_if_get_u32_off10_888A1E30, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A1E90(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 27) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_if_get_u32_off10_888A1E30;
        return 14;
    }
    return 11;
}

/* Swing_DLL.xex 0x888A21B0: if_get u32@0x10, ts4_if_get_u32_off10_888A2150, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A21B0(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 27) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_if_get_u32_off10_888A2150;
        return 14;
    }
    return 11;
}

/* Swing_DLL.xex 0x888A2380: if_addr ts4_prolog_entity_external_or_value_888A2210, u32@0x0, u32@0x10, ts4_if_get_u32_off10_888A2320, u32@0x0, u32@0x10 */
ts4_word ts4_if_addr_fn_888A2210_888A2380(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 18) {
            if ((int)a1 != 22) {
                t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
                if ((int)t2 == 0 && (int)a1 == 28) {
                    return 59;
                }
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
                return -1;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_if_get_u32_off10_888A2320;
            return 11;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_prolog_entity_external_or_value_888A2210;
        return 9;
    }
    return 11;
}

/* Swing_DLL.xex 0x888A2700: if_get u32@0x10, ts4_if_addr_fn_888A1178_888A2680, u32@0x0, u32@0x10, ts4_fn_888A09C0, u32@0x0 */
ts4_word ts4_if_get_u32_off10_888A2700(ts4_word a0, int a1)
{
    int t2;

    if ((int)a1 != 15) {
        if ((int)a1 != 27) {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            if ((int)t2 == 0 && (int)a1 == 28) {
                return 59;
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_fn_888A09C0;
            return -1;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)ts4_if_addr_fn_888A1178_888A2680;
        return 5;
    }
    return 3;
}


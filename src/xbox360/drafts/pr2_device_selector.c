/*
 * DRAFT (not byte-matched): storage-device selector state machine, frontend-map section 1.3.
 *
 * 0x8888A1B8 (0x2D8) per-frame update of one device-selector object (the object TCR_SelectDevice
 *   0x88785B10 starts; TCR_WaitForDeviceSelector polls its +0x4C/"active" through 0x88D45A58).
 *   Fields: +0x1C pad index, +0x20 chosen device id, +0x24 XOVERLAPPED (first word = status,
 *   0x3E5 = ERROR_IO_PENDING), +0x40 XN_SYS listener, +0x4C active, +0x254 default device id,
 *   +0x258 XN_SYS_UI listener, +0x25C use-default, +0x25D device-lost reported, +0x25E waiting for the UI
 *   to close, +0x25F UI seen open, +0x260 show requested, +0x268 minimum bytes (u64), +0x270 flags.
 *   Order of work each frame:
 *   1. XN_SYS_STORAGEDEVICESCHANGED (0xB): when the pad's record (+0x1C device) has a device and
 *      XamContentGetDeviceState says it is gone, report it once (record +0x19 set:
 *      ts4_call_seq_ts4_find_service_88907630(pad)) or reset the selector (fn_88887A00).  Then, if the pad
 *      is signed in (+0x1A) and +0x19 is set and fn_888F67B8(pad, [0x88D45B34]) is 0, ask the TCR service
 *      0xF4F09230 (fn_888DA428).
 *   2. Nothing more unless active or waiting for close.
 *   3. Show requested: when XN_SYS_UI reports 0 (no system UI up) call
 *      XamShowDeviceSelectorUI(user, 1, flags, min_bytes, &device, &overlapped) and clear the request.
 *   4. Not yet waiting for close: XN_SYS_UI == 1 marks the UI as seen; while the overlapped is pending
 *      return; otherwise take the default device when none was chosen, store it in the pad record
 *      (+0x1C), and if there is a device read XamContentGetDeviceData (type 2 = memory unit calls
 *      fn_888DA288 and finishes).  Then wait for the UI to close if it was seen, else finish.
 *   5. Waiting for close: XN_SYS_UI == 0 clears the wait and finishes (active = 0).
 *   Port note: the selector only finishes when XN_SYS_UI notifications arrive (1 then 0) or the UI was
 *   never seen; a host that completes the overlapped but never posts XN_SYS_UI keeps it waiting if
 *   the "seen" flag was set.
 *   19 instructions off on the LTCG route (context src/xbox360/pr2_signin.c, needed because the original
 *   keeps r4 live across ts4_pad_record_find_88614938): the two notification out-parameter pairs get
 *   interleaved stack slots in the original (id 0x50, ui_param 0x54, param 0x58, ui_id 0x5C), and the
 *   four saved arguments of XamShowDeviceSelectorUI get different register numbers.  Tried: all 24
 *   declaration orders, renaming, splitting the tail.
 * fn_equiv (work/equiv/pr2_8888A1B8.json, --trials 2000): UNCHECKED, coverage 87% (33/38 blocks) is below
 *   the 90% bar; all 1883 valid trials agree.
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;
typedef struct PadObj { u8 pad[0xc]; int pad_index; u8 pad10[9]; u8 b19; u8 b1a; u8 b1b; u32 device; } PadObj;
typedef struct ModList ModList;
typedef struct Engine { u8 pad[0x234]; ModList *modules; } Engine;
typedef struct XDeviceData { u32 device_id; u32 device_type; u64 bytes; u64 free_bytes; unsigned short name[27]; } XDeviceData;
typedef struct DevSel {
    u8 pad[0x1c]; int pad_index; u32 device_id; u32 ov_status; u8 pad28[0x18]; void *storage_listener;
    u8 pad44[8]; u8 active; u8 pad4d[0x207]; u32 default_device; void *ui_listener; u8 use_default;
    u8 lost_reported; u8 wait_close; u8 ui_seen; u8 show_pending; u8 pad261[7]; u64 min_bytes; u32 flags;
} DevSel;
extern Engine *lbl_88D45B1C;
extern void *lbl_88D45B34;
extern int XNotifyGetNext(void *listener, u32 id, u32 *out_id, int *out_param);
extern PadObj *ts4_pad_record_find_88614938(ModList *m, int pad);
extern u32 ts4_tailcall_XamContentGetDeviceState_8857B2F8(u32 device, void *ov);
extern u32 ts4_tailcall_XamContentGetDeviceData_8857B300(u32 device, XDeviceData *d);
extern u32 ts4_tailcall_XamShowDeviceSelectorUI_8857A6C8(u32 user, u32 content_type, u32 flags, u64 min_bytes, u32 *device, void *ov);
extern void ts4_call_seq_ts4_find_service_88907630(int pad);
extern void fn_88887A00(DevSel *s);
extern u8 fn_888F67B8(int pad, void *x);
extern void *ts4_find_service(u32 id);
extern void fn_888DA428(void *tcr, int pad);
extern u32 ts4_if_call_seq_u32_off1c_888864F8(DevSel *s);
extern void fn_888DA288(int pad);

void ts4_device_selector_update_8888A1B8(DevSel *s)
{
    u32 id;
    u32 param;
    int ui_param;
    u32 ui_id;
    XDeviceData d;
    if (XNotifyGetNext(s->storage_listener, 0, &id, (int *)&param) && id == 0xB) {
        if (ts4_pad_record_find_88614938(lbl_88D45B1C->modules, s->pad_index)->device != 0
            && ts4_tailcall_XamContentGetDeviceState_8857B2F8(s->device_id, 0) != 0) {
            Engine *e = lbl_88D45B1C;
            if (ts4_pad_record_find_88614938(e->modules, s->pad_index)->b19) {
                if (!s->lost_reported) {
                    s->lost_reported = 1;
                    ts4_call_seq_ts4_find_service_88907630(ts4_pad_record_find_88614938(e->modules, s->pad_index)->pad_index);
                }
            } else {
                fn_88887A00(s);
            }
        }
        {
            ModList *m = lbl_88D45B1C->modules;
            if (ts4_pad_record_find_88614938(m, s->pad_index)->b1a
                && ts4_pad_record_find_88614938(m, s->pad_index)->b19
                && !fn_888F67B8(ts4_pad_record_find_88614938(m, s->pad_index)->pad_index, lbl_88D45B34)) {
                int pad = ts4_pad_record_find_88614938(lbl_88D45B1C->modules, s->pad_index)->pad_index;
                fn_888DA428(ts4_find_service(0xF4F09230), pad);
            }
        }
    }
    if (!s->active && !s->wait_close)
        return;
    if (s->show_pending) {
        if (!XNotifyGetNext(s->ui_listener, 9, &ui_id, &ui_param) || ui_param != 0)
            return;
        ts4_tailcall_XamShowDeviceSelectorUI_8857A6C8(ts4_if_call_seq_u32_off1c_888864F8(s), 1, s->flags, s->min_bytes, &s->device_id, &s->ov_status);
        s->show_pending = 0;
        return;
    }
    if (!s->wait_close) {
        if (XNotifyGetNext(s->ui_listener, 9, &ui_id, &ui_param) && ui_param == 1)
            s->ui_seen = 1;
        if (s->ov_status == 0x3e5)
            return;
        if (s->device_id == 0 && s->use_default)
            s->device_id = s->default_device;
        ts4_pad_record_find_88614938(lbl_88D45B1C->modules, s->pad_index)->device = s->device_id;
        if (s->device_id != 0) {
            ts4_tailcall_XamContentGetDeviceData_8857B300(s->device_id, &d);
            s->lost_reported = 0;
            if (d.device_type == 2) {
                fn_888DA288(ts4_pad_record_find_88614938(lbl_88D45B1C->modules, s->pad_index)->pad_index);
                s->active = 0;
            } else if (s->ui_seen) {
                s->wait_close = 1;
            } else {
                s->active = 0;
            }
        } else if (s->ui_seen) {
            s->wait_close = 1;
        } else {
            s->active = 0;
        }
        return;
    }
    if (XNotifyGetNext(s->ui_listener, 9, &ui_id, &ui_param) && ui_param == 0) {
        s->wait_close = 0;
        s->active = 0;
    }
}

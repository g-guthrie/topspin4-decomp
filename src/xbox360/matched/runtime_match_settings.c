/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
#include "typed_handle.h"
#include "registry_lookup.h"

typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
typedef int ts4_s32;

extern void *g_ts4_session_context;
extern void *lbl_88D458F0;
extern void *lbl_88D45B1C;
extern void *lbl_88D45B0C;
extern void *lbl_88D45AD4;
extern void *lbl_88D45910;
extern void *lbl_88D45A60;
extern void *lbl_88D41FC4;
extern void *lbl_88D42948[];     /* item array; its count word is at +0x31A4 */
extern const ts4_u8 lbl_88C4763C[];  /* type descriptor */
extern const char lbl_880D891C[];
extern const char lbl_880D85CC[];
extern const char lbl_880D82D0[];

void *fn_881518D0(void *table, const ts4_u32 *key);
ts4_u8 *fn_8892E7A0(void *self, void *bucket, ts4_u32 one_a, void *context, ts4_u32 one_b, ts4_entry_iterator after,
    ts4_entry_filter filter);
void fn_88169350(ts4_u32 *kind, const ts4_typed_handle *handle);
ts4_u8 *fn_88180F08(void *registry, ts4_u32 key, void *context, ts4_entry_iterator after, ts4_entry_filter filter);
void fn_888E6DE0(void);
ts4_u32 fn_888CDBC8(void *settings, ts4_u32 key);
void fn_888D7850(ts4_u8 *entry, ts4_u32 value);
void fn_886ECAE0(void *mode, ts4_u32 kind);
void fn_888C3940(void *mode, ts4_u32 kind);
void fn_886EA830(void *item, ts4_entry_iterator after, ts4_entry_filter filter);
ts4_typed_handle *fn_88610778(ts4_typed_handle *result, const ts4_typed_handle *handle, const ts4_u32 *key);
ts4_typed_handle *fn_88164450(ts4_typed_handle *result, const ts4_typed_handle *handle, const ts4_u32 *key,
    ts4_u32 zero);
void fn_8876BCA8(void *notifier);
void fn_88210B18(void *packs);
void fn_888C3198(void *self, ts4_u32 enable);

#define TS4_MATCH_TYPE_KEY 0xC750E1ACu
#define TS4_MATCH_TYPE_KIND 0x1DCA7285u
#define TS4_ONLINE_MODE_TYPE 0xF895ECB1u
#define TS4_RANKED_MODE 0xCD0B222Fu

static ts4_u32 ts4_online_mode_kind(const ts4_u8 *settings)
{
    ts4_typed_handle handle;
    ts4_u8 *record;
    fn_8862C0E8(&handle, lbl_880D85CC);
    record = fn_88923530(handle.container, handle, TS4_ONLINE_MODE_TYPE);
    if (*(const ts4_u32 *)(settings + 0x18) != TS4_MATCH_TYPE_KIND) {
        return 1;
    }
    return *(ts4_u32 *)(record + 0x22C) == TS4_RANKED_MODE ? 2 : 4;
}

/*
 * 0x8899D348-0x8899D3B0, upstream name ts4_lobby_is_full (called by
 * ts4_script_is_lobby_full with the lobby at +0x1C of the session context):
 * counts the 216-byte slots (array at the lobby's +0xAC object: {offset,
 * count}) whose byte +0xC0 is set, last to first, and returns 1 when the
 * count equals the match's words +0x2C8 + +0x2C4 (low 32 bits).
 */
struct TS4Lobby;

/*
 * 0x88180DA0-0x88180E18 (1 direct caller): returns `object` when the type
 * chain from its slot 0 (each descriptor's word +8 is its parent) reaches
 * lbl_88C4763C, else 0; 0 for a null object. The first descriptor is used
 * without a null test (bounded: slot 0 returns a descriptor).
 */
typedef const ts4_u8 *(*ts4_type_of)(void *object);

void *ts4_runtime_cast_to_88c4763c_88180da0(void *object)
{
    const ts4_u8 *type;
    if (!object) {
        return 0;
    }
    type = ((ts4_type_of)(*(void ***)object)[0])(object);
    do {
        if (type == lbl_88C4763C) {
            return object;
        }
        type = *(const ts4_u8 *const *)(type + 8);
    } while (type);
    return 0;
}

/*
 * 0x8890A948-0x8890AA50 (3 direct callers): the first argument is a 12-byte
 * handle by value (r3, upper half of r4). Looks up the child keyed
 * 0x7C78B5F5 (0x88610778), writes `value` as a byte to its member keyed
 * 0xD91411DA and 0 to its member keyed 0xB01F4F95 (0x88164450, then slot
 * +0x28 of the member's owner with size 1 returns the storage), and when
 * `notify` has a nonzero low byte calls 0x8876BCA8(lbl_88D45AD4 + 0x150).
 */
typedef ts4_u8 *(*ts4_member_storage)(ts4_typed_owner *owner, ts4_typed_handle *member, ts4_u32 index, ts4_u32 size);

static ts4_u8 *ts4_member_byte(ts4_typed_handle *child, ts4_u32 key, ts4_typed_handle *scratch)
{
    ts4_typed_handle *member = fn_88164450(scratch, child, &key, 0);
    ts4_typed_owner *owner = member->owner;
    return ((ts4_member_storage)(*(void ***)owner)[0x28 / 4])(owner, member, member->index, 1);
}


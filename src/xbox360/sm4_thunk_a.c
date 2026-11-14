/* SM4: forwarders from an embedded sub-object (at +0x20 of the owner) to a shared helper. */
extern void ts4_push_back_word_8846C738(void *, void *);
extern void ts4_push_back_word_8846C8F8(void *, void *);
extern void ts4_clear_pointer_slot_8846B168(void *, void *);
extern void ts4_clear_pointer_slot_8846B2A8(void *, void *);

/* helper(x, owner ? &owner->field28 : 0) where this points at owner + 0x20 */
#define SUBOBJ_FWD(NAME, CALLEE) \
    void NAME(char *self, void *x) \
    { \
        char *owner = self - 0x20; \
        char *member = self + 8; \
        CALLEE(x, owner ? member : 0); \
    }

SUBOBJ_FWD(ts4_sub28_push_back_884AB8C8, ts4_push_back_word_8846C738) /* Swing_DLL.xex 0x884AB8C8 */
SUBOBJ_FWD(ts4_sub28_clear_slot_884AB8E8, ts4_clear_pointer_slot_8846B168) /* Swing_DLL.xex 0x884AB8E8 */
SUBOBJ_FWD(ts4_sub28_push_back_884AFB30, ts4_push_back_word_8846C8F8) /* Swing_DLL.xex 0x884AFB30 */
SUBOBJ_FWD(ts4_sub28_clear_slot_884AFB50, ts4_clear_pointer_slot_8846B2A8) /* Swing_DLL.xex 0x884AFB50 */
SUBOBJ_FWD(ts4_sub28_push_back_884B1070, ts4_push_back_word_8846C738) /* Swing_DLL.xex 0x884B1070 */
SUBOBJ_FWD(ts4_sub28_clear_slot_884B1090, ts4_clear_pointer_slot_8846B168) /* Swing_DLL.xex 0x884B1090 */
SUBOBJ_FWD(ts4_sub28_push_back_884B2370, ts4_push_back_word_8846C738) /* Swing_DLL.xex 0x884B2370 */
SUBOBJ_FWD(ts4_sub28_clear_slot_884B2390, ts4_clear_pointer_slot_8846B168) /* Swing_DLL.xex 0x884B2390 */
SUBOBJ_FWD(ts4_sub28_push_back_884B2E98, ts4_push_back_word_8846C738) /* Swing_DLL.xex 0x884B2E98 */
SUBOBJ_FWD(ts4_sub28_clear_slot_884B2EB8, ts4_clear_pointer_slot_8846B168) /* Swing_DLL.xex 0x884B2EB8 */
SUBOBJ_FWD(ts4_sub28_push_back_884B96B0, ts4_push_back_word_8846C738) /* Swing_DLL.xex 0x884B96B0 */
SUBOBJ_FWD(ts4_sub28_clear_slot_884B96D0, ts4_clear_pointer_slot_8846B168) /* Swing_DLL.xex 0x884B96D0 */

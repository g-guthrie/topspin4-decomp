/* Family FAM2: small helpers that share their shape with already-matched functions (Swing_DLL.xex).
   Each pattern names the matched sibling it was taken from. */
typedef unsigned int u32;
typedef unsigned char u8;

extern char lbl_880EFD04[];
extern char lbl_880D75FC[];
extern char lbl_880D7604[];
extern char lbl_880DC604[];
void ts4_destroy_owned_object(void *object);
void *fn_881AA340(void *dst, void *src, u32 count);
void *ts4_copy_vec3_range_8816B0F8(void *dst, void *src, u32 count);
void *ts4_copy_friend_leaderboard_records(void *dst, void *src, u32 count);
u32 fn_8887B148(void *object, u32 tag);
struct TS4BufferPair { u32 size; void *data; };

/* Destructor: install the vtable, then destroy the owned object in FIELD if present (as ts4_dtor_owned_8867C0E0). */
#define TS4_DTOR_OWNED(A, VT, FIELD) \
void ts4_dtor_owned_##A(char *p); \
void ts4_dtor_owned_##A(char *p) { void *q; *(char *volatile *)p = (VT); q = *(void *volatile *)(p + (FIELD)); if (q) ts4_destroy_owned_object(q); }
TS4_DTOR_OWNED(8876FD18, lbl_880EFD04, 4)
TS4_DTOR_OWNED(8887CB48, lbl_880D75FC, 4)
TS4_DTOR_OWNED(8890ECC0, lbl_880D75FC, 4)
TS4_DTOR_OWNED(8890EF68, lbl_880D75FC, 4)
TS4_DTOR_OWNED(8890FFD0, lbl_880D7604, 0x14)

/* Destroy the object held in the first word when present. */
#define TS4_DESTROY_HELD(A, FIELD) \
void ts4_destroy_held_object_##A(char *holder); \
void ts4_destroy_held_object_##A(char *holder) { void *p = *(void **)(holder + (FIELD)); if (p) ts4_destroy_owned_object(p); }
TS4_DESTROY_HELD(88870B68, 0)
TS4_DESTROY_HELD(88870FB0, 0xc)
TS4_DESTROY_HELD(888714A0, 0)
TS4_DESTROY_HELD(888716B8, 0)

/* Re-run a range operation over a (count, data) pair in place: data = OP(data, data, count)
   (as ts4_buffer_step_88709D58). */
#define TS4_BUFFER_STEP(A, OP, OFF) \
typedef struct obj_##A { char pad[OFF]; struct TS4BufferPair pair; } obj_##A; \
void ts4_buffer_step_##A(obj_##A *self); \
void ts4_buffer_step_##A(obj_##A *self) { struct TS4BufferPair *pair = &self->pair; pair->data = OP(pair->data, pair->data, pair->size); }
TS4_BUFFER_STEP(888709F8, fn_881AA340, 0xc)
TS4_BUFFER_STEP(8887DCB0, ts4_copy_vec3_range_8816B0F8, 0xbc)
TS4_BUFFER_STEP(8899C9F8, ts4_copy_friend_leaderboard_records, 0x20)

/* Self-relative array (offset, count): address one past the last STRIDE-byte element, or NULL when the
   offset is -1 (as ts4_offset_array_end132_88160A88). */
#define TS4_ARRAY_END(A, STRIDE) \
char *ts4_offset_array_end_##A(int *arr); \
char *ts4_offset_array_end_##A(int *arr) { char *result = 0; if (arr[0] != -1) result = (char *)arr + (arr[1] * (STRIDE) + arr[0]); return result; }
TS4_ARRAY_END(88219CD8, 0x44)
TS4_ARRAY_END(8825E9A8, 0x34)

/* Clear a (flag byte, three words) record. */
#define TS4_CLEAR_FLAG_RECORD(A) \
void ts4_clear_flag_record_##A(char *p); \
void ts4_clear_flag_record_##A(char *p) { *(u8 *)p = 0; *(u32 *)(p + 4) = 0; *(u32 *)(p + 8) = 0; *(u32 *)(p + 12) = 0; }
TS4_CLEAR_FLAG_RECORD(8887BD00)
TS4_CLEAR_FLAG_RECORD(8887BD18)

/* Install the vtable and clear three words (volatile keeps the store order, as ts4_addr_lbl_880EFD04_8876FD38). */
#define TS4_INIT_THREE_WORDS(A, VT) \
void ts4_init_three_words_##A(char *p); \
void ts4_init_three_words_##A(char *p) { *(char *volatile *)p = (VT); *(volatile u32 *)(p + 4) = 0; *(volatile u32 *)(p + 8) = 0; *(volatile u32 *)(p + 12) = 0; }
TS4_INIT_THREE_WORDS(8887CB68, lbl_880D75FC)
TS4_INIT_THREE_WORDS(888AE338, lbl_880DC604)

/* Forward with a fixed tag constant. */
#define TS4_FORWARD_TAG(A, OP, TAG) \
u32 ts4_forward_tag_##A(void *object); \
u32 ts4_forward_tag_##A(void *object) { return OP(object, TAG); }
TS4_FORWARD_TAG(8887C388, fn_8887B148, 0x01505C7E)
TS4_FORWARD_TAG(8887C398, fn_8887B148, 0x26296DD2)
TS4_FORWARD_TAG(8887C3A8, fn_8887B148, 0x2B05E119)

/* Clear the byte at OFF of the object referenced at +8. */
#define TS4_CLEAR_CHILD_BYTE(A, OFF) \
void ts4_clear_child_byte_##A(char *p); \
void ts4_clear_child_byte_##A(char *p) { *(u8 *)(*(char **)(p + 8) + (OFF)) = 0; }
TS4_CLEAR_CHILD_BYTE(8887A330, 0x66)
TS4_CLEAR_CHILD_BYTE(8887A340, 0x67)

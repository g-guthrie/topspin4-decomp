/* Family FAM2: per-member state accessors (Swing_DLL.xex 0x888389C0..0x8883DCA8).
   Each finds the member whose id (+0x180) equals key in the owner's member vector (+0x20..+0x24;
   NULL when absent) and asks the member's component at +0x8c for its state block (virtual slot
   +0x4c with 0).  The variants store into, return the address of, or read a field of that block;
   the _OR0 getters tolerate a missing member or component and then return 0. */
typedef unsigned int u32;
typedef struct Ts4MemberOwner { char pad[0x20]; void ***first, ***last; } Ts4MemberOwner;
typedef char *(*Ts4StateFn)(void *, u32);

static __inline char *member_find(Ts4MemberOwner *self, int key)
{
    void ***end = self->last;
    void ***it = self->first;
    char *m = 0;
    for (; it != end; ++it) {
        if (*(int *)((char *)*it + 0x180) == key) {
            m = (char *)*it;
            break;
        }
    }
    return m;
}

static __inline char *member_state(Ts4MemberOwner *self, int key)
{
    void **comp = *(void ***)(member_find(self, key) + 0x8c);
    return ((Ts4StateFn)(*(void ***)comp)[0x4c / 4])(comp, 0);
}

#define TS4_MEMBER_FIELD_SET(A, OFF) \
void ts4_member_field_set_##A(Ts4MemberOwner *self, int key, u32 value); \
void ts4_member_field_set_##A(Ts4MemberOwner *self, int key, u32 value) \
{ \
    *(u32 *)(member_state(self, key) + OFF) = value; \
}

#define TS4_MEMBER_FIELD_ADDR(A, OFF) \
void *ts4_member_field_addr_##A(Ts4MemberOwner *self, int key); \
void *ts4_member_field_addr_##A(Ts4MemberOwner *self, int key) \
{ \
    return member_state(self, key) + OFF; \
}

#define TS4_MEMBER_FIELD_GET_OR0(A, OFF) \
u32 ts4_member_field_get_or0_##A(Ts4MemberOwner *self, int key); \
u32 ts4_member_field_get_or0_##A(Ts4MemberOwner *self, int key) \
{ \
    char *m = member_find(self, key); \
    void **comp; \
    u32 r = 0; \
    if (m != 0 && (comp = *(void ***)(m + 0x8c)) != 0) \
        r = *(u32 *)(((Ts4StateFn)(*(void ***)comp)[0x4c / 4])(comp, 0) + OFF); \
    return r; \
}

/* Store three words at +0, +8, +4 (Swing_DLL.xex 0x8883B3F8). */
void ts4_member_state_set3_8883B3F8(Ts4MemberOwner *self, int key, u32 a, u32 b, u32 c);
void ts4_member_state_set3_8883B3F8(Ts4MemberOwner *self, int key, u32 a, u32 b, u32 c)
{
    u32 *s = (u32 *)member_state(self, key);
    s[0] = a;
    s[2] = b;
    s[1] = c;
}

/* Return the state's +0xc word through a one-word struct out-parameter (Swing_DLL.xex 0x88838BB8). */
typedef struct Ts4StateWord { u32 v; } Ts4StateWord;
typedef struct Ts4StateBlock { u32 pad[3]; Ts4StateWord word; } Ts4StateBlock;
Ts4StateWord *ts4_member_state_word_88838BB8(Ts4StateWord *out, Ts4MemberOwner *self, int key);
Ts4StateWord *ts4_member_state_word_88838BB8(Ts4StateWord *out, Ts4MemberOwner *self, int key)
{
    *out = ((Ts4StateBlock *)member_state(self, key))->word;
    return out;
}

/* Swing_DLL.xex addresses */
TS4_MEMBER_FIELD_SET(8883B478, 0x20)
TS4_MEMBER_FIELD_SET(8883B4F8, 0x1c)
TS4_MEMBER_FIELD_SET(8883DBA8, 0x24)
TS4_MEMBER_FIELD_SET(8883DC28, 0x10)
TS4_MEMBER_FIELD_SET(8883DCA8, 0xc)
TS4_MEMBER_FIELD_ADDR(8883B318, 0x104)
TS4_MEMBER_FIELD_ADDR(8883B388, 0x3c)
TS4_MEMBER_FIELD_ADDR(8883B578, 0x1174)
TS4_MEMBER_FIELD_GET_OR0(888389C0, 0x1238)
TS4_MEMBER_FIELD_GET_OR0(88838C40, 0x1248)


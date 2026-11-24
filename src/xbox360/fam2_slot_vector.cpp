// FAM2: flag accessors on a vector of 0x1c-byte slots held at +0xc.  Each
// bounds-checks the index against size() and reads or writes byte flags of
// one slot.  Written as C++ so the vector's size()/operator[] produce the
// original pointer arithmetic.
typedef unsigned int u32;
typedef unsigned char u8;

struct Ts4Slot {
    u8 b[0x1c];
};

template <class T> struct Ts4Vec {
    T *first, *last, *end_;
    u32 size() const { return (u32)(last - first); }
    T &operator[](u32 i) { return *(first + i); }
};

struct Ts4SlotOwner {
    u32 pad[3];
    Ts4Vec<Ts4Slot> slots;
};

// Slot is in use and its flag pair (OFF, OFF+1) equals (V0, V1).
#define TS4_SLOT_FLAGS_EQ(A, OFF, V0, V1) \
extern "C" int ts4_slot_flags_eq_##A(Ts4SlotOwner *self, u32 idx) \
{ \
    if (self->slots.size() > idx) { \
        Ts4Slot &s = self->slots[idx]; \
        if (s.b[0] && s.b[OFF] == V0 && s.b[OFF + 1] == V1) \
            return 1; \
    } \
    return 0; \
}

TS4_SLOT_FLAGS_EQ(888C0B18, 6, 1, 0)
TS4_SLOT_FLAGS_EQ(888C0C10, 4, 0, 1)
TS4_SLOT_FLAGS_EQ(888C0C68, 4, 1, 0)
TS4_SLOT_FLAGS_EQ(888C0CC0, 2, 0, 1)
TS4_SLOT_FLAGS_EQ(888C0D18, 2, 1, 0)

extern "C" int ts4_slot_flag4_clear_888C0B70(Ts4SlotOwner *self, u32 idx)
{
    if (self->slots.size() > idx) {
        Ts4Slot &s = self->slots[idx];
        if (s.b[0] && s.b[4] == 0)
            return 1;
    }
    return 0;
}

extern "C" void ts4_slot_mark_used_888C0D70(Ts4SlotOwner *self, u32 idx)
{
    if (self->slots.size() > idx)
        self->slots[idx].b[0] = 1;
}

extern "C" void ts4_slot_clear_flag1_888C0AE0(Ts4SlotOwner *self, u32 idx)
{
    if (idx < self->slots.size())
        self->slots[idx].b[1] = 0;
}

extern "C" void ts4_slot_set_all_flag1_888C0A30(Ts4SlotOwner *self)
{
    for (u32 i = 0; i < self->slots.size(); i++)
        self->slots[i].b[1] = 1;
}

extern "C" u8 ts4_slot_flag1_888C09F8(Ts4SlotOwner *self, u32 idx)
{
    if (idx < self->slots.size())
        return self->slots[idx].b[1];
    return 0;
}

extern "C" void ts4_slot_clear_all_flag1_888C0A88(Ts4SlotOwner *self)
{
    for (u32 i = 0; i < self->slots.size(); i++)
        self->slots[i].b[1] = 0;
}

extern "C" int ts4_slot_flag2_clear_888C0BC0(Ts4SlotOwner *self, u32 idx)
{
    if (self->slots.size() > idx) {
        Ts4Slot &s = self->slots[idx];
        if (s.b[0] && s.b[2] == 0)
            return 1;
    }
    return 0;
}

extern "C" void ts4_slot_mark_free_888C0DA0(Ts4SlotOwner *self, u32 idx)
{
    if (self->slots.size() > idx)
        self->slots[idx].b[0] = 0;
}

// 0x14-byte records whose first word is an id; vector at +0x68.
struct Ts4IdRecord {
    int id;
    u32 pad[4];
};

struct Ts4IdOwner {
    u8 pad[0x68];
    Ts4Vec<Ts4IdRecord> recs;
};

extern "C" int ts4_id_record_get_88838568(Ts4IdOwner *self, int idx)
{
    if (idx > -1 && (u32)idx < self->recs.size())
        return self->recs[idx].id;
    return -1;
}

extern "C" void ts4_id_record_clear_888385B0(Ts4IdOwner *self, int idx)
{
    if (idx > -1 && (u32)idx < self->recs.size())
        self->recs[idx].id = -1;
}

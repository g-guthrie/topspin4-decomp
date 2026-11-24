/* Swing_DLL.xex 0x883FD1D8: equality test of two FMOD event-system objects (FMOD Ex 4.32 event range;
 * vtable 0x8803A1C8 slot 4): equal when `other` is non-null, reports the same kind through virtual
 * slot 3, and has the same byte at +0x11.
 * Matches only as a member function with the receiver's byte written first (`sub_id == other->sub_id`):
 * the implicit-this field is then loaded after other's. As an extern "C" function with an explicit
 * `self`, every operand order loads self's byte first (2 off). */

struct Ts4FmodKeyed {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int kind();
    char pad_04[0xd];
    unsigned char sub_id; /* +0x11 */
    bool same_as(Ts4FmodKeyed *other);
};

/* Swing_DLL.xex 0x883FD1D8 (vtable slot only, no direct callers) */
bool Ts4FmodKeyed::same_as(Ts4FmodKeyed *other)
{
    if (other && other->kind() == kind())
        return sub_id == other->sub_id;
    return false;
}

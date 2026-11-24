/* Swing_DLL.xex family of member virtual call forwarders, executable version 0.0.0.3. */
typedef struct Ts4VObject {
    int (**vtable)(struct Ts4VObject *);
} Ts4VObject;
typedef struct Ts4VMemberOwner178 { char pad[0x178]; Ts4VObject *member; } Ts4VMemberOwner178;
typedef struct Ts4VMemberOwner24 { char pad[0x24]; Ts4VObject *member; } Ts4VMemberOwner24;

int ts4_forward_member_vcall_8860CCC0(Ts4VMemberOwner178 *self)
{
    Ts4VObject *member = self->member;
    int result = 0;
    if (member != 0) {
        result = member->vtable[16](member);
    }
    return result;
}

int ts4_forward_member_vcall_8860CCE8(Ts4VMemberOwner178 *self)
{
    Ts4VObject *member = self->member;
    int result = 0;
    if (member != 0) {
        result = member->vtable[15](member);
    }
    return result;
}

int ts4_forward_member_vcall_8860CD10(Ts4VMemberOwner178 *self)
{
    Ts4VObject *member = self->member;
    int result = 0;
    if (member != 0) {
        result = member->vtable[14](member);
    }
    return result;
}

int ts4_forward_member_vcall_8860E5E8(Ts4VMemberOwner24 *self)
{
    Ts4VObject *member = self->member;
    int result = 0;
    if (member != 0) {
        result = member->vtable[14](member);
    }
    return result;
}

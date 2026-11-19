/* 0x8836B5D0: Calls fn_88319C40(owner->target (+0x108), (unsigned int)value, 0) and returns whether the result is non-zero; the first argument is unused. */
/* Matched on /Oc (agAH). A long long argument truncated with (unsigned int) gives the clrrwi r4,r4,0 zero-extend; an unsigned int parameter gives rldicl instead. */
typedef struct Owner { char pad[0x108]; void *target; } Owner;
int fn_88319C40(void *o, long long a, int c);
int fn_8836B5D0(void *self, long long value, Owner *owner)
{
    return fn_88319C40(owner->target, (unsigned int)value, 0) != 0;
}

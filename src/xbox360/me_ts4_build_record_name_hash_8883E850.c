/* Swing_DLL.xex 0x8883E850: hash prefix + record name (fallback key 0x68FDB418) + suffix, returned through a hidden pointer
 * bounded copy as do/break/while with the cursor set after the lookups; strncat room is 0x7C - (int)strlen(buf) */
typedef unsigned char u8;
typedef unsigned int u32;
unsigned int strlen(const char *s);
#pragma intrinsic(strlen)

typedef struct RelStr { int off; } RelStr; /* self-relative, -1 = none */
typedef struct NameRecord { u8 pad[8]; RelStr name; } NameRecord;
typedef struct NameTable NameTable;
typedef struct NameOwner { u8 pad[0xC]; NameTable *names; } NameOwner;
typedef struct NameHash { u32 hash; } NameHash;

NameRecord *ts4_find_record_by_key_881AD158(NameTable *t, const u32 *key);
char *ts4_crt_strncat_88564EF0(char *dst, const char *src, u32 n);
u32 fn_88608590(u32 seed, const char *s);
extern const char lbl_880E146C[];
extern const char lbl_880E1084[];
extern const char lbl_880C1320[];

static __inline const char *rel_str(RelStr *r, const char *def)
{
    return r->off != -1 ? (const char *)r + r->off : def;
}

NameHash *fn_8883E850(NameHash *out, NameOwner *o, u32 key)
{
    NameTable *t = o->names;
    NameRecord *r = ts4_find_record_by_key_881AD158(t, &key);
    char buf[0x80];
    const char *s;
    char *d;
    if (r == 0) {
        u32 def = 0x68FDB418;
        r = ts4_find_record_by_key_881AD158(t, &def);
    }
    s = lbl_880E146C;
    d = buf;
    do {
        if (*s == 0)
            break;
        *d++ = *s++;
    } while (d != buf + 0x7C);
    *d = 0;
    ts4_crt_strncat_88564EF0(buf, rel_str(&r->name, lbl_880C1320), 0x7C - (int)strlen(buf));
    ts4_crt_strncat_88564EF0(buf, lbl_880E1084, 0x7C - (int)strlen(buf));
    out->hash = fn_88608590(0, buf);
    return out;
}

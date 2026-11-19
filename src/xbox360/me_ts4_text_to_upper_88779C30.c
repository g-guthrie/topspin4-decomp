/* Swing_DLL.xex 0x88779C30: upper-case a wide string in place; non-ASCII characters go through the font's case mapper. */
typedef unsigned short u16;
typedef struct Ts4CaseMap Ts4CaseMap;
typedef struct Ts4CaseMapVt { void *s[13]; void (*to_upper)(Ts4CaseMap *m, u16 c, u16 *dst); } Ts4CaseMapVt;
struct Ts4CaseMap { Ts4CaseMapVt *vt; };
typedef struct Ts4FontSys { char pad[0xf0]; Ts4CaseMap *case_map; } Ts4FontSys;
typedef struct Ts4TextOwner { char pad[0x1b0]; Ts4FontSys *fonts; } Ts4TextOwner;
extern u16 ts4_if_fn_885677E8(u16 c);
void ts4_text_to_upper_88779C30(Ts4TextOwner *o, u16 **str)
{
    u16 *p = *str;
    if (((int *)p)[-3] == 0) return; /* string header: length word 12 bytes before the data */
    for (; *p; p++) {
        if (*p < 0x80)
            *p = ts4_if_fn_885677E8(*p);
        else
            o->fonts->case_map->vt->to_upper(o->fonts->case_map, *p, p);
    }
}

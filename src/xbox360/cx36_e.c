/* CX36: lookup and vector helpers, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* 0x889269F0: binary search of the object's sorted element array (count from slot 12) by the key at +0x30 */
typedef struct Cx36SrtEl { u8 pad[0x30]; u32 key; } Cx36SrtEl;
typedef struct Cx36SrtOwner { void **vt; u8 pad[0x70]; Cx36SrtEl **arr; } Cx36SrtOwner;
typedef int (*Cx36CountFn)(Cx36SrtOwner *o);
Cx36SrtEl *ts4_sorted_find_by_key_889269F0(Cx36SrtOwner *o, u32 key)
{
    Cx36SrtEl *r = 0;
    int lo = 0;
    int hi = ((Cx36CountFn)o->vt[12])(o) - 1;
    while (lo <= hi) {
        int mid = (hi + lo) / 2;
        Cx36SrtEl *e = o->arr[mid];
        if (e->key > key)
            hi = mid - 1;
        else if (e->key < key)
            lo = mid + 1;
        else {
            r = e;
            break;
        }
    }
    return r;
}

/* 0x88924250: binary search of the sorted pointer vector at +0x24 by the word at +4 */
typedef struct Cx36PtrEl { u32 w0; u32 key; } Cx36PtrEl;
typedef struct Cx36PtrVec { Cx36PtrEl **first; Cx36PtrEl **last; } Cx36PtrVec;
typedef struct Cx36PtrOwner { u8 pad[0x24]; Cx36PtrVec *v; } Cx36PtrOwner;
#if 0 /* near miss, not byte-identical */
Cx36PtrEl *ts4_ptrvec_find_88924250(Cx36PtrOwner *o, u32 *keyp)
{
    Cx36PtrVec *v = o->v;
    Cx36PtrEl *r = 0;
    int lo = 0;
    int hi = (int)(v->last - v->first) - 1;
    Cx36PtrEl *e;
    int mid;
    while (lo <= hi) {
        mid = (hi + lo) / 2;
        e = v->first[mid];
        if (e->key > *keyp)
            hi = mid - 1;
        else if (e->key < *keyp)
            lo = mid + 1;
        else {
            r = e;
            break;
        }
    }
    return r;
}
#endif

/* 0x88926DD8: look up a key in the self-relative table at +8; entries hold an offset to their name or -1 for the default */
typedef struct Cx36NameTab { int rel; int count; } Cx36NameTab;
typedef struct Cx36NameOwner { u8 pad[8]; Cx36NameTab *tab; } Cx36NameOwner;
extern char lbl_880C1320[];
#if 0 /* near miss, not byte-identical */
char *ts4_name_lookup_88926DD8(Cx36NameOwner *o, u32 key)
{
    Cx36NameTab *t = o->tab;
    int n;
    int i = 0;
    char *r = 0;
    if (t == 0)
        return 0;
    n = t->count;
    if (n > 0) {
        for (; i < n; i++) {
            u32 *e = (u32 *)((char *)t + (i * 8 + t->rel));
            if (e[1] == key) {
                int off;
                e = (u32 *)((char *)t + (i * 8 + t->rel));
                off = (int)e[0];
                if (off != -1)
                    return (char *)e + off;
                return lbl_880C1320;
            }
        }
    }
    return r;
}
#endif

/* 0x889281C0: push a word on the vector at +0x54 (grow when full), then notify */
typedef struct Cx36WVec { u32 *first; u32 *last; u32 *cap; } Cx36WVec;
typedef struct Cx36WOwner { u8 pad[0x54]; Cx36WVec v; } Cx36WOwner;
extern void ts4_vector_realloc_insert_8817F4E8(Cx36WVec *v, u32 *pos, u32 *val, u32 n);
extern void fn_88927E78(Cx36WOwner *o, u32 val);
void ts4_push_word_notify_889281C0(Cx36WOwner *o, u32 val)
{
    u32 tmp = val;
    Cx36WVec *v = &o->v;
    if (v->last != v->cap) {
        if (v->last)
            *v->last = val;
        v->last++;
    } else {
        ts4_vector_realloc_insert_8817F4E8(v, v->last, &tmp, 1);
    }
    fn_88927E78(o, val);
}

/* 0x88932388: copy the 16-byte payload from another object unless its slot-12 predicate holds */
typedef struct Cx36PaySub { u32 a, b, c, d; } Cx36PaySub;
typedef struct Cx36Pay { void **vt; Cx36PaySub s; } Cx36Pay;
#if 0
void cx36_pay_copy(Cx36PaySub *d, Cx36PaySub *s)
{
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
}
#endif
typedef u8 (*Cx36PayFn)(Cx36Pay *p);
#if 0 /* near miss, not byte-identical */
Cx36Pay *ts4_copy_payload_unless_88932388(Cx36Pay *dst, Cx36Pay *src)
{
    Cx36Pay *d = dst;
    Cx36Pay *s = src;
    if (!((Cx36PayFn)s->vt[12])(s)) {
        cx36_pay_copy(&d->s, &s->s);
    }
    return d;
}
#endif

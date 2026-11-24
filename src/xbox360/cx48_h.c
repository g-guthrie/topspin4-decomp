/* CW48 part h: small object helpers (0x88760000-0x88780000), plain route. */
typedef unsigned int u32;
typedef unsigned char u8;
#define W(p, o) (*(u32 *)((char *)(p) + (o)))
#define B(p, o) (*(u8 *)((char *)(p) + (o)))

extern void fn_88773A18(void *self, u32 *key);
extern void fn_88772A38(void *self, u32 a, int b);
extern char *lbl_88D45B1C;

/* 0x88774470: store a/b into the owned record at +0x10; b == -1 looks up by key, else applies */
void ts4_set_owned_pair_88774470(char *self, u32 a, int b)
{
    u32 key;
    if (W(self, 0x10) != 0) {
        W(*(char **)(self + 0x10), 0xb4) = a;
        W(*(char **)(self + 0x10), 0xb8) = (u32)b;
        if (b == -1) {
            key = 0xb6c65665u;
            fn_88773A18(self, &key);
        } else {
            fn_88772A38(self, a, b);
        }
    }
}


extern void fn_88771868(void *obj, u32 key);
extern void fn_88772C10(void *obj, u32 a, u32 b);
extern float fn_88771618(void *obj, u32 a);

/* 0x88773980: for each child of the owner (when its +0xb8 is set) whose record matches key, forward */
void ts4_notify_matching_88773980(char *self, u32 *key, u32 a, u32 b)
{
    char *o = *(char **)(self + 0x10);
    if (o != 0 && W(o, 0xb8) != 0xffffffffu) {
        int n = (int)(W(o, 0x44) - W(o, 0x40)) >> 2;
        if (n > 0) {
            u32 i = 0;
            int cnt = n;
            do {
                char *e = *(char **)(*(char **)(*(char **)(self + 0x10) + 0x40) + i);
                char *rec = *(char **)e;
                if (rec != 0) {
                    { u32 f = *(volatile u32 *)(rec + 0x1c); if (*key == f) fn_88772C10(e, a, b); }
                }
                i += 4;
            } while (--cnt != 0);
        }
    }
}




extern char *ts4_object_new_882159B0(u32 key);
typedef struct Cx48VObj { void **vt; } Cx48VObj;

/* 0x8877D938: look up the object for self+0x10, tag it with the same key, run its vslot 3 then delete it */
void ts4_tsu_finalize_object(char *self)
{
    Cx48VObj *o = (Cx48VObj *)ts4_object_new_882159B0(W(self, 0x10));
    W(o, 0x20) = W(self, 0x10);
    ((void (*)(Cx48VObj *))o->vt[3])(o);
    ((void (*)(Cx48VObj *, int))o->vt[0])(o, 1);
}


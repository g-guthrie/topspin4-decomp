/* CW38 part c: UI event checkers and lookups in 0x887B0000-0x887D0000. */
typedef unsigned int u32;
typedef unsigned char u8;

/* 0x887CF328: hash id to slot index, -1 when unknown. */
int ts4_hash_to_slot_887CF328(u32 h)
{
    int r = -1;
    switch (h) {
    case 0x5a362d8cU: r = 0; break;
    case 0xb484c517U: r = 1; break;
    case 0xc1df4081U: r = 2; break;
    case 0xa172ef26U: r = 3; break;
    case 0x1dfb5824U: r = 4; break;
    }
    return r;
}

typedef struct Ev { char pad[0x2c]; char *p2c; char pad2[4]; char *p34; } Ev;

void ts4_check_mod3_887CF620(u32 *out, Ev *ev, u32 *res)
{
    if (ev->p34[0xc6]) {
        char *c = ev->p2c;
        if (*(u32 *)(c + 0x1d0) == 0xe981b5d1U) {
            char *t = c + 0x35c;
            char *b = t + *(int *)t;
            u32 v = *(u32 *)(b + 0x84);
            if (v >= 3 && v % 3 == 0) {
                res[8] = v;
                *out = 0x382bb6c0U;
                return;
            }
        }
    }
    *out = 0;
}

/* 0x887CE5C0: first word of an event record to a category index, 6 when unknown. */
int ts4_event_category_887CE5C0(u32 *rec)
{
    switch (rec[0]) {
    case 0x236f2ea1U: return 0;
    case 0x2fa88503U: return 1;
    case 0xab05ac63U: return 2;
    case 0x042762f9U: return 3;
    case 0x65c4b507U: return 4;
    case 0x55acca9cU: return 5;
    }
    return 6;
}

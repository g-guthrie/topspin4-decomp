/* Analyser framework: publish an object in the global hash registry (lbl_88D458F0). */
typedef unsigned int u32;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
typedef struct Ts4HashKey { u32 value; } Ts4HashKey;
typedef struct Ts4HashTable Ts4HashTable;
extern Ts4HashTable *lbl_88D458F0;
extern void *ts4_hash_find_args_88170EC0(Ts4HashTable *table, Ts4HashKey hash, u32 a, u32 b,
                                         u32 c, Ts4Handle12 h);
/* 0x887ECB68: store `obj` in the registry slot of hash 0x25BD833A (null handle). */
void ts4_anlz_publish_slot_25bd833a_887ECB68(void *obj)
{
    Ts4Handle12 h;
    Ts4HashKey k;
    h.a = 0;
    h.b = 0xFFFFF;
    h.c = 0;
    k.value = 0x25BD833A;
    *(void **)ts4_hash_find_args_88170EC0(lbl_88D458F0, k, 1, 0, 0, h) = obj;
}

/* 0x8872B948: renderer: destructor body of the singleton held in lbl_88D45AD8 (next to g_Display): set vtable lbl_880F2918, clear the global, destroy the member at +0x1C, run the base destructor 88617D28 */
/* Matched on /Oc (LTCG) (agAL). LTCG route, first try. */
typedef struct Singleton { const void *vt; unsigned char pad4[0x1c - 4]; unsigned char sub1c[4]; } Singleton;
extern const char lbl_880F2918[];
extern Singleton *lbl_88D45AD8;
extern void ts4_if_call_seq_u32_off0_882240E8(void *p);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(Singleton *o);

void ts4_singleton_destroy_8872B948(Singleton *o)
{
    o->vt = lbl_880F2918;
    lbl_88D45AD8 = 0;
    ts4_if_call_seq_u32_off0_882240E8(o->sub1c);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(o);
}

/* HKB: LTCG-route destructor with two external calls (/Oc, pool primer context). */

struct HkbSingleton { void *vtbl; unsigned char pad[0x18]; unsigned char sub[4]; };
extern unsigned char lbl_880F51E0[];
extern void *lbl_88D45B0C;
extern void *ts4_loop_call_seq_lbl_880D6268_8892AF80(void *);
extern void *ts4_if_call_seq_lbl_880F7EE4_88617D28(void *);

/* Swing_DLL.xex 0x886588C0 */
void ts4_singleton_dtor_886588C0(struct HkbSingleton *s)
{
    s->vtbl = lbl_880F51E0;
    lbl_88D45B0C = 0;
    ts4_loop_call_seq_lbl_880D6268_8892AF80(s->sub);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(s);
}

/* W7D: functions relying on a matched callee (LTCG, include). */
struct W7dSub { char pad[0x24]; unsigned f24, f28; };
struct W7dA { char pad0[4]; void *p4; void *p8; char pad1[0x20 - 0xc]; unsigned f20; char pad2[0x30 - 0x24]; struct W7dSub *s30; struct W7dSub *s34; };
extern void ts4_reset_pairs_886C4278(void *);
extern void ts4_clear_three_vectors_886C3658(void *);
/* Swing_DLL.xex 0x886C5C28 */
void ts4_reset_sub_886C5C28(struct W7dA *a)
{
    a->s30->f24 = 0;
    a->s30->f28 = 0;
    a->s34->f24 = 0;
    a->s34->f28 = 0;
    a->f20 = 0;
    ts4_clear_three_vectors_886C3658(a->p8);
    ts4_reset_pairs_886C4278(a->p4);
}

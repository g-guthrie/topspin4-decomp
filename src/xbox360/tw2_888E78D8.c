/* Twin of 0x886A0478 (ga4_owner_four_dtor_886A0478 in src/xbox360/ga4_a.c). Element stride 0x54, array at +4. */
typedef struct Ga4E84 { char pad[0x54]; } Ga4E84;
struct Ga4OwnerFourB {
    void *vtbl;
    Ga4E84 elem[4];
};
extern char lbl_880DBE94[], lbl_880DBE70[];
extern void ts4_destroy_vector_set_888E77E8(void *self);

void ts4_ga4_owner_four_dtor_888E78D8(struct Ga4OwnerFourB *self)
{
    Ga4E84 *e = self->elem + 4;
    int n;
    self->vtbl = &lbl_880DBE94;
    for (n = 3; n >= 0; n--) {
        e--;
        ts4_destroy_vector_set_888E77E8(e);
    }
    self->vtbl = &lbl_880DBE70;
}

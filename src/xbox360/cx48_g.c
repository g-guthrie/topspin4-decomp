/* CW48 part g: name-formatting initialisers (self-relative name strings), plain route. */
typedef unsigned int u32;
typedef unsigned char u8;
#define W(p, o) (*(u32 *)((char *)(p) + (o)))
extern const char lbl_880C1320[];
extern void fn_8876FBD0(void *self, void *rec);
extern void *ts4_assign_formatted_text(void *self, const char *text);
extern void fn_88150600(void *dst, void *src);
extern void ts4_destroy_owned_object(void *obj);
typedef struct Cx48Rec { u8 pad[0x14]; int n0; int pad18; int n1; } Cx48Rec;

/* assign the name found at *own (self-relative, -1 = default) into a temp, copy it to dst, destroy it */
#define CX48_NAME(DST, OWN) \
    { const char *name; int *own = (OWN); u32 tmp; \
      name = *own != -1 ? (char *)own + *own : lbl_880C1320; \
      ts4_assign_formatted_text(&tmp, name); \
      fn_88150600((DST), &tmp); \
      ts4_destroy_owned_object((void *)(unsigned long)tmp); }

/* 0x88777A60 */
void ts4_init_names_88777A60(char *self, Cx48Rec *rec)
{
    fn_8876FBD0(self, rec);
    CX48_NAME(self + 0x30, &rec->n0)
    CX48_NAME(self + 0x24, &rec->n1)
}

/* 0x88777D78: same body as 0x88777A60 */
void ts4_init_names_88777D78(char *self, Cx48Rec *rec)
{
    fn_8876FBD0(self, rec);
    CX48_NAME(self + 0x30, &rec->n0)
    CX48_NAME(self + 0x24, &rec->n1)
}

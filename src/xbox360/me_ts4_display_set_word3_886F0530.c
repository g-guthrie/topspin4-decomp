/* 0x886F0530: renderer: store a 12-byte value (passed by value) into g_Display+0xD4 and, when the object at lbl_88D45A78 exists, into its +0x28 */
/* Matched on /Oc (LTCG) (agAL). LTCG route, first try (struct by value spilled with std and reloaded). */
typedef struct Word3 { unsigned int r, g, b; } Word3;
typedef struct Display { unsigned char pad[0xd4]; Word3 value; } Display;
typedef struct Mirror { unsigned char pad[0x28]; Word3 value; } Mirror;
extern Display *lbl_88D45AD4;
extern Mirror *lbl_88D45A78;

void ts4_display_set_word3_886F0530(Word3 v)
{
    Mirror *m;
    lbl_88D45AD4->value = v;
    m = lbl_88D45A78;
    if (m)
        m->value = v;
}

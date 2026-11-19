/* Swing_DLL.xex 0x888C7E58: ORs the busy byte of every 0xB0-byte slot in the session's self-relative slot table, then sets the widget text (slot 12) to the busy or idle string.
 * /Oc. agAH begin/end inlines ('e = 0; if (first != -1) ...'); the int argument is passed through as the vcall's third argument (the 'mr r5,r3'). */
typedef struct Slot { unsigned char pad[0x19]; unsigned char busy; unsigned char pad1a[0xb0 - 0x1a]; } Slot;
typedef struct SlotTab { int first; int count; } SlotTab;
typedef struct Session { unsigned char pad[0x38]; SlotTab *slots; } Session;
typedef struct Online { unsigned char pad[0x234]; Session *session; } Online;
typedef struct Texts { unsigned char pad[0x1c]; void *idle; unsigned char pad20[0x5c - 0x20]; void *busy; } Texts;
typedef struct Widget Widget;
typedef struct WidgetVt { void *s[12]; void (*set_text)(Widget *, void *, int); } WidgetVt;
struct Widget { WidgetVt *vt; };

extern Online *lbl_88D45B1C;
extern Widget *lbl_88D45A08;
extern Texts *lbl_88D459CC;

static __inline Slot *tbegin(SlotTab *t) { Slot *e = 0; if (t->first != -1) e = (Slot *)((char *)t + t->first); return e; }
static __inline Slot *tend(SlotTab *t) { Slot *e = 0; if (t->first != -1) e = (Slot *)((char *)t + t->first + t->count * sizeof(Slot)); return e; }

void fn_888C7E58(int flags)
{
    unsigned char any = 0;
    SlotTab *t = lbl_88D45B1C->session->slots;
    Slot *e = tbegin(t);
    Slot *end = tend(t);
    for (; e != end; e++) any |= e->busy;
    if (any) lbl_88D45A08->vt->set_text(lbl_88D45A08, lbl_88D459CC->busy, flags);
    else lbl_88D45A08->vt->set_text(lbl_88D45A08, lbl_88D459CC->idle, flags);
}

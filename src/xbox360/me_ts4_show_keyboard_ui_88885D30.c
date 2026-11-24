/* 0x88885D30: open the Xbox keyboard UI for a pad: mode flags from the keyboard type (0x2 when +0x4c is set), clear the XOVERLAPPED at +0x40, pad record user index or -1, result buffer +0x44+4 with *cnt+1 chars. Matched /Oc (agBJ). */
typedef struct { char p[0x1c]; int x1c; char p20[8]; int x28; char p2c[8]; int x34; char p38[8]; void *x40; char *x44; int x48; int x4c; } O;
typedef struct { char p[0x10]; int id; } E;
typedef struct { char p[0x234]; void *tab; } G;
extern G *lbl_88D45B1C;
void *ts4_memset(void *p, int v, unsigned int n);
E *ts4_pad_record_find_88614938(void *tab, int key);
unsigned long ts4_tailcall_XamShowKeyboardUI_8857A698(int user, unsigned flags, int deflt, int title, int desc, char *result, int cch, void *overlapped);
void fn_88885D30(O *o, int key, int *cnt)
{
    int fl = 0;
    E *e;
    if (o->x4c == 0) {
        switch (o->x48) {
        case 1: fl = 0x1000; break;
        case 6: fl = 0x2000; break;
        case 7: fl = 0x4000; break;
        case 9: fl = 0x8000; break;
        }
    } else {
        fl = 2;
    }
    ts4_memset(o->x40, 0, 0x1c);
    e = ts4_pad_record_find_88614938(lbl_88D45B1C->tab, key);
    ts4_tailcall_XamShowKeyboardUI_8857A698(e ? e->id : -1, fl | 0x20000000, o->x34, o->x28, o->x1c, o->x44 + 4, *cnt + 1, o->x40);
}

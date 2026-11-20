/* 0x888682F0: constructor. Runs the base constructor fn_88617D88, installs the vtable, clears the state fields, sets up
 * the mode record at +0x90, publishes the object in lbl_88D459DC and stores the hash 0xE495B255 at +0x68. */
typedef struct ModeRec { char p[0xc]; unsigned char flag; char p1[3]; int a, b, c; } ModeRec;
typedef struct Self888682F0 {
    void *vt; char p4[0x18]; unsigned char b1c, b1d; char p1e[2]; int m20; int m24[5]; int m38; int key3c; int m40[20];
    ModeRec rec;
} Self888682F0;
extern char lbl_880E0688[];
extern Self888682F0 *lbl_88D459DC;
void fn_88617D88(Self888682F0 *s);
void ts4_init_mode_record_887EA830(ModeRec *r, unsigned char mode);
Self888682F0 *fn_888682F0(Self888682F0 *s)
{
    fn_88617D88(s);
    s->vt = lbl_880E0688;
    s->b1c = 0; s->b1d = 0;
    s->m20 = -1;
    s->m38 = 0; s->m40[0] = 0; s->key3c = 0xFFFFF;
    s->m40[1] = 0; s->m40[2] = 0; s->m40[3] = 0; s->m40[4] = 0; s->m40[5] = 0; s->m40[6] = 0; s->m40[7] = 0; s->m40[8] = 0; s->m40[9] = 0; s->m40[10] = 0; s->m40[11] = 0; s->m40[12] = 0; s->m40[13] = 0; s->m40[14] = 0; s->m40[15] = 0; s->m40[16] = 0; s->m40[17] = 0; s->m40[18] = 0; s->m40[19] = 0;
    ts4_init_mode_record_887EA830(&s->rec, 0);
    { ModeRec *r = &s->rec; r->flag = 0; r->a = 0; r->b = 0; r->c = 0; }
    s->m24[0] = 0; s->m24[1] = 0; s->m24[2] = 0; s->m24[3] = 0; s->m24[4] = 0;
    lbl_88D459DC = s;
    s->m40[10] = 0xE495B255u;
    return s;
}

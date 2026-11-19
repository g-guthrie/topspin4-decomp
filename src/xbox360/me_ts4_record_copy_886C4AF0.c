/* 0x886C4AF0: field-wise copy of a 0x70-byte record (skips +0/+8/+1c/+30 slots); two 5-word arrays copied by struct assignment (agAY). Plain /Oc. */
typedef struct Arr5 { int v[5]; } Arr5;
typedef struct Rec {
    int pad0; int id; int pad8; float a[4]; int pad1c[2]; float b[3]; int pad30[2];
    int c38; int c3c; int c40; Arr5 x; Arr5 y; int c6c;
} Rec;
void ts4_record_copy_886C4AF0(Rec *d, const Rec *s)
{
    d->id = s->id;
    d->a[0] = s->a[0]; d->a[1] = s->a[1]; d->a[2] = s->a[2]; d->a[3] = s->a[3];
    d->b[0] = s->b[0]; d->b[1] = s->b[1]; d->b[2] = s->b[2];
    d->c38 = s->c38; d->c3c = s->c3c; d->c40 = s->c40;
    d->x = s->x;
    d->y = s->y;
    d->c6c = s->c6c;
}

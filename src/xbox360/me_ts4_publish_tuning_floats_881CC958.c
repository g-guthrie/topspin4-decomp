/* 0x881CC958: copies the five floats at +0x38..+0x48 to the globals lbl_88D45A34 and lbl_88C69CB4..CC0 */
/* Matched on /Oc LTCG only (work/army/ME/v.py chk). */
extern float lbl_88D45A34, lbl_88C69CB4, lbl_88C69CB8, lbl_88C69CBC, lbl_88C69CC0;
typedef struct { char pad[0x38]; float a, b, c, d, e; } O;
void ts4_publish_tuning_floats_881CC958(O *o)
{
    lbl_88D45A34 = o->a;
    lbl_88C69CB4 = o->b;
    lbl_88C69CB8 = o->c;
    lbl_88C69CBC = o->d;
    lbl_88C69CC0 = o->e;
}

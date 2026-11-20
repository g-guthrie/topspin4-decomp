/* Swing_DLL.xex 0x884018B0-0x88401954, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Ts4VwEnt9 { u32 w; u32 h; u32 x; } Ts4VwEnt9;
typedef struct Ts4VwTab9 { char pad[8]; u32 count; char pad2[0x18 - 0xc]; u32 **arrs; char pad3[8]; Ts4VwEnt9 *ents; } Ts4VwTab9;
void ts4_fill_index_pairs_884018B0(u8 *out, Ts4VwTab9 *t, u32 idx)
{
    u32 *a;
    u32 k;
    if (idx < t->count) {
        a = t->arrs[idx];
        k = 0;
        if (t->ents[idx].h * t->ents[idx].w != 0) {
            do {
                a[0] = 0;
                a[1] = k % t->ents[idx].h;
                a += 2;
                k++;
            } while (k < t->ents[idx].h * t->ents[idx].w);
        }
        *out = 1;
        return;
    }
    *out = 0;
}

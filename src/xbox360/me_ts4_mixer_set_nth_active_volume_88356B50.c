/* 0x88356B50: Sets the volume of the n-th channel (of 16) that has a voice. Returns 0x25 if n or the volume (lbl_88001A20..lbl_88001A68) is out of range, else 0. */
/* Matched on /Oc (agAH). Plain loop. */
typedef struct Channel { void *voice; char p4[0x290]; float volume; char p298[0x2c0 - 0x298]; } Channel;
typedef struct Mixer { char p0[0x194]; Channel ch[16]; } Mixer;
extern const float lbl_88001A20;
extern const float lbl_88001A68;
int fn_88356B50(Mixer *m, int n, float volume)
{
    int k = 0;
    int i;
    if (n < 0 || n >= 16 || volume < lbl_88001A20 || volume > lbl_88001A68)
        return 0x25;
    for (i = 0; i < 16; i++) {
        if (m->ch[i].voice != 0) {
            if (n == k) {
                m->ch[i].volume = volume;
                return 0;
            }
            k++;
        }
    }
    return 0;
}

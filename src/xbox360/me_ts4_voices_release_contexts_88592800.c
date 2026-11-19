/* Swing_DLL.xex 0x88592800: release every voice's XMA context and clear the 0x40000 flag
 * /Oc (this one is not /O1 like the page-pool code) */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Voice { u8 pad[0x40]; void *context; u8 pad44[0x60 - 0x44]; } Voice;
typedef struct VoiceSet { u32 count; u32 flags; Voice *voices; } VoiceSet;

void XMAReleaseContext(void *context);

int fn_88592800(VoiceSet *v)
{
    u32 i;
    for (i = 0; i < v->count; i++) {
        if (v->voices[i].context) {
            XMAReleaseContext(v->voices[i].context);
            v->voices[i].context = 0;
        }
    }
    v->flags &= ~0x40000;
    return 0;
}

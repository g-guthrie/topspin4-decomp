/* 0x88600CD0: validate a blob header. The u16 at +0 holds major (high byte) and minor (low byte); the known minor counts per major are 0:37, 1:6, 2:5, 3:3, 4:1, 6:7 (5 and 7 are rejected). Returns 1 when the version is known and the u32 size at +4 is <= 0x20000, else 0.
 * Matched on plain /Oc and LTCG routes (work/army/ME/v.py chk, matching-b129). */
typedef struct Hdr { unsigned short ver; short pad; unsigned size; } Hdr;
int fn_88600CD0(Hdr *h)
{
    int major = h->ver >> 8;
    int minor;
    if (major < 0 || major >= 8) return 0;
    minor = h->ver & 0xff;
    if (minor < 0) return 0;
    switch (major) {
    case 0: if (minor >= 0x25) return 0; break;
    case 1: if (minor >= 6) return 0; break;
    case 2: if (minor >= 5) return 0; break;
    case 3: if (minor >= 3) return 0; break;
    case 4: if (minor >= 1) return 0; break;
    case 6: if (minor >= 7) return 0; break;
    default: return 0;
    }
    return h->size <= 0x20000;
}

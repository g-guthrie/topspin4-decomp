/* 0x8877B1F0: ask service 0x8C5A4922 for its record and report whether its two 100-byte blocks differ. */
int memcmp(const void *a, const void *b, unsigned n);
#pragma intrinsic(memcmp)
typedef struct SvcRel { int rel; unsigned count; } SvcRel;
typedef struct SvcRecord { char pad[0x1a4]; SvcRel data; } SvcRecord;
typedef struct Svc { struct SvcVt *vt; } Svc;
typedef struct SvcVt { char pad[0x4c]; SvcRecord *(*get_record)(Svc *, int); } SvcVt;
void *ts4_find_service(unsigned service_id);
unsigned char svc_blocks_differ_8877B1F0(void)
{
    unsigned char r = 0;
    Svc *s = (Svc *)ts4_find_service(0x8C5A4922);
    SvcRecord *p = s->vt->get_record(s, 0);
    if (p->data.count > 6) {
        SvcRel *t = &p->data;
        char *b = (char *)t + t->rel;
        r = 0 != memcmp(b + 0x190, b + 0x258, 100);
    }
    return r;
}

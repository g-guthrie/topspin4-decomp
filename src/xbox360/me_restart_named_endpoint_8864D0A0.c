/* 0x8864D0A0 (hand match): (re)starts the object under a name: closes a live handle, re-initialises,
 * resets the 16-byte address block to family 2 / port 1000, copies the name and opens the handle. */
char *strcpy(char *, const char *);
void *memset(void *, int, unsigned int);
#pragma intrinsic(strcpy, memset)
typedef struct Addr { short family; unsigned short port; int a, b, c; } Addr;
typedef struct Obj { void *handle; int active; char p[0x84 - 8]; Addr addr; char p2[0x1b0 - 0x94]; char name[1]; } Obj;
void ts4_if_call_seq_u32_off0_8864BC08(Obj *o);
unsigned char fn_8864BCF8(Obj *o);
void *fn_889BDA40(Obj *o);
void fn_8864B528(Obj *o);
int ts4_restart_named_endpoint_8864D0A0(Obj *o, const char *name)
{
    if (o->handle != 0)
        ts4_if_call_seq_u32_off0_8864BC08(o);
    if (!fn_8864BCF8(o))
        return -1;
    memset(&o->addr, 0, sizeof(o->addr));
    o->addr.family = 2;
    o->addr.port = 1000;
    o->active = 1;
    strcpy(o->name, name);
    if (o->handle == 0) {
        o->handle = fn_889BDA40(o);
        if (o->handle == 0) {
            fn_8864B528(o);
            return -1;
        }
    }
    return 0;
}

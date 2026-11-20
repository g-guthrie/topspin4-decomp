typedef unsigned int u32;
typedef unsigned char u8;
struct W8bStep {
    unsigned char pad00[0x14]; u32 mode; u32 steps;
    unsigned char pad1c[0x43c - 0x1c]; u8 b43c;
    unsigned char pad43d[0x4e0 - 0x43d]; u8 b4e0;
    unsigned char pad4e1[0x530 - 0x4e1]; u8 b530;
};
struct W8bStepOwner { unsigned char pad00[0x5dc]; void *proc; };
extern void fn_889C1160(void *c, struct W8bStep *p);
extern void fn_889C19F0(void *c);
extern void fn_889C1F70(void *c, struct W8bStep *p);
extern void fn_889C0FE8(void *c, struct W8bStep *p);

void ts4_run_step_loop_886AB0E8(struct W8bStepOwner *self, struct W8bStep *p)
{
    unsigned i = 0;
    while (p->mode == 1 && i < 600) {
        void *c;
        { u32 *sp = &p->steps; *sp = *sp + 1; }
        c = self->proc;
        if (p->b530 != 0) {
            u8 more;
            fn_889C1160(c, p);
            more = 1;
            if (p->b43c != 0) {
                fn_889C19F0(c);
                more = (u8)(p->b4e0 == 0);
                p->b43c = 0;
            }
            if (more != 0)
                fn_889C1F70(c, p);
            fn_889C0FE8(c, p);
        }
        i++;
    }
}

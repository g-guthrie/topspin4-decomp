/* agAM: 3 off (was 23): flag clear through an unrolled inline on &shared->flags fixes the register numbering; left: slot address adds the offset load before (i*8 + table) (target computes i*8+table first). */
typedef struct Slot { int value; unsigned int hash; } Slot;
typedef struct Table { int offset; unsigned int count; char p[4]; int filled; } Table;
typedef struct Flags { unsigned char f[12]; } Flags;
typedef struct Shared { char p[0x2f0]; Flags flags; } Shared;
typedef struct Ctx { char p[0x44]; Shared *shared; } Ctx;
typedef struct Owner { char p[0x1c]; Ctx *ctx; char p2[0x28 - 0x20]; Table *table; } Owner;
static void clrf(Flags *f){ int k; for(k=0;k<12;k++) f->f[k]=0; }
static Slot *slot(Table *t, unsigned int i){ return (Slot *)((char *)t + (i * sizeof(Slot) + t->offset)); }
static void clrf2(Flags *f){ f->f[0]=0;f->f[1]=0;f->f[2]=0;f->f[3]=0;f->f[4]=0;f->f[5]=0;f->f[6]=0;f->f[7]=0;f->f[8]=0;f->f[9]=0;f->f[10]=0;f->f[11]=0; }
void fn_886643F8(Owner *o){ unsigned int i; unsigned int n=o->table->count; for(i=0;i<n;i++) slot(o->table,i)->hash=0x968230B3; clrf2(&o->ctx->shared->flags); o->table->filled=0; }

/* 0x88956B20: Returns true only if fn_88956658(self,a,ctx), fn_88941FA0(self,c,ctx) and fn_88941E90(self,b,ctx) all succeed, in that order and short-circuiting. */
/* Matched on /Oc (agAH). Single && expression returning u8. */
extern unsigned char fn_88956658(void *self, void *a, void *ctx);
extern unsigned char fn_88941FA0(void *self, void *c, void *ctx);
extern unsigned char fn_88941E90(void *self, void *b, void *ctx);
unsigned char fn_88956B20(void *self, void *a, void *b, void *c, void *ctx)
{
    return fn_88956658(self, a, ctx) && fn_88941FA0(self, c, ctx) && fn_88941E90(self, b, ctx);
}

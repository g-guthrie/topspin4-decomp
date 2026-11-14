/* Loader_DLL.xex 0x830C2C30-0x831482E0, executable version 0.0.0.3. */
extern void fn_830C2B68(void *self, void *p, int n);
extern void fn_83148048(void *self, void *p, int n);

void ts4l_push_u32_830C2C30(void *self, int v)
{
    fn_830C2B68(self, &v, 4);
}

void ts4l_push_u32_831481E8(void *self, int v)
{
    fn_83148048(self, &v, 4);
}

void ts4l_push_u32_83148248(void *self, int v)
{
    fn_83148048(self, &v, 4);
}

void ts4l_push_u32_831482E0(void *self, int v)
{
    fn_83148048(self, &v, 4);
}

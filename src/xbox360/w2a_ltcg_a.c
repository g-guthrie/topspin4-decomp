extern void *ts4_msg_pool_service_get_8864DFF0(void);
extern void ts4_registry_dispatch_888860A0(void *key);
/* Swing_DLL.xex 0x889C0910 */
void ts4_pool_dispatch_889C0910(void *key)
{
    ts4_msg_pool_service_get_8864DFF0();
    ts4_registry_dispatch_888860A0(key);
}

extern void *ts4_find_rec8c_by_keys_886C8438(void *self, unsigned key_a, unsigned key_b);
extern void fn_886C5230(void *self, void *rec, unsigned key);
/* Swing_DLL.xex 0x886C84B8 */
void ts4_set_rec_by_keys_886C84B8(void *self, unsigned key_a, unsigned key_b, unsigned c)
{
    fn_886C5230(self, ts4_find_rec8c_by_keys_886C8438(self, key_a, key_b), c);
}

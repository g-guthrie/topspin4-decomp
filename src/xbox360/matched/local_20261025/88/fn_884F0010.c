typedef unsigned int ts4_u32;
extern void NetDll_XNetGetEthernetLinkStatus(ts4_u32 arg);

void fn_884F0010(void)
{
    NetDll_XNetGetEthernetLinkStatus(1);
}
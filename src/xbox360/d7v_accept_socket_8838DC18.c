/* Swing_DLL.xex 0x8838DC18-0x8838DCA0, executable version 0.0.0.3. */
typedef unsigned int u32;
u32 ts4_tailcall_NetDll_accept_884F02E0(int a, int b, int c);
int ts4_tailcall_NetDll_WSAGetLastError_884F0390(void);

int ts4_accept_socket_8838DC18(int sock, int *out)
{
    int s;
    if (sock == -1)
        return 0x35;
    s = (int)ts4_tailcall_NetDll_accept_884F02E0(sock, 0, 0);
    if (s == -1) {
        if (ts4_tailcall_NetDll_WSAGetLastError_884F0390() == 0x2733)
            return 0x37;
        return 0x35;
    }
    *out = s;
    return 0;
}

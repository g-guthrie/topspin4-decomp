/* 0x884F6858: Finds the peer whose 64-bit xuid matches in a table {count (+8), peers[] (+0x60)}; returns the peer pointer or 0. */
/* Matched on /Oc /Os (agAH). Built /Os: on /Oc the peer pointer and the index get their own registers (4 off). Index loop with break, then the bound test again. */
typedef struct Peer { unsigned long long xuid; } Peer;
typedef struct PeerTable { char pad[8]; unsigned int count; char padc[0x60 - 0xc]; Peer *peers[16]; } PeerTable;
Peer *fn_884F6858(PeerTable *t, unsigned long long xuid)
{
    unsigned int i;
    for (i = 0; i < t->count; i++) {
        if (xuid == t->peers[i]->xuid)
            break;
    }
    if (i < t->count)
        return t->peers[i];
    return 0;
}

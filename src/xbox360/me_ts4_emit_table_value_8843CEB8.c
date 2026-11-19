/* 0x8843CEB8: Looks up value index in the reader table (indices below splitIndex go through the remap array into values[k + 1], the rest index the extra array) and passes it to the host sink at +0x10 through vtable slot 4. */
/* Matched on /Oc (agAH). Table reached through r->table at every use (a local copy stops the split-index reload). */
typedef struct Sink Sink;
typedef struct SinkVtbl { void *slot0[4]; void (*put)(Sink *s, int value); } SinkVtbl;
struct Sink { SinkVtbl *vtable; };
typedef struct Host { char pad[0x10]; Sink sink; } Host;
typedef struct ValueTable {
    char pad[8];
    int *values;
    char padc[8];
    int *remap;
    unsigned int splitIndex;
    char pad1c[4];
    int *extra;
} ValueTable;
typedef struct Reader { int unk0; int unk4; ValueTable *table; Host *host; } Reader;
void fn_8843CEB8(Reader *r, unsigned int index)
{
    int value;
    if (index < r->table->splitIndex)
        value = r->table->values[r->table->remap[index] + 1];
    else
        value = r->table->extra[index - r->table->splitIndex];
    r->host->sink.vtable->put(&r->host->sink, value);
}

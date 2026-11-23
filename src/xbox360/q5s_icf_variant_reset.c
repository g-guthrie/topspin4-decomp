/* 0x881A2508: reset of a tagged value {u32 type; u32 pad; body at +8}. A value of type 0xfffd or 0xffff
 * releases its body through one function, a value of type 0xfffe through another; then the type becomes
 * 0xfff9 (empty). The two release functions had identical bodies and the original linker folded them
 * (/OPT:ICF): both calls reach 0x881A2570. The second name is the reviewed alias
 * ts4_call_seq_u32_off0_881A2570_icf_b (config/54540859/icf_aliases.json); with one name the compiler
 * merges the two calls. */
extern void ts4_call_seq_u32_off0_881A2570(void *body);
extern void ts4_call_seq_u32_off0_881A2570_icf_b(void *body);

typedef struct Q5sTagged {
    unsigned type;
    unsigned pad04;
    unsigned body;
} Q5sTagged;

void ts4_tagged_value_reset_881A2508(Q5sTagged *v)
{
    unsigned type = v->type;
    if (type == 0xfffd || type == 0xffff)
        ts4_call_seq_u32_off0_881A2570_icf_b(&v->body);
    else if (type == 0xfffe)
        ts4_call_seq_u32_off0_881A2570(&v->body);
    v->type = 0xfff9;
}

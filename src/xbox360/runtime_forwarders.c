extern void KeQuerySystemTime(void);
extern void ts4_record_status(void);
extern void fn_881B3360(void);
extern void fn_8858BEE8(void);

void ts4_query_system_time(void) { KeQuerySystemTime(); }
void ts4_forward_record_status(void) { ts4_record_status(); }
void ts4_forward_runtime_b3360(void) { fn_881B3360(); }
void ts4_forward_runtime_8bee8(void) { fn_8858BEE8(); }

#include "tsu_adjacent_wrappers.h"

extern float g_ts4_event_value;
extern void ts4_report_component_event(
    void *component, int player, u32 event_id, float value
);

/* Swing_DLL.xex 0x8878BDD0; callback registration name remains under review. */
u32 ts4_script_tsu_report_event(void)
{
    Ts4Service *service = ts4_find_service(0x585B1D0A);
    ts4_report_component_event(
        service->component, -1, 0xA3AE3B93, g_ts4_event_value
    );
    return 0;
}

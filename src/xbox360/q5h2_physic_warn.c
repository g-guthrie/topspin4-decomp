/* Q5h2: physics loader warning shim (Top Spin 4, Xbox 360, Swing_DLL.xex), plain route, no flags.
 * Clone of ts4_physic_data_update_version_88879098 for the sister 0x888791E8. Same body and the same message;
 * only the source file string (PhysicEngineCommandProcessor.cpp, lbl_880DF6D8) and the line (0x1E3) differ.
 * Game code: when the version update of a loaded package fails, format a message into a 0x200-byte stack buffer
 * through a 0x10-byte text stream and send it to the global error reporter as a warning with file and line. */

/* 0x10-byte text stream writing into a caller buffer. */
typedef struct Q5h2TextStream { char opaque[0x10]; } Q5h2TextStream;
typedef struct Q5h2Reporter Q5h2Reporter;
typedef struct Q5h2ReporterVt {
    void *slot00[3];
    /* +0x0c */ void (*message)(Q5h2Reporter *self, int type, int id, const char *text, const char *file, int line);
} Q5h2ReporterVt;
struct Q5h2Reporter { Q5h2ReporterVt *vt; };

extern Q5h2Reporter *lbl_88CAD340;   /* global error reporter */
extern void *lbl_88D26FCC;           /* version registry passed to the update */
extern char lbl_880DF64C[];          /* "Couldn't update version, skipping.\n" */
extern char lbl_880DF6D8[];          /* "...\\physicengine\\Loader\\PhysicEngineCommandProcessor.cpp" */

/* nonzero when the package could not be updated to the current version */
int ts4_if_get_u32_off0_884C6B58(void *package, void *registry);
void fn_8841CBF8(Q5h2TextStream *stream, char *buffer, int size);
Q5h2TextStream *ts4_if_get_u32_off8_8841D058(Q5h2TextStream *stream, const char *text);
void ts4_ref_holder_dtor_8841D638(Q5h2TextStream *stream);

/* 0x888791E8: update the package version; on failure warn "Couldn't update version, skipping." (PhysicEngineCommandProcessor.cpp:0x1E3) */
void ts4_physic_data_update_version_888791E8(void *package)
{
    if (ts4_if_get_u32_off0_884C6B58(package, lbl_88D26FCC) != 0) {
        char buffer[0x200];
        Q5h2TextStream stream;
        fn_8841CBF8(&stream, buffer, 0x200);
        ts4_if_get_u32_off8_8841D058(&stream, lbl_880DF64C);
        lbl_88CAD340->vt->message(lbl_88CAD340, 1, 0, buffer, lbl_880DF6D8, 0x1E3);
        ts4_ref_holder_dtor_8841D638(&stream);
    }
}

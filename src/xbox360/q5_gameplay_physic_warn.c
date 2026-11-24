/* Q5: physics loader warning shims (Top Spin 4, Xbox 360, Swing_DLL.xex), plain route, no flags.
 * Game code (coretech PhysicData.cpp / PhysicEngineCommandProcessor.cpp): when the version update of a
 * loaded package fails, format a message into a 0x200-byte stack buffer through a 0x10-byte text stream
 * and send it to the global error reporter as a warning with the source file and line. */

/* 0x10-byte text stream writing into a caller buffer. */
typedef struct Q5TextStream { char opaque[0x10]; } Q5TextStream;
typedef struct Q5Reporter Q5Reporter;
typedef struct Q5ReporterVt {
    void *slot00[3];
    /* +0x0c */ void (*message)(Q5Reporter *self, int type, int id, const char *text, const char *file, int line);
} Q5ReporterVt;
struct Q5Reporter { Q5ReporterVt *vt; };

extern Q5Reporter *lbl_88CAD340;   /* global error reporter */
extern void *lbl_88D26FCC;         /* version registry passed to the update */
extern char lbl_880DF64C[];        /* "Couldn't update version, skipping.\n" */
extern char lbl_880DF670[];        /* "...\\physicengine\\Loader\\PhysicData.cpp" */

/* nonzero when the package could not be updated to the current version */
int ts4_if_get_u32_off0_884C6B58(void *package, void *registry);
void fn_8841CBF8(Q5TextStream *stream, char *buffer, int size);
Q5TextStream *ts4_if_get_u32_off8_8841D058(Q5TextStream *stream, const char *text);
void ts4_ref_holder_dtor_8841D638(Q5TextStream *stream);

/* 0x88879098: update the package version; on failure warn "Couldn't update version, skipping." (PhysicData.cpp:39) */
void ts4_physic_data_update_version_88879098(void *package)
{
    if (ts4_if_get_u32_off0_884C6B58(package, lbl_88D26FCC) != 0) {
        char buffer[0x200];
        Q5TextStream stream;
        fn_8841CBF8(&stream, buffer, 0x200);
        ts4_if_get_u32_off8_8841D058(&stream, lbl_880DF64C);
        lbl_88CAD340->vt->message(lbl_88CAD340, 1, 0, buffer, lbl_880DF670, 0x27);
        ts4_ref_holder_dtor_8841D638(&stream);
    }
}

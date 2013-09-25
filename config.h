#define _CRT_SECURE_NO_WARNINGS
/* This is only here for people using modern Microsoft compilers.
 * Usually the default warning level complains over "deprecated" CRT methods.
 * It's basically Microsoft's way of saying they're better than everyone.
 */

#define MINIMUM_MESSAGE_PRIORITY    1
#define EXTERN_COMMAND_LIST_GBI
#define EXTERN_COMMAND_LIST_ABI
#define SEMAPHORE_LOCK_CORRECTIONS
#define WAIT_FOR_CPU_HOST
#define EMULATE_STATIC_PC

#if (0)
#define SP_EXECUTE_LOG
#define VU_EMULATE_SCALAR_ACCUMULATOR_READ
#define SSE2_SHUFFLE_JUMP_DIMENSION
#endif

const char* DLL_name = "Iconoclast's SP Interpreter";

static unsigned char conf[32];
#define CFG_FILE    "rsp_conf.bin"
/*
 * The name of the config file is subject to change.
 * On InitiateRSP, plug-in checks if a file named after the game code in the
 * ROM header of the loaded ROM exists.  If so, load the settings per-ROM.
 */

#define CFG_HLE         (conf[0x00])
#define CFG_HLE_GFX     ((CFG_HLE >> 0) & 1)
#define CFG_HLE_AUD     ((CFG_HLE >> 1) & 1)
#define CFG_HLE_VID     ((CFG_HLE >> 2) & 1) /* reserved/unused */
#define CFG_HLE_JPG     ((CFG_HLE >> 3) & 1) /* reserved/unused */
#define CFG_HLE_005     (0) /* I have no idea what (OSTask.type == 5) is. */
#define CFG_HLE_HVQ     ((CFG_HLE >> 5) & 1) /* reserved/unused */
#define CFG_HLE_HVQM    ((CFG_HLE >> 6) & 1) /* reserved/unused */
#define CFG_HLE_UNK     ((CFG_HLE >> 7) & 1) /* anything else, reserved */
/*
 * Most of the point behind this config system is to let users use HLE video
 * or audio plug-ins.  The other task types are used less than 1% of the time
 * and only in a few games.  They require simulation from within the RSP
 * internally, which I have no intention to ever support.  Some good research
 * on a few of these special task types was done by Hacktarux in the MUPEN64
 * HLE RSP plug-in, so consider using that instead for complete HLE.
 */

/*
 * Anything between 0x01 and 0x0F of the config file, I have not yet found a
 * use for.  That section of bits is currently all reserved for new settings.
 */

#define CFG_WAIT_FOR_CPU_HOST       (*(int *)(conf + 0x10))
#define CFG_MEND_SEMAPHORE_LOCK     (*(int *)(conf + 0x14))
#define CFG_RESERVED                (*(int *)(conf + 0x18))
#define CFG_CHECKSUM                (*(conf + 0x1F))

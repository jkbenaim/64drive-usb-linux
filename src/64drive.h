#ifndef _64DRIVE_H_
#define _64DRIVE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h> //getopt
#include <getopt.h> //getopt_long
#include <errno.h>
#include <libftdi1/ftdi.h>

#define DEV_MAGIC                  0x55444556 // "UDEV"
#define	DEV_CMD_LOADRAM            0x20
#define	DEV_CMD_DUMPRAM            0x30
#define	DEV_CMD_SETSAVE            0x70
#define	DEV_CMD_SETCIC             0x72
#define	DEV_CMD_GETVER             0x80
#define	DEV_CMD_UPGRADE            0x84
#define	DEV_CMD_UPGREPORT          0x85
#define	DEV_CMD_STD_ENTER          0x88
#define	DEV_CMD_STD_LEAVE          0x89
#define	DEV_CMD_PI_RD_32           0x90
#define	DEV_CMD_PI_WR_32           0x91
#define	DEV_CMD_PI_RD_BURST        0x92
#define	DEV_CMD_PI_WR_BURST        0x93
#define	DEV_CMD_PI_WR_BL           0x94
#define	DEV_CMD_PI_WR_BL_LONG      0x95
#define	DEV_CMD_SI_OP              0x98

enum {
    BANK_INVALID,
    BANK_CARTROM,
    BANK_SRAM256,
    BANK_SRAM768,
    BANK_FLASHRAM1M,
    BANK_FLASHPKM1M,
    BANK_EEPROM16,
    BANK_LAST
};

enum {
    SAVETYPE_NONE = 0,
    SAVETYPE_EEP4K = 1,
    SAVETYPE_EEP16K = 2,
    SAVETYPE_SRAM256K = 3,
    SAVETYPE_FLASH = 4,
    SAVETYPE_SRAM768K = 5,
    SAVETYPE_FLASHPK = 6,
    SAVETYPE_LAST
};

enum {
    CIC_6101,
    CIC_6102,
    CIC_7101,
    CIC_7102,
    CIC_X103,
    CIC_X105,
    CIC_X106,
    CIC_5101,
    CIC_LAST
};

typedef struct {
    struct ftdi_context* ftdi;
    int version;
    char variant[3];
} sixtyfourDrive;

#endif //_64DRIVE_H_

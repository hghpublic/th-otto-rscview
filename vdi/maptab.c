#include "visibility.h"
#include "maptab.h"

unsigned short const atari_to_utf16[256] = {
/* 00 */	0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
/* 08 */	0x0008, 0x0009, 0x000a, 0x000b, 0x000c, 0x000d, 0x000e, 0x000f,
/* 10 */	0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017,
/* 18 */	0x0018, 0x0019, 0x001a, 0x001b, 0x001c, 0x001d, 0x001e, 0x001f,
/* 20 */	0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
/* 28 */	0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
/* 30 */	0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
/* 38 */	0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
/* 40 */	0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
/* 48 */	0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
/* 50 */	0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
/* 58 */	0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
/* 60 */	0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
/* 68 */	0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
/* 70 */	0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
/* 78 */	0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x007f,
/* 80 */	0x00c7, 0x00fc, 0x00e9, 0x00e2, 0x00e4, 0x00e0, 0x00e5, 0x00e7,
/* 88 */	0x00ea, 0x00eb, 0x00e8, 0x00ef, 0x00ee, 0x00ec, 0x00c4, 0x00c5,
/* 90 */	0x00c9, 0x00e6, 0x00c6, 0x00f4, 0x00f6, 0x00f2, 0x00fb, 0x00f9,
/* 98 */	0x00ff, 0x00d6, 0x00dc, 0x00a2, 0x00a3, 0x00a5, 0x00df, 0x0192,
/* a0 */	0x00e1, 0x00ed, 0x00f3, 0x00fa, 0x00f1, 0x00d1, 0x00aa, 0x00ba,
/* a8 */	0x00bf, 0x2310, 0x00ac, 0x00bd, 0x00bc, 0x00a1, 0x00ab, 0x00bb,
/* b0 */	0x00e3, 0x00f5, 0x00d8, 0x00f8, 0x0153, 0x0152, 0x00c0, 0x00c3,
/* b8 */	0x00d5, 0x00a8, 0x00b4, 0x2020, 0x00b6, 0x00a9, 0x00ae, 0x2122,
/* c0 */	0x0133, 0x0132, 0x05d0, 0x05d1, 0x05d2, 0x05d3, 0x05d4, 0x05d5,
/* c8 */	0x05d6, 0x05d7, 0x05d8, 0x05d9, 0x05db, 0x05dc, 0x05de, 0x05e0,
/* d0 */	0x05e1, 0x05e2, 0x05e4, 0x05e6, 0x05e7, 0x05e8, 0x05e9, 0x05ea,
/* d8 */	0x05df, 0x05da, 0x05dd, 0x05e3, 0x05e5, 0x00a7, 0x2227, 0x221e,
/* e0 */	0x03b1, 0x03b2, 0x0393, 0x03c0, 0x03a3, 0x03c3, 0x00b5, 0x03c4,
/* e8 */	0x03a6, 0x0398, 0x03a9, 0x03b4, 0x222e, 0x03c6, 0x2208, 0x2229,
/* f0 */	0x2261, 0x00b1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00f7, 0x2248,
/* f8 */	0x00b0, 0x2219, 0x00b7, 0x221a, 0x207f, 0x00b2, 0x00b3, 0x00af
};

/* same, except for the controls char which map to themselves in the table above */

unsigned short const atarifont_to_utf16[256] = {
/* 00 */	0x0000, 0x21e7, 0x21e9, 0x21e8, 0x21e6, 0x2610, 0x2611, 0x2612,
/* 08 */	0x2713, 0x231a, 0x237e, 0x266a, 0x240c, 0x240d, 0x26f0, 0x26f1,
/* 10 */	0x24ea, 0x2460, 0x2461, 0x2462, 0x2463, 0x2464, 0x2465, 0x2466,
/* 18 */	0x2467, 0x2468, 0x018f, 0x241b, 0x26f2, 0x26f3, 0x26f4, 0x26f5,
/* 20 */	0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
/* 28 */	0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
/* 30 */	0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
/* 38 */	0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
/* 40 */	0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
/* 48 */	0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
/* 50 */	0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
/* 58 */	0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
/* 60 */	0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
/* 68 */	0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
/* 70 */	0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
/* 78 */	0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x2206,
/* 80 */	0x00c7, 0x00fc, 0x00e9, 0x00e2, 0x00e4, 0x00e0, 0x00e5, 0x00e7,
/* 88 */	0x00ea, 0x00eb, 0x00e8, 0x00ef, 0x00ee, 0x00ec, 0x00c4, 0x00c5,
/* 90 */	0x00c9, 0x00e6, 0x00c6, 0x00f4, 0x00f6, 0x00f2, 0x00fb, 0x00f9,
/* 98 */	0x00ff, 0x00d6, 0x00dc, 0x00a2, 0x00a3, 0x00a5, 0x00df, 0x0192,
/* a0 */	0x00e1, 0x00ed, 0x00f3, 0x00fa, 0x00f1, 0x00d1, 0x00aa, 0x00ba,
/* a8 */	0x00bf, 0x2310, 0x00ac, 0x00bd, 0x00bc, 0x00a1, 0x00ab, 0x00bb,
/* b0 */	0x00e3, 0x00f5, 0x00d8, 0x00f8, 0x0153, 0x0152, 0x00c0, 0x00c3,
/* b8 */	0x00d5, 0x00a8, 0x00b4, 0x2020, 0x00b6, 0x00a9, 0x00ae, 0x2122,
/* c0 */	0x0133, 0x0132, 0x05d0, 0x05d1, 0x05d2, 0x05d3, 0x05d4, 0x05d5,
/* c8 */	0x05d6, 0x05d7, 0x05d8, 0x05d9, 0x05db, 0x05dc, 0x05de, 0x05e0,
/* d0 */	0x05e1, 0x05e2, 0x05e4, 0x05e6, 0x05e7, 0x05e8, 0x05e9, 0x05ea,
/* d8 */	0x05df, 0x05da, 0x05dd, 0x05e3, 0x05e5, 0x00a7, 0x2227, 0x221e,
/* e0 */	0x03b1, 0x03b2, 0x0393, 0x03c0, 0x03a3, 0x03c3, 0x00b5, 0x03c4,
/* e8 */	0x03a6, 0x0398, 0x03a9, 0x03b4, 0x222e, 0x03c6, 0x2208, 0x2229,
/* f0 */	0x2261, 0x00b1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00f7, 0x2248,
/* f8 */	0x00b0, 0x2219, 0x00b7, 0x221a, 0x207f, 0x00b2, 0x00b3, 0x00af
};

static unsigned char const revmaptab_00[256] = {
/* 00 */	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
/* 08 */	0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
/* 10 */	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
/* 18 */	0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
/* 20 */	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
/* 28 */	0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
/* 30 */	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
/* 38 */	0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
/* 40 */	0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
/* 48 */	0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
/* 50 */	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
/* 58 */	0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
/* 60 */	0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
/* 68 */	0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
/* 70 */	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
/* 78 */	0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
/* 80 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 88 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 90 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 98 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a0 */	0xff, 0xad, 0x9b, 0x9c, 0xde, 0x9d, 0xff, 0xdd,
/* a8 */	0xb9, 0xbd, 0xa6, 0xae, 0xaa, 0xff, 0xbe, 0xff,
/* b0 */	0xf8, 0xf1, 0xfd, 0xfe, 0xba, 0xe6, 0xbc, 0xfa,
/* b8 */	0xff, 0xff, 0xa7, 0xaf, 0xac, 0xab, 0xff, 0xa8,
/* c0 */	0xb6, 0xff, 0xff, 0xb7, 0x8e, 0x8f, 0x92, 0x80,
/* c8 */	0xff, 0x90, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d0 */	0xff, 0xa5, 0xff, 0xff, 0xff, 0xb8, 0x99, 0xff,
/* d8 */	0xb2, 0xff, 0xff, 0xff, 0x9a, 0xff, 0xff, 0x9e,
/* e0 */	0x85, 0xa0, 0x83, 0xb0, 0x84, 0x86, 0x91, 0x87,
/* e8 */	0x8a, 0x82, 0x88, 0x89, 0x8d, 0xa1, 0x8c, 0x8b,
/* f0 */	0xff, 0xa4, 0x95, 0xa2, 0x93, 0xb1, 0x94, 0xf6,
/* f8 */	0xb3, 0x97, 0xa3, 0x96, 0x81, 0xff, 0xff, 0x98
};
static unsigned char const revmaptab_01[256] = {
/* 00 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 08 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 10 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 18 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 20 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 28 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 30 */	0xff, 0xff, 0xc1, 0xc0, 0xff, 0xff, 0xff, 0xff,
/* 38 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 40 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 48 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 50 */	0xff, 0xff, 0xb5, 0xb4, 0xff, 0xff, 0xff, 0xff,
/* 58 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 60 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 68 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 70 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 78 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 80 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 88 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1a,
/* 90 */	0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 98 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
static unsigned char const revmaptab_03[256] = {
/* 00 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 08 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 10 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 18 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 20 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 28 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 30 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 38 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 40 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 48 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 50 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 58 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 60 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 68 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 70 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 78 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 80 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 88 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 90 */	0xff, 0xff, 0xff, 0xe2, 0xff, 0xff, 0xff, 0xff,
/* 98 */	0xe9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a0 */	0xff, 0xff, 0xff, 0xe4, 0xff, 0xff, 0xe8, 0xff,
/* a8 */	0xff, 0xea, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b0 */	0xff, 0xe0, 0xe1, 0xff, 0xeb, 0xff, 0xff, 0xff,
/* b8 */	0xff, 0xff, 0xff, 0xff, 0xe6, 0xff, 0xff, 0xff,
/* c0 */	0xe3, 0xff, 0xff, 0xe5, 0xe7, 0xff, 0xed, 0xff,
/* c8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
static unsigned char const revmaptab_05[256] = {
/* 00 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 08 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 10 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 18 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 20 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 28 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 30 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 38 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 40 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 48 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 50 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 58 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 60 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 68 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 70 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 78 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 80 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 88 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 90 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 98 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d0 */	0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9,
/* d8 */	0xca, 0xcb, 0xd9, 0xcc, 0xcd, 0xda, 0xce, 0xd8,
/* e0 */	0xcf, 0xd0, 0xd1, 0xdb, 0xd2, 0xdc, 0xd3, 0xd4,
/* e8 */	0xd5, 0xd6, 0xd7, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
static unsigned char const revmaptab_20[256] = {
/* 00 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 08 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 10 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 18 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 20 */	0xbb, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 28 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 30 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 38 */	0xde, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 40 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 48 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 50 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 58 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 60 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 68 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 70 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 78 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
/* 80 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 88 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 90 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 98 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a8 */	0xff, 0xff, 0xff, 0xff, 0xde, 0xff, 0xff, 0xff,
/* b0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
static unsigned char const revmaptab_21[256] = {
/* 00 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 08 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 10 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 18 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 20 */	0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 28 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 30 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 38 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 40 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 48 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 50 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 58 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 60 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 68 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 70 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 78 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 80 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 88 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 90 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 98 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x04, 0x01,
/* e8 */	0x03, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
static unsigned char const revmaptab_22[256] = {
/* 00 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff,
/* 08 */	0xee, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 10 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 18 */	0xff, 0xf9, 0xfb, 0xff, 0xff, 0xff, 0xdf, 0xff,
/* 20 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xde,
/* 28 */	0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xec, 0xff,
/* 30 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 38 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 40 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 48 */	0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 50 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 58 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 60 */	0xff, 0xf0, 0xff, 0xff, 0xf3, 0xf2, 0xff, 0xff,
/* 68 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 70 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 78 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 80 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 88 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 90 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 98 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
static unsigned char const revmaptab_23[256] = {
/* 00 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 08 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 10 */	0xa9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 18 */	0xff, 0xff, 0x09, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 20 */	0xf4, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 28 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 30 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 38 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 40 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 48 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 50 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 58 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 60 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 68 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 70 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 78 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0xff,
/* 80 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 88 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 90 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 98 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
static unsigned char const revmaptab_24[256] = {
/* 00 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 08 */	0xff, 0xff, 0xff, 0xff, 0x0c, 0x0d, 0xff, 0xff,
/* 10 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 18 */	0xff, 0xff, 0xff, 0x1b, 0xff, 0xff, 0xff, 0xff,
/* 20 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 28 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 30 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 38 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 40 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 48 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 50 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 58 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 60 */	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
/* 68 */	0x19, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 70 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 78 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 80 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 88 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 90 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 98 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e8 */	0xff, 0xff, 0x10, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
static unsigned char const revmaptab_26[256] = {
/* 00 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 08 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 10 */	0x05, 0x06, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 18 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 20 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 28 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 30 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 38 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 40 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 48 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 50 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 58 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 60 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 68 */	0xff, 0xff, 0x0b, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 70 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 78 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 80 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 88 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 90 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 98 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f0 */	0x0e, 0x0f, 0x1c, 0x1d, 0x1e, 0x1f, 0xff, 0xff,
/* f8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
static unsigned char const revmaptab_27[256] = {
/* 00 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 08 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 10 */	0xff, 0xff, 0xff, 0x08, 0xff, 0xff, 0xff, 0xff,
/* 18 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 20 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 28 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 30 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 38 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 40 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 48 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 50 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 58 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 60 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 68 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 70 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 78 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 80 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 88 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 90 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* 98 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* a8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* b8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* c8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* d8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* e8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f0 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
/* f8 */	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
static unsigned char const revmaptab_ff[256] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
const unsigned char (*const utf16_to_atari[256])[256] = {
	&revmaptab_00, &revmaptab_01, &revmaptab_ff, &revmaptab_03, &revmaptab_ff, &revmaptab_05, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_20, &revmaptab_21, &revmaptab_22, &revmaptab_23, &revmaptab_24, &revmaptab_ff, &revmaptab_26, &revmaptab_27,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff,
	&revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff, &revmaptab_ff
};

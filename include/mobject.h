/*****************************************************************************
 * MOBJECT.H
 *****************************************************************************/

#ifndef __MOBJECT_H__
#define __MOBJECT_H__

#ifndef __PORTAB_H__
#  include <portab.h>
#endif
#ifndef __PORTAES_H__
#  include <portaes.h>
#endif


/*
 * configurable settings
 */

#define MAXNAMELEN		32			/* maximum length of object names */
#define RSDNAMELEN		8			/* maximum length of names in old formats */
#define RSMNAMELEN      99
#define COMMENTLEN		250			/* maximum length of comment strings */
#define COMMENTLINES	3			/* number of comment lines */
#define FNAMELEN		32			/* size of file names */
#define MAXCOLOR		15
#define MAX_TEXT_EDIT	256
#define NAME_TEXT_LEN	6

/*
 * a list of strings terminated by 2 '\0'
 */
typedef char *stringarray;
typedef const char *cstringarray;


typedef struct _rsctree RSCTREE;
typedef struct _rscfile RSCFILE;
typedef _UWORD RSC_RSM_CRC;
#define RSC_CRC_NONE ((RSC_RSM_CRC)-1)

/*
 * RSM embedded CRC strings
 */
#define RSM_CRC_STRING "& RSM-crc >%04X< crc-MSR $"
/* length of printed version of above, including NUL byte */
#define RSM_CRC_STRLEN 27
/* name that is used for the string name */
#define RSM_CRC_STRID "_RSM_CRC_"
/* name that is used for the string itself */
#define RSM_CRC_STRINGID "_RSM_CRC_STRING_"


typedef struct {
	OBJECT *mn_tree;
	OBJECT *mn_title;
	OBJECT *mn_menu;
	OBJECT *mn_submenu;
} ORMENUINFO;

typedef struct {
	OBJECT *di_tree;
	OBJECT *di_popup; /* parent */
	OBJECT *di_popup_tree; /* displayed popup */
	_WORD di_x, di_y;
} DIALINFO;

typedef struct _bghentry BGHENTRY;
struct _bghentry {
	_WORD idx;
	BGHENTRY *next;
	BGHENTRY *prev;
	stringarray cmnt;
};

typedef struct _bghinfo BGHINFO;
struct _bghinfo {
	_WORD type;
	_WORD idx; /* unused; tree->rt_index is used for import/export */
	BGHENTRY head;
};

typedef struct {
	_UBYTE *al_str;
	BGHINFO *al_bgh;
} ALERTINFO;

typedef struct {
	_UBYTE *fr_str;
	BGHINFO *fr_bgh;
} STRINFO;

#define FOR_ALL_BGH(bgh, entry) for (entry = bgh->head.next; entry != &bgh->head; entry = entry->next)

/*
 * Rueckgabewerte der Exit-Funktion eines Dialogs
 */
typedef enum { RET_OK, RET_NEXT, RET_CAN, RET_EDIT, RET_PREV } dialog_retcode;

/*
 * trees in resource file
 */
struct _rsctree {
	_WORD rt_type;					/* type of tree */
	_UBYTE rt_name[MAXNAMELEN+1];	/* tree name */
	union {
		void *any;
		DIALINFO dial;				/* RT_DIALOG, RT_FREE, RT_UNKNOWN */
		ORMENUINFO menu;			/* RT_MENU */
		STRINFO str;				/* RT_FRSTR */
		ALERTINFO alert;			/* RT_ALERT */
		BITBLK *bit;				/* RT_FRIMG/RT_MOUSE */
		BGHINFO *bgh;				/* RT_BUBBLEMORE/RT_BUBBLEUSER */
	} rt_objects;					/* OBJECT structs */
	_LONG rt_index;                 /* tree index */
	RSCFILE *rt_file;				/* backward link to file */
	RSCTREE *rt_next;				/* next in linked list of file */
	RSCTREE *rt_prev;				/* previous in linked list of file */
	stringarray rt_cmnt;
};

#define DIAL_TREE(wr) wr_rtree(wr)->rt_objects.dial.di_tree
#define DIAL_TTREE(tree) tree->rt_objects.dial.di_tree

#define MENU_TREE(wr) wr_rtree(wr)->rt_objects.menu.mn_tree
#define MENU_TTREE(tree) tree->rt_objects.menu.mn_tree

#define BGH_TREE(wr) wr_rtree(wr)->rt_objects.bgh
#define BGH_TTREE(tree) tree->rt_objects.bgh

/*
 * Table of RSC-Extensions.
 * Unused entries are marked with ptr == -1 and size == 0,
 * the end of the list will have ptr == 0.
 */
typedef struct _rsc_ext {
	_LONG_PTR ext_ptr;
	_LONG ext_size;
} RSC_EXT;


#define FOR_ALL_RSC(file,tree) for (tree = file->rsc_treehead.rt_next; tree != &file->rsc_treehead; tree = tree->rt_next)

/*
 * resource tree types
 */

#ifdef __WIN32__
#undef RT_MENU
#undef RT_DIALOG
#endif

#define RT_UNKNOWN		0	/* unknown type */
#define RT_FREE         1	/* free (handled as dialog) */
#define RT_MENU         2	/* menu bar */
#define RT_DIALOG		3	/* dialog box */
#define RT_ALERT		4	/* alert box */
#define RT_FRSTR		5	/* free string */
#define RT_FRIMG		6	/* free image */
#define RT_MOUSE		7	/* mouse form */
#define RT_BUBBLEMORE   8   /* BGH more collection */
#define RT_BUBBLEUSER   9   /* BGH user collection */


typedef struct {
	_UBYTE ted_fillchar;		/* char used to fill up editable text fields */
	_WORD menu_leftmargin;		/* min. spaces left of menu text */
	_WORD menu_rightmargin;		/* min. spaces at end of emnu entry */
	_WORD menu_minspace;		/* min. spaces between text & shortcut */
	_BOOL menu_fillspace;
	_WORD menu_maxchars;		/* from RSM; not yet used */
	_BOOL alert_limits;			/* wether to check alert limits; not yet supported */
	_WORD alert_max_icon;		/* max # of icon for alerts */
	_WORD alert_max_linesize;	/* max. linesize for alert texts */
	_BOOL crc_string;			/* wether to embed CRC string in resource */
	_BOOL dummy_icons;			/* wether to duplicate mono part of color icons; unsupported useless RSM option */
	_BOOL ted_small_valid;		/* wether to shorten te_pvalid; not yet supported (always TRUE) */
	_WORD layer_save_mode;		/* how to create single layers; not yet supported */
	_BOOL objc_size_check;		/* wether to recalc object size */
	_BOOL magic_buttons;		/* wether to handle '[' in buttons; RSM option, done via extended object types in ORCS */
	_BOOL menu_keycheck;		/* wether to check for duplicate shortcuts in menus */
} rsc_options;

/*
 * output flags
 */

#define RF_NONE             0x0l
#define RF_C				0x00000001l
#define RF_PASCAL			0x00000002l
#define RF_MODULA			0x00000004l
#define RF_FORTRAN			0x00000008l
#define RF_GFA				0x00000010l
#define RF_CSOURCE1         0x00000020l
#define RF_ASS				0x00000040l
#define RF_ASOURCE			0x00000080l
#define RF_CSOURCE2         0x00000100l
#define RF_BASIC			0x00000200l
#define RF_FORTH			0x00000400l
#define RF_MODULA_MM2		0x00000800l
#define RF_MODULA_TDI		0x00001000l
#define RF_NRSC             0x00002000l
#define RF_VERBOSE			0x00004000l
/* #define RF_MERGE			0x00008000l */
#define RF_DEF				0x00010000l
#define RF_DFN				0x00020000l
#define RF_HRD				0x00040000l
#define RF_RSO				0x00080000l
#define RF_MODULA_LPR		0x00100000l
#define RF_CDATA			0x00200000l
#define RF_PSOURCE			0x00400000l
#define RF_MODULA_ARRAY		0x00800000l
#define RF_RSC              0x10000000l
#define RF_RCSOURCE         0x20000000l
#define RF_RSX              0x40000000l
#define RF_RSM              0x80000000l
#define RF_ALL				0xf0ffffffl

#define RF_SDLSOURCE        0x00000001l
#define RF_EXTERNAL         0x00000002l
#define RF_XML              0x00000004l
#define RF_BGH              0x00000008l
#define RF_ALTORDER         0x00000010l
#define RF_NOPVALOPT        0x00000020l
#define RF_STATIC           0x00000040l
#define RF_ROMABLE          0x00000080l

#define RF_EXTOB_NONE		0x00000000l
#define RF_EXTOB_ORCS		0x01000000l
#define RF_EXTOB_FLYDIAL	0x02000000l
#define RF_EXTOB_MYDIAL     0x03000000l
#define RF_EXTOB_GEISS1     0x04000000l
#define RF_EXTOB_GEISS2     0x05000000l
#define RF_EXTOB_MAGIC		0x06000000l
#define RF_EXTOB_WEGA		0x07000000l
#define RF_EXTOB_WIN		0x08000000l
#define RF_EXTOB_HONKA		0x09000000l
#define RF_EXTOB_MAGIX		0x0A000000l
#define RF_EXTOB_AES		0x0B000000l
#define RF_EXTOB_FACEVALUE  0x0C000000l
#define RF_EXTOB_SYSGEM     0x0D000000l
#define RF_EXTOB_OVERLAY    0x0E000000l

#define RF_EXTOB_MASK		0x0F000000l

#define RF_TO_EXTOB(x) ((EXTOB_MODE)(((x) & RF_EXTOB_MASK) >> 24))
#define EXTOB_TO_RF(x) ((((_LONG)(x)) << 24) & RF_EXTOB_MASK)


/*
 * format of old DRI definition file (*.def,*.dfn)
 */
typedef struct {
	_UWORD na_count;				/* number of infos */
	_UWORD na_flags;				/* application binding flags */
	_UBYTE na_treeidx;				/* tree index */
	_UBYTE na_obidx;				/* object index */
	_UBYTE na_nametype;             /* type of entry: 0 = tree, 1 = object */
	_UBYTE na_treetype;             /* type of tree */
	_UBYTE na_name[RSDNAMELEN];     /* object name */
} NAMEINFO;


/* File FILEIO.C */

_BOOL export_strings(RSCFILE *file, const _UBYTE *filename);
_BOOL import_strings(RSCFILE *file, const _UBYTE *filename);


/* File MOBJ.C */

enum fix_code { UF_FROM_DESKTOP, UF_TO_DESKTOP, UF_TO_WINDOW };

/* bgh.c */

BGHINFO *bgh_new(_WORD type, _WORD idx);
BGHINFO *bgh_dup(BGHINFO *old);
BGHENTRY *bgh_new_entry(BGHINFO *bgh, _WORD idx, const char *cmnt);
void bgh_delete(BGHINFO *bgh);
_WORD bgh_count(BGHINFO *bgh);
BGHENTRY *bgh_idx(BGHINFO *bgh, _WORD idx);


/* *_FIO.C */

enum check_code { CHECK_ABORT, CHECK_OK, CHECK_APPEND };

_BOOL load_all(RSCFILE *file, const _UBYTE *filename);
enum check_code check_file(_UBYTE *filename, const _UBYTE *extension, _BOOL append_allowed);
_BOOL save_all(RSCFILE *file, const _UBYTE *filename);
_VOID err_nota_rsc(const _UBYTE *filename);
_BOOL ask_ibm(const _UBYTE *filename, _BOOL);
_BOOL ask_unknown_ext(_VOID);
_BOOL ask_convert_names(_VOID);
_BOOL ask_rsm_single_layer(_VOID);
_BOOL ask_rsm_multi_layer(_VOID);
_BOOL ask_damaged_rsx(const _UBYTE *filename);
_VOID warn_cicons(_VOID);
_VOID warn_rso_toonew(_VOID);
_VOID warn_names_truncated(_WORD maxlen);
void warn_rsm_bgh_comments(void);
_VOID warn_name_truncated(const _UBYTE *name);
_VOID warn_damaged(const _UBYTE *filename, const _UBYTE *where);
_VOID warn_def_damaged(const _UBYTE *filename);
_VOID warn_interface_flags(const _UBYTE *filename);
_VOID warn_names_deleted(const _UBYTE *filename);
_BOOL ask_corrupted(_WORD tree_index, _WORD obj_index, _UWORD type, const _UBYTE *whats_wrong);
_BOOL ask_cicon_probs(_VOID);
_BOOL ask_tree_notfound(_WORD);
_BOOL ask_object_notfound(_LONG ob_index, _UBYTE *tree_name);
_VOID warn_toobig(_VOID);
_BOOL ask_file_toobig(_LONG filesize);
_BOOL warn_ted_length(const _UBYTE *treename, const _UBYTE *obname, _WORD dstlen, _WORD srclen);
_WORD rsc_icon_type(_WORD tree_type);
_VOID close_tree_window(RSCTREE *tree);
_VOID rsc_name_change(RSCFILE *file);
_VOID err_overlay_crashed(void);
_VOID warn_unknown_module(const _UBYTE *filename, const char *id, const char *name);
_VOID warn_crc_mismatch(const _UBYTE *filename);
_VOID warn_crc_string_mismatch(const _UBYTE *filename);

const char *ob_name(RSCFILE *file, OBJECT *tree, _WORD ob);
const char *ob_cmnt(RSCFILE *file, OBJECT *tree, _WORD ob);

#endif /* __MOBJECT_H__ */

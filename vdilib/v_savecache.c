/*
 *  $Id: v_savecache.c,v 1.6 2003/08/07 07:05:33 a_bercegeay Exp $
 */

#include "gem_vdiP.h"

/** 
 *
 *  @param handle Device handle
 *  @param filename
 *
 *  @return 
 *
 *  @since 
 *
 *  @sa
 *
 *
 *
 */

short
v_savecache (short handle, const char *filename)
{
	short vdi_control[VDI_CNTRLMAX]; 
	short vdi_intin[VDI_INTINMAX];
	short vdi_intout[VDI_INTOUTMAX]; /* todo (doc wanted) */
	register short n = vdi_str2array (filename, vdi_intin);

	VDI_PARAMS(vdi_control, vdi_intin, 0L, vdi_intout, vdi_dummy );
	
	VDI_TRAP (vdi_params, handle, 249, 0,n);
	
	return vdi_intout[0];
}

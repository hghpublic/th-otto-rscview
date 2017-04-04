/*
 *  $Id: pdlg_create.c,v 1.5 2003/02/28 20:46:41 a_bercegeay Exp $
 */

#include "gem_aesP.h"
#include "gemx.h"

/** initialises the print dialog
 *
 *  @param dialog_flags Only 3D-flag at present:
 *         - PDLG_3D     (1)    Display selection in 3D-look
 *  @param global_aes global AES array
 *
 *  @return Pointer to management structure
 *
 *  @since mt_appl_getinfo(7) give informations on mt_pdlg_xx() functions availability
 *
 *  On calling the function a 
 *  scan will be made for the printer drivers present and memory will be 
 *  allocated for the resource.
 *
 */

PRN_DIALOG *
mt_pdlg_create(short dialog_flags, short *global_aes)
{
	AES_PARAMS(200,1,0,0,1);

	aes_intin[0] = dialog_flags;

	AES_TRAP(aes_params);

	return aes_addrout[0];
}

PRN_DIALOG *(pdlg_create)(short dialog_flags)
{
	return mt_pdlg_create(dialog_flags, aes_global);
}

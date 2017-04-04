/*
 *  $Id: pdlg_add_printers.c,v 1.5 2003/02/28 20:46:41 a_bercegeay Exp $
 */

#include "gem_aesP.h"
#include "gemx.h"

/** Add application's printers
 *
 *  @param prn_dialog Pointer to management structure
 *  @param drv_info contains a pointer to a list of 
 *         available printers and dither processes.
 *  @param global_aes global AES array
 *
 *  @return 0: Error \n   1: All OK
 *
 *  @since mt_appl_getinfo(7) give informations on mt_pdlg_xx() functions availability
 *
 *  With mt_pdlg_add_printers() a program can add its own private printer 
 *  descriptions to the dialog. The driver number should be 
 *  set to 0x7fff to differentiate the private driver from the OS-drivers.
 */

short 
mt_pdlg_add_printers(PRN_DIALOG *prn_dialog, DRV_INFO *drv_info, short *global_aes)
{
	AES_PARAMS(205,1,1,2,0);

	aes_intin[0] = 0;

	aes_addrin[0] = prn_dialog;
	aes_addrin[1] = drv_info;

	AES_TRAP(aes_params);

	return aes_intout[0];
}

short (pdlg_add_printers)(PRN_DIALOG *prn_dialog, DRV_INFO *drv_info)
{
	return mt_pdlg_add_printers(prn_dialog, drv_info, aes_global);
}

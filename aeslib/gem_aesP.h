#ifndef _GEM_AES_P_
# define _GEM_AES_P_

#include <portaes.h>

#ifndef NULL
#  define NULL ((void *)0)
#endif


/** size of the aes_control[] array */
#define AES_CTRLMAX		6		/* actually 5; use 6 to make it long aligned */
/** size of the aes_global[] array */
#define AES_GLOBMAX		(sizeof(AES_GLOBAL) / sizeof(aes_global[0]))
/** size of the aes_intin[] array */
#define AES_INTINMAX 		16
/** size of the aes_intout[] array */
#define AES_INTOUTMAX		16
/** size of the aes_addrin[] array */
#define AES_ADDRINMAX		16
/** size of the aes_addrout[] array */
#define AES_ADDROUTMAX		16

#define AES_TRAP(aespb) aes(&aespb)

#ifdef __GNUC__

static __inline long *__aes_intout_long(short n, short *aes_intout)
{
	return ((long *)(aes_intout   +n));
}
#define aes_intout_long(n)  *__aes_intout_long(n, aes_intout)

#else

#define aes_intout_long(n)  *((long *)(aes_intout+(n)))

#endif


#define AES_PARAMS(opcode,nintin,nintout,naddrin,naddrout) \
	static short const aes_control[AES_CTRLMAX]={opcode,nintin,nintout,naddrin,naddrout}; \
	short			aes_intin[AES_INTINMAX];			  \
	short			aes_intout[AES_INTOUTMAX];			  \
	const void *	aes_addrin[AES_ADDRINMAX];			  \
	void *			aes_addrout[AES_ADDROUTMAX];		  \
 														  \
	AESPB aes_params;									  \
  	aes_params.control = aes_control;				  \
  	aes_params.global  = aes_global;				  \
  	aes_params.intin   = aes_intin; 				  \
  	aes_params.intout  = aes_intout;				  \
  	aes_params.addrin  = aes_addrin;				  \
  	aes_params.addrout = aes_addrout



/* special feature for AES bindings: pointer in parameters (for return values)
 * could be NULL (nice idea by Martin Elsasser against dummy variables) 
 */
#define CHECK_NULLPTR 1


#endif /* _GEM_AES_P_ */

/*
 * Configuration of module PduR (PduR_Cfg.h)
 *
 * Created by: Arccore AB
 * Configured for (MCU): MPC551x
 *
 * Module vendor: ArcCore
 * Module version: 2.0.2
 *
 * 
 * Generated by Arctic Studio (http://arccore.com) 
 *           on Fri Dec 03 08:32:04 CET 2010
 */


#if (PDUR_SW_MAJOR_VERSION != 1) 
#error "PduR: Configuration file version differs from BSW version."
#endif



#ifndef PDUR_CFG_H_
#define PDUR_CFG_H_

// Module support
#define PDUR_CANIF_SUPPORT 			STD_ON
#define PDUR_CANTP_SUPPORT			STD_OFF
#define PDUR_FRIF_SUPPORT			STD_OFF  /* Not supported */
#define PDUR_FRTP_SUPPORT			STD_OFF  /* Not supported */
#define PDUR_LINIF_SUPPORT			STD_OFF
#define PDUR_LINTP_SUPPORT			STD_OFF  /* Not supported */
#define PDUR_COM_SUPPORT			STD_ON
#define PDUR_DCM_SUPPORT			STD_OFF
#define PDUR_IPDUM_SUPPORT			STD_OFF  /* Not supported */


#define PDUR_DEV_ERROR_DETECT		STD_OFF
#define PDUR_VERSION_INFO_API		STD_OFF


// Zero cost operation mode
#define PDUR_ZERO_COST_OPERATION	STD_ON
#define PDUR_SINGLE_IF				CAN_IF
#define PDUR_SINGLE_TP				CAN_TP


// Gateway operation
#define PDUR_GATEWAY_OPERATION				STD_OFF
#define PDUR_MEMORY_SIZE					10 /* Not used */
#define PDUR_SB_TX_BUFFER_SUPPORT			STD_OFF
#define PDUR_FIFO_TX_BUFFER_SUPPORT			STD_OFF

/**
 * The maximum numbers of Tx buffers.
 */
#define PDUR_MAX_TX_BUFFER_NUMBER			10 /* Not used */





// Multicast
/* Not supported
#define PDUR_MULTICAST_TOIF_SUPPORT			STD_OFF
#define PDUR_MULTICAST_FROMIF_SUPPORT		STD_OFF
#define PDUR_MULTICAST_TOTP_SUPPORT			STD_OFF
#define PDUR_MULTICAST_FROMTP_SUPPORT		STD_OFF
*/


// Minimum routing
/* Minimum routing not supported.
#define PDUR_MINIMUM_ROUTING_UP_MODULE		COM
#define PDUR_MINIMUM_ROUTING_LO_MODULE		CAN_IF
#define PDUR_MINIMUM_ROUTING_UP_RXPDUID		((PduIdType)100)
#define PDUR_MINIMUM_ROUTING_LO_RXPDUID 	((PduIdType)255)
#define PDUR_MINIMUM_ROUTING_UP_TXPDUID 	((PduIdType)255)
#define PDUR_MINIMUM_ROUTING_LO_TXPDUID 	((PduIdType)255)
*/


#endif

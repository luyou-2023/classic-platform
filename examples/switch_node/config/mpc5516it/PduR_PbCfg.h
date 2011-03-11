/*
 * Configuration of module PduR (PduR_PbCfg.h)
 *
 * Created by: ArcCore AB
 * Configured for (MCU): MPC551x
 *
 * Module vendor: ArcCore
 * Module version: 2.0.2
 *
 * Copyright ArcCore AB 2010
 * Generated by Arctic Studio (http://arccore.com) 
 *           on Mon Jan 17 12:24:21 CET 2011
 */


#if !(((PDUR_SW_MAJOR_VERSION == 1) && (PDUR_SW_MINOR_VERSION == 0)) )
#error "PduR: Configuration file version differs from BSW version."
#endif


#if defined(USE_DCM)
#include "Dcm.h"
#endif
#if defined(USE_COM)
#include "Com.h"
#endif
#if defined(USE_CANIF)
#include "CanIf.h"
#endif
#if defined(USE_CANTP)
#include "CanTp.h"
#endif

extern PduR_PBConfigType PduR_Config;

//  PduR Polite Defines.

#define PDUR_SOURCE_PDU_ID_LedCommandTx COM_PDU_ID_LedCommandTx
#define PDUR_DEST_PDU_ID_LedCommandTx CANIF_PDU_ID_LedCommandTx

/*
 * Configuration of module Dio (Dio_Cfg.h)
 *
 * Created by: 
 * Configured for (MCU): TMS570
 *
 * Module vendor: ArcCore
 * Module version: 2.0.0
 *
 * 
 * Generated by Arctic Studio (http://arccore.com) 
 *           on Fri Dec 10 11:45:13 CET 2010
 */


#if (DIO_SW_MAJOR_VERSION != 1) 
#error "Dio: Configuration file version differs from BSW version."
#endif


#ifndef DIO_CFG_H_
#define DIO_CFG_H_
#include "Port.h"

#define DIO_VERSION_INFO_API    STD_ON
#define DIO_DEV_ERROR_DETECT    STD_ON

#define DIO_END_OF_LIST  -1

// Physical ports
typedef enum
{
  DIO_PORT_A = 0,
  DIO_PORT_B = 1,
} Dio_PortTypesType;


// Channels	
#define DIO_CHANNEL_NAME_DioChannel_1	PORT_PAD_3

// Channel group

// Ports
#define DIO_PORT_NAME_DioPort_1 		(DIO_PORT_A)




// Pointers for convenience.
// Channels	
extern const Dio_ChannelType DioChannelConfigData[];
// Channel group
extern const Dio_ChannelGroupType DioConfigData[];
// Port
extern const Dio_PortType DioPortConfigData[];

#endif /*DIO_CFG_H_*/

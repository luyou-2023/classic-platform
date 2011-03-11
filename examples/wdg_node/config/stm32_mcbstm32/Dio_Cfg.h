/*
 * Configuration of module Dio (Dio_Cfg.h)
 *
 * Created by: 
 * Configured for (MCU): STM32_F103
 *
 * Module vendor: ArcCore
 * Module version: 2.0.0
 *
 * 
 * Generated by Arctic Studio (http://arccore.com) 
 *           on Mon Feb 28 18:42:03 CET 2011
 */


#if !(((DIO_SW_MAJOR_VERSION == 1) && (DIO_SW_MINOR_VERSION == 0)) )
#error "Dio: Configuration file version differs from BSW version."
#endif


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#define DIO_VERSION_INFO_API    STD_OFF
#define DIO_DEV_ERROR_DETECT    STD_OFF

#define DIO_END_OF_LIST  -1

// Physical ports
typedef enum
{
  A = 0,
  B = 1,
  C = 2,
  D = 3,
  E = 4,
  F = 5,
  G = 6,
} Dio_PortTypesType;


// Channels	
#define DIO_CHANNEL_NAME_HeartBeatLED	31

// Channel group

// Ports
#define DIO_PORT_NAME_DioPort_1 		(B)




// Pointers for convenience.
// Channels	
extern const Dio_ChannelType DioChannelConfigData[];
// Channel group
extern const Dio_ChannelGroupType DioConfigData[];
// Port
extern const Dio_PortType DioPortConfigData[];

#endif /*DIO_CFG_H_*/

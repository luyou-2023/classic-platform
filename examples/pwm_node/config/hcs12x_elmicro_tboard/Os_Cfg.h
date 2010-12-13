/*
 * Configuration of module Os (Os_Cfg.h)
 *
 * Created by: Arccore AB
 * Configured for (MCU): HCS12
 *
 * Module vendor: ArcCore
 * Module version: 2.0.11
 *
 * 
 * Generated by Arctic Studio (http://arccore.com) 
 *           on Wed Dec 01 15:28:34 CET 2010
 */


#if (OS_SW_MAJOR_VERSION != 2) 
#error "Os: Configuration file version differs from BSW version."
#endif


#ifndef OS_CFG_H_
#define OS_CFG_H_


// Alarm Id's
#define ALARM_ID_Alarm100	0
#define ALARM_ID_Alarm25	1

// Counter Id's
#define COUNTER_ID_OsTick	0

// Counter macros
#define OSMAXALLOWEDVALUE_OsTick 65535


// Event masks

// Isr Id's

// Resource Id's

// Linked resource id's

// Resource masks

// Task Id's
#define TASK_ID_OsIdle	0
#define TASK_ID_Startup	1
#define TASK_ID_bTask100	2
#define TASK_ID_bTask25	3

// Task entry points
void OsIdle( void );
void Startup( void );
void bTask100( void );
void bTask25( void );

// Schedule table id's

// Stack size
#define OS_INTERRUPT_STACK_SIZE	512
#define OS_OSIDLE_STACK_SIZE 512

#define OS_ALARM_CNT			2 
#define OS_TASK_CNT				4
#define OS_SCHTBL_CNT			0
#define OS_COUNTER_CNT			1
#define OS_EVENTS_CNT			0
#define OS_ISRS_CNT				0
#define OS_RESOURCE_CNT			0
#define OS_LINKED_RESOURCE_CNT	0

#define CFG_OS_DEBUG				STD_OFF

#define OS_SC1 						STD_ON     
#define OS_STACK_MONITORING			STD_ON
#define OS_STATUS_EXTENDED			STD_ON
#define OS_USE_GET_SERVICE_ID		STD_ON
#define OS_USE_PARAMETER_ACCESS		STD_ON
#define OS_RES_SCHEDULER			STD_ON

#endif /*OS_CFG_H_*/

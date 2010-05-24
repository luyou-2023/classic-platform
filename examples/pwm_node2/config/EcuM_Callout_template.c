/* 
* Configuration of module EcuM (EcuM_Callout_template.c)
* 
* Created by: 
* Configured for (MCU): MPC551x
* 
* Module editor vendor:  ArcCore
* Module editor version: 2.0.0
* 
* 
* Generated by Arctic Studio (http://arccore.com)
*           on Fri Apr 30 14:42:38 CEST 2010
*/


#include "EcuM.h"
#include "Det.h"
#if defined(USE_DEM)
#include "Dem.h"
#endif
#if defined(USE_MCU)
#include "Mcu.h"
#endif
#if defined(USE_GPT)
#include "Gpt.h"
#endif
#if defined(USE_CAN)
#include "Can.h"
#endif
#if defined(USE_CANIF)
#include "CanIf.h"
#endif
#if defined(USE_PDUR)
#include "PduR.h"
#endif
#if defined(USE_COM)
#include "Com.h"
#endif
#if defined(USE_CANTP)
#include "CanTp.h"
#endif
#if defined(USE_DCM)
#include "Dcm.h"
#endif
#if defined(USE_PWM)
#include "Pwm.h"
#endif
#if defined(USE_IOHWAB)
#include "IoHwAb.h"
#endif

void EcuM_AL_DriverInitZero()
{
	Det_Init();
    Det_Start();
}

EcuM_ConfigType* EcuM_DeterminePbConfiguration()
{
	return &EcuMConfig;
}

void EcuM_AL_DriverInitOne(const EcuM_ConfigType *ConfigPtr)
{
#if defined(USE_MCU)
	Mcu_Init(ConfigPtr->McuConfig);

	// Set up default clock (Mcu_InitClock requires initRun==1)
	Mcu_InitClock( ConfigPtr->McuConfig->McuDefaultClockSettings );

	// Wait for PLL to sync.
	while (Mcu_GetPllStatus() != MCU_PLL_LOCKED)
	  ;
#endif

#if defined(USE_DEM)
	// Preinitialize DEM
	Dem_PreInit();
#endif

#if defined(USE_PORT)
	// Setup Port
	Port_Init(ConfigPtr->PortConfig);
#endif


#if defined(USE_GPT)
	// Setup the GPT
	Gpt_Init(ConfigPtr->GptConfig);
#endif

	// Setup watchdog
	// TODO

#if defined(USE_DMA)
	// Setup DMA
	Dma_Init(ConfigPtr->DmaConfig);
#endif

#if defined(USE_ADC)
	// Setup ADC
	Adc_Init(ConfigPtr->AdcConfig);
#endif

	// Setup ICU
	// TODO

	// Setup PWM
#if defined(USE_PWM)
	// Setup PWM
	Pwm_Init(ConfigPtr->PwmConfig);
#endif
}

void EcuM_AL_DriverInitTwo(const EcuM_ConfigType* ConfigPtr)
{
#if defined(USE_SPI)
	// Setup SPI
	Spi_Init(ConfigPtr->SpiConfig);
#endif

#if defined(USE_EEP)
	// Setup EEP
	Eep_Init(ConfigPtr->EEpConfig);
#endif

#if defined(USE_FLS)
	// Setup Flash
	FlashInit(ConfigPtr->FlashConfig);
#endif

	// Setup NVRAM Manaager
	// TODO

	// Setup CAN tranceiver
	// TODO

#if defined(USE_CAN)
	// Setup Can driver
	Can_Init(ConfigPtr->CanConfig);
#endif

#if defined(USE_CANIF)
	// Setup CanIf
	CanIf_Init(ConfigPtr->CanIfConfig);
#endif

#if defined(USE_CANTP)
	// Setup CAN TP
	CanTp_Init();
#endif
	// Setup LIN
	// TODO

#if defined(USE_PDUR)
	// Setup PDU Router
	PduR_Init(ConfigPtr->PduRConfig);
#endif

#if defined(USE_COM)
	// Setup COM layer
	Com_Init(ConfigPtr->ComConfig);
#endif

#if defined(USE_DCM)
	// Setup DCM
	Dcm_Init();
#endif

#if defined(USE_IOHWAB)
	// Setup IO hardware abstraction layer
	IoHwAb_Init();
#endif

}

void EcuM_AL_DriverInitThree(const EcuM_ConfigType ConfigPtr)
{
#if defined(USE_DEM)
	// Setup DEM
	Dem_Init();
#endif

#if defined(USE_CANIF)
	// Startup the CAN interafce; due to the missing COM manager
	CanIf_InitController(CANIF_CHANNEL_0, CANIF_CHANNEL_0_CONFIG_0);
	CanIf_SetControllerMode(CANIF_CHANNEL_0, CANIF_CS_STARTED);
#endif
}

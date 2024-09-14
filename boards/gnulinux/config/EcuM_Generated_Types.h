/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 *
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with
 * the terms contained in the written license agreement between you and ArcCore,
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as
 * published by the Free Software Foundation and appearing in the file
 * LICENSE.GPL included in the packaging of this file or here
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/

//该结构体包含了 ECU（电子控制单元）管理系统所需的各种配置信息。这个结构体是根据 AUTOSAR 标准定义的，并且在编译时根据 ARXML 文件中的配置信息生成

#if !(((ECUM_SW_MAJOR_VERSION == 2) && (ECUM_SW_MINOR_VERSION == 3)) )
#error EcuM: Configuration file expected BSW module version to be 2.3.\*
#endif


#ifndef _ECUM_GENERATED_TYPES_H_
#define _ECUM_GENERATED_TYPES_H_


#include "PreCompiledDataHash.h"

/* @req SWS_EcuM_02992 */ /* @req SWS_EcuM_02992 */

#include "EcuM_Types.h"

#if defined(USE_MCU)
#include "Mcu.h"
#endif
#if defined(USE_PORT)
#include "Port.h"
#endif
#if defined(USE_CAN)
#include "Can.h"
#endif
#if defined(USE_DIO)
#include "Dio.h"
#endif
#if defined(USE_LIN)
#include "Lin.h"
#endif
#if defined(USE_CANIF)
#include "CanIf.h"
#endif
#if defined(USE_LINIF)
#include "LinIf.h"
#endif
#if defined(USE_PWM)
#include "Pwm.h"
#endif
#if defined (USE_OCU)
#include "Ocu.h"
#endif
#if defined (USE_ICU)
#include "Icu.h"
#endif
#if defined(USE_COM)
#include "Com.h"
#endif
#if defined(USE_PDUR)
#include "PduR.h"
#endif
#if defined(USE_DMA)
#include "Dma.h"
#endif
#if defined(USE_ADC)
#include "Adc.h"
#endif
#if defined(USE_GPT)
#include "Gpt.h"
#endif
#if defined(USE_COMM)
#include "ComM.h"
#endif
#if defined(USE_NM)
#include "Nm.h"
#endif
#if defined(USE_CANNM)
#include "CanNm.h"
#endif
#if defined(USE_CANSM)
#include "CanSM.h"
#endif

#if defined(USE_LINSM)
#include "LinSM.h"
#endif
#if defined(USE_J1939TP)
#include "J1939Tp.h"
#endif
#if defined(USE_UDPNM)
#include "UdpNm.h"
#endif
#if defined(USE_FLS)
#include "Fls.h"
#endif
#if defined(USE_EEP)
#include "Eep.h"
#endif
#if defined(USE_SPI)
#include "Spi.h"
#endif
#if defined(USE_WDG)
#include "Wdg.h"
#endif
#if defined(USE_WDGM)
#include "WdgM.h"
#endif
#if defined(USE_WDGIF)
#include "WdgIf.h"
#endif
#if defined(USE_ETH)
#include "Eth.h"
#endif
#if defined(USE_FR)
#include "Fr.h"
#endif

#if defined(USE_BSWM)
#include "BswM.h"
#endif

#if defined(USE_PDUR) || defined(USE_COM) || defined(USE_CANIF) || defined(USE_CANTP) || defined(USE_FRTP)
#include "EcuM_PBTypes.h"
#endif

#if defined(USE_DCM)
#include "Dcm.h"
#endif
#if defined(USE_DEM)
#include "Dem.h"
#endif
#if defined(USE_XCP)
#include "Xcp.h"
#endif
#if defined(USE_IPDUM)
#include "IpduM.h"
#endif
#if defined(USE_DLT)
#include "Dlt.h"
#endif

#if defined(USE_FR)
#include "Fr.h"
#endif

#if defined(USE_FRIF)
#include "FrIf.h"
#endif

#if defined(USE_FRNM)
#include "FrNm.h"
#endif

#if defined(USE_FRSM)
#include "FrSM.h"
#endif

#if defined(USE_FRTP)
#include "FrTp.h"
#endif

/***
Post-Build 变种标识：EcuMPostBuildVariant，用于标识特定的 Post-Build 变种。
配置一致性哈希值：EcuMConfigConsistencyHashLow 和 EcuMConfigConsistencyHashHigh，用于验证配置的一致性。
默认关机目标状态：EcuMDefaultShutdownTarget，指定默认的关机目标状态。
默认睡眠模式：EcuMDefaultSleepMode，指定默认的睡眠模式。
默认应用模式：EcuMDefaultAppMode，指定默认的应用模式。
最小运行持续时间：EcuMRunMinimumDuration，指定最小的运行持续时间。
非易失存储读取超时时间：EcuMNvramReadAllTimeout，指定非易失存储读取超时时间。
非易失存储写入超时时间：EcuMNvramWriteAllTimeout，指定非易失存储写入超时时间。
正常 MCU 模式：EcuMNormalMcuMode，指定正常 MCU 模式的类型。
诊断事件 ID：EcuMDemInconsistencyEventId、EcuMDemRamCheckFailedEventId、EcuMDemAllRunRequestsKilledEventId，用于诊断事件的 ID。
睡眠模式配置指针：EcuMSleepModeConfig，指向睡眠模式的配置数据。
唤醒源配置指针：EcuMWakeupSourceConfig，指向唤醒源的配置数据。
其他模块配置指针：包括但不限于 Mcu_ConfigType、Can_ConfigType、Dio_ConfigType 等模块的配置数据。


EcuM_ConfigType 结构体中的字段及其定义是基于 AUTOSAR（Automotive Open System Architecture）标准的一部分。AUTOSAR 规定了一个开放的架构，以支持汽车电子系统的标准化和模块化开发。EcuM（ECU Management）是 AUTOSAR 定义的一个基础软件（BSW）模块之一，负责管理 ECU（电子控制单元）的启动、停止以及各种运行模式。
**/

typedef struct EcuM_ConfigS
{
    uint32 EcuMPostBuildVariant;            /* @req SWS_EcuM_02794 */ /* @req SWS_EcuM_02794 */
    uint64 EcuMConfigConsistencyHashLow;    /* @req SWS_EcuM_02795 Hash set when compiling the whole software for the */ /* @req SWS_EcuM_02795 */
    uint64 EcuMConfigConsistencyHashHigh;   /* PB module. It is compared to the PB hash at startup. */
    EcuM_StateType EcuMDefaultShutdownTarget;
    uint8 EcuMDefaultSleepMode;
    AppModeType EcuMDefaultAppMode;
    uint32 EcuMRunMinimumDuration;
    uint32 EcuMNvramReadAllTimeout;
    uint32 EcuMNvramWriteAllTimeout;
    Mcu_ModeType EcuMNormalMcuMode;
#if defined(USE_DEM)
    Dem_EventIdType EcuMDemInconsistencyEventId;
    Dem_EventIdType EcuMDemRamCheckFailedEventId;
    Dem_EventIdType EcuMDemAllRunRequestsKilledEventId;
#endif
    const EcuM_SleepModeType *EcuMSleepModeConfig;
    const EcuM_WakeupSourceConfigType *EcuMWakeupSourceConfig;
#if defined(USE_ECUM_FLEXIBLE)
    const EcuM_UserType *EcuMGoDownAllowedUsersConfig;
#endif
#if defined (USE_COMM)
    const EcuM_ComMConfigType *EcuMComMConfig;
#endif   
#if defined(USE_MCU)
    const Mcu_ConfigType* McuConfigPtr;
#endif
#if defined(USE_PORT)
    const Port_ConfigType* PortConfigPtr;
#endif
#if defined(USE_CAN)
    const Can_ConfigType* CanConfigPtr;
#endif
#if defined(USE_DIO)
    const Dio_ConfigType* DioConfigPtr;
#endif
#if defined(USE_CANSM)
    const CanSM_ConfigType* CanSMConfigPtr;
#endif
#if defined(USE_LIN)
    const Lin_ConfigType* LinConfigPtr;
#endif
#if defined(USE_LINIF)
    const LinIf_ConfigType* LinIfConfigPtr;
#endif
#if defined(USE_LINSM)
    const LinSM_ConfigType* LinSMConfigPtr;
#endif
#if defined(USE_ETH)
    const Eth_ConfigType* EthConfigPtr;
#endif
#if defined(USE_NM)
    const Nm_ConfigType* NmConfigPtr;
#endif
#if defined(USE_UDPNM)
    const UdpNm_ConfigType* UdpNmConfigPtr;
#endif
#if defined(USE_COMM)
    const ComM_ConfigType* ComMConfigPtr;
#endif
#if defined(USE_BSWM)
    const BswM_ConfigType* BswMConfigPtr;
#endif
#if defined(USE_J1939TP)
    const J1939Tp_ConfigType* J1939TpConfigPtr;
#endif
#if defined(USE_PWM)
    const Pwm_ConfigType* PwmConfigPtr;
#endif
#if defined(USE_OCU)
    const Ocu_ConfigType* OcuConfigPtr;
#endif
#if defined(USE_ICU)
    const Icu_ConfigType* IcuConfigPtr;
#endif
#if defined(USE_DMA)
    const Dma_ConfigType* DmaConfigPtr;
#endif
#if defined(USE_ADC)
    const Adc_ConfigType* AdcConfigPtr;
#endif
#if defined(USE_GPT)
    const Gpt_ConfigType* GptConfigPtr;
#endif
#if defined(USE_FLS)
    const Fls_ConfigType* FlsConfigPtr;
#endif
#if defined(USE_EEP)
    const Eep_ConfigType* EepConfigPtr;
#endif
#if defined(USE_SPI)
    const Spi_ConfigType* SpiConfigPtr;
#endif
#if defined(USE_WDG)
    const Wdg_ConfigType* WdgConfigPtr;
#endif
#if defined(USE_WDGIF)
    const WdgIf_ConfigType* WdgIfConfigPtr;
#endif
#if defined(USE_WDGM)
    const WdgM_ConfigType* WdgMConfigPtr;
#endif
#if defined(USE_DCM)
    const Dcm_ConfigType* DcmConfigPtr;
#endif
#if defined(USE_DEM)
    const Dem_ConfigType* DemConfigPtr;
#endif
#if defined(USE_XCP)
    const Xcp_ConfigType* XcpConfigPtr;
#endif
#if defined(USE_IPDUM)
    const IpduM_ConfigType* IpduMConfigPtr;
#endif
#if defined(USE_PDUR) || defined(USE_COM) || defined(USE_CANIF) || defined(USE_CANTP) || defined(USE_CANNM)
    const PostbuildConfigType* PostBuildConfig;
#endif
#if defined(USE_DLT)
    const Dlt_ConfigType* DltConfigPtr;
#endif
#if defined(USE_FR)
    const Fr_ConfigType * FrConfigPtr;
#endif

#if defined(USE_FRIF)
    const FrIf_ConfigType * FrIfConfigPtr;
#endif

#if defined(USE_FRNM)
    const FrNm_ConfigType * FrNmConfigPtr;
#endif

#if defined(USE_FRSM)
    const FrSM_ConfigType * FrSMConfigPtr;
#endif

#if defined(USE_FRTP)
    const FrTp_ConfigType * FrTpConfigPtr;
#endif
} EcuM_ConfigType;

#endif /*_ECUM_GENERATED_TYPES_H_*/

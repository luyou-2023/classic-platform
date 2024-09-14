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

/** @reqSettings DEFAULT_SPECIFICATION_REVISION=4.3.0 */

/*lint -e451 -e9021 AUTOSAR API SWS_MemMap_00003 */
//这些代码通常用于初始化和清理不同类型的内存区域。这些内存区域的定义和配置通常来源于 ARXML 文件，特别是在 AUTOSAR 环境中。
#define BSWM_MEMMAP_ERROR

#ifdef BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /*lint !e451 !e9019 MISRA:STANDARDIZED_INTERFACE:AUTOSAR Require Inclusion:[MISRA 2012 Directive 4.10, required] [MISRA 2012 Rule 20.1, advisory] */
#undef BSWM_MEMMAP_ERROR
#undef BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /*lint !e451 !e9019 MISRA:STANDARDIZED_INTERFACE:AUTOSAR Require Inclusion:[MISRA 2012 Directive 4.10, required] [MISRA 2012 Rule 20.1, advisory] */
#undef BSWM_MEMMAP_ERROR
#undef BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#endif


#ifdef BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /*lint !e451 !e9019 MISRA:STANDARDIZED_INTERFACE:AUTOSAR Require Inclusion:[MISRA 2012 Directive 4.10, required] [MISRA 2012 Rule 20.1, advisory] */
#undef BSWM_MEMMAP_ERROR
#undef BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif

#ifdef BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /*lint !e451 !e9019 MISRA:STANDARDIZED_INTERFACE:AUTOSAR Require Inclusion:[MISRA 2012 Directive 4.10, required] [MISRA 2012 Rule 20.1, advisory] */
#undef BSWM_MEMMAP_ERROR
#undef BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif


#ifdef BSWM_MEMMAP_ERROR
#error "BswM_BswMemMap.h error, section not mapped"
#endif

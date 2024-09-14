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

#include "Fls.h"
#if defined(USE_FEE)
#include "Fee.h"
#endif

const FlashType flashInfo[] =
{
    {
        .FlsBaseAddress=   0x00000000U,
        .FlsTotalSize  =   0x01000000U,
        .sectCnt	   =   256U,
        .bankSize 	   =   0x01000000U, //128 MB
        .regBase	   =   0xE000D000U,
        .sectAddr =
        {
            0x00000000U,
            0x00010000U,
            0x00020000U,
            0x00030000U,
            0x00040000U,
            0x00050000U,
            0x00060000U,
            0x00070000U,
            0x00080000U,
            0x00090000U,
            0x000A0000U,
            0x000B0000U,
            0x000C0000U,
            0x000D0000U,
            0x000E0000U,
            0x000F0000U,
            0x00100000U,
            0x00110000U,
            0x00120000U,
            0x00130000U,
            0x00140000U,
            0x00150000U,
            0x00160000U,
            0x00170000U,
            0x00180000U,
            0x00190000U,
            0x001A0000U,
            0x001B0000U,
            0x001C0000U,
            0x001D0000U,
            0x001E0000U,
            0x001F0000U,
            0x00200000U,
            0x00210000U,
            0x00220000U,
            0x00230000U,
            0x00240000U,
            0x00250000U,
            0x00260000U,
            0x00270000U,
            0x00280000U,
            0x00290000U,
            0x002A0000U,
            0x002B0000U,
            0x002C0000U,
            0x002D0000U,
            0x002E0000U,
            0x002F0000U,
            0x00300000U,
            0x00310000U,
            0x00320000U,
            0x00330000U,
            0x00340000U,
            0x00350000U,
            0x00360000U,
            0x00370000U,
            0x00380000U,
            0x00390000U,
            0x003A0000U,
            0x003B0000U,
            0x003C0000U,
            0x003D0000U,
            0x003E0000U,
            0x003F0000U,
            0x00400000U,
            0x00410000U,
            0x00420000U,
            0x00430000U,
            0x00440000U,
            0x00450000U,
            0x00460000U,
            0x00470000U,
            0x00480000U,
            0x00490000U,
            0x004A0000U,
            0x004B0000U,
            0x004C0000U,
            0x004D0000U,
            0x004E0000U,
            0x004F0000U,
            0x00500000U,
            0x00510000U,
            0x00520000U,
            0x00530000U,
            0x00540000U,
            0x00550000U,
            0x00560000U,
            0x00570000U,
            0x00580000U,
            0x00590000U,
            0x005A0000U,
            0x005B0000U,
            0x005C0000U,
            0x005D0000U,
            0x005E0000U,
            0x005F0000U,
            0x00600000U,
            0x00610000U,
            0x00620000U,
            0x00630000U,
            0x00640000U,
            0x00650000U,
            0x00660000U,
            0x00670000U,
            0x00680000U,
            0x00690000U,
            0x006A0000U,
            0x006B0000U,
            0x006C0000U,
            0x006D0000U,
            0x006E0000U,
            0x006F0000U,
            0x00700000U,
            0x00710000U,
            0x00720000U,
            0x00730000U,
            0x00740000U,
            0x00750000U,
            0x00760000U,
            0x00770000U,
            0x00780000U,
            0x00790000U,
            0x007A0000U,
            0x007B0000U,
            0x007C0000U,
            0x007D0000U,
            0x007E0000U,
            0x007F0000U,
            0x00800000U,
            0x00810000U,
            0x00820000U,
            0x00830000U,
            0x00840000U,
            0x00850000U,
            0x00860000U,
            0x00870000U,
            0x00880000U,
            0x00890000U,
            0x008A0000U,
            0x008B0000U,
            0x008C0000U,
            0x008D0000U,
            0x008E0000U,
            0x008F0000U,
            0x00900000U,
            0x00910000U,
            0x00920000U,
            0x00930000U,
            0x00940000U,
            0x00950000U,
            0x00960000U,
            0x00970000U,
            0x00980000U,
            0x00990000U,
            0x009A0000U,
            0x009B0000U,
            0x009C0000U,
            0x009D0000U,
            0x009E0000U,
            0x009F0000U,
            0x00A00000U,
            0x00A10000U,
            0x00A20000U,
            0x00A30000U,
            0x00A40000U,
            0x00A50000U,
            0x00A60000U,
            0x00A70000U,
            0x00A80000U,
            0x00A90000U,
            0x00AA0000U,
            0x00AB0000U,
            0x00AC0000U,
            0x00AD0000U,
            0x00AE0000U,
            0x00AF0000U,
            0x00B00000U,
            0x00B10000U,
            0x00B20000U,
            0x00B30000U,
            0x00B40000U,
            0x00B50000U,
            0x00B60000U,
            0x00B70000U,
            0x00B80000U,
            0x00B90000U,
            0x00BA0000U,
            0x00BB0000U,
            0x00BC0000U,
            0x00BD0000U,
            0x00BE0000U,
            0x00BF0000U,
            0x00C00000U,
            0x00C10000U,
            0x00C20000U,
            0x00C30000U,
            0x00C40000U,
            0x00C50000U,
            0x00C60000U,
            0x00C70000U,
            0x00C80000U,
            0x00C90000U,
            0x00CA0000U,
            0x00CB0000U,
            0x00CC0000U,
            0x00CD0000U,
            0x00CE0000U,
            0x00CF0000U,
            0x00D00000U,
            0x00D10000U,
            0x00D20000U,
            0x00D30000U,
            0x00D40000U,
            0x00D50000U,
            0x00D60000U,
            0x00D70000U,
            0x00D80000U,
            0x00D90000U,
            0x00DA0000U,
            0x00DB0000U,
            0x00DC0000U,
            0x00DD0000U,
            0x00DE0000U,
            0x00DF0000U,
            0x00E00000U,
            0x00E10000U,
            0x00E20000U,
            0x00E30000U,
            0x00E40000U,
            0x00E50000U,
            0x00E60000U,
            0x00E70000U,
            0x00E80000U,
            0x00E90000U,
            0x00EA0000U,
            0x00EB0000U,
            0x00EC0000U,
            0x00ED0000U,
            0x00EE0000U,
            0x00EF0000U,
            0x00F00000U,
            0x00F10000U,
            0x00F20000U,
            0x00F30000U,
            0x00F40000U,
            0x00F50000U,
            0x00F60000U,
            0x00F70000U,
            0x00F80000U,
            0x00F90000U,
            0x00FA0000U,
            0x00FB0000U,
            0x00FC0000U,
            0x00FD0000U,
            0x00FE0000U,
            0x00FF0000U,
        }
    }
};

const Fls_ConfigType FlsConfigSet[] =
{
    {
#if (USE_FLS_INFO==STD_ON)
        .FlsInfo 				= flashInfo	,
#endif
        .FlsAcErase				= 0u,
        .FlsAcWrite				= 0u,
        .FlsMaxReadFastMode		= 0x100u,
        .FlsMaxReadNormalMode	= 0x100u,
        .FlsMaxWriteFastMode	= 0x100u,
        .FlsMaxWriteNormalMode	= 0x100u,
#if (FEE_POLLING_MODE == STD_OFF)
        .FlsJobEndNotification  = Fee_JobEndNotification,
        .FlsJobErrorNotification= Fee_JobErrorNotification,

#else
        .FlsJobEndNotification  = NULL,
        .FlsJobErrorNotification= NULL,
#endif
        .FlsProtection			= 0u,
    }
};

In this directory modules related to the System services specifications
should be placed.

031610_1056_ArcticCore13.png


标准库
标准库中个目录详细信息如下：

目录名

概述

所包含的内容

arch

CPU构架所支持的基本数据结构、内部驱动和启动代码

arm，ppc

boards

目标板对于CPU构架的集成配置情况，每一块目标板都有自己的目录与之对应

et_stm32_stamp，generic，mpc5516it，mpc551xsim，mpc5554sim，mpc5567qrtech

common

最基本的库，字符串处理，内核调试支持和状态解释文件

arc.c，newlib_port.c，printf.c，ramlog.c，strace.c，xtoa.c

communication

基本通信模块，支持Can和Lin总线

CanIf，Com，ComM，Lin，PduR

components

包含各个应用特有的AUTOSAR构件，由于构件在库文件中，所以可以复用

每个应用特有一个或多个

diagnostic

目前诊断模块中只有Det（Development Error Tracer）驱动可用，它操纵detCbk_t跟踪错误

Dem，Det

include

基本的类型文件和所有函数的原型


memory

内存管理，目前没有实现

NvmM

peripherals

特定目标板的外设控制

Fls_SST25xx.c

rte

运行时环境支持，目前没有实现，但是可以从include/rte.h看到所有函数的原型

rte.c

system

操作系统，用于管理ECU，内存和实时内核的基本代码

EcuM，kernel，mm，SchM，WdgM

用户目录
用户目录中结构详细信息如下：

目录名

概述

所包含的内容

makefile

本项目中所有需要编译和链接的目标文件的编译信息，整个项目的链接信息

obj-y（目标文件），inc-y（包含头文件），libitem-y（库文件），ldcmdfile-y（link文件），build-exe-y（可执行文件）

build_config.mk

在整个项目编译过程中，库文件需要包含的目标文件

如MOD_USE+=KERNEL T32_TERM SIMPLE_PRINTF

Task.c

任务体的实现

各个任务的任务体函数

Hook.c

钩子的实现


config

对于操作系统和外设的配置


Rte

运行时环境（任务体直接调用运行时环境的主函数）

rte.c,rte.h


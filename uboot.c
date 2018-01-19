
1   make hi3516a_config

 hi3516a_config: unconfig
	@$(MKCONFIG) hi3516a arm hi3516a hi3516a NULL hi3516a
	
 Parameters:  Target  Architecture  CPU  Board [VENDOR] [SOC]
 
在 mkconfig中

(1)ln -s 源文件 目标文件
 asm -> arch/arm/include/asm
 asm/arch -> arch/arm/include/asm/arch-hi3516a
 proc-armv  -> arch/arm/include/asm/proc
 
 cd /include
(2) config.h
#define CONFIG_BOARDDIR board/hi3516a //spinand
#include <config_defaults.h>
#include <configs/hi3516a.h> //spinand          many peizhi here
#include <asm/config.h>
(2) config.mk
ARCH   = arm
CPU    = hi3516a
BOARD  = hi3516a
SOC    = hi3516a

BOARDDIR=hi3516a

MAKEFILE:::::::::::::::::::::::::::::::::::
1 sinclude include/autoconf.mk
解析 include/common.h中的CONFIG_*放入到include/autoconf.mk
common.h包含上边 make hi3516a_config 生成的config.h

2 sinclude include/config.mk

3 include $(TOPDIR)/config.mk
	
	include/autoconf.mk
	
	CPUDIR=arch/arm/cpu/hi3516a

	sinclude arch/arm/config.mk	# include architecture dependend rules
			指定
			CROSS_COMPILE ?= arm-hisiv300-linux-
			LDSCRIPT := $(SRCTREE)/$(CPUDIR)/u-boot.lds
	sinclude arch/arm/cpu/hi3516a/config.mk		# include  CPU	specific rules
			PLATFORM_RELFLAGS += -fno-strict-aliasing -fno-common -ffixed-r8
			PLATFORM_RELFLAGS += -fno-aggressive-loop-optimizations
			PLATFORM_CPPFLAGS += -march=armv7-a
			PLATFORM_CPPFLAGS += -mno-unaligned-access
			PLATFORM_RELFLAGS +=$(call cc-option,-mshort-load-bytes,\
								$(call cc-option,-malignment-traps,))
	sinclude arch/arm/cpu/hi3516a/hi3516a/config.mk	# include  SoC	specific rules

	BOARDDIR=hi3516a

	sinclude board/hi3516a/config.mk	# include board specific rules
			TEXT_BASE = 0x80800000
			PLATFORM_CPPFLAGS += -march=armv7-a -mno-unaligned-access -DTEXT_BASE=$(TEXT_BASE)

	指定编译规则
4 LIBS
5 $(obj)u-boot:	ddr_training depend $(SUBDIRS) $(OBJS) $(LIBBOARD) $(LIBS) $(LDSCRIPT) $(obj)u-boot.lds
		$(GEN_UBOOT)
	
	
	
start_armboot  -> in board.c main.c	
	
	
do_bootm ->
	do_bootm_linux
	
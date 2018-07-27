################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Filter_RJcfg.cmd: ../Filter_RJ.tcf
	@echo 'Building file: $<'
	@echo 'Invoking: TConf Script Compiler'
	"C:/Program Files (x86)/Texas Instruments/xdctools_3_22_01_21/tconf" -b -Dconfig.importPath="C:/Program Files (x86)/Texas Instruments/bios_5_41_10_36/packages;" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Filter_RJcfg.s??: Filter_RJcfg.cmd
Filter_RJcfg_c.c: Filter_RJcfg.cmd
Filter_RJcfg.h: Filter_RJcfg.cmd
Filter_RJcfg.h??: Filter_RJcfg.cmd
Filter_RJ.cdb: Filter_RJcfg.cmd

Filter_RJcfg.obj: .//Filter_RJcfg.s?? $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Ronny/Documents/workspace/Filter_RJ/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="Filter_RJcfg.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Filter_RJcfg_c.obj: .//Filter_RJcfg_c.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Ronny/Documents/workspace/Filter_RJ/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="Filter_RJcfg_c.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

filter_rj.obj: ../filter_rj.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Ronny/Documents/workspace/Filter_RJ/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="filter_rj.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '



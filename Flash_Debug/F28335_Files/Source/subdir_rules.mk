################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
F28335_Files/Source/DSP2833x_ADC_cal.obj: ../F28335_Files/Source/DSP2833x_ADC_cal.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_ADC_cal.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_CodeStartBranch.obj: ../F28335_Files/Source/DSP2833x_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_CodeStartBranch.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_CpuTimers.obj: ../F28335_Files/Source/DSP2833x_CpuTimers.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_CpuTimers.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_DefaultIsr.obj: ../F28335_Files/Source/DSP2833x_DefaultIsr.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_DefaultIsr.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_ECan.obj: ../F28335_Files/Source/DSP2833x_ECan.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_ECan.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_EPwm.obj: ../F28335_Files/Source/DSP2833x_EPwm.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_EPwm.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_GlobalVariableDefs.obj: ../F28335_Files/Source/DSP2833x_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_GlobalVariableDefs.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_Gpio.obj: ../F28335_Files/Source/DSP2833x_Gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_Gpio.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_MemCopy.obj: ../F28335_Files/Source/DSP2833x_MemCopy.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_MemCopy.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_PieCtrl.obj: ../F28335_Files/Source/DSP2833x_PieCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_PieCtrl.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_PieVect.obj: ../F28335_Files/Source/DSP2833x_PieVect.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_PieVect.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_Sci.obj: ../F28335_Files/Source/DSP2833x_Sci.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_Sci.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_Spi.obj: ../F28335_Files/Source/DSP2833x_Spi.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_Spi.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_SysCtrl.obj: ../F28335_Files/Source/DSP2833x_SysCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_SysCtrl.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F28335_Files/Source/DSP2833x_usDelay.obj: ../F28335_Files/Source/DSP2833x_usDelay.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="F28335_Files/Source/DSP2833x_usDelay.d" --obj_directory="F28335_Files/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



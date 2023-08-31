################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
MotCtl_Driver/Source/adc.obj: ../MotCtl_Driver/Source/adc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_Driver/Source/adc.d" --obj_directory="MotCtl_Driver/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotCtl_Driver/Source/cpu.obj: ../MotCtl_Driver/Source/cpu.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_Driver/Source/cpu.d" --obj_directory="MotCtl_Driver/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotCtl_Driver/Source/flash.obj: ../MotCtl_Driver/Source/flash.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_Driver/Source/flash.d" --obj_directory="MotCtl_Driver/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotCtl_Driver/Source/gpio.obj: ../MotCtl_Driver/Source/gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_Driver/Source/gpio.d" --obj_directory="MotCtl_Driver/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotCtl_Driver/Source/pie.obj: ../MotCtl_Driver/Source/pie.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_Driver/Source/pie.d" --obj_directory="MotCtl_Driver/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotCtl_Driver/Source/pwm.obj: ../MotCtl_Driver/Source/pwm.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_Driver/Source/pwm.d" --obj_directory="MotCtl_Driver/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotCtl_Driver/Source/pwr.obj: ../MotCtl_Driver/Source/pwr.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_Driver/Source/pwr.d" --obj_directory="MotCtl_Driver/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotCtl_Driver/Source/qep.obj: ../MotCtl_Driver/Source/qep.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_Driver/Source/qep.d" --obj_directory="MotCtl_Driver/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotCtl_Driver/Source/sci.obj: ../MotCtl_Driver/Source/sci.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_Driver/Source/sci.d" --obj_directory="MotCtl_Driver/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotCtl_Driver/Source/spi.obj: ../MotCtl_Driver/Source/spi.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_Driver/Source/spi.d" --obj_directory="MotCtl_Driver/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotCtl_Driver/Source/sysctrl.obj: ../MotCtl_Driver/Source/sysctrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_Driver/Source/sysctrl.d" --obj_directory="MotCtl_Driver/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotCtl_Driver/Source/timer.obj: ../MotCtl_Driver/Source/timer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_Driver/Source/timer.d" --obj_directory="MotCtl_Driver/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



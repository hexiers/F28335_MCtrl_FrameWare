################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
MotCtl_appSoft/Source/usDelay.obj: ../MotCtl_appSoft/Source/usDelay.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_appSoft/Source/usDelay.d" --obj_directory="MotCtl_appSoft/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

MotCtl_appSoft/Source/user.obj: ../MotCtl_appSoft/Source/user.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/Software/ti/CCS6.2/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Driver/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_appSoft/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_HAL/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/F28335_Files/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Core/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Paras/Include" --include_path="D:/My_Pjt/F28335_MotCtl/F28335_MotCtl_Frameware/DSP28xx_MotCtl_Frameware/MotCtl_Users/Include" --advice:performance=all -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MotCtl_appSoft/Source/user.d" --obj_directory="MotCtl_appSoft/Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



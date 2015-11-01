################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
alerts.obj: D:/CC3000FP_v1.0/Source/Application/alerts.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmspx --abi=coffabi -Ooff --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="D:/CC3000FP_v1.0/Source/CC3000 Spi" --include_path="D:/CC3000FP_v1.0/Source/inc" --include_path="D:/CC3000FP_v1.0/Source/CC3000HostDriver" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --gcc --define=__CCS__ --define=__MSP430FR5739__ --diag_warning=225 --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="alerts.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

appmain.obj: D:/CC3000FP_v1.0/Source/Application/appmain.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmspx --abi=coffabi -Ooff --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="D:/CC3000FP_v1.0/Source/CC3000 Spi" --include_path="D:/CC3000FP_v1.0/Source/inc" --include_path="D:/CC3000FP_v1.0/Source/CC3000HostDriver" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --gcc --define=__CCS__ --define=__MSP430FR5739__ --diag_warning=225 --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="appmain.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

board-pds.obj: D:/CC3000FP_v1.0/Source/Application/board-pds.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmspx --abi=coffabi -Ooff --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="D:/CC3000FP_v1.0/Source/CC3000 Spi" --include_path="D:/CC3000FP_v1.0/Source/inc" --include_path="D:/CC3000FP_v1.0/Source/CC3000HostDriver" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --gcc --define=__CCS__ --define=__MSP430FR5739__ --diag_warning=225 --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="board-pds.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

board.obj: D:/CC3000FP_v1.0/Source/Application/board.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmspx --abi=coffabi -Ooff --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="D:/CC3000FP_v1.0/Source/CC3000 Spi" --include_path="D:/CC3000FP_v1.0/Source/inc" --include_path="D:/CC3000FP_v1.0/Source/CC3000HostDriver" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --gcc --define=__CCS__ --define=__MSP430FR5739__ --diag_warning=225 --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="board.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

boot.obj: D:/CC3000FP_v1.0/Source/Application/boot.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmspx --abi=coffabi -Ooff --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="D:/CC3000FP_v1.0/Source/CC3000 Spi" --include_path="D:/CC3000FP_v1.0/Source/inc" --include_path="D:/CC3000FP_v1.0/Source/CC3000HostDriver" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --gcc --define=__CCS__ --define=__MSP430FR5739__ --diag_warning=225 --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="boot.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cc3000.obj: D:/CC3000FP_v1.0/Source/Application/cc3000.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmspx --abi=coffabi -Ooff --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="D:/CC3000FP_v1.0/Source/CC3000 Spi" --include_path="D:/CC3000FP_v1.0/Source/inc" --include_path="D:/CC3000FP_v1.0/Source/CC3000HostDriver" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --gcc --define=__CCS__ --define=__MSP430FR5739__ --diag_warning=225 --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="cc3000.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

features.obj: D:/CC3000FP_v1.0/Source/Application/features.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmspx --abi=coffabi -Ooff --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="D:/CC3000FP_v1.0/Source/CC3000 Spi" --include_path="D:/CC3000FP_v1.0/Source/inc" --include_path="D:/CC3000FP_v1.0/Source/CC3000HostDriver" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --gcc --define=__CCS__ --define=__MSP430FR5739__ --diag_warning=225 --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="features.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

msp430_main.obj: D:/CC3000FP_v1.0/Source/Application/msp430_main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmspx --abi=coffabi -Ooff --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="D:/CC3000FP_v1.0/Source/CC3000 Spi" --include_path="D:/CC3000FP_v1.0/Source/inc" --include_path="D:/CC3000FP_v1.0/Source/CC3000HostDriver" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --gcc --define=__CCS__ --define=__MSP430FR5739__ --diag_warning=225 --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="msp430_main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

schedule_output.obj: D:/CC3000FP_v1.0/Source/Application/schedule_output.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmspx --abi=coffabi -Ooff --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="D:/CC3000FP_v1.0/Source/CC3000 Spi" --include_path="D:/CC3000FP_v1.0/Source/inc" --include_path="D:/CC3000FP_v1.0/Source/CC3000HostDriver" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --gcc --define=__CCS__ --define=__MSP430FR5739__ --diag_warning=225 --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="schedule_output.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

snet.obj: D:/CC3000FP_v1.0/Source/Application/snet.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmspx --abi=coffabi -Ooff --opt_for_speed=0 -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="D:/CC3000FP_v1.0/Source/CC3000 Spi" --include_path="D:/CC3000FP_v1.0/Source/inc" --include_path="D:/CC3000FP_v1.0/Source/CC3000HostDriver" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --gcc --define=__CCS__ --define=__MSP430FR5739__ --diag_warning=225 --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="snet.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Versuch\ 01/Variablen.cpp 

CPP_DEPS += \
./Versuch\ 01/Variablen.d 

OBJS += \
./Versuch\ 01/Variablen.o 


# Each subdirectory must supply rules for building sources it contributes
Versuch\ 01/Variablen.o: ../Versuch\ 01/Variablen.cpp Versuch\ 01/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Versuch 01/Variablen.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Versuch-20-01

clean-Versuch-20-01:
	-$(RM) ./Versuch\ 01/Variablen.d ./Versuch\ 01/Variablen.o

.PHONY: clean-Versuch-20-01


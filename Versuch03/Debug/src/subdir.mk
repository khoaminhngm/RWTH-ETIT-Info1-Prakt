################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/othello.cpp \
../src/othelloKI.cpp \
../src/test.cpp 

CPP_DEPS += \
./src/othello.d \
./src/othelloKI.d \
./src/test.d 

OBJS += \
./src/othello.o \
./src/othelloKI.o \
./src/test.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/othello.d ./src/othello.o ./src/othelloKI.d ./src/othelloKI.o ./src/test.d ./src/test.o

.PHONY: clean-src


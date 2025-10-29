################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Liste.cpp \
../src/ListenElement.cpp \
../src/Student.cpp \
../src/main.cpp 

CPP_DEPS += \
./src/Liste.d \
./src/ListenElement.d \
./src/Student.d \
./src/main.d 

OBJS += \
./src/Liste.o \
./src/ListenElement.o \
./src/Student.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++2a -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Liste.d ./src/Liste.o ./src/ListenElement.d ./src/ListenElement.o ./src/Student.d ./src/Student.o ./src/main.d ./src/main.o

.PHONY: clean-src


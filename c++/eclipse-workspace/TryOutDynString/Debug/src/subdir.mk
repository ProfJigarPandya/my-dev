################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DemoCPPstring.cpp \
../src/MyString.cpp 

CPP_DEPS += \
./src/DemoCPPstring.d \
./src/MyString.d 

OBJS += \
./src/DemoCPPstring.o \
./src/MyString.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/DemoCPPstring.d ./src/DemoCPPstring.o ./src/MyString.d ./src/MyString.o

.PHONY: clean-src


################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Student_Code/Factory.cpp \
../Student_Code/Quicksort.cpp 

OBJS += \
./Student_Code/Factory.o \
./Student_Code/Quicksort.o 

CPP_DEPS += \
./Student_Code/Factory.d \
./Student_Code/Quicksort.d 


# Each subdirectory must supply rules for building sources it contributes
Student_Code/%.o: ../Student_Code/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



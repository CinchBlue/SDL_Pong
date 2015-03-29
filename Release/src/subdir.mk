################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Event_Queue.cpp \
../src/Event_Sender.cpp \
../src/TestPong.cpp 

OBJS += \
./src/Event_Queue.o \
./src/Event_Sender.o \
./src/TestPong.o 

CPP_DEPS += \
./src/Event_Queue.d \
./src/Event_Sender.d \
./src/TestPong.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\Users\Austin\Desktop\prog\SDL2-2.0.3\i686-w64-mingw32\include\SDL2" -I"C:\Users\Austin\Desktop\prog\boost_1_57_0" -I"C:\Users\Austin\Desktop\prog\SDL2_image-2.0.0\i686-w64-mingw32\include\SDL2" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



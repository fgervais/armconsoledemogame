################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/filesystem/Bitmap.cpp \
../src/filesystem/File.cpp \
../src/filesystem/Wave.cpp 

OBJS += \
./src/filesystem/Bitmap.o \
./src/filesystem/File.o \
./src/filesystem/Wave.o 

CPP_DEPS += \
./src/filesystem/Bitmap.d \
./src/filesystem/File.d \
./src/filesystem/Wave.d 


# Each subdirectory must supply rules for building sources it contributes
src/filesystem/%.o: ../src/filesystem/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"E:\lolprojetlol\src\filesystem" -I"E:\lolprojetlol\src\game\megaman_demo" -I"E:\lolprojetlol\src" -I"E:\lolprojetlol\src\game\megaman_demo\levels" -I"E:\lolprojetlol\sdl\include" -I"E:\lolprojetlol\src\game\engine" -I"E:\lolprojetlol\src\game\megaman_demo\states" -I"E:\lolprojetlol\src\display" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



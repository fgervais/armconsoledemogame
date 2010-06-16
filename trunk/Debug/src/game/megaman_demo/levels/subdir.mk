################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/game/megaman_demo/levels/Level1.cpp 

OBJS += \
./src/game/megaman_demo/levels/Level1.o 

CPP_DEPS += \
./src/game/megaman_demo/levels/Level1.d 


# Each subdirectory must supply rules for building sources it contributes
src/game/megaman_demo/levels/%.o: ../src/game/megaman_demo/levels/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"E:\lolprojetlol\src\filesystem" -I"E:\lolprojetlol\src\game\megaman_demo" -I"E:\lolprojetlol\src" -I"E:\lolprojetlol\src\game\megaman_demo\levels" -I"E:\lolprojetlol\sdl\include" -I"E:\lolprojetlol\src\game\engine" -I"E:\lolprojetlol\src\game\megaman_demo\states" -I"E:\lolprojetlol\src\display" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



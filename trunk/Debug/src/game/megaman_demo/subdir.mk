################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/game/megaman_demo/Buster.cpp \
../src/game/megaman_demo/Entity.cpp \
../src/game/megaman_demo/GameLevel.cpp \
../src/game/megaman_demo/InputHandler.cpp \
../src/game/megaman_demo/LifeGauge.cpp \
../src/game/megaman_demo/LifeUnity.cpp \
../src/game/megaman_demo/Megaman.cpp \
../src/game/megaman_demo/MegamanCollisionHandler.cpp \
../src/game/megaman_demo/Metool.cpp \
../src/game/megaman_demo/MetoolCollisionHandler.cpp \
../src/game/megaman_demo/ScreenUI.cpp \
../src/game/megaman_demo/ShotgunPellet.cpp \
../src/game/megaman_demo/ThrowingAxe.cpp 

OBJS += \
./src/game/megaman_demo/Buster.o \
./src/game/megaman_demo/Entity.o \
./src/game/megaman_demo/GameLevel.o \
./src/game/megaman_demo/InputHandler.o \
./src/game/megaman_demo/LifeGauge.o \
./src/game/megaman_demo/LifeUnity.o \
./src/game/megaman_demo/Megaman.o \
./src/game/megaman_demo/MegamanCollisionHandler.o \
./src/game/megaman_demo/Metool.o \
./src/game/megaman_demo/MetoolCollisionHandler.o \
./src/game/megaman_demo/ScreenUI.o \
./src/game/megaman_demo/ShotgunPellet.o \
./src/game/megaman_demo/ThrowingAxe.o 

CPP_DEPS += \
./src/game/megaman_demo/Buster.d \
./src/game/megaman_demo/Entity.d \
./src/game/megaman_demo/GameLevel.d \
./src/game/megaman_demo/InputHandler.d \
./src/game/megaman_demo/LifeGauge.d \
./src/game/megaman_demo/LifeUnity.d \
./src/game/megaman_demo/Megaman.d \
./src/game/megaman_demo/MegamanCollisionHandler.d \
./src/game/megaman_demo/Metool.d \
./src/game/megaman_demo/MetoolCollisionHandler.d \
./src/game/megaman_demo/ScreenUI.d \
./src/game/megaman_demo/ShotgunPellet.d \
./src/game/megaman_demo/ThrowingAxe.d 


# Each subdirectory must supply rules for building sources it contributes
src/game/megaman_demo/%.o: ../src/game/megaman_demo/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"E:\lolprojetlol\src\filesystem" -I"E:\lolprojetlol\src\game\megaman_demo" -I"E:\lolprojetlol\src" -I"E:\lolprojetlol\src\game\megaman_demo\levels" -I"E:\lolprojetlol\sdl\include" -I"E:\lolprojetlol\src\game\engine" -I"E:\lolprojetlol\src\game\megaman_demo\states" -I"E:\lolprojetlol\src\display" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



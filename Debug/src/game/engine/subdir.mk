################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/game/engine/Background.cpp \
../src/game/engine/ClipableSprite.cpp \
../src/game/engine/Collider.cpp \
../src/game/engine/Engine.cpp \
../src/game/engine/Environment.cpp \
../src/game/engine/Graphic.cpp \
../src/game/engine/Physics.cpp \
../src/game/engine/Random.cpp \
../src/game/engine/Renderable.cpp \
../src/game/engine/Sprite.cpp \
../src/game/engine/State.cpp \
../src/game/engine/Synchronized.cpp \
../src/game/engine/Tile.cpp \
../src/game/engine/VideoMemory.cpp \
../src/game/engine/VisibleArea.cpp 

OBJS += \
./src/game/engine/Background.o \
./src/game/engine/ClipableSprite.o \
./src/game/engine/Collider.o \
./src/game/engine/Engine.o \
./src/game/engine/Environment.o \
./src/game/engine/Graphic.o \
./src/game/engine/Physics.o \
./src/game/engine/Random.o \
./src/game/engine/Renderable.o \
./src/game/engine/Sprite.o \
./src/game/engine/State.o \
./src/game/engine/Synchronized.o \
./src/game/engine/Tile.o \
./src/game/engine/VideoMemory.o \
./src/game/engine/VisibleArea.o 

CPP_DEPS += \
./src/game/engine/Background.d \
./src/game/engine/ClipableSprite.d \
./src/game/engine/Collider.d \
./src/game/engine/Engine.d \
./src/game/engine/Environment.d \
./src/game/engine/Graphic.d \
./src/game/engine/Physics.d \
./src/game/engine/Random.d \
./src/game/engine/Renderable.d \
./src/game/engine/Sprite.d \
./src/game/engine/State.d \
./src/game/engine/Synchronized.d \
./src/game/engine/Tile.d \
./src/game/engine/VideoMemory.d \
./src/game/engine/VisibleArea.d 


# Each subdirectory must supply rules for building sources it contributes
src/game/engine/%.o: ../src/game/engine/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"E:\lolprojetlol\src\filesystem" -I"E:\lolprojetlol\src\game\megaman_demo" -I"E:\lolprojetlol\src" -I"E:\lolprojetlol\src\game\megaman_demo\levels" -I"E:\lolprojetlol\sdl\include" -I"E:\lolprojetlol\src\game\engine" -I"E:\lolprojetlol\src\game\megaman_demo\states" -I"E:\lolprojetlol\src\display" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



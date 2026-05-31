TARGET = bin/game
WEB_TARGET = bin/game.html
SRC = $(wildcard code/src/*.c)
OBJ = $(patsubst code/src/%.c, code/obj/%.o, $(SRC))
WEB_LIBS = code/deps/static_libs/web/

LIB_SRC = $(wildcard code/libs/src/*.c)
LIB_OBJ = $(patsubst code/libs/src/%.c, code/libs/obj/%.o, $(LIB_SRC))

###################################
# Build Everything
###################################
default: from_scratch

from_scratch: clean build
###################################

###################################
# Build Game
###################################
build: $(TARGET)

$(TARGET): $(OBJ)
	gcc -o $@ $? -std=c99 -Wall -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

code/obj/%.o : code/src/%.c
	gcc -c $< -o $@ -Icode/include

###################################
# Tools
###################################
clean:
# 	rm -f code/obj/*.o
	rm -f $(TARGET)*

all_clean:
	rm -f code/obj/*.o
	rm -f $(TARGET)*

bear: all_clean
	bear -- make
###################################

###################################
# Build Web
###################################
update_emcc:
	~/emsdk/emsdk install latest

activate_emcc:
	~/emsdk/emsdk activate latest
	source "/home/lhgs/emsdk/emsdk_env.sh"
	echo 'source "/home/lhgs/emsdk/emsdk_env.sh"' >> $HOME/.bash_profile

web_build: cleanAll
	emcc -o $(WEB_TARGET) $(SRC) -Os -Wall ./$(WEB_LIBS)/libraylib.a -Icode/include -Icode/deps/include -I/home/lhgs/raylib/src -L$(WEB_LIBS) -s USE_GLFW=3 -s ASYNCIFY -s ALLOW_MEMORY_GROWTH=1 -s STACK_SIZE=1MB -s TOTAL_MEMORY=67108864 -s ASSERTIONS=1 -s EXPORTED_RUNTIME_METHODS=ccall -s EXPORTED_RUNTIME_METHODS=cwrap -s MODULARIZE=1 --profiling --preload-file resources -DPLATFORM_WEB
# -s EXPORT_NAME="game"
###################################

###################################
# Run Game
###################################
run:
	./$(TARGET)

web_run:
	emrun $(TARGET).html
###################################

# Nome do projeto
PROJ_NAME=palindromo
BUILD_DIR=build

# Arquivos fonte
C_SOURCE=main.c lista/lista.c
H_SOURCE=lista/lista.h

# Objetos
OBJ=$(BUILD_DIR)/main.o $(BUILD_DIR)/lista.o

# Compilador
CC=gcc

# Flags para o compilador
CC_FLAGS=-c -Wall -g -pedantic

#########################
# Compilação e linkagem #
#########################
all: $(BUILD_DIR) $(BUILD_DIR)/$(PROJ_NAME).exe

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/main.o: main.c lista/lista.h | $(BUILD_DIR)
	$(CC) $(CC_FLAGS) -o $@ main.c

$(BUILD_DIR)/lista.o: lista/lista.c lista/lista.h | $(BUILD_DIR)
	$(CC) $(CC_FLAGS) -o $@ lista/lista.c

$(BUILD_DIR)/$(PROJ_NAME).exe: $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -rf $(BUILD_DIR) *.o *~

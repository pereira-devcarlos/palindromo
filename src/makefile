CC=gcc
CFLAGS=-Wall -Wextra -O2
SRC=main.c lista/lista.c pilha/pilha.c
INC=-Ilista -Ipilha
BUILD=build
TARGET=$(BUILD)/palindromo

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(INC) $(SRC) -o $(TARGET)

clean:
	rm -rf $(BUILD)

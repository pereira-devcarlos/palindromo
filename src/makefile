CC=gcc
CFLAGS=-Wall -Wextra -O2
SRC=main.c lista/lista.c
INC=-Ilista
BUILD=build
TARGET=$(BUILD)/palindromo

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(INC) $(SRC) -o $(TARGET)

clean:
	rm -rf $(BUILD)

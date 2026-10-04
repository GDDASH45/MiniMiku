CC := gcc

CFLAGS := -Wall -Wextra -O2

TARGET := mikuc.elf

all: $(TARGET)

$(TARGET): mikuc.c
	$(CC) $(CFLAGS) mikuc.c -o $(TARGET)

clean:
	rm -f $(TARGET)
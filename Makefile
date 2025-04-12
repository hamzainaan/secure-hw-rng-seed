CC = gcc
CFLAGS = -Wall -Wextra -O2 -mrdseed -mrdrnd
TARGET = rdseed_secure

ifeq ($(shell uname -m), x86_64)
    BITS = 64
else
    BITS = 32
endif

all:
	@echo "Compiling for $(BITS)-bit system..."
	$(CC) $(CFLAGS) rdseed_secure.c -o $(TARGET)

clean:
	rm -f $(TARGET)

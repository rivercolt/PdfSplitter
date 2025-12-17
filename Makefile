CC := gcc
CFLAGS := $(shell pkg-config)# --cflags gtk4)
LDFLAGS := $(shell pkg-config)# --libs gtk4)
TARGET := app

all: $(TARGET)

$(TARGET): main.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o $(TARGET)


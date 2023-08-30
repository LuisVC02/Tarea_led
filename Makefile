
CC ?= gcc

APP_NAME = led_control
OBJ_FILES = led_control.o
LIBS = .


all: $(APP_NAME)

$(APP_NAME): $(OBJ_FILES)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $^ -g


clean:
	rm *.o $(APP_NAME)

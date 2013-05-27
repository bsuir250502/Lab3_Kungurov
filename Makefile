OBJ = mystdlib.o lab3.o
CFLAGS = -Wall -Wextra -std=c99

all: bin

bin: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o bin

clean:
	rm bin $(OBJ)

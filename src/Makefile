

CFLAGS=-std=c99 -pedantic -Wall -O0 -g -ggdb 
CFLAGS+= -I../deps/lua/src

LDFLAGS=-g -ggdb
LDFLAGS+= -lm 
LDFLAGS+= ../deps/lua/src/liblua.a

UTIL_SRC=$(wildcard util/*.c)
UTIL_OBJ=$(patsubst %.c,%.o,$(UTIL_SRC) )

#example-server
EXAMPLE_BIN=example-server
EXAMPLE_OBJ=$(UTIL_OBJ) example.o


%.o: %.c 
	$(CC) -c -o $@ $(CFLAGS) $<

$(EXAMPLE_BIN): $(EXAMPLE_OBJ)
	$(LD) $(LDFLAGS) -o $@ $^ 

all: $(EXAMPLE_BIN)
	echo $(EXAMPLE_OBJ)
	#pass
	
test:
	echo $(UTIL_SRC)
	echo $(EXAMPLE_OBJ)
	#pass

clean:
	rm -rf $(EXAMPLE_BIN) 
	rm -rf *.o *.gcda *.gcno *.gcov
	rm -rf util/*.o 

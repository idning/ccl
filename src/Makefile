

LD=$(CC)

CFLAGS=-std=c99 -pedantic -Wall -O0 -g -ggdb -D_POSIX_C_SOURCE -D_GNU_SOURCE
CFLAGS+= -I../deps/lua/src

LDFLAGS=-g -ggdb -rdynamic
LDFLAGS+= -lm 
LDFLAGS+= ../deps/lua/src/liblua.a

UTIL_SRC=$(wildcard util/*.c)
UTIL_OBJ=$(patsubst %.c,%.o,$(UTIL_SRC) )

#kv-server
KV_BIN=kv-server
KV_OBJ=$(UTIL_OBJ) kv.o


%.o: %.c 
	$(CC) -c -o $@ $(CFLAGS) $<

$(KV_BIN): $(KV_OBJ)
	$(LD) $(LDFLAGS) -o $@ $^ 

all: $(KV_BIN)
	echo "done"

clean:
	rm -rf $(KV_BIN) 
	rm -rf *.o *.gcda *.gcno *.gcov
	rm -rf util/*.o 

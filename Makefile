CC:=g++
LD:=ld
AR:=ar
SH:=sh

CFLAGS:= -fPIC -c -O -g -Wall -DLCOMP_LINUX=1

CFLAGS+= -I../dstr/include -L../dstr/bin

all:
	$(CC) $(CFLAGS) wlcomp.cpp
	$(CC) -shared wlcomp.o -o libwlcomp.so -ldl /usr/lib/liblcomp.so

install:
	cp libwlcomp.so /usr/lib/

clean:
	rm *.o
	rm *.so

CC:=g++
LD:=ld
AR:=ar
SH:=sh

CFLAGS:= -c -O -g -Wall

CFLAGS+= -I../dstr/include -L../dstr/bin

all:
	$(CC) $(CFLAGS) wlcomp.cpp
	$(CC) -shared wlcomp.o -o libwlcomp.so -ldl ../dstr/bin/lcomp.dll

install:
	cp libwlcomp.so /usr/lib/

clean:
	rm *.o
	rm *.so

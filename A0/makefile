INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := mainP.o customErrorClass.o
DEPS 		 := bstP.h bstPo.h customErrorClass.h

.PHONY: clean all

all: customErrorClass.o mainP.o A0 clean

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainP.o: mainP.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

A0: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJS)

#IDIR =include
CC=g++
#CFLAGS=-I$(IDIR)

CDIR=.
BDIR=bin
#LDIR =lib

#LIBS=-lreadLine

#DEPS = $(wildcard $(IDIR)/*.h)

SRC = $(wildcard $(CDIR)/*.cpp)

build: $(SRC)
	#$(CC) -g -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)
	$(CC) $^ -o $(BDIR)/main 

run: build
	cd $(BDIR); ./main
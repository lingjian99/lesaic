CC=g++
IDIR=/usr/local/include/opencv4
LDIR=/usr/local/lib

lesaic: lesaic.cpp mosaic.o
	$(CC) -I $(IDIR) -L $(LDIR) -o lesaic mosaic.o
mosaic.o: mosaic.cpp
	$(CC) -I $(IDIR) -L $(LDIR) -c mosaic.cpp -o mosaic.o
	

GXX=g++
CXXFLAGS=-Wall -g -std=c++11 
PROG=chess

all: $(PROG)

chess: ChessGameDriver.o ChessAdmin.o Chess.o ChessField.o
	$(GXX) $(CXXFLAGS) -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system


ChessGameDriver.o: ChessGameDriver.cc
	$(GXX) $(CXXFLAGS) -o $@ -c $<

ChessAdmin.o: ChessAdmin.cc ChessAdmin.h
	$(GXX) $(CXXFLAGS) -o $@ -c $<

Chess.o: Chess.cc Chess.h
	$(GXX) $(CXXFLAGS) -o $@ -c $<

ChessField.o: ChessField.cc ChessField.h
	$(GXX) $(CXXFLAGS) -o $@ -c $<
clean:
	rm -f *.o *~ $(PROG)

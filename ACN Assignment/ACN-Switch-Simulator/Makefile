CXX = g++

CXXFLAGS = -I include

SRC = src/*.cpp

OUT = routing

all:
	$(CXX) $(SRC) $(CXXFLAGS) -o $(OUT)

run:
	./$(OUT)

clean:
	del $(OUT).exe 2>nul || rm -f $(OUT)
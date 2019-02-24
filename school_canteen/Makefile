CXX = g++ 
CXXFLAGS = -std=c++17 -lsqlite3
OBJ = main.o

%.o: *.c $(DEPS) 
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

run:
	./main

clean: 
	rm *.o main

OBJECTS=graph.o main.o graph_algorithms.o barabasi_albert.o 
bin_packing:$(OBJECTS)
	g++ -ggdb  $(OBJECTS) -o graph
graph.o:graph.cpp project3.h node.h graph.h
	g++ -c -std=c++11 -ggdb graph.cpp
graph_algorithms:graph_algorithms project3.h node.h graph.h
	g++ -c  -std=c++11 -ggdb graph_algorithms.cpp
barabasi_albert.o:barabasi_albert.cpp project3.h node.h graph.h
	g++ -c -std=c++11 -ggdb barabasi_albert.cpp
main.o:main.cpp project3.h
	g++ -c -std=c++11 -ggdb main.cpp

clean:
	/bin/rm -f $(OBJECTS)


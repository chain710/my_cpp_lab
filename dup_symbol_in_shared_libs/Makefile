all:
	g++ -g -fPIC -c -o lib_a.o lib_a.cc
	g++ -g -shared -o libA.so lib_a.o
	g++ -g -fPIC -c -o lib_b.o lib_b.cc
	g++ -g -shared -o libB.so lib_b.o
	g++ -g -o compiler_link_a compiler_link.cc -L./ -lA -lB
	g++ -g -o compiler_link_b compiler_link.cc -L./ -lB -lA
clean:
	rm -f libA.so lib_a.o libB.so lib_b.o compiler_link_a compiler_link_b
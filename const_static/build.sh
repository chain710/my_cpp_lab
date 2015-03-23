rm *.o -f
rm *.out -f
rm *.so -f

g++ -g -Wall -fPIC -c -o my_string.o my_string.cc -I./
g++ -g -Wall -fPIC -c -o container.o container.cc -I./
g++ -g -Wall -fPIC -c -o dump_string.o dump_string.cc -I./
g++ -g -Wall -shared -o libmy_string.so my_string.o container.o
g++ -g -Wall -shared -o libdump_string.so my_string.o container.o dump_string.o
ar rcs libmy_string_static.a my_string.o container.o

g++ -g -Wall -fPIC -c -o midware.o midware.cc -I./
g++ -g -Wall -shared -o libmidware.so midware.o -lmy_string_static -L./
g++ -g -Wall -shared -o libmidware_force.so midware.o my_string.o container.o -L./

g++ -g -Wall -o main1.out main.cc -I./ -L./ -lmidware -lmy_string
g++ -g -Wall -o main2.out main.cc  -I./ -L./ -lmy_string -lmidware
g++ -g -Wall -o main3.out main.cc container.o  -I./ -L./ -lmidware -lmy_string
g++ -g -Wall -o main4.out main.cc container.o  -I./ -L./ -lmy_string -lmidware

g++ -g -Wall -o main5.out main_inc_container.cc -I./ -L./ -lmidware -lmy_string
g++ -g -Wall -o main6.out main_inc_container.cc  -I./ -L./ -lmy_string -lmidware

g++ -g -Wall -o main7.out main_dump.cc  -I./ -L./ -ldump_string -lmidware_force
g++ -g -Wall -o main8.out main_dump.cc  -I./ -L./ -lmidware_force -ldump_string 
#undefined symbol
#g++ -g -Wall -o main7.out main_inc_container.cc -I./ -L./ -lmidware



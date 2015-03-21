DIRNAME=`dirname $0`

cd $DIRNAME
DIRNAME=`pwd`

find . -name "*.o" | xargs rm -f
find . -name "*.so" | xargs rm -f
find . -name "*.out" | xargs rm -f

cd $DIRNAME/case1

g++ -g -Wall -fPIC -c -o my_string.o my_string.cc  -I./
g++ -g -Wall -shared -o libmy_string.so  my_string.o

g++ -g -Wall -o case1.out case1.cc -lmy_string -I./ -L./

cd $DIRNAME/case2

g++ -g -Wall -fPIC -c -o my_string.o my_string.cc  -I./
g++ -g -Wall -shared -o libmy_string.so  my_string.o

g++ -g -Wall -o case2.out case2.cc -lmy_string -I./ -L./

cd $DIRNAME/case3

g++ -g -Wall -fPIC -c -o my_string.o my_string.cc  -I./
g++ -g -Wall -shared -o libmy_string.so  my_string.o

g++ -g -Wall -fPIC -c -o midware.o midware.cc  -I./
g++ -g -Wall -shared -o libmidware.so  midware.o -lmy_string -L./

g++ -g -Wall -o case3.out case3.cc -lmidware -lmy_string -I./ -L./

cd $DIRNAME/case4

g++ -g -Wall -fPIC -c -o my_string.o my_string.cc  -I./
g++ -g -Wall -shared -o libmy_string_a.so  my_string.o
g++ -g -Wall -shared -o libmy_string_b.so  my_string.o

g++ -g -Wall -o case4.out case4.cc -lmy_string_a -ldl -I./ -L./

cd $DIRNAME/case5

g++ -g -Wall -fPIC -c -o my_string.o my_string.cc  -I./
g++ -g -Wall -shared -o libmy_string.so  my_string.o

g++ -g -Wall -o case5.out case5.cc -lmy_string -I./ -L./

cd $DIRNAME/case6

g++ -g -Wall -fPIC -c -o my_string.o my_string.cc  -I./
g++ -g -Wall -shared -o libmy_string_a.so  my_string.o
g++ -g -Wall -shared -o libmy_string_b.so  my_string.o

g++ -g -Wall -o case6.out case6.cc -lmy_string_a -ldl -I./ -L./

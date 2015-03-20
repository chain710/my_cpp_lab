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



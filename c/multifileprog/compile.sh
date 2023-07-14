rm -rf *.o
gcc -c linkedlist/linearSingly/linearslinkedlist.c -o linkedlist/linearSingly/linearslinkedlist.o -I ./include
gcc -I ./include linkedlist/linearSingly/driver.c linkedlist/linearSingly/linearslinkedlist.o -o linkedlist/linearSingly/driver.o
gcc -c queue/simple/simplequeue.c -o queue/simple/simplequeue.o -I ./include
#gcc -I ./include queue/simple/driver.c queue/simple/simplequeue.o -o queue/simple/driver.o


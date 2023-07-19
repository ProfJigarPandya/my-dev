find . -name "*.o" -delete
#gcc -Wall -I myclibrary/include -c myclibrary/linkedlist/linearSingly/linearslinkedlist.c -o myclibrary/lib/linearslinkedlist.o
#gcc -Wall -I myclibrary/include myclibrary/lib/linearslinkedlist.o myclibrary/linkedlist/linearSingly/driver.c -o myclibrary/linkedlist/linearSingly/driver.o
#gcc -Wall -I myclibrary/include -c myclibrary/queue/simple/simplequeue.c -o myclibrary/lib/simplequeue.o
#gcc -Wall -I myclibrary/include myclibrary/lib/linearslinkedlist.o myclibrary/lib/simplequeue.o myclibrary/queue/simple/driver.c -o myclibrary/queue/simple/driver.o

gcc -Wall -I myclibrary/include -c myclibrary/linkedlist/linearSingly/linearslinkedlist_gn.c -o myclibrary/lib/linearslinkedlist_gn.o
gcc -Wall -I myclibrary/include myclibrary/lib/linearslinkedlist_gn.o myclibrary/linkedlist/linearSingly/driver_gn.c -o myclibrary/linkedlist/linearSingly/driver_gn.o
gcc -Wall -I myclibrary/include -c myclibrary/queue/simple/simplequeue_gn.c -o myclibrary/lib/simplequeue_gn.o
gcc -Wall -I myclibrary/include myclibrary/lib/linearslinkedlist_gn.o myclibrary/lib/simplequeue_gn.o myclibrary/queue/simple/driver_gn.c -o myclibrary/queue/simple/driver_gn.o

gcc -Wall -I myclibrary/include myclibrary/lib/linearslinkedlist_gn.o myclibrary/lib/simplequeue_gn.o demograph.c -o demograph.o



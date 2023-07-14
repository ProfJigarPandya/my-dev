               /* Program 33 */
goal
   write("Before graphics"),readchar(_),
   graphics(1,1,3),
   line(4000,4000,10000,20000,2),
   write("ordinary write during graphics mode"),
   readchar(_),
   text,
   write("After graphics").

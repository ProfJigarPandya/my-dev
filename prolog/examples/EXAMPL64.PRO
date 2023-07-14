      /* program 64 */

  /* read the read64.me to link language modules*/

global predicates
   treble(integer,integer) - (i,o) language c
goal
   write("Type an integer "),
   readint(A),
   treble(A,T),
   write("Treble that number is ",T),nl.
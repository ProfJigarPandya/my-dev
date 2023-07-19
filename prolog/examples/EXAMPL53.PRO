                /* Program 53 */
domains
     room  =  symbol
     roomlist = room*
predicates
    gallery(room,room)  /* There is a gallery between
                           two rooms */
    neighborroom(room,room) /* Necessary because it does
                               not matter which direction
                               we go along a gallery */
    avoid(roomlist)
    go(room,room)
    route(room,room,roomlist) /* This is the route to be
                                 followed. Roomlist consists
                                 of a list of rooms already
                                 visited. */
    member(room,roomlist)
clauses
    gallery(entry,monsters).       gallery(entry,fountain).
    gallery(fountain,hell).        gallery(fountain,food).
    gallery(exit,gold_treasure).   gallery(fountain,mermaid).
    gallery(robbers,gold_treasure).gallery(fountain,robbers).
    gallery(food,gold_treasure).   gallery(mermaid,exit).
    gallery(monsters,gold_treasure).

    neighborroom(X,Y) if gallery(X,Y).
    neighborroom(X,Y) if gallery(Y,X).

    avoid([monsters,robbers]).

    go(Here,There) if route(Here,There,[Here]).

    route(exit,exit,VisitedRooms) if
         member(gold_treasure,VisitedRooms) and
         write(VisitedRooms) and nl.
    route(Room,Way_out,VisitedRooms) if
         neighborroom(Room,Nextroom) and
         avoid(DangerousRooms) and
         not(member(NextRoom,DangerousRooms)) and
         not(member(NextRoom,VisitedRooms)) and
         route(NextRoom,Way_out,[NextRoom|VisitedRooms]).

    member(X,[X|_]).
    member(X,[_|H]) if member (X,H).

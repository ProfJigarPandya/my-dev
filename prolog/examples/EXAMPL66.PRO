/* Program 66 */

   predicates
   
     dosver(real)
     diskspace(integer,real,real)
     makedir(STRING)
     removedir(STRING)
     
   clauses
   
     dosver(VERSION):-
        AX=48*256,
        bios($21,reg(AX,0,0,0,0,0,0,0),reg(VV,_,_,_,_,_,_,_)),
        L=VV div 256,H=VV-256*L,VERSION=H+L/100.

        diskspace(DISK,TOTALSPACE,FREESPACE):-
           AAX=54*256,
           bios(33,reg(AAX,0,0,DISK,0,0,0,0),
           reg(AX,BX,CX,DX,_,_,_,_)),
           FREESPACE=1.0*BX*CX*AX,TOTALSPACE=1.0*DX*CX*AX.
           
        makedir(NAME):-
           ptr_dword(NAME,DS,DX),
           AX=256*57,
           bios(33,reg(AX,0,0,DX,0,0,DS,0),_).
           
        removedir(NAME):-
           ptr_dword(NAME,DS,DX),AX=256*58,
           bios(33,reg(AX,0,0,DX,0,0,DS,0),_).
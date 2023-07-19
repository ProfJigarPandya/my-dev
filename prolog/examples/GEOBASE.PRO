/******************************************************************/
/*								  */
/*		    ***	 G E O B A S E  ***			  */
/*								  */
/*	GEOGRAPHY-database with a natural language interface	  */
/*								  */
/******************************************************************/
/*	CAUTION: GEOBASE REQUIRES A LARGE AMOUNT OF MEMORY TO     */
/*               COMPILE AND RUN.   IF THE FOLLOWING ERROR        */
/*               MESSAGE APPEARS IN THE MESSAGE WINDOW:           */
/*                                                                */
/*                  1003  HEAP OVERFLOW. NOT ENOUGH MEMORY OR     */
/*                  ENDLESS LOOP,                                 */
/*                                                                */
/*               REMOVE ANY RAM RESEDENT PROGRAMS TO FREE         */
/*               ADDITIONAL MEMORY.  THEN RECOMPILE AND RUN       */
/*               GEOBASE AGAIN.                                   */
/******************************************************************/

code=2500

DOMAINS
  LIST = SYMBOL*			/* The domain LIST is a list of words */

DATABASE
  /* The Language Database */
  relat(SYMBOL,LIST)			/* Relation name and a list of attributes */
  schema(SYMBOL,SYMBOL,SYMBOL)		/* Entity network: entity-assoc-entity */

  entitysize(SYMBOL,SYMBOL)		/* Which attribute gives the size of an entity */
  relop(LIST,SYMBOL)			/* Example: relop([greater,than],gt] */
  assoc(SYMBOL,LIST)			/* Alternative assoc names */
  synonym(SYMBOL,SYMBOL)		/* Synonyms for entities */
  ignore(SYMBOL)			/* Words to be ignored */
  min(SYMBOL)				/* Words stating minimum */
  max(SYMBOL)				/* Words stating maximum */
  big(SYMBOL,SYMBOL)			/* big, long, high .... */
  unit(SYMBOL,SYMBOL)			/* Unit for population, area ... */

  /* The Real database */
  
  /* state(NAME,ABBREVIATION,CAPITAL,AREA,ADMIT,POPULATION,CITY,CITY,CITY,CITY */
  state(SYMBOL,SYMBOL,SYMBOL,REAL,REAL,INTEGER,SYMBOL,SYMBOL,SYMBOL,SYMBOL)
  
  /* city(STATE,ABBREVIATION,NAME,POPULATION) */
  city(SYMBOL,SYMBOL,SYMBOL,REAL)
  
  /*river(NAME,LENGTH,STATELIST */
  river(SYMBOL,INTEGER,LIST)
  
  /* border(STATE,ABBREVIATION,STATELIST) */
  border(SYMBOL,SYMBOL,LIST)

  /* highlow(STATE,ABBREVIATION,POINT,HEIGHT,POINT,HEIGHT) */
  highlow(SYMBOL,SYMBOL,SYMBOL,INTEGER,SYMBOL,INTEGER)

  /* mountain(STATE,ABBREVIATION,NAME,HEIGHT) */
  mountain(SYMBOL,SYMBOL,SYMBOL,REAL)

  /* lake(NAME,AREA,STATELIST) */
  lake(SYMBOL,REAL,LIST)

  /* road(NUMBER,STATELIST) */
  road(SYMBOL,LIST)


/****************************************************************/
/* 		Database Access					*/
/****************************************************************/

PREDICATES
  member(SYMBOL,LIST)		/* membership of a list */

CLAUSES
  member(X,[X|_]).
  member(X,[_|L]):-member(X,L).


PREDICATES
  /* Access to database */
  db(SYMBOL,SYMBOL,SYMBOL,SYMBOL,SYMBOL)
  ent(SYMBOL,SYMBOL)


CLAUSES

/* ent returns values for a given entity name. Ex. if called by
   ent(city,X)  X  is instantiated to cities.
*/

  ent(continent,usa).
  ent(city,NAME):-	city(_,_,NAME,_).
  ent(state,NAME):-	state(NAME,_,_,_,_,_,_,_,_,_).
  ent(capital,NAME):-	state(_,_,NAME,_,_,_,_,_,_,_).
  ent(river,NAME):-	river(NAME,_,_).
  ent(point,POINT):-	highlow(_,_,_,_,POINT,_).
  ent(point,POINT):-	highlow(_,_,POINT,_,_,_).
  ent(mountain,M):-	mountain(_,_,M,_).
  ent(lake,LAKE):-	lake(LAKE,_,_).
  ent(road,NUMBER):-	road(NUMBER,_).


/* The db predicate is used to establish relationships between
   entities. The first three parameters should always be instantiated
   to entityname-assocname-entityname, the last two parameters
   return the values corresponding to the two entity names.
*/

  /* Relationships about cities */
  db(city,in,state,CITY,STATE):-	city(STATE,_,CITY,_).
  db(state,with,city,STATE,CITY):-	city(STATE,_,CITY,_).
  db(population,of,city,POPUL,CITY):-	city(_,_,CITY,POPUL1),str_real(POPUL,POPUL1).
  db(population,of,capital,POPUL,CITY):-city(_,_,CITY,POPUL1),str_real(POPUL,POPUL1).

  /* Relationships about states */
  db(abbreviation,of,state,ABBREVIATION,STATE):-	state(STATE,ABBREVIATION,_,_,_,_,_,_,_,_).
  db(state,with,abbreviation,STATE,ABBREVIATION):-state(STATE,ABBREVIATION,_,_,_,_,_,_,_,_).
  db(area,of,state,AREA,STATE):-	state(STATE,_,_,_,AREA1,_,_,_,_,_),str_real(AREA,AREA1).
  db(capital,of,state,CAPITAL,STATE):-	state(STATE,_,CAPITAL,_,_,_,_,_,_,_).
  db(state,with,capital,STATE,CAPITAL):-state(STATE,_,CAPITAL,_,_,_,_,_,_,_).
  db(population,of,state,POPULATION,STATE):-state(STATE,_,_,POPUL,_,_,_,_,_,_),str_real(POPULATION,POPUL).
  db(state,border,state,STATE1,STATE2):-border(STATE2,_,LIST),member(STATE1,LIST).

  /* Relationships about rivers */
  db(length,of,river,LENGTH,RIVER):-	river(RIVER,LENGTH1,_),str_real(LENGTH,LENGTH1).
  db(state,with,river,STATE,RIVER):-	river(RIVER,_,LIST),member(STATE,LIST).
  db(river,in,state,RIVER,STATE):-	river(RIVER,_,LIST),member(STATE,LIST).

  /* Relationships about points */
  db(point,in,state,POINT,STATE):-	highlow(STATE,_,POINT,_,_,_).
  db(point,in,state,POINT,STATE):-	highlow(STATE,_,_,_,POINT,_).
  db(state,with,point,STATE,POINT):-	highlow(STATE,_,POINT,_,_,_).
  db(state,with,point,STATE,POINT):-	highlow(STATE,_,_,_,POINT,_).
  db(height,of,point,HEIGTH,POINT):-	highlow(_,_,_,_,POINT,H),str_int(HEIGTH,H),!.
  db(height,of,point,HEIGTH,POINT):-	highlow(_,_,POINT,H,_,_),str_int(HEIGTH,H),!.

  /* Relationships about mountainss */
  db(mountain,in,state,MOUNT,STATE):-	mountain(STATE,_,MOUNT,_).
  db(state,with,mountain,STATE,MOUNT):-	mountain(STATE,_,MOUNT,_).
  db(height,of,mountain,HEIGHT,MOUNT):-	mountain(_,_,MOUNT,H1),str_int(HEIGHT,H1).

  /* Relationships about lakes */
  db(lake,in,state,LAKE,STATE):-	lake(LAKE,_,LIST),member(STATE,LIST).
  db(state,with,lake,STATE,LAKE):-	lake(LAKE,_,LIST),member(STATE,LIST).
  db(area,of,lake,AREA,LAKE):-		lake(LAKE,A1,_),str_real(AREA,A1).

  /* Relationships about roads */
  db(road,in,state,ROAD,STATE):-	road(ROAD,LIST),member(STATE,LIST).
  db(state,with,road,STATE,ROAD):-	road(ROAD,LIST),member(STATE,LIST).

  db(E,in,continent,VAL,usa):-		ent(E,VAL).
  db(name,of,_,X,X):-			bound(X).

INCLUDE "geobase.inc" /* Include parser + scanner + eval + Menusystem */

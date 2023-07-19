                /* Program 42 */
domains
    direction=up;down
predicates
      jack_and_jill(direction,integer)
goal
      jack_and_jill(up,500).
clauses
      jack_and_jill(up,F):-
          F<5000,!,sound(1,F),F1=F+200,jack_and_jill(up,F1).
      jack_and_jill(up,F):-
          jack_and_jill(down,F).
      jack_and_jill(down,F):-
          F>500,!,sound(1,F),F1=F-200,jack_and_jill(down,F1).
      jack_and_jill(down,F):-
          jack_and_jill(up,F).

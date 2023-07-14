                  /* Program 22 */
domains
    sentence   = sentence(nounphrase,verbphrase)
    nounphrase = nounp(article,noun) ; name(name)
    verbphrase = verb(verb) ; verbphrase(verb,nounphrase)
    article,noun,name,verb = symbol
predicates
    write_sentence(sentence)
    write_nounphrase(nounphrase)
    write_verbphrase(verbphrase)
clauses
    write_sentence(sentence(S,V)) if
             write_nounphrase(S) and write_verbphrase(V).

    write_nounphrase(nounp(A,N)) if write(A,' ',N,' ').
    write_nounphrase(name(N)) if write(N,' ').

    write_verbphrase(verb(V)) if write(V,' ').
      write_verbphrase(verbphrase(V,N)) if
           write(V,' ') and write_nounphrase(N).

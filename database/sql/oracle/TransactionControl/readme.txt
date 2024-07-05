TCL
Transaction control language
-commit
-rollback
-savepoint

Commit:

Make the changes permanent to database;

Explicit commit using the "commit" keyword.

Implicit commit happens (1) before and after any DDL (create, alter, drop, grant, revoke) automatically. (2) successful exit of client.

Any DML statements prior to commit event (implicity or explicity) are in a sort of staging area (temporary), where the user can work in what is almost a "draft" mode. However, any commit event, explicit or implicit - will make changes permanent and expose the new data to the user population at large.

Rollback:
Somewhat equivalent to "undo". 
It undoes any changes to the draft within a given session till prior commit point. It does not remove any changes that have been already been committed.

i.e.
commit;
insert into ...;
delete from ...;
rollaback;

In this example, one insert and one delete statement (DML) are issued. When we issue rollback the both changes are eliminated from the current draft.


Savepoint:
Demarcation points within a transaction in order to empower any following commit and or rollback statments to subdivide the points at which data can be saved or undone.

If periodic savepoints (i.e. labels/checkpoints/names of SCN-System change number) have been issued along the way, then the following commit or rollback can be designed to save or restore data to those points in time. 

i.e.
commit;
update ...;
savepoint sp_one;
update ...;
rollback work to sp_one;
commit;

In this example, because of savepoint we have a choice to rollback bottom update and commit only upto sp_one, which includes any and all prior to that savepoint.




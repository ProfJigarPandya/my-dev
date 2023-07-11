You may need DBA privilege to store or load database dump. This can be a huge binary file representing the complete database. It is widely used at industry for migrating database from one company to another in case of project ownership and maintenance contract changes. Original owner company may create the database dump and provide in the form of physical harddrive to another company who is not going forward to handle the project. 

To create/load database dump using command line following utilities are used. 

In the bin folder of Oracle Installation, you will find many utilities including these:

[root@aharnish bin]# pwd
/opt/oracle/product/21c/dbhomeXE/bin
[root@aharnish bin]# ls -l exp expdp imp impdp
-rwxr-x--x. 1 oracle oinstall 1019512 Aug 18  2021 exp
-rwxr-x--x. 1 oracle oinstall  238104 Aug 18  2021 expdp
-rwxr-x--x. 1 oracle oinstall  508032 Aug 18  2021 imp
-rwxr-x--x. 1 oracle oinstall  250104 Aug 18  2021 impdp
[root@aharnish bin]# 


Note that database dump is a binary file containing data tables and metadata as chosen when generating the dump.There are many objects it supports to dump:
grants/privileges
table data
pre-schema procedural objects and actions
foreign function library names for user SCOTT
PUBLIC type synonyms
private type synonyms
object type definitions for user SCOTT
About to export SCOTT's objects ...
database links
sequence numbers
cluster definitions
. about to export SCOTT's tables via Conventional Path ...
synonyms
views
stored procedures
operators
referential integrity constraints
triggers
indextypes
bitmap, functional and extensible indexes
posttables actions
materialized views
snapshot logs
job queues
refresh groups and children
dimensions
post-schema procedural objects and actions
statistics

 

Let us create oracle database dump for the user scott.

SQL> select table_name from all_tables where owner='SCOTT';

TABLE_NAME
--------------------------------------------------------------------------------
CLIENT_MASTER
PRODUCT_MASTER
SUBJECT_MASTER

SQL> quit;


exp scott/tiger@localhost/pdb

[root@aharnish bin]# exp scott/tiger@localhost/pdb

Export: Release 21.0.0.0.0 - Production on Tue Jul 11 12:36:15 2023
Version 21.3.0.0.0

Copyright (c) 1982, 2021, Oracle and/or its affiliates.  All rights reserved.


Connected to: Oracle Database 21c Express Edition Release 21.0.0.0.0 - Production
Version 21.3.0.0.0
Enter array fetch buffer size: 4096 > 

Export file: expdat.dmp > scott_11_07_23.dmp

(2)U(sers), or (3)T(ables): (2)U >  

Export grants (yes/no): yes > 

Export table data (yes/no): yes > 

Compress extents (yes/no): yes > 

Export done in US7ASCII character set and AL16UTF16 NCHAR character set
server uses AL32UTF8 character set (possible charset conversion)
. exporting pre-schema procedural objects and actions
. exporting foreign function library names for user SCOTT 
. exporting PUBLIC type synonyms

. exporting private type synonyms
. exporting object type definitions for user SCOTT 
About to export SCOTT's objects ...
. exporting database links
. exporting sequence numbers
. exporting cluster definitions
. about to export SCOTT's tables via Conventional Path ...
. . exporting table                  CLIENT_MASTER          6 rows exported
. . exporting table                 PRODUCT_MASTER          9 rows exported
. . exporting table                 SUBJECT_MASTER         12 rows exported
EXP-00091: Exporting questionable statistics.
. exporting synonyms
. exporting views
. exporting stored procedures
. exporting operators
. exporting referential integrity constraints
. exporting triggers
. exporting indextypes
. exporting bitmap, functional and extensible indexes
. exporting posttables actions
. exporting materialized views
. exporting snapshot logs
. exporting job queues
. exporting refresh groups and children
. exporting dimensions
. exporting post-schema procedural objects and actions
. exporting statistics
Export terminated successfully with warnings.

[root@aharnish bin]# ls -l scott*.dmp
-rw-r--r--. 1 root root 16384 Jul 11 12:37 scott_11_07_23.dmp
[root@aharnish bin]# 




You can import this database dump to another computer having oracle database. I am temporarily removing tables of user scott and will load back using database dump file generated in the previous step.

SQL> drop table client_master;

Table dropped.

SQL> drop table product_master;

Table dropped.

SQL> drop table subject_master;

Table dropped.

SQL> select * from client_master;
select * from client_master
              *
ERROR at line 1:
ORA-00942: table or view does not exist


SQL> select * from product_master;
select * from product_master
              *
ERROR at line 1:
ORA-00942: table or view does not exist


SQL> select * from subject_master;
select * from subject_master
              *
ERROR at line 1:
ORA-00942: table or view does not exist


SQL> 



Note that all 3 tables are dropped.

Now lets import using database dump file generated previously.

[root@aharnish bin]# imp scott/tiger@localhost/pdb

Import: Release 21.0.0.0.0 - Production on Tue Jul 11 12:43:59 2023
Version 21.3.0.0.0

Copyright (c) 1982, 2021, Oracle and/or its affiliates.  All rights reserved.


Connected to: Oracle Database 21c Express Edition Release 21.0.0.0.0 - Production
Version 21.3.0.0.0

Import data only (yes/no): no > 

Import file: expdat.dmp > scott_11_07_23.dmp

Enter insert buffer size (minimum is 8192) 30720> 

Export file created by EXPORT:V21.00.00 via conventional path
import done in US7ASCII character set and AL16UTF16 NCHAR character set
import server uses AL32UTF8 character set (possible charset conversion)
List contents of import file only (yes/no): no > 

Ignore create error due to object existence (yes/no): no > 

Import grants (yes/no): yes > 

Import table data (yes/no): yes > 

Import entire export file (yes/no): no > 
Username: ^C

Enter table(T) or partition(T:P) names. Null list means all tables for user
Enter table(T) or partition(T:P) name or . if done: 

. importing SCOTT's objects into SCOTT
IMP-00034: Warning: FromUser "" not found in export file
Import terminated successfully with warnings.
[root@aharnish bin]# 
[root@aharnish bin]# 
[root@aharnish bin]# imp scott/tiger@localhost/pdb

Import: Release 21.0.0.0.0 - Production on Tue Jul 11 12:44:38 2023
Version 21.3.0.0.0

Copyright (c) 1982, 2021, Oracle and/or its affiliates.  All rights reserved.


Connected to: Oracle Database 21c Express Edition Release 21.0.0.0.0 - Production
Version 21.3.0.0.0

Import data only (yes/no): no > 

Import file: expdat.dmp > scott_11_07_23.dmp

Enter insert buffer size (minimum is 8192) 30720> 

Export file created by EXPORT:V21.00.00 via conventional path
import done in US7ASCII character set and AL16UTF16 NCHAR character set
import server uses AL32UTF8 character set (possible charset conversion)
List contents of import file only (yes/no): no > 

Ignore create error due to object existence (yes/no): no > 

Import grants (yes/no): yes > 

Import table data (yes/no): yes > 

Import entire export file (yes/no): no > yes

. importing SCOTT's objects into SCOTT
. . importing table                "CLIENT_MASTER"          6 rows imported
. . importing table               "PRODUCT_MASTER"          9 rows imported
. . importing table               "SUBJECT_MASTER"         12 rows imported
Import terminated successfully without warnings.




Let's verify on sql


SQL> select count(*) from client_master;

  COUNT(*)
----------
	 6

SQL> select count(*) from product_master;

  COUNT(*)
----------
	 9

SQL> select count(*) from subject_master;

  COUNT(*)
----------
	12

SQL> 

Conclusion:

Note that other than exporting/importing data format files like .csv, .tsv, .xml, .json or any other, which are truly regular text files only, the file generated using database dump is a binary file. Hence, it litterally dumps the database objects. Of course, you need to practice more and explore. i.e. database user passwords exported or not, etc. There are GUI utilities also doing similar functionality. 



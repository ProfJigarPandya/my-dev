The sqlplus command line from few version of Linux up arrow key does not show up easy history.

Workaround as described below:

Install rlwrap third party utility.

sudo yum install rlwrap

Add below into .bash_profile of root/oracle/your user and source it if using first time in same window.


alias rlsqlplus='rlwrap sqlplus'
alias rlrman='rlwrap rman'

To verify the alias availability,
alias -p | grep rlwrap

Now onward use rlsqlplus alias instead of original sqlplus and rlrman instead of rman.

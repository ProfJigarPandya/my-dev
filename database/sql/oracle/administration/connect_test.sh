#Avoid below syntax as password better not be typed directly on shell. History can be read anytime.
#sqlplus myusername/mypassword@Host/ORCL
sqlplus '/ as sysdba'
#system
#password
#select sysdate from dual;

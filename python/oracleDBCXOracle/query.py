import cx_Oracle

con = cx_Oracle.connect('username/password@192.168.29.152/xe')

cur = con.cursor()
cur.execute('select sysdate from dual')
for result in cur:
    print (result)

cur.close()
con.close()         

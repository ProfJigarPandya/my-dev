import cx_Oracle

con = cx_Oracle.connect('username/password@192.168.29.152/xe')
print (con.version)

con.close()

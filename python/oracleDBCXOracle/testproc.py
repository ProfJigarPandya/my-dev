import cx_Oracle

con = cx_Oracle.connect('username/password@192.168.29.152/xe')

cur = con.cursor()
cur.callproc('UpdateADVERTISERSRD',[1,"20-MAR-1982"])
cur.close()
con.commit()
con.close() 

import cx_Oracle

con = cx_Oracle.connect('username/password@192.168.29.152/xe')

cur = con.cursor()

cur.execute("""update ADVERTISERS set REGISTRY_DATE=sysdate where ADVERTISER_ID=1""")
con.commit()
con.close()

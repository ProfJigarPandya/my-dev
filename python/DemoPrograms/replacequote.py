import re
p = re.compile( '(blue|white|red)')
p.sub( 'colour', 'blue socks and red shoes')
print (p)



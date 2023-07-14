import turtle

def drawtriangle():
    sidelen = 20
    brad = turtle.Turtle()
    brad.color('red', 'yellow')
    
    brad.forward(8*sidelen)

    numtriangles = 8
    for r in range(8):
        
        for c in range(numtriangles):
            brad.begin_fill()
            brad.left(120)
            brad.forward(sidelen)
            brad.left(120)
            brad.forward(sidelen)
            brad.left(120)
            brad.end_fill()
        brad.left(60)
        brad.forward(sidelen)
        brad.right(60)
        numtriangles = numtriangles - 1
        brad.forward(numtriangles*sidelen)
        
    

drawtriangle()

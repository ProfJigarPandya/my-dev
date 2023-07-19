import turtle

def draw_square():
    window = turtle.Screen()
    window.bgcolor("red")

    brad = turtle.Turtle()
    brad.speed(10)

    brad.color("yellow")
    for i in range(36):
        for i in range(4):
            brad.forward(100)
            brad.right(90)
        brad.right(10)
        

    
    
    


draw_square()

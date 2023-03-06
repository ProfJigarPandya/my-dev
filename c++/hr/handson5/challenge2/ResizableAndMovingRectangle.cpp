#include <iostream>
using namespace std;
class Point
{
        int x,y;
    public:
        Point()
        {

        }
        Point(int x, int y)
        {
            this->x=x;
            this->y=y;
        }
        int getPointX()
        {
            return x;
        }
        void setPointX(int x)
        {
            this->x = x;
        }
        int getPointY()
        {
            return y;
        }
        void setPointY(int y)
        {
            this->y = y;
        }
        void increaseX(int units)
        {
            x+=units;
        }
        void increaseY(int units)
        {
            y+=units;
        }
        void decreaseX(int units)
        {
            x-=units;
        }
        void decreaseY(int units)
        {
            y-=units;
        }


};
class Rectangle
{
    Point toplp, toprp, botlp, botrp;
    bool doinit=true;
    public:
        void initialize(int tl_x,int tl_y,int tr_x,int tr_y,int bl_x,int bl_y,int br_x,int br_y)
        {
            this->toplp.setPointX(tl_x);
            this->toplp.setPointY(tl_y);
            this->toprp.setPointX(tr_x);
            this->toprp.setPointY(tr_y);
            this->botlp.setPointX(bl_x);
            this->botlp.setPointY(bl_y);
            this->botrp.setPointX(br_x);
            this->botrp.setPointY(br_y);
  
            doinit=false;
        }
        void moveLeft(int units)
        {
            toplp.decreaseX(units);
            toprp.decreaseX(units);
            botlp.decreaseX(units);
            botrp.decreaseX(units);
        }
        void moveRight(int units)
        {
            toplp.increaseX(units);
            toprp.increaseX(units);
            botlp.increaseX(units);
            botrp.increaseX(units);
        }
        void moveUp(int units)
        {
            toplp.increaseY(units);
            toprp.increaseY(units);
            botlp.increaseY(units);
            botrp.increaseY(units);
        }
        void moveDown(int units)
        {
            toplp.decreaseY(units);
            toprp.decreaseY(units);
            botlp.decreaseY(units);
            botrp.decreaseY(units);
        }

        void alterIncreaseLeft(int units)
        {
            toplp.decreaseX(units);
            botlp.decreaseX(units);
        }
        void alterDecreaseLeft(int units)
        {
            toplp.increaseX(units);
            botlp.increaseX(units);
        }    
        void alterIncreaseRight(int units)
        {
            toprp.increaseX(units);
            botrp.increaseX(units);
        }
        void alterDecreaseRight(int units)
        {
            toprp.decreaseX(units);
            botrp.decreaseX(units);
        }
        void alterIncreaseTop(int units)
        {
            toplp.increaseY(units);
            toprp.increaseY(units);
        }
        void alterDecreaseTop(int units)
        {
            toplp.decreaseY(units);
            toprp.decreaseY(units);
        }
        void alterIncreaseBottom(int units)
        {
            botlp.decreaseY(units);
            botrp.decreaseY(units);
        }        
        void alterDecreaseBottom(int units)
        {
            botlp.increaseY(units);
            botrp.increaseY(units);
        }        
        void display()
        {
            cout<<toplp.getPointX()<<" "<<toplp.getPointY()<<endl;
            cout<<toprp.getPointX()<<" "<<toprp.getPointY()<<endl;
            cout<<botlp.getPointX()<<" "<<botlp.getPointY()<<endl;
            cout<<botrp.getPointX()<<" "<<botrp.getPointY()<<endl;
        }
};
int main()
{
    Rectangle robj;
    int tl_x,tl_y,tr_x,tr_y,bl_x,bl_y,br_x,br_y;
    int numberOfActions;
    char inputletter;
    int units;
    cin>>tl_x>>tl_y;
    cin>>tr_x>>tr_y;
    cin>>bl_x>>bl_y;
    cin>>br_x>>br_y;
    robj.initialize(tl_x,tl_y,tr_x,tr_y,bl_x,bl_y,br_x,br_y);
    //cout<<"robj after initialization : ";
    //robj.display();
    cin>>numberOfActions;
    //cout<<"Number of actions read "<<numberOfActions<<endl;
    while(numberOfActions)
    {
        cin>>inputletter;
        //cout<<"Input Letter read "<<inputletter;
        switch(inputletter)
        {
            case 'L'://Left Move
                        cin>>units;
                        //cout<<"You are moving left by "<<units;
                        robj.moveLeft(units);
                        break;
            case 'R'://Right Move
                        cin>>units;
                        robj.moveRight(units);
                        break;
            case 'U'://Up Move
                        cin>>units;
                        robj.moveUp(units);
                        break;
            case 'D'://Down Move
                        cin>>units;
                        robj.moveDown(units);
                        break;
            case 'A'://Alter   example A D L 5
                        cin>>inputletter;
                        //cout<<inputletter;
                        switch(inputletter)
                        {
                            case 'D'://Decrease
                                        cin>>inputletter;
                                        //cout<<inputletter;
                                        cin>>units;
                                        //cout<<units;
                                        switch(inputletter)
                                        {
                                            case 'L':// A D L
                                                        robj.alterDecreaseLeft(units);
                                                        break;
                                            case 'R': // A D R
                                                        robj.alterDecreaseRight(units);
                                                        break;
                                            case 'T': // A D T
                                                        robj.alterDecreaseTop(units);
                                                        break;
                                            case 'B': // A D B
                                                        robj.alterDecreaseBottom(units);
                                                        break;
                                            default:
                                                    cout<<"Input letter not supported. Read Place: 3"<<endl;

                                        };
                                        break;
                                
                            case 'I'://Increase
                                        cin>>inputletter;
                                        //cout<<inputletter;
                                        cin>>units;
                                        //cout<<units;
                                        switch(inputletter)
                                        {
                                            case 'L':// A I L
                                                        robj.alterIncreaseLeft(units);
                                                        break;
                                            case 'R':// A I R
                                                        robj.alterIncreaseRight(units);
                                                        break;
                                            case 'T':// A I T
                                                        robj.alterIncreaseTop(units);
                                                        break;
                                            case 'B':// A I B
                                                        robj.alterIncreaseBottom(units);
                                                        break;
                                            default:
                                                    cout<<"Input letter not supported. Read Place: 4"<<endl;
                                        };
                                
                                        break;
                            default:
                                    cout<<"Iput letter not supported. Read Place: 2 "<<inputletter;
                            
                        };
                        break;
            default:
                        cout<<"Iput letter not supported. Read Place: 1 "<<inputletter;
        };   
        numberOfActions--;
    }
    robj.display();



    return (0);
}

//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
#include <stdio.h>



// ===========================================================================
//                             Include Project Files
// ===========================================================================
#include "boids.h"
#include "individue.h"
#include "bwindow.h"



// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================








// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
    boids Boids = boids();
    individue Individue = individue();

    
    bwindow win(Individue.Get_width(),Individue.Get_height());
    printf("%d\n",win.init());
    win.map();

    Boids.Set_population(100);

    Boids.initialization();

    int pop = Boids.Get_population();

    for (;;)
    {
        win.draw_fsquare(0,0,Individue.Get_width(),Individue.Get_height(),0xFFFFFF);
        int ev = win.parse_event();
    switch(ev)
    {
        case BKPRESS :
        printf("keypressed\n"); 
        printf("key : %s\n",win.get_lastkey());
        break;
        case BBPRESS:
        printf("buttonpressed\n"); break;
        case BEXPOSE:
        printf("expose\n"); break;
        case BCONFIGURE:
        printf("configure\n"); break;
    }

    individue* tab = Boids.Get_tab();

    for (int i = 0; i < pop; ++i)
    {
        win.draw_fsquare(-4+tab[i].Get_x(),-4+tab[i].Get_y(),4+tab[i].Get_x(),4+tab[i].Get_y(),0xFF00);
    }
    Boids.deplacement();

    }
    
    /*
    Boids.initialization();
    individue* t = Boids.Get_tab();
    for (int i = 0; i < 10; ++i)
    {
        printf("%lg %lg %lg %lg\n", t[i].Get_x(),t[i].Get_y(),t[i].Get_vx(),t[i].Get_vy());
    }
    printf("\n");
    Boids.deplacement();
    for (int i = 0; i < 10; ++i)
    {
        printf("%lg %lg %lg %lg\n", t[i].Get_x(),t[i].Get_y(),t[i].Get_vx(),t[i].Get_vy());
    }
    */


    

  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================


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
#include <ctime>


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
    srand(time(NULL));

    boids Boids = boids();
    individue Individue = individue();

    Boids.Set_dt(0.001);

    Boids.Set_population(100);  //100

    Boids.Set_disti(60);
    Boids.Set_distc(10);
    Boids.Set_distp(40);
    Boids.Set_distk(5);

    Boids.Set_g1(5);  //5
    Boids.Set_g2(1);  //1
    Boids.Set_g3(35);  //35
    Boids.Set_g4(4);

    Boids.Set_nb_object(10);

    Boids.Set_width(700);
    Boids.Set_height(700);

    Boids.Set_speed_init(100);  //10

    Boids.Set_nb_predator(1);
    Boids.Set_speed_predator(100);

    int w = Boids.Get_width();
    int h = Boids.Get_height();

    
    bwindow win(w,h);
    printf("%d\n",win.init());
    win.map();
    Boids.initialization(); 

    int nbo = Boids.Get_nb_object();
    double* tabo = Boids.Get_tab_object();

    individue* tabp = Boids.Get_predator();
    int nbp = Boids.Get_nb_predator();

    individue* tab = Boids.Get_tab();

    // for (int i = 0; i < pop; ++i)
    // {
    //     printf("%lg %lg\n", tabo[i].Get_x(),tabo[i].Get_y());
    // }
    // printf("\n");
    

    for (;;)
    {
        
        int ev = win.parse_event();
        switch(ev)
        {
        case BKPRESS :
            printf("keypressed\n");
            printf("key : %s\n",win.get_lastkey());
        break;

        case BBPRESS:
            printf("buttonpressed\n"); 
        break;
        
        case BEXPOSE:
            printf("expose\n"); 
        break;
        
        case BCONFIGURE:
            printf("configure\n"); 
        break;
        }

        int pop = Boids.Get_population();

        win.draw_fsquare(0,0,w,h,0xFFFFFF);
        for (int i = 0; i < nbo; i++)
        {
            win.draw_fsquare(-4+tabo[2*i],-4+tabo[2*i+1],4+tabo[2*i],4+tabo[2*i+1],0x0000FF);
        }

        for (int i = 0; i < pop; ++i)
        {
            double x = tab[i].Get_x();
            double y = tab[i].Get_y();

            win.draw_fsquare(-2+x,-2+y,2+x,2+y,0xFF0000);
        }

        for (int i = 0; i < nbp; ++i)
        {
            double x = tabp[i].Get_x();
            double y = tabp[i].Get_y();

            win.draw_fsquare(-2+x,-2+y,2+x,2+y,0x00FF00);
        }

        Boids.deplacement();
        usleep(3000);
        
    }
    

    // Boids.initialization();
    // individue* t = Boids.Get_tab();

    // for (int i = 0; i < pop; ++i)
    // {
    //     printf("%lg %lg %lg %lg\n", t[i].Get_x(),t[i].Get_y(),t[i].Get_vx(),t[i].Get_vy());
    // }
    // printf("\n");

    // for (int i = 0; i < 7; ++i)
    // {
    //     Boids.deplacement();
    //     for (int i = 0; i < pop; ++i)
    //     {
    //         printf("%lg %lg %lg %lg\n", t[i].Get_x(),t[i].Get_y(),t[i].Get_vx(),t[i].Get_vy());
    //     }
    //     printf("\n");
    // }
  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================


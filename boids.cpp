// ===========================================================================
//                                   Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <cmath>

// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "boids.h"


//############################################################################
//                                                                           #
//                           Class boids
//                                                                           #
//############################################################################

// ===========================================================================
//                                  Constructors
// ===========================================================================
boids::boids(void)
{
	dt = 0;
	population = 0;
	
    tab=NULL;
    predator=NULL;
    tab_object=NULL;
    Getter=NULL;    

    disti = 0;
    distc = 0;
    distp = 0;
    distk = 0;

    g1 = 0;
    g2 = 0;
    g3 = 0;
    g4 = 0;

    speed = new double[10];

    nb_object = 0;

    w=0;
    h=0;

    nb_predator = 0;
    speed_predator = 0;

    width = 0;
    height = 0;

    speed_init = 0;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
boids::~boids(void)
{
	delete [] tab;

    delete [] speed;

    delete [] Getter;

    delete [] predator;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

void boids::initialization(void)
{
    //for the birds
	tab = new individue[population];
    for (int i = 0; i < population; ++i)
    {
        tab[i].Set_x( ((width-100)-100)*((double)rand()/(double)RAND_MAX)+100 );
        tab[i].Set_y( ((height-100)-100)*((double)rand()/(double)RAND_MAX)+100 );

        tab[i].Set_vx(2*speed_init*((double)rand()/(double)RAND_MAX)-speed_init);
        tab[i].Set_vy(2*speed_init*((double)rand()/(double)RAND_MAX)-speed_init);
    }


    //for the predator
    predator = new individue[nb_predator];
    for (int i = 0; i < nb_predator; ++i)
    {
        predator[i].Set_x( ((width-100)-100)*((double)rand()/(double)RAND_MAX)+100 );
        predator[i].Set_y( ((height-100)-100)*((double)rand()/(double)RAND_MAX)+100 );
    }


    Getter = new double[4*population];

    //set the object
    tab_object = new double[2*nb_object];

    for (int i = 0; i < 2*nb_object; i+=2)
    {
        tab_object[i] = ((width-20)-20)*((double)rand()/(double)RAND_MAX)+20; //for x coordonate
        tab_object[i+1] = ((height-20)-20)*((double)rand()/(double)RAND_MAX)+20; //for y coordonate
    }
}


void boids::deplacement(void)
{
for (int ind=0; ind<population; ind++)
{
    double x = tab[ind].Get_x();
    double y = tab[ind].Get_y();
    double vx = tab[ind].Get_vx();
    double vy = tab[ind].Get_vy();

    //for change the x, y
    Getter[4*ind] = x + dt * vx;
    Getter[4*ind+1] = y + dt * vy;

    int ci = 0;  //compteur individue around
    int cc = 0;  //compteur individue too close
    int co = 0;  //compteur object too close

    //for initialize every rule
    speed[0] = 0;  //for vx from rule 1
    speed[1] = 0;  //for vy from rule 1

    speed[2] = 0;  //for vx from rule 2
    speed[3] = 0;  //for vy from rule 2

    speed[4] = 0;  //for vx from rule 3 inter individue
    speed[5] = 0;  //for vy from rule 3 inter individue

    speed[6] = 0;  //for vx from rule 3 object
    speed[7] = 0;  //for vy from rule 3 object

    speed[8] = 0;  //for vx from rule 4
    speed[9] = 0;  //for vy from rule 4


    // for the rules
    for (int i = 0; i < population; ++i)
    {
        double x_other = tab[i].Get_x();
        double y_other = tab[i].Get_y();

        double a = sqrt((x - x_other)*(x - x_other) + (y - y_other)*(y - y_other)); //distance between 2 individue
        
        if (a<=disti  && a>0)
        {
            //rule 1
            speed[0] += (tab[i].Get_vx() - vx);
            speed[1] += (tab[i].Get_vy() - vy);

            //rule 2
            speed[2] += (x_other - x);
            speed[3] += (y_other - y);

            ci++;
        }
        
        //rule 3
        if (a<=distc  && a>0)
        {
            speed[4] += (x_other - x);
            speed[5] += (y_other - y);

            cc++;
        }

        if (i<nb_object)
        {
            double xo = tab_object[2*i];
            double yo = tab_object[2*i+1];
            a = sqrt((x - xo)*(x - xo) + (y - yo)*(y - yo));
            
            if (a<=distc)
            {
                speed[6] += (xo - x);
                speed[7] += (yo - y);
                co++;
            }
        }

        //rule 4
        if (i<nb_predator)
        {
            double xp = predator[i].Get_x();
            double yp = predator[i].Get_y();

            a = sqrt((x - xp)*(x - xp)+(y - yp)*(y - yp));

            speed[8] = - (xp - x)/a;
            speed[9] = - (yp - y)/a;
        }
        
    }


    if (ci!=0)
    {
        speed[0] = speed[0]/ci;
        speed[1] = speed[1]/ci;

        speed[2] = speed[2]/ci; 
        speed[3] = speed[3]/ci;
    }    
    
    if (cc!=0)
    {
        speed[4] =  - speed[4]/cc; 
        speed[5] =  - speed[5]/cc;
    }

    if (co!=0)
    {
        speed[6] = - speed[6]/co; 
        speed[7] = - speed[7]/co;
    }


    //==================================================================

    vx = vx + dt*(g1*speed[0]+g2*speed[2]+g3*(speed[4]+speed[6])+g4*speed[8]);  //for change the vx
    vy = vy + dt*(g1*speed[1]+g2*speed[3]+g3*(speed[5]+speed[7])+g4*speed[9]);  //for change the vy   

    // for the wind
    if (x<100) {vx = vx +200;}
    if (x > width-100) {vx = vx - 200;}
    if (y<100) {vy = vy +200;}
    if (y > height-100) {vy = vy -200;}

    //for the Getter because if no getter the value of vx, vy change at the end of the loop
    Getter[4*ind+2] = vx;
    Getter[4*ind+3] = vy; 
}

//for mouvement of predators
// for (int i = 0; i < nb_predator; ++i)
// {
//     double xp = predator[i].Get_x();
//     double yp = predator[i].Get_y();

//     double tableau[population];

//     bool eat = 0;

//     //for see the distance of the prey
//     for (int ind = 0; ind < population; ++ind)
//     {
//         double x_prey = tab[ind].Get_x();
//         double y_prey = tab[ind].Get_y();

//         double a = sqrt((xp - x_prey)*(xp - x_prey)+(yp - y_prey)*(yp - y_prey));

//         if (a<=distp && a>distk)
//         {
//             tableau[ind] = a;
//         }
//         else if (a>distp)
//         {
//             tableau[ind] = -1;
//         }
//         else if (a<=distk)
//         {
//             tab[ind] = NULL;
//             eat = 1;
//         }
//     }


//     if (eat=0)
//     {
//         predator[i].Set_x(xp + dt*predator[i].Get_vx());
//         predator[i].Set_y(yp + dt*predator[i].Get_vy());

//         // for find the prey closer than the others
//         double min = tableau[0];
//         int prey = -1;

//         for (int ind = 1; ind < population; ++ind)
//         {
//             if (tableau[ind] < min && tableau[ind]>0)
//             {
//             prey = ind;
//             min = tableau[ind];
//             }
//         }

//         // for the wind
//         int vx = 0;
//         int vy = 0;

//         if (xp<100) {vx = 200;} else { vx = 0;}
//         if (xp>w-100) {vx = - 200;}
//         if (yp<100) {vy = 200;} else { vy = 0;}
//         if (yp>h-100) {vy = - 200;}

//         // for the speed of the predator
//         if (prey>=0)
//         {
//             predator[i].Set_vx((xp - tab[prey].Get_x())*speed_predator/min + vx);
//             predator[i].Set_vy((yp - tab[prey].Get_y())*speed_predator/min + vy);
//         }
//         else
//         {
//             double x = w*((double)rand()/(double)RAND_MAX);
//             double y = h*((double)rand()/(double)RAND_MAX);

//             predator[i].Set_vx((xp - x)*speed_predator/min + vx);
//             predator[i].Set_vy((yp - y)*speed_predator/min + vy);
//         }
//     }
//     else if (eat = 1)
//     {
//         break;
//     }
// }


for (int i = 0; i < population; ++i)
{
    tab[i].Set_x(Getter[4*i]); 
    tab[i].Set_y(Getter[4*i+1]); 
    tab[i].Set_vx(Getter[4*i+2]);
    tab[i].Set_vy(Getter[4*i+3]);
}

}
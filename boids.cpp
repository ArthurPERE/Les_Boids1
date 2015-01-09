//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <algorithm>

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
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
boids::boids(void)
{
	dt = 0;
	population = 0;
	
    
    disti = 0;
    distc = 0;

    g1 = 0;
    g2 = 0;
    g3 = 0;

    speed1 = new double[2];
    speed2 = new double[2];
    speed3i = new double[2];
    speed3o = new double[2];
    speed4 = new double[2];

    nb_object = 0;

    w=0;
    h=0;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
boids::~boids(void)
{
	delete[] tab;

    delete[] speed1;
    delete[] speed2;
    delete[] speed3i;
    delete[] speed3o;
    delete[] speed4;

    delete[] around;
    delete[] Getter;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

void boids::initialization(void)
{
	tab = new individue[population];
    around = new int[2*population+2*nb_object];
    Getter = new double[4*population];

    //set the object
    tab_object = new double[nb_object];

    w = Individue.Get_width();
    h = Individue.Get_height();

    for (int i = 0; i < nb_object; i+=2)
    {
        tab_object[i] = (w-20)*((double)rand()/(double)RAND_MAX)+20; //for x coordonate
        tab_object[i+1] = (h-20)*((double)rand()/(double)RAND_MAX)+20; //for y coordonate
    }
}


void boids::deplacement(void)
{
for (int ind=0; ind<population; ind++)
{
    double vx = tab[ind].Get_vx();
    double vy = tab[ind].Get_vy();
    double x = tab[ind].Get_x();
    double y = tab[ind].Get_y();

    double xf = x + dt * vx;
    double yf = y + dt * vy;

    detection(ind);

    int ci = around[0];  //compteuri
    int cc = around[ci+1];  //compteurc
    int co = around[cc+ci+3];  //compteuro

    //for initialize every rule
    speed1[0] = 0;
    speed1[1] = 0;

    speed2[0] = 0;
    speed2[1] = 0;

    speed3i[0] = 0;
    speed3i[1] = 0;

    speed3o[0] = 0;
    speed3o[1] = 0;


    // for the rule
    for (int i = 0; i < ci+cc+co; ++i)
    {
        if (i<ci)
        {
            int a = around[i+1];

            //rule 1
            speed1[0] += (tab[a].Get_vx() - vx);
            speed1[1] += (tab[a].Get_vy() - vy);

            //rule 2
            speed2[0] += (tab[a].Get_x() - x);
            speed2[1] += (tab[a].Get_y() - y);
        }
        

        //rule 3
        if (i < cc)
        {
            int b = around[ci+2+i];

            speed3i[0] += (tab[b].Get_x() - x);
            speed3i[1] += (tab[b].Get_y() - y);
        }

        if (i<co)
        {
            int c = around[cc+ci+4+i];
            speed3o[0] += (tab_object[c] -x);
            speed3o[1] += (tab_object[c+1] -y);
        }
    }

    if (ci!=0)
    {
        speed1[0] = speed1[0]/ci;
        speed1[1] = speed1[1]/ci;

        speed2[0] = speed2[0]/ci; 
        speed2[1] = speed2[1]/ci;
    }    
    
    if (cc!=0)
    {
        speed3i[0] =  - speed3i[0]/cc; 
        speed3i[1] =  - speed3i[1]/cc;
    }

    if (co!=0)
    {
        speed3o[0] = - speed3o[0]/co; 
        speed3o[1] = - speed3o[1]/co;
    }


    //==================================================================

    vx = vx + dt*(g1*speed1[0]+g2*speed2[0]+g3*(speed3i[0]+speed3o[0]));  //for change the vx
    vy = vy + dt*(g1*speed1[1]+g2*speed2[1]+g3*(speed3i[1]+speed3o[1]));  //for change the vy   

    // for the wind
    if (x<100) {vx = vx +200;}
    if (x > w-100) {vx = vx - 200;}
    if (y<100) {vy = vy +200;}
    if (y > h-100) {vy = vy -200;}

    //for the Getter because if no getter the value of x, y , vx, vy change at the end of the loop
    Getter[4*ind] = xf;
    Getter[4*ind+1] = yf;
    Getter[4*ind+2] = vx;
    Getter[4*ind+3] = vy; 
}

for (int i = 0; i < population; ++i)
{
    tab[i].Set_x(Getter[4*i]); 
    tab[i].Set_y(Getter[4*i+1]); 
    tab[i].Set_vx(Getter[4*i+2]);
    tab[i].Set_vy(Getter[4*i+3]);
}

}


void boids::detection(int ind)  //for detecte the individue around
{
    int compteuri = 0;  //for compte the individue around in the distance dist
    int compteurc = 0;  //for compte the individue around in the distance dist
    int compteuro = 0;  //for compte the object around in the distance dist

    int tableaui[population];  // tableau of inter individue
    int tableauc[population];  //tableau of contact of individue
    int tableauo[nb_object];

    double xpos = tab[ind].Get_x();  //for performance reason
    double ypos = tab[ind].Get_y();  //for performance reason
    
    //for the population
    for (int i=0; i<population; i++)
    {
        double a = (xpos-tab[i].Get_x())*(xpos-tab[i].Get_x()) + (ypos-tab[ind].Get_y())*(ypos-tab[ind].Get_y()); //distance between 2 individue
        
        if (a<=disti*disti  && a>0)
        {
            tableaui[i] = i;
            compteuri++;
        }
        else
        {
            tableaui[i] = population+12;  //for if i=0 respond to the critere of the if
        }
        

        if (a<=distc*distc  && a>0)
        {
            tableauc[i] = i;
            compteurc++;
        }
        else
        {
            tableauc[i] = population+12;  //for if i=0 respond to the critere of the if
        }

    }
    
    //for the object
    for (int i = 0; i < nb_object; i+=2)
    {
        double a = (xpos-tab_object[i])*(xpos-tab_object[i]) + (ypos-tab_object[i+1])*(ypos-tab_object[i+1]);

        if (a<=distc*distc)
        {
            tableauo[i] = i;
            compteuro++;
        }
        else
        {
            tableauo[i] = nb_object+12;  //for if i=0 respond to the critere of the if
        }
    }


    //fill the tableau around
    int a = 1;
    int b = 1;
    int c = 1;

    for (int i=0; i<population; i++)
    {
        if (tableaui[i]<=population)
        {
            around[a] = i;
            a++;
        }

        if (tableauc[i]<=population)
        {
            around[b+1+compteuri] = i;
            b++;
        }
    }

    for (int i = 0; i < nb_object; i+=2)
    {
        if (tableauo[i]<=nb_object)
        {
            around[c+3+compteurc+compteuri] = i;
            c++;
        }
    }

    around[0] = compteuri; //for have how many content around have for the for boucle in the function rule
    around[compteuri+1] = compteurc;
    around[compteuri+compteurc+3] = compteuro;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================

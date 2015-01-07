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
	dt = 0.01;
	population = 5;
	
    
    disti = 2.;
    disto = 4.;
    distc = 1.;

    g1 = 1;
    g2 = 4;
    g3 = 3;

    speed1 = new double[2];
    speed2 = new double[2];
    speed3 = new double[2];
    speed4 = new double[2];
    
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
boids::~boids(void)
{
	delete[] tab;
    delete[] speed1;
    delete[] speed2;
    delete[] speed3;
    delete[] speed4;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

void boids::initialization(void)
{
	tab = new individue[population];
}
/*
void boids::rule1(int ind, int* around)
{
	double vx = tab[ind].Get_vx();
	double vy = tab[ind].Get_vy();

	for (int i = 0; i < around[0]; ++i)
	{
		int a = around[i+1];

		vx += (tab[a].Get_vx() - vx);
		vy += (tab[a].Get_vy() - vy);
	}

	speed1[0] = vx/around[0];
	speed1[1] = vy/around[0];
}

void boids::rule2(int ind, int* around)
{
	double vx = tab[ind].Get_vx();
	double vy = tab[ind].Get_vy();

	for (int i = 0; i < around[0]; ++i)
	{
		int a = around[i+1];

		vx += (tab[a].Get_x() - vx);
		vy += (tab[a].Get_y() - vy);
	}

	speed2[0] = vx/around[0];
	speed2[1] = vy/around[0];
}

void boids::rule3(int ind, int* around1, int* object_around)
{
    double vx = tab[ind].Get_vx();
    double vy = tab[ind].Get_vy();

    for (int i = 0; i < around1[0]; ++i)
    {
        int a = around1[i+1];

        vx += (tab[a].Get_x() - vx);
        vy += (tab[a].Get_y() - vy);
    }

    speed3[0] = vx/around1[0];
    speed3[1] = vy/around1[0];
}

void boids::rule4(int ind, int* around)
{
    
}

*/

void boids::deplacement(void)
{
double sl = Individue.Get_speed_limit();


for (int ind=0; ind<population; ind++)
{
    double vx = tab[ind].Get_vx();
    double vy = tab[ind].Get_vy();

    tab[ind].Set_x( tab[ind].Get_x() + dt*tab[ind].Get_vx() ); //for set x
    tab[ind].Set_y( tab[ind].Get_y() + dt*tab[ind].Get_vy() ); //for set y

    int* around = detection(ind, disti);
    int* around1 = detection(ind, disto);



    //rule 1 and 2
    //===============================
    speed1[0] = vx;
    speed1[1] = vy;

    speed2[0] = vx;
    speed2[1] = vy;

    for (int i = 0; i < around[0]; ++i)
    {
        int a = around[i+1];

        speed1[0] += (tab[a].Get_vx() - speed1[0]);
        speed1[1] += (tab[a].Get_vy() - speed1[1]);

        speed2[0] += (tab[a].Get_x() - speed2[0]);
        speed2[1] += (tab[a].Get_y() - speed2[1]);
    }

    speed1[0] = speed1[0]/around[0];
    speed1[1] = speed1[1]/around[0];

    speed2[0] = speed2[0]/around[0];
    speed2[1] = speed2[1]/around[0];
    //==========================

    //rule 3
    //=============================
    speed3[0] = vx;
    speed3[1] = vy;

    for (int i = 0; i < around1[0]; ++i)
    {
        int a = around1[i+1];

        speed3[0] += (tab[a].Get_x() - speed3[0]);
        speed3[1] += (tab[a].Get_y() - speed3[1]);
    }

    speed3[0] = speed3[0]/around1[0];
    speed3[1] = speed3[1]/around1[0];
    //==============================

    vx = vx + dt*(g1*speed1[0]+g2*speed2[0]+g3*speed3[0]);  //for change the x
    vy = vy + dt*(g1*speed1[1]+g2*speed2[1]+g3*speed3[1]);  //for change the y
        


    if (vx > sl)
    {
        vx = sl;
    }

    if(vy > sl)
    {
        vy = sl;
    }
    tab[ind].Set_vx(vx);
    tab[ind].Set_vy(vy);

    delete[] around;
    delete[] around1;
}
    
}


int* boids::detection(int ind, double dist)  //for detecte the individue around
{
    int compteur = 0;  //for compte the individue around in the distance dist
    int tableau[population];
    
    double xpos = tab[ind].Get_x();  //for performance reason
    double ypos = tab[ind].Get_y();  //for performance reason
    
    for (int i=0; i<population; i++)
    {
        double a = (xpos-tab[i].Get_x())*(xpos-tab[i].Get_x()) - (ypos-tab[ind].Get_y())*(ypos-tab[ind].Get_y()); //distance between 2 individue
        
        if (a<=dist*dist)
        {
            tableau[i] = i;
            compteur++;
        }
        else
        {
            tableau[i] = population+12;  //for if i=0 respond to the critere of the if
        }
    }
    
    int* around = new int[compteur+1];
    int a = 1;
    
    for (int i=0; i<population; i++)
    {
        if (tableau[i]<=population)
        {
            around[a] = tableau[i];
            a++;
        }
    }

    around[0] = compteur; //for have how many content around have for the for boucle in the function rule
    return around;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================

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
	dt = 0.001;
	population = 10;
	
    
    disti = 2.;
    disto = 4.;
    distc = 1.;

    g1 = 0.1;
    g2 = 0.01;
    g3 = 0.3;

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
	tab = new individue[Get_population()];
}

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



void boids::deplacement(void)
{
    double sl = Individue.Get_speed_limit();

    for (int i=0; i<Get_population(); i++)
    {
        double x = tab[i].Get_x() + dt*tab[i].Get_vx();
        double y = tab[i].Get_y() + dt*tab[i].Get_vy();

        int* around = detection(i, disti);
        int* around1 = detection(i, disto);

        //rule 1
        

        double vx = tab[i].Get_vx() + dt*(g1*speed1[0]+g2*speed2[0]+g3*speed3[0]);  //for change the x
        double vy = tab[i].Get_vy() + dt*(g1*speed1[1]+g2*speed2[1]+g3*speed3[1]);  //for change the y
        
        tab[i].Set_x(x);
        tab[i].Set_y(y);

        if (vx > sl)
        {
            vx = sl;
        }

        if(vy > sl)
        {
            vy = sl;
        }
        tab[i].Set_vx(vx);
        tab[i].Set_vy(vy);

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

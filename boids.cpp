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
	dt = 0.1;
	population = 10;
	
    
    disti = 2.;
    disto = 4.;
    distc = 1.;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
boids::~boids(void)
{
	delete[] tab;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

void boids::initialization(void)
{
	tab = new individue[Get_population()];
}

double* boids::rule1(int ind)
{
	int* around = detection(ind,Get_disti()); //tableau for around people

	double vx = tab[ind].Get_vx();
	double vy = tab[ind].Get_vy();

	for (int i = 0; i < around[0]; ++i)
	{
		int a = around[i+1];

		vx += (tab[a].Get_vx() - vx);
		vy += (tab[a].Get_vy() - vy);
	}

    double* speed =new double[2];

	speed[0] = vx/around[0];
	speed[1] = vy/around[0];

	delete[] around;

    return speed;
}

double* boids::rule2(int ind)
{
	int* around = detection(ind,Get_disti()); //tableau for around people

	double vx = tab[ind].Get_vx();
	double vy = tab[ind].Get_vy();

	for (int i = 0; i < around[0]; ++i)
	{
		int a = around[i+1];

		vx += (tab[a].Get_x() - vx);
		vy += (tab[a].Get_y() - vy);
	}

    double* speed = new double[2];

	speed[0] = vx/around[0];
	speed[1] = vy/around[0];

	delete[] around;

    return speed;
}

double* boids::rule3(int ind)
{
    int* around = detection(ind,Get_distc()); //tableau for around people

    double vx = tab[ind].Get_vx();
    double vy = tab[ind].Get_vy();

    for (int i = 0; i < around[0]; ++i)
    {
        int a = around[i+1];

        vx += (tab[a].Get_x() - vx);
        vy += (tab[a].Get_y() - vy);
    }

    double* speed = new double[2];

    speed[0] = vx/around[0];
    speed[1] = vy/around[0];

    delete[] around;

    return speed;
}

double* boids::rule4(int ind)
{
    
}



void boids::deplacement(void)
{
    for (int i=0; i<Get_population(); i++)
    {
        double x = tab[i].Get_x() + dt*tab[i].Get_vx();
        double y = tab[i].Get_y() + dt*tab[i].Get_vy();

        double* speed1 = rule1(i);
        double* speed2 = rule2(i);
        double* speed3 = rule3(i);

        double vx = tab[i].Get_vx() + dt*(g1*speed1[0]+g2*speed2[0]+g3*speed3[0]);  //for change the x
        double vy = tab[i].Get_vy() + dt*(g1*speed1[1]+g2*speed2[1]+g3*speed3[1]);  //for change the y
        
        tab[i].Set_x(x);
        tab[i].Set_y(y);
        tab[i].Set_vx(vx);
        tab[i].Set_vy(vy);
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

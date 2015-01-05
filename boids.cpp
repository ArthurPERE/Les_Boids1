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
	tab = new individue[Get_population()];
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
/*
double* boids::rule1(int ind)
{

}

double* boids::rule2(int ind)
{

}

double* boids::rule3(int ind)
{
    
}

double* boids::rule4(int ind)
{
    
}
*/

/*
void boids::deplacement(void)
{
    for (int i=0; i<Individue->Get_population(); i++)
    {
        (tab[i])[0] = Individue->Get_x(i) + dt*Individue->Get_vx(i);  //for change the x
        (tab[i])[1] = Individue->Get_y(i) + dt*Individue->Get_vy(i);  //for change the y
    }
    
}
*/

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

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
#include "individue.h"




//############################################################################
//                                                                           #
//                           Class individue              
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
individue::individue(void)
{
    width = 10;
    height = 10;
    speed_limit = 10.;

	x = Get_width() * ( (double)rand() / (double)RAND_MAX );
	y = Get_height() * ( (double)rand() / (double)RAND_MAX );

	vx = 2*Get_speed_limit() * ( (double)rand() / (double)RAND_MAX ) - Get_speed_limit();
	vy = 2*Get_speed_limit() * ( (double)rand() / (double)RAND_MAX ) - Get_speed_limit();
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
individue::~individue(void)
{

}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

/*
int* individue::detection(int ind, double dist)  //for detecte the individue around
{
    int compteur = 0;  //for compte the individue around in the distance dist
    int tableau[population];
    
    double xpos = Get_x(ind);  //for performance reason
    double ypos = Get_y(ind);  //for performance reason
    
    for (i=0; i<population; i++)
    {
        double a = (xpos-Get_x(i))*(xpos-Get_x(i)) - (ypos-Get_y(i))*(ypos-Get_y(i)); //distance between 2 individue
        
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
    
    for (i=0; i<population; i++)
    {
        if (tableau[i]<=population)
        {
            around[a] = tableau[i];
            a++;
        }
        else
        {
            break;
        }
    }
    around[0] = compteur; //for have how many content around have for the for boucle in the function rule
    return around;
}*/
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================

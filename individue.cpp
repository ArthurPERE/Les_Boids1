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
    i=0;
	tab = NULL;

	x=0;
	y=0;
	vx=0;
	vy=0;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
individue::~individue(void)
{
	for (i = 0; i< population; ++i)
	{
		delete[] tab[i];
	}

	delete[] tab;
	delete boid;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
void individue::initialization(void)  //for initialize the problem
{
	tab = new double*[population];


	for (i = 0; i < population; ++i)
	{
        tab[i] = new double[4];
        
        
		(tab[i])[0] = Get_width() * ( (double)rand() / (double)RAND_MAX );  //for x
		(tab[i])[1] = Get_height() * ( (double)rand() / (double)RAND_MAX );  //for y

		(tab[i])[2] = 2*Get_speed_limit() * ( (double)rand() / (double)RAND_MAX ) - boid->Get_speed_limit();  //for vx
		(tab[i])[3] = 2*Get_speed_limit() * ( (double)rand() / (double)RAND_MAX ) - boid->Get_speed_limit();  //for vy
	}
}





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
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================

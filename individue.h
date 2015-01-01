//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __INDIVIDUE_H__
#define __INDIVIDUE_H__

// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================
#include "boids.h"



// ===========================================================================
//                              Class declarations
// ===========================================================================






class individue
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    individue(void);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~individue(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    double** Get_tab(void) const;
    int Get_i(void) const;
    int* Get_around(void) const;

    double Get_x(int ind) const;
    double Get_y(int ind) const;
    double Get_vx(int ind) const;
    double Get_vy(int ind) const;
    
    int Get_population(void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
    void Set_population(int n);
    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    int* detection(int ind); //for detecte the individue around the individue number ind
    
    void organisation(int ind); //for organize the individue ind

    void initialization(void); //for initialize the parameter

    // =======================================================================
    //                             Public Attributes
    // =======================================================================
    int population; //number total of individue




  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*individue(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };
    individue(const individue &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    int i;
    int* around;    //numero of the individue around the individue i

    double** tab;  //tableau of individue;
    
    double x;   //position x of i
    double y;   //position y of i
    double vx;  //speed x coordonate of i
    double vy;  //speed x coordonate of i

    boids* boid;

};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
double** individue::Get_tab(void) const{return tab;}
int individue::Get_i(void) const {return i;}
int* individue::Get_around(void) const {return around;}

double individue::Get_x(int ind) const {return (tab[ind])[0];}
double individue::Get_y(int ind) const {return (tab[ind])[1];}
double individue::Get_vx(int ind) const {return (tab[ind])[2];}
double individue::Get_vy(int ind) const {return (tab[ind])[3];}

int individue::Get_population(void) const {return population;}
// ===========================================================================
//                              Setters' definitions
// ===========================================================================
void individue::Set_population(int n)
{
    population = n;
}
// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __INDIVIDUE_H__


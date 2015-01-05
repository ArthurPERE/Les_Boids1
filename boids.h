//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __BOIDS_H__
#define __BOIDS_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================
#include "individue.h"



// ===========================================================================
//                              Class declarations
// ===========================================================================






class boids
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    boids(void);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~boids(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    inline int Get_population(void) const;
    inline individue* Get_tab(void) const;

    inline double Get_disti(void) const;
    inline double Get_disto(void) const;
    inline double Get_distc(void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
    inline void Set_dt(double dtt);
    inline void Set_population(int n);

    inline void Set_disti(double di);
    inline void Set_disto(double di);
    inline void Set_distc(double di);
    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    double* rule1(int ind);
    double* rule2(int ind);
    double* rule3(int ind);
    double* rule4(int ind);
    
    void deplacement(void);

    void initialization(void);

    int* detection(int ind, double dist); //for detecte the individue around ind
    // =======================================================================
    //                             Public Attributes
    // =======================================================================




  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*boids(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };
    boids(const boids &model)
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
    double dt;

    individue Individue;
    individue* tab;

    int population; //number total of individue

    double disti; //the distance of individue
    double disto; //the distance of object
    double distc; //the distance of contact

};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
inline individue* boids::Get_tab(void) const{return tab;}
inline int boids::Get_population(void) const {return population;}

inline double boids::Get_disti(void) const{return disti;}
inline double boids::Get_disto(void) const{return disto;}
inline double boids::Get_distc(void) const{return distc;}
// ===========================================================================
//                              Setters' definitions
// ===========================================================================
inline void boids::Set_dt(double dtt) {dt = dtt;}

inline void boids::Set_population(int n){population = n;}

inline void boids::Set_disti(double di){disti=di;}
inline void boids::Set_disto(double di){disto=di;}
inline void boids::Set_distc(double di){distc=di;}
// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __BOIDS_H__


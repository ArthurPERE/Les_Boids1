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
    inline double Get_distc(void) const;

    inline int Get_nb_object(void) const;

    inline int* Get_around(void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
    inline void Set_dt(double dtt);
    inline void Set_population(int n);

    inline void Set_disti(double di);
    inline void Set_distc(double di);

    inline void Set_g1(double g);
    inline void Set_g2(double g);
    inline void Set_g3(double g);

    inline void Set_nb_object(int nb);
    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    void deplacement(void);

    void initialization(void);

    void detection(int ind); //for detinline int* Get_around(void) const;ecte the individue around ind
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
    double* Getter;

    int population; //number total of individue

    double disti; //the distance of individue
    double distc; //the distance of contact

    double g1; //gamma 1
    double g2; //gamma 2
    double g3; //gamma 3

    double* speed1;
    double* speed2;
    double* speed3i;  //speed 3 for individue
    double* speed3o;  //speed 3 for object
    double* speed4;

    int* around;

    double* tab_object;  //tab of coordonate of object
    int nb_object;

    int w;  //widht
    int h;  //height
    
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
inline individue* boids::Get_tab(void) const{return tab;}
inline int boids::Get_population(void) const {return population;}

inline double boids::Get_disti(void) const{return disti;}
inline double boids::Get_distc(void) const{return distc;}

inline int boids::Get_nb_object(void) const{return nb_object;}

inline int* boids::Get_around(void) const{return around;}
// ===========================================================================
//                              Setters' definitions
// ===========================================================================
inline void boids::Set_dt(double dtt) {dt = dtt;}

inline void boids::Set_population(int n){population = n;}

inline void boids::Set_disti(double di){disti=di;}
inline void boids::Set_distc(double di){distc=di;}

inline void boids::Set_g1(double g){g1 = g;}
inline void boids::Set_g2(double g){g2 = g;}
inline void boids::Set_g3(double g){g3 = g;}

inline void boids::Set_nb_object(int nb){nb_object=nb;}
// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __BOIDS_H__


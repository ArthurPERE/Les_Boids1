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



class boids
{
  public :
    
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

    inline int Get_nb_object(void) const;
    inline double* Get_tab_object(void) const;

    inline int Get_nb_predator(void) const;
    inline individue* Get_predator(void) const;

    inline int Get_width(void) const;
    inline int Get_height(void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
    inline void Set_dt(double dtt);
    inline void Set_population(int n);

    inline void Set_disti(double di);
    inline void Set_distc(double di);
    inline void Set_distp(double dp);
    inline void Set_distk(double di);

    inline void Set_g1(double g);
    inline void Set_g2(double g);
    inline void Set_g3(double g);
    inline void Set_g4(double g);

    inline void Set_nb_object(int nb);

    inline void Set_nb_predator(int nb);
    inline void Set_speed_predator(double vp);

    inline void Set_width(int w);
    inline void Set_height(int h);

    inline void Set_speed_init(double sl);

    inline void Set_wait(int w);

    inline void Set_wind_force(double wf);

    inline void Set_speed_limit(double sl);
    // =======================================================================
    //                              Public Methods
    // =======================================================================
    void initialization(void);

    void deplacement(void);

    double abs(double x);
    int signe(double x);

  protected :

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
    double distp; //the distance of seeing a prey for a predator
    double distk; //the distance of kill the prey

    double g1; //gamma 1
    double g2; //gamma 2
    double g3; //gamma 3
    double g4; //gamma 4

    double* speed;
    double speed_predator;

    double* tab_object;  //tab of coordonate of object
    int nb_object;

    int w;  //widht
    int h;  //height

    individue* predator;
    int nb_predator;

    double speed_init;

    int width;
    int height;

    bool* found_no_prey; // for choose a direction and stay at that direction
    int* predator_feed;
    int wait;

    double x_alea;
    double y_alea;

    double wind_force;

    double speed_limit;
    
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
inline individue* boids::Get_tab(void) const{return tab;}
inline int boids::Get_population(void) const {return population;}

inline int boids::Get_nb_object(void) const{return nb_object;}
inline double* boids::Get_tab_object(void) const {return tab_object;}

inline int boids::Get_nb_predator(void) const {return nb_predator;}
inline individue* boids::Get_predator(void) const {return predator;}

inline int boids::Get_width(void) const {return width;}
inline int boids::Get_height(void) const {return height;}
// ===========================================================================
//                              Setters' definitions
// ===========================================================================
inline void boids::Set_dt(double dtt) {dt = dtt;}

inline void boids::Set_population(int n){population = n;}

inline void boids::Set_disti(double di){disti = di;}
inline void boids::Set_distc(double di){distc = di;}
inline void boids::Set_distp(double dp){distp = dp;}
inline void boids::Set_distk(double di){distk = di;}

inline void boids::Set_g1(double g){g1 = g;}
inline void boids::Set_g2(double g){g2 = g;}
inline void boids::Set_g3(double g){g3 = g;}
inline void boids::Set_g4(double g){g4 = g;}

inline void boids::Set_nb_object(int nb){nb_object = nb;}

inline void boids::Set_nb_predator(int nb){nb_predator = nb;}
inline void boids::Set_speed_predator(double vp){speed_predator = vp;}

inline void boids::Set_width(int w) {width = w;}
inline void boids::Set_height(int h) {height = h;}

inline void boids::Set_speed_init(double sl){speed_init = sl;}

inline void boids::Set_wait(int w) {wait=w;}

inline void boids::Set_wind_force(double wf){wind_force=wf;}

inline void boids::Set_speed_limit(double sl) {speed_limit=sl;}


#endif // __BOIDS_H__
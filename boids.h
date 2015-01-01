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
    int Get_width(void) const;
    int Get_height(void) const;
    double Get_speed_limit(void) const;
    double Get_disti(void) const;
    double Get_disto(void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
    void Set_width(int w);
    void Set_height(int h);
    void Set_disti(double di);
    void Set_disto(double di);
    void Set_dt(double dtt);
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
    // =======================================================================
    //                             Public Attributes
    // =======================================================================
    int width; //the widht of the cader
    int height; //the height of the cader
    double disti; //the distance of detection of the individue
    double disto; //the distance of detedction of the object
    double dt;



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
    double speed_limit;
    individue* Individue;

};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
int boids::Get_width(void) const {return width;}
int boids::Get_height(void) const {return height;}
double boids::Get_speed_limit(void) const {return speed_limit;}
double boids::Get_disti(void) const {return disti;}
double boids::Get_disto(void) const {return disto;}


// ===========================================================================
//                              Setters' definitions
// ===========================================================================
void boids::Set_width(int w) {width = w;}
void boids::Set_height(int h) {height = h;}
void boids::Set_disti(double di) {disti = di;}
void boids::Set_disto(double di) {disto = di;}
void boids::Set_dt(double dtt) {dt = dtt;}
// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __BOIDS_H__


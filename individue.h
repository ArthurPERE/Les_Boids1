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
    double Get_x(int ind) const;
    double Get_y(int ind) const;

    double Get_vx(int ind) const;
    double Get_vy(int ind) const;
    double Get_speed_limit(void) const;
    
    int Get_population(void) const;

    int Get_width(void) const;
    int Get_height(void) const;



    double Get_disti(void) const;
    double Get_disto(void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
    void Set_population(int n);
    void Set_tab(double** tab1);

    void Set_width(int w);
    void Set_height(int h);

    void Set_disti(double di);
    void Set_disto(double di);
    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    int* detection(int ind, double dist); //for detecte the individue around the individue number ind
    
    void initialization(void); //for initialize the parameter

    // =======================================================================
    //                             Public Attributes
    // =======================================================================





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
    double** tab;

    double x;   //position x of i
    double y;   //position y of i

    double vx;  //speed x coordonate of i
    double vy;  //speed x coordonate of i
    double speed_limit;

    int width; //the widht of the cader
    int height; //the height of the cader

    double disti; //the distance of detection of the individue
    double disto; //the distance of detedction of the object

    int population; //number total of individue

};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================

double individue::Get_x(int ind) const {return (tab[ind])[0];}
double individue::Get_y(int ind) const {return (tab[ind])[1];}

double individue::Get_vx(int ind) const {return (tab[ind])[2];}
double individue::Get_vy(int ind) const {return (tab[ind])[3];}
double individue::Get_speed_limit(void) const {return speed_limit;}

int individue::Get_population(void) const {return population;}

int individue::Get_width(void) const {return width;}
int individue::Get_height(void) const {return height;}



double individue::Get_disti(void) const {return disti;}
double individue::Get_disto(void) const {return disto;}
// ===========================================================================
//                              Setters' definitions
// ===========================================================================
void individue::Set_population(int n){population = n;}
void individue::Set_tab(double** tab1){tab = tab1;}

void individue::Set_width(int w) {width = w;}
void individue::Set_height(int h) {height = h;}

void individue::Set_disti(double di) {disti = di;}
void individue::Set_disto(double di) {disto = di;}
// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __INDIVIDUE_H__


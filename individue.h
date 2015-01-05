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
    inline double Get_x(void) const;
    inline double Get_y(void) const;

    inline int Get_width(void) const;
    inline int Get_height(void) const;

    inline double Get_speed_limit(void) const;

    inline double Get_vx(void) const;
    inline double Get_vy(void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
    inline void Set_x(double x1);
    inline void Set_y(double y1);

    inline void Set_width(int w);
    inline void Set_height(int h);

    inline void Set_speed_limit(double sl);

    inline void Set_vx(double vx1);
    inline void Set_vy(double vy1);
    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    
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

    double x;   //position x of i
    double y;   //position y of i

    double vx;  //speed x coordonate of i
    double vy;  //speed x coordonate of i

    double speed_limit;

    int width;
    int height;
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================

inline double individue::Get_x(void) const {return x;}
inline double individue::Get_y(void) const {return y;}

inline double individue::Get_vx(void) const {return vx;}
inline double individue::Get_vy(void) const {return vy;}

inline int individue::Get_width(void) const {return width;}
inline int individue::Get_height(void) const {return height;}

inline double individue::Get_speed_limit(void) const {return speed_limit;}
// ===========================================================================
//                              Setters' definitions
// ===========================================================================

inline void individue::Set_x(double x1){x=x1;}
inline void individue::Set_y(double y1){y=y1;}

inline void individue::Set_vx(double vx1){vx=vx1;}
inline void individue::Set_vy(double vy1){vy=vy1;}

inline void individue::Set_width(int w) {width = w;}
inline void individue::Set_height(int h) {height = h;}

inline void individue::Set_speed_limit(double sl){speed_limit = sl;}
// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __INDIVIDUE_H__


#ifndef __INDIVIDUE_H__
#define __INDIVIDUE_H__

// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>

class individue
{
  public :

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

    inline double Get_vx(void) const;
    inline double Get_vy(void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
    inline void Set_x(double x1);
    inline void Set_y(double y1);

    inline void Set_vx(double vx1);
    inline void Set_vy(double vy1);




  protected :

    // =======================================================================
    //                             Protected Attributes
    // ======================================================================= 

    double x;   //position x of i
    double y;   //position y of i

    double vx;  //speed x coordonate of i
    double vy;  //speed x coordonate of i
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================

inline double individue::Get_x(void) const {return x;}
inline double individue::Get_y(void) const {return y;}

inline double individue::Get_vx(void) const {return vx;}
inline double individue::Get_vy(void) const {return vy;}

// ===========================================================================
//                              Setters' definitions
// ===========================================================================

inline void individue::Set_x(double x1){x=x1;}
inline void individue::Set_y(double y1){y=y1;}

inline void individue::Set_vx(double vx1){vx=vx1;}
inline void individue::Set_vy(double vy1){vy=vy1;}


#endif // __INDIVIDUE_H__
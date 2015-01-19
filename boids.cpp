// ===========================================================================
//                                   Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "boids.h"


//############################################################################
//                                                                           #
//                           Class boids
//                                                                           #
//############################################################################

// ===========================================================================
//                                  Constructors
// ===========================================================================
boids::boids(void)
{
	dt = 0;
	population = 0;
	
    tab=NULL;
    predator=NULL;
    tab_object=NULL;
    Getter=NULL;    

    disti = 0;
    distc = 0;
    distp = 0;
    distk = 0;

    g1 = 0;
    g2 = 0;
    g3 = 0;
    g4 = 0;

    speed = new double[10];

    nb_object = 0;

    w=0;
    h=0;

    nb_predator = 0;
    speed_predator = 0;

    width = 0;
    height = 0;

    speed_init = 0;

    found_no_prey = new bool[nb_predator];
    for (int i = 0; i < nb_predator; ++i)
    {
        found_no_prey[i]=true;
    }

    wait = 0;

    predator_feed = new int[nb_predator];
    for (int i = 0; i < nb_predator; ++i)
    {
        predator_feed[i]=0;
    }

    x_alea = 0;
    y_alea = 0;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
boids::~boids(void)
{
	delete [] tab;

    delete [] speed;

    delete [] Getter;

    delete [] predator;

    delete [] found_no_prey;

    delete [] predator_feed;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

void boids::initialization(void)
{
    //for the birds
	tab = new individue[population];
    for (int i = 0; i < population; ++i)
    {
        tab[i].Set_x( ((width-100)-100)*((double)rand()/(double)RAND_MAX)+100 );
        tab[i].Set_y( ((height-100)-100)*((double)rand()/(double)RAND_MAX)+100 );

        tab[i].Set_vx(2*speed_init*((double)rand()/(double)RAND_MAX)-speed_init);
        tab[i].Set_vy(2*speed_init*((double)rand()/(double)RAND_MAX)-speed_init);
    }


    //for the predator
    predator = new individue[nb_predator];
    for (int i = 0; i < nb_predator; ++i)
    {
        predator[i].Set_x( ((width-100)-100)*((double)rand()/(double)RAND_MAX)+100 );
        predator[i].Set_y( ((height-100)-100)*((double)rand()/(double)RAND_MAX)+100 );
    }


    Getter = new double[4*population];

    //set the object
    tab_object = new double[2*nb_object];

    for (int i = 0; i < 2*nb_object; i+=2)
    {
        tab_object[i] = ((width-100)-100)*((double)rand()/(double)RAND_MAX)+100; //for x coordonate
        tab_object[i+1] = ((height-100)-100)*((double)rand()/(double)RAND_MAX)+100; //for y coordonate
    }
}


void boids::deplacement(void)
{
for (int ind=0; ind<population; ind++)
{
    double x = tab[ind].Get_x();
    double y = tab[ind].Get_y();
    double vx = tab[ind].Get_vx();
    double vy = tab[ind].Get_vy();

    //for change the x, y
    Getter[4*ind] = x + dt * vx;
    Getter[4*ind+1] = y + dt * vy;

    int ci = 0;  //compteur individue around
    int cc = 0;  //compteur individue too close
    int co = 0;  //compteur object too close

    //for initialize every rule
    speed[0] = 0;  //for vx from rule 1
    speed[1] = 0;  //for vy from rule 1

    speed[2] = 0;  //for vx from rule 2
    speed[3] = 0;  //for vy from rule 2

    speed[4] = 0;  //for vx from rule 3 inter individue
    speed[5] = 0;  //for vy from rule 3 inter individue

    speed[6] = 0;  //for vx from rule 3 object
    speed[7] = 0;  //for vy from rule 3 object

    speed[8] = 0;  //for vx from rule 4
    speed[9] = 0;  //for vy from rule 4


    // for the rules
    for (int i = 0; i < population; ++i)
    {
        double x_other = tab[i].Get_x();
        double y_other = tab[i].Get_y();

        double a = sqrt((x - x_other)*(x - x_other) + (y - y_other)*(y - y_other)); //distance between 2 individue
        if (a<=disti)
        {
            //rule 1
            speed[0] += (tab[i].Get_vx() - vx);
            speed[1] += (tab[i].Get_vy() - vy);

            //rule 2
            speed[2] += (x_other - x);
            speed[3] += (y_other - y);

            ci++;
        }
        
        //rule 3
        if (a<=distc)
        {
            speed[4] += (x_other - x);
            speed[5] += (y_other - y);
            cc++;
        }

        if (i<nb_object)
        {
            double xo = tab_object[2*i];
            double yo = tab_object[2*i+1];
            double a = sqrt((x - xo)*(x - xo) + (y - yo)*(y - yo));
            
            if (a<=distc)
            {
                speed[6] += (xo - x);
                speed[7] += (yo - y);
                co++;
            }
        }

        //rule 4
        if (i<nb_predator)
        {
            double xp = predator[i].Get_x();
            double yp = predator[i].Get_y();

            double a = sqrt((x - xp)*(x - xp)+(y - yp)*(y - yp));

            speed[8] = - (xp - x)/a;
            speed[9] = - (yp - y)/a;
        }
        
    }


    if (ci!=0)
    {
        speed[0] = speed[0]/ci;
        speed[1] = speed[1]/ci;

        speed[2] = speed[2]/ci; 
        speed[3] = speed[3]/ci;
    }    
    
    if (cc!=0)
    {
        speed[4] =  - speed[4]/cc;
        speed[5] =  - speed[5]/cc;
    }

    if (co!=0)
    {
        speed[6] = - speed[6]/co; 
        speed[7] = - speed[7]/co;
    }   


    //==================================================================

    vx = vx + dt*(g1*speed[0]+g2*speed[2]+g3*(speed[4]+speed[6])+g4*speed[8]);  //for change the vx
    vy = vy + dt*(g1*speed[1]+g2*speed[3]+g3*(speed[5]+speed[7])+g4*speed[9]);  //for change the vy

    // for the wind
    if (x<50  && x>-99) {vx = vx +50;}
    if (x > width - 50) {vx = vx - 50;}
    if (y<50 && y>-99) {vy = vy +50;}
    if (y > height - 50) {vy = vy -50;}

    //for the Getter because if no getter the value of vx, vy change at the end of the loop
    Getter[4*ind+2] = vx;
    Getter[4*ind+3] = vy; 
}

//=============================================================================
//for mouvement of predators
for (int i = 0; i < nb_predator; ++i)
{

    if (predator_feed[i]==0 || predator_feed[i] > wait)
    {
        predator_feed[i]=0;

        double x_pred = predator[i].Get_x();
        double y_pred = predator[i].Get_y();

        double min = distp+1; // +1 for the case a = distp, min for find the distance min in the radius of the sight of this predator
        int prey = population+1; // for numero of the prey

        // find the next prey
        for (int pop = 0; pop < population; ++pop)
        {
            double a = sqrt((x_pred - tab[pop].Get_x())*(x_pred - tab[pop].Get_x())+(y_pred - tab[pop].Get_y())*(y_pred - tab[pop].Get_y()));
    
            if (a<=distp && a<min)
            {
                prey = pop;  
                min = a;
            }
        }

        predator[i].Set_x(x_pred + dt*predator[i].Get_vx());
        predator[i].Set_y(x_pred + dt*predator[i].Get_vy());

        //if he see a prey
        if (min <= distp && min > distk)
        {
            predator[i].Set_vx((tab[prey].Get_x() - x_pred)*speed_predator/min);
            predator[i].Set_vy((tab[prey].Get_y() - y_pred)*speed_predator/min);

            found_no_prey[i] = false;
        }

        //if he is out of reach for the prey for the first time
        if (min > distp  && found_no_prey[i]==false)
        {
            x_alea = ((width-100)-100)*((double)rand()/(double)RAND_MAX)+100;
            y_alea = ((height-100)-100)*((double)rand()/(double)RAND_MAX)+100;

            double d = sqrt((x_pred - x_alea)*(x_pred - x_alea)+(y_alea - y_pred)*(y_alea - y_pred));

            predator[i].Set_vx((x_alea - x_pred)*speed_predator/d);
            predator[i].Set_vy((y_alea - y_pred)*speed_predator/d);

            found_no_prey[i] = true;

            printf("%lg %lg\n", x_alea, y_alea);
        }


        //if the predator kill a boid
        if (min<=distk)
        {

            // printf("%lg\n", min);
            // printf("%d\n", prey);
            // //temporal tab of individue
            // double tab_temp[4*(population-1)];

            // for (int pop = 0; pop < population; ++pop)
            // {
            //     //take information in the temporal tab
            //     if (pop != prey)
            //     {
            //         tab_temp[4*pop] = tab[pop].Get_x();
            //         tab_temp[4*pop+1] = tab[pop].Get_y();

            //         tab_temp[4*pop+2] = tab[pop].Get_vx();
            //         tab_temp[4*pop+3] = tab[pop].Get_vy();
            //     }
            // }

            //     delete[] tab;
            //     tab=NULL;

            //     population = population - 1;
         
            // //individue* tab = new individue[population];
            // tab = new individue[population];
            // for (int pop = 0; pop < population; ++pop)
            // {
            //     tab[pop].Set_x(tab_temp[4*pop]);
            //     tab[pop].Set_y(tab_temp[4*pop+1]);
            //     tab[pop].Set_vx(tab_temp[4*pop+2]);
            //     tab[pop].Set_vy(tab_temp[4*pop+3]);
            // }


            // another idea

            

            Getter[4*prey]=-1000;
            Getter[4*prey+1]=-1000;
            Getter[4*prey+2]=0;
            Getter[4*prey+3]=0;


            predator_feed[i]=1;


        }

        //for the wind
        if (x_pred<50) {predator[i].Set_vx(- predator[i].Get_vx());}
        if (y_pred<50) {predator[i].Set_vy(- predator[i].Get_vy());}
        if (x_pred>width-50) {predator[i].Set_vx(- predator[i].Get_vx());}
        if (y_pred<height-50) {predator[i].Set_vy(- predator[i].Get_vy());}
    }

    if (predator_feed[i]>0 && predator_feed[i]<=wait+1)
    {
        predator_feed[i]++;
    }
}


for (int i = 0; i < population; ++i)
{
    tab[i].Set_x(Getter[4*i]); // for x
    tab[i].Set_y(Getter[4*i+1]); //for y
    tab[i].Set_vx(Getter[4*i+2]); //for vx
    tab[i].Set_vy(Getter[4*i+3]);  //for vy
}

}
#include <stdio.h>
#include "bwindow.h"


int main()
{
    bwindow win(640,480);
    printf("%d\n",win.init());
    win.map();
    for(;;)
    {
	int ev = win.parse_event();
	switch(ev)
	{
	    case BKPRESS :
		printf("keypressed\n"); 
		printf("key : %s\n",win.get_lastkey());
		break;
	    case BBPRESS:
		printf("buttonpressed\n"); break;
	    case BEXPOSE:
		printf("expose\n"); break;
	    case BCONFIGURE:
		printf("configure\n"); break;
	}
	win.draw_point(100,100,0xFF00);
	win.draw_line(200,200,195,195,0xFF0000);
	win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));
	win.draw_square(0,0,205,205,0xFF00);
	win.draw_fsquare(400,400,440,440,0xFF00);
    }
    return 0;
}

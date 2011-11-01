#ifndef _____INTERFACE_H________
#define _____INTERFACE_H________

#include <gtk/gtk.h>
#include "defines.h"

typedef struct  UserInterface
{
    GtkWidget* MainWnd  ;




    guint   TimerID[5]  ;
    PARA  para          ;
}UI, *UI_P ;





#endif

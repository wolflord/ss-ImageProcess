#ifndef _____INTERFACE_H________
#define _____INTERFACE_H________

#include <gtk/gtk.h>
#include "defines.h"

typedef struct  UserInterface
{
    GtkWidget*       MainWnd;
    GtkUIManager*         ui;
    GtkActionGroup*  actions;
    GtkWidget*       MainBox;
    GtkWidget*          hBox;
    GtkWidget*          vBox;
    GtkWidget*       LeftBar;
    //GtkWidget* ImageView;
    GtkWidget*  GridDataView;
    GtkWidget*    ImageFrame;
    GtkWidget* GridDataFrame;
    GdkPixbuf* ImageViewBuff;


    unsigned char*    pixels;
    guint   TimerID[5]  ;
    PARA  para          ;
}UI, *UI_P ;





#endif

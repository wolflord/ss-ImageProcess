#ifndef _____INTERFACE_H________
#define _____INTERFACE_H________

#include <gtk/gtk.h>
#include "defines.h"

#define SETTING_BUTTON_LABEL_LENGTH 50
#define SETTING_BUTTON_STEP_COUNT   5


typedef struct _LOCATION
{
     int xOffset ;
     int yOffset ;
     int width   ;
     int height  ;
}LOCATION, *LOCATION_P ;

typedef struct _SETTING_BUTTON
{
    GtkWidget* Button   ;
    GtkWidget* Label    ;

    char*  Markup       ;
    int    Width        ;
    int    Height       ;
    int    ButtonCondtion;

    double MinValue     ;
    double MaxValue     ;
    double CurrentValue ;
    double StepValue[SETTING_BUTTON_STEP_COUNT] ;
    int    StepSlected  ;
    int  DecimalDisplay ;

    char*  Bgroud       ;
    char*  Fgroud       ;

    LOCATION  ScrollBar ;

    GdkEventType  EventMark;
    void*  CallBackFunc ;
    int   CurrentStatus ;

}SETTING_BUTTON , *SETTING_BUTTON_P  ;


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
    int       ImageViewWidth;
    int      ImageViewHeight;

    unsigned char*    pixels;
    guint         TimerID[5];
    PARA                para;

}UI, *UI_P ;





#endif

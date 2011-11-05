#ifndef ___ULTRASONIC_H______
#define ___ULTRASONIC_H______
/***standard C Include Head Files****/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <malloc.h>
/********Gtk Include Head Files******/
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
/*****Project Include Head Files*****/
#include "interface.h"
#include "defines.h"

#ifdef DEBUG
#define Debug(formate, ARGS...)   printf(formate"\n", ##ARGS)
#else
#define Debug(formate, ARGS...)
#endif

#define VERSION  1.0

//************************************
// main.c
//************************************
extern UI     ui;
extern UI_P p_ui;
extern int ReadSettingFiles() ;
extern int SaveSettingFiles() ;
extern int InitParameters()   ;
//************************************
// file_op.c
//************************************
extern int  read_parameter_file(const char* filename, PARA_P file) ;
extern int  write_parameter_file(const char* filename, PARA_P file);

//************************************
// drawui.c
//************************************
extern void InitUserInterface() ;
extern void SetWidgetBackGroud(GtkWidget *widget,GdkPixbuf* image) ;
//************************************
// callback.c
//************************************
extern void AppExit (GtkWidget* widget, GdkEvent* event, gpointer data) ;
extern int  TimmerCallback_1s (gpointer data) ;
extern int  AppIdleFunction (gpointer data)    ;
extern void ActivateAction (GtkAction *action);
extern void ActivateRadioAction (GtkAction *action, GtkRadioAction *current);
extern void AboutMessage (GtkAction *action);
extern void FileOpenAction(GtkAction* action) ;
extern void ImageViewMouseMove (GtkWidget* widget, GdkEvent* event, gpointer data);
extern void ImageViewButtonClick (GtkWidget* widget, GdkEvent* event, gpointer data);
extern void ImageViewScrollEvent (GtkWidget* widget, GdkEvent* event, gpointer data);
extern void ImageViewRealizeEvent (GtkWidget* widget, GdkEvent* event, gpointer data);
extern void ImageViewConfigEvent (GtkWidget* widget, GdkEvent* event, gpointer data);
extern int  ImageViewExposeEvent (GtkWidget* widget, GdkEventExpose *event, gpointer data);
extern void EventBoxTest (GtkAction* action) ;
#endif

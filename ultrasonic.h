#ifndef ___ULTRASONIC_H______
#define ___ULTRASONIC_H______

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <malloc.h>
#include <gtk/gtk.h>


#include "interface.h"
#include "defines.h"

#ifdef DEBUG
#define Debug(formate, ARGS...)   printf(formate"\n", ##ARGS)
#else
#define Debug(formate, ARGS...)
#endif


//main.c
extern UI ui;
extern UI_P p_ui;


//file_op.c
extern int read_parameter_file(const char* filename, PARA_P file) ;
extern int write_parameter_file(const char* filename, PARA_P file);

// drawui.c
extern void InitUserInterface() ;

// callback.c
extern void AppExit (GtkWidget* widget, GdkEvent* event, gpointer data) ;
extern int timmer_callback_1s (gpointer data) ;
extern int AppIdleFunction (gpointer data)    ;






















#endif

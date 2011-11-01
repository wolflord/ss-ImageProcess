#include "ultrasonic.h"

void AppExit (GtkWidget* widget, GdkEvent* event, gpointer data)
{
    Debug("Main Function Exit!") ;
    write_parameter_file("default.param" , &(p_ui->para));
    gtk_main_quit();
}


int timmer_callback_1s (gpointer data)
{
    Debug ("1s Interval!") ;
    return TRUE ;
}


int AppIdleFunction (gpointer data)
{
    Debug (" Idle Function!") ;
    return 0 ;
}

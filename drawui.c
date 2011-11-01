#include "ultrasonic.h"

GdkColor color_black     = { 0 ,    0 ,      0,     0} ;
GdkColor color_white     = { 0 , 65535, 65535 , 65535} ;
GdkColor color_red       = { 0 , 65535,     0 ,     0} ;
GdkColor color_green     = { 0 ,    0 , 65535 ,     0} ;
GdkColor color_blue      = { 0 ,    0 ,    0 ,  65535} ;
GdkColor color_yellow    = { 0 , 65535, 65535,      0} ;

void InitUserInterface()
{
    GtkWidget* WND ;
    //
    WND = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    p_ui->MainWnd = WND ;

    gtk_widget_set_size_request (WND , 800 , 600) ;
    gtk_window_set_title (GTK_WINDOW(WND), "UltraSonic");
    gtk_widget_modify_bg (WND , GTK_STATE_NORMAL, &color_green ) ;
    gtk_window_maximize (GTK_WINDOW(WND)) ;
    //gtk_window_fullscreen (GTK_WINDOW(WND)) ;
    //gtk_window_set_decorated (GTK_WINDOW(WND) , FALSE) ;
    g_signal_connect (G_OBJECT(WND), "destroy", G_CALLBACK(AppExit) , NULL) ;

    gtk_widget_show_all(WND);
}

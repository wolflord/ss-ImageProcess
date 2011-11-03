#include "project.h"

void AppExit (GtkWidget* widget, GdkEvent* event, gpointer data)
{
    Debug("Main Function Exit!") ;
    write_parameter_file(".CONFIG" , &(p_ui->para));
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

void About_Message (GtkAction *action)
{

  GtkWidget *dialog;
  dialog = gtk_message_dialog_new (GTK_WINDOW (p_ui->MainWnd),
				   GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
				   GTK_MESSAGE_INFO,
				   GTK_BUTTONS_OK,
				   "This Application Interface is Created by\n"
				   "WolfLord 20110101");

  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

void activate_action (GtkAction *action)
{
  g_message ("Action \"%s\" activated", gtk_action_get_name (action));
  GtkWidget* dialog;
  gint response ;
  dialog = gtk_dialog_new();
  //dialog = gtk_color_selection_dialog_new ("Changing color");
  gtk_window_set_transient_for (GTK_WINDOW (dialog), GTK_WINDOW (p_ui->MainWnd));
  gtk_widget_set_size_request (dialog, 280 , 120);
  gtk_widget_show(dialog);
  //  this function make the dialog to be do model
  response = gtk_dialog_run (GTK_DIALOG (dialog));

  if (response == GTK_RESPONSE_OK)
    {
        Debug ("GTK_RESPONSE_OK IS PRESSED!") ;
    }

  gtk_widget_destroy (dialog);
}

void
activate_radio_action (GtkAction *action, GtkRadioAction *current)
{
  g_message ("Radio action \"%s\" selected",
	     gtk_action_get_name (GTK_ACTION (current)));
}


void 
open_file_action (GtkAction* action)
{
   Debug ("OPEN FILE ACTION!") ;
}


void ImageViewMouseMove (GtkWidget* widget, GdkEvent* event, gpointer data)
{
	Debug ("ImageViewMouseMove") ;
}

void ImageViewButtonClick (GtkWidget* widget, GdkEvent* event, gpointer data)
{
	Debug ("ImageViewButtonClick!") ;
}

void ImageViewScrollEvent (GtkWidget* widget, GdkEvent* event, gpointer data)
{
	Debug ("ImageViewScrollEvent!") ;
}

void ImageViewRealizeEvent (GtkWidget* widget, GdkEvent* event, gpointer data)
{
	Debug ("ImageViewRealizeEvent!") ;
}

void ImageViewConfigEvent (GtkWidget* widget, GdkEvent* event, gpointer data)
{
	Debug ("ImageViewConfigEvent!") ;
}

void ImageViewExposeEvent (GtkWidget* widget, GdkEvent* event, gpointer data)
{
	Debug ("ImageViewExposeEvent!") ;
}

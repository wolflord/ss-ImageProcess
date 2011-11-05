#include "project.h"

void AppExit (GtkWidget* widget, GdkEvent* event, gpointer data)
{
    Debug("Main Function Exit!") ;
    write_parameter_file(".CONFIG" , &(p_ui->para));
    gtk_main_quit();
}

int TimmerCallback_1s (gpointer data)
{
    Debug ("1s Interval!") ;
    return TRUE ;
}

int AppIdleFunction (gpointer data)
{
    Debug (" Idle Function!") ;
    return 0 ;
}

void AboutMessage (GtkAction *action)
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

void ActivateAction (GtkAction *action)
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

void ActivateRadioAction (GtkAction *action, GtkRadioAction *current)
{
  g_message ("Radio action \"%s\" selected",
	     gtk_action_get_name (GTK_ACTION (current)));
}

void OpenImageFile(GtkWidget* widget, gpointer data)
{
    char* filename = NULL;
    filename = (char*)gtk_file_selection_get_filename(GTK_FILE_SELECTION(data)) ;
    Debug("%s" , filename) ;
    gtk_widget_destroy(data);
}
void FileSlectionCancel(GtkWidget* widget, gpointer data)
{
    gtk_widget_destroy(data);
}

void
FileOpenAction (GtkAction* action)
{
    Debug ("OPEN FILE ACTION!") ;
    GtkWidget* FileSelection ;
    FileSelection = gtk_file_selection_new("SlectionFile") ;
    gtk_file_selection_set_filename(GTK_FILE_SELECTION(FileSelection),"/home/*.c");
    g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(FileSelection)->ok_button),"clicked" , G_CALLBACK(OpenImageFile), FileSelection) ;
    g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(FileSelection)->cancel_button),"clicked" , G_CALLBACK(FileSlectionCancel), FileSelection) ;
    gtk_widget_show(FileSelection);
}


void ImageViewMouseMove (GtkWidget* widget, GdkEvent* event, gpointer data)
{
    Debug ("ImageViewMouseMove") ;
}

void ImageViewButtonClick (GtkWidget* widget, GdkEvent* event, gpointer data)
{
    int x  = event->button.x;
    int y  = event->button.y;
    int button = event->button.button ;
    switch (button)
    {
	case 1:   // left button
	   Debug ("ImageViewLeftButtonClick!   x-%d--y-%d", x, y) ;
	   break;
	case 2:   // scroll button
	   Debug ("ImageViewScrollButtonClick! x-%d--y-%d", x, y) ;
	   break;
	case 3:   // right button
	   Debug ("ImageViewRightButtonClick!  x-%d--y-%d", x, y) ;
	   break;
	default:
	   break;
    }
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

int ImageViewExposeEvent (GtkWidget* widget, GdkEventExpose *event, gpointer data)
{
    unsigned char* pixels;
    int rowstride;

    rowstride = gdk_pixbuf_get_rowstride (p_ui->ImageViewBuff);
    pixels = gdk_pixbuf_get_pixels (p_ui->ImageViewBuff) + rowstride * event->area.y + event->area.x * 3;
    p_ui->ImageViewWidth = event->area.width ;
    p_ui->ImageViewHeight= event->area.height;
    gdk_draw_rgb_image_dithalign (widget->window,
				widget->style->black_gc,
				event->area.x, event->area.y,
				event->area.width, event->area.height,
				GDK_RGB_DITHER_NORMAL,
				pixels, rowstride,
				event->area.x , event->area.y);
    return TRUE;
}

void callbackfunc(GtkWidget* widget , GdkEvent* event , gpointer data)
{
      Debu("callbackfun!");
}

void EventBoxTest (GtkAction* action)
{
    Debug("EventBox test!!!") ;
    GtkWidget* window;
    SETTING_BUTTON button ;
    window = gtk_window_new(GTK_WINDOW_POPUP);

    button.Markup = g_markup_printf_escaped ("<span foreground='white' font_desc='10'>%s</span>", "HELLO!");
    button.EventMark = GDK_BUTTON_PRESS_MASK ;
    //button.CallBackFunc = (void*) callbackfunc ;

}

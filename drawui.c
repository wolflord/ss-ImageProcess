#include "project.h"

GdkColor color_black     = { 0 ,    0 ,      0,     0} ;
GdkColor color_white     = { 0 , 65535, 65535 , 65535} ;
GdkColor color_red       = { 0 , 65535,     0 ,     0} ;
GdkColor color_green     = { 0 ,    0 , 65535 ,     0} ;
GdkColor color_blue      = { 0 ,    0 ,    0 ,  65535} ;
GdkColor color_yellow    = { 0 , 65535, 65535,      0} ;
GdkColor color_dark      = { 0 , 40000, 40000,  40000} ;


static void register_stock_icons (void)
{
	GdkPixbuf *pixbuf;
	GtkIconFactory *factory;
    GtkIconSet *icon_set;
	GdkPixbuf *transparent;
	char *filename;
    // if the icons is registed 
    // return 
    static gboolean icons_registed = FALSE ;
    if(icons_registed)  return ;
    
	static GtkStockItem items[] = {
	{ "demo-gtk-logo",
	  "Help",
	  0, 0, NULL }
	};

	/* Register our stock items */
	gtk_stock_add (items, G_N_ELEMENTS (items));

	/* Add our custom icon factory to the list of defaults */
	factory = gtk_icon_factory_new ();
	gtk_icon_factory_add_default (factory);

	/* demo_find_file() looks in the current directory first,
	* so you can run gtk-demo without installing GTK, then looks
	* in the location where the file is installed.
	*/
	pixbuf = NULL;
	filename = "res/icon9.ico" ;
	if (filename)
	{
	    pixbuf = gdk_pixbuf_new_from_file (filename, NULL);
	    // g_free (filename);
	}

	/* Register icon to accompany stock item */
	if (pixbuf != NULL)
	{
	  /* The gtk-logo-rgb icon has a white background, make it transparent */
	  transparent = gdk_pixbuf_add_alpha (pixbuf, TRUE, 0xff, 0xff, 0xff);
	  
	  icon_set = gtk_icon_set_new_from_pixbuf (transparent);
	  gtk_icon_factory_add (factory, "demo-gtk-logo", icon_set);
	  gtk_icon_set_unref (icon_set);
	  g_object_unref (pixbuf);
	  g_object_unref (transparent);
	}
	else
	  g_warning ("failed to load GTK logo for toolbar");
     
	/* Drop our reference to the factory, GTK will hold a reference. */
	g_object_unref (factory);
	icons_registed = TRUE ;
}


GtkWidget* OpenGLView()
{  
    GtkWidget *ImageView;
    GtkWidget *ImageFrame;
    
    // create opengl view
    ImageView = gtk_drawing_area_new();
	gtk_widget_set_size_request(ImageView,640,480);
	ImageFrame = gtk_frame_new (NULL);
	gtk_frame_set_shadow_type (GTK_FRAME(ImageFrame),GTK_SHADOW_IN) ;
	gtk_container_add(GTK_CONTAINER(ImageFrame),ImageView);	
	gtk_widget_modify_bg (ImageView, GTK_STATE_NORMAL, &color_dark );
	
	// Set OpenGL configure
	//glconfig = gdk_gl_config_new_by_mode (GDK_GL_MODE_RGB    |
	//                                   GDK_GL_MODE_DEPTH  |
	//                                   GDK_GL_MODE_DOUBLE);	                               
									
	//* Set opengl to this screen
	//gtk_widget_set_gl_capability (ImageView,
	//                          glconfig,
	//                           NULL,
	//                           TRUE,
	//                           GDK_GL_RGBA_TYPE);


	// enable opengl view response signal 
	//gtk_widget_add_events ( ImageView,
	//		 GDK_BUTTON_PRESS_MASK | GDK_SCROLL_MASK |GDK_BUTTON1_MOTION_MASK
	//        |GDK_BUTTON3_MOTION_MASK );

	/* Connect signal handlers to the drawing area */
	//g_signal_connect (G_OBJECT (ImageView), "motion_notify_event", G_CALLBACK (motion_notify_event), NULL);
	//g_signal_connect (G_OBJECT (ImageView), "button_press_event", G_CALLBACK (button_press_event), NULL);
	//g_signal_connect (G_OBJECT (ImageView), "scroll_event",G_CALLBACK (scroll_event), ImageView);
	//  realize the widget (Create)
	//g_signal_connect_after (G_OBJECT (ImageView), "realize", G_CALLBACK (realize), NULL);
	//  pre set configure of widget (PreCreateWindow)
	//g_signal_connect (G_OBJECT (ImageView), "configure_event", G_CALLBACK (configure_event), NULL);
	//  expose event is actually a redraw signal after redraw requirement is triger  (OnDraw)
	//g_signal_connect (G_OBJECT (ImageView), "expose_event", G_CALLBACK (expose_event), NULL);	    
	//g_signal_connect_swapped (G_OBJECT (MainFrame), "key_press_event", G_CALLBACK (key_press_event), ImageView);     
                        
    return ImageFrame;                
}


GtkWidget* CreateDataView()
{
	  GtkWidget* sw;
	  GtkWidget *DataView;
      GtkTreeModel *model = NULL;
	  GtkTreeViewColumn *column;
	  GtkCellRenderer *cell_renderer;
	  	  
	  sw = gtk_scrolled_window_new (NULL, NULL);
      gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (sw),
                                      GTK_POLICY_NEVER,
                                      GTK_POLICY_AUTOMATIC);
    
      //model = create_model ();
      
      DataView = gtk_tree_view_new_with_model (model);

      //g_object_unref (model);

      gtk_container_add (GTK_CONTAINER (sw), DataView);
      
      column = gtk_tree_view_column_new ();
      gtk_tree_view_column_set_title (column, "Macro");

      cell_renderer = gtk_cell_renderer_text_new ();
      gtk_tree_view_column_pack_start (column,
				       cell_renderer,
				       FALSE);
      gtk_tree_view_column_set_attributes (column, cell_renderer,
					   "stock_id", 1, NULL);
      cell_renderer = gtk_cell_renderer_text_new ();
      gtk_tree_view_column_pack_start (column,
				       cell_renderer,
				       TRUE);
      gtk_tree_view_column_set_cell_data_func (column, cell_renderer,
					       NULL, NULL, NULL);

      gtk_tree_view_append_column (GTK_TREE_VIEW (DataView),
				   column);

      cell_renderer = gtk_cell_renderer_text_new ();
      gtk_tree_view_insert_column_with_data_func (GTK_TREE_VIEW (DataView),
                                                  -1,
                                                  "Label",
                                                  cell_renderer,
                                                  NULL,
                                                  NULL,
                                                  NULL);

      cell_renderer = gtk_cell_renderer_text_new ();
      gtk_tree_view_insert_column_with_data_func (GTK_TREE_VIEW (DataView),
                                                  -1,
                                                  "Accel",
                                                  cell_renderer,
                                                  NULL,
                                                  NULL,
                                                  NULL);

      cell_renderer = gtk_cell_renderer_text_new ();
      gtk_tree_view_insert_column_with_data_func (GTK_TREE_VIEW (DataView),
                                                  -1,
                                                  "ID",
                                                  cell_renderer,
                                                  NULL,
                                                  NULL,
                                                  NULL);
      
      gtk_widget_set_size_request (sw, 600, 200);
	  return sw;
}
//************************************
// Create Left stock bar window
//************************************
GtkWidget* CreateLeftStockBar()
{
	GtkWidget* notebook;
	GtkWidget* label;
	GtkWidget* frame;

	notebook = gtk_notebook_new ();
    gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_TOP);
    gtk_widget_set_size_request(notebook, 300, 500);
    gtk_widget_show (notebook);
    
    /* add some pages into the notebook */
	
	     frame = gtk_frame_new ("Hardware");
	     gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
	     gtk_widget_show (frame);
	
	     label = gtk_label_new ("Hardware");
	     gtk_container_add (GTK_CONTAINER (frame), label);
	     gtk_widget_show (label);
	
	     label = gtk_label_new ( "Hardware");
	     gtk_notebook_append_page (GTK_NOTEBOOK (notebook), frame, label);
	     
	     frame = gtk_frame_new ("Bean");
	     gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
	     gtk_widget_show (frame);
	     label = gtk_label_new ("Bean");
	     gtk_container_add (GTK_CONTAINER (frame), label);
	     gtk_widget_show (label);
	     label = gtk_label_new ("Bean");
	     gtk_notebook_append_page (GTK_NOTEBOOK (notebook), frame, label);	     	
	     frame = gtk_frame_new ("Specimen");
	     gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
	     gtk_widget_show (frame);
	     label = gtk_label_new ("Specimen");
	     gtk_container_add (GTK_CONTAINER (frame), label);
	     gtk_widget_show (label);
	     label = gtk_label_new ("Specimen");
	     gtk_notebook_append_page (GTK_NOTEBOOK (notebook), frame, label);
	     
 
    return notebook;	
}

static GtkActionEntry entries[] = {
  { "FileMenu", NULL, "_File" },               /* name, stock id, label */
  { "PreferencesMenu", NULL, "_Preferences" }, /* name, stock id, label */
  { "ColorMenu", NULL, "_Color"  },            /* name, stock id, label */
  { "ShapeMenu", NULL, "_Shape" },             /* name, stock id, label */
  { "HelpMenu", NULL, "_Help" },               /* name, stock id, label */
  { "New", GTK_STOCK_NEW,                      /* name, stock id */
    "_New", "<control>N",                      /* label, accelerator */
    "Create a new file",                       /* tooltip */ 
    G_CALLBACK (activate_action) },      
  { "Open", GTK_STOCK_OPEN,                    /* name, stock id */
    "_Open","<control>O",                      /* label, accelerator */     
    "Open a file",                             /* tooltip */
    G_CALLBACK (activate_action) }, 
  { "Save", GTK_STOCK_SAVE,                    /* name, stock id */
    "_Save","<control>S",                      /* label, accelerator */     
    "Save current file",                       /* tooltip */
    G_CALLBACK (activate_action) },
  { "SaveAs", GTK_STOCK_SAVE,                  /* name, stock id */
    "Save _As...", NULL,                       /* label, accelerator */     
    "Save to a file",                          /* tooltip */
    G_CALLBACK (activate_action) },
  { "Quit", GTK_STOCK_QUIT,                    /* name, stock id */
    "_Quit", "<control>Q",                     /* label, accelerator */     
    "Quit",                                    /* tooltip */
    G_CALLBACK (activate_action) },
  { "About", NULL,                             /* name, stock id */
    "_About", "<control>A",                    /* label, accelerator */     
    "About",                                   /* tooltip */  
    G_CALLBACK (activate_action) },
  { "Logo", "demo-gtk-logo",                   /* name, stock id */
     NULL, NULL,                               /* label, accelerator */     
    "GTK+",                                    /* tooltip */
    G_CALLBACK (About_Message) },
};
static guint n_entries = G_N_ELEMENTS (entries);


static GtkToggleActionEntry toggle_entries[] = {
  { "Bold", GTK_STOCK_BOLD,                    /* name, stock id */
     "_Bold", "<control>B",                    /* label, accelerator */     
    "Bold",                                    /* tooltip */
    G_CALLBACK (activate_action), 
    TRUE },                                    /* is_active */
};
static guint n_toggle_entries = G_N_ELEMENTS (toggle_entries);

enum {
  COLOR_RED,
  COLOR_GREEN,
  COLOR_BLUE
};

static GtkRadioActionEntry color_entries[] = {
  { "Red", NULL,                               /* name, stock id */
    "_Red", "<control>R",                      /* label, accelerator */     
    "Blood", COLOR_RED },                      /* tooltip, value */
  { "Green", NULL,                             /* name, stock id */
    "_Green", "<control>G",                    /* label, accelerator */     
    "Grass", COLOR_GREEN },                    /* tooltip, value */
  { "Blue", NULL,                              /* name, stock id */
    "_Blue", "<control>B",                     /* label, accelerator */     
    "Sky", COLOR_BLUE },                       /* tooltip, value */
};
static guint n_color_entries = G_N_ELEMENTS (color_entries);

enum {
  SHAPE_SQUARE,
  SHAPE_RECTANGLE,
  SHAPE_OVAL
};

static GtkRadioActionEntry shape_entries[] = {
  { "Square", NULL,                            /* name, stock id */
    "_Square", "<control>S",                   /* label, accelerator */     
    "Square",  SHAPE_SQUARE },                 /* tooltip, value */
  { "Rectangle", NULL,                         /* name, stock id */
    "_Rectangle", "<control>R",                /* label, accelerator */     
    "Rectangle", SHAPE_RECTANGLE },            /* tooltip, value */
  { "Oval", NULL,                              /* name, stock id */
    "_Oval", "<control>O",                     /* label, accelerator */     
    "Egg", SHAPE_OVAL },                       /* tooltip, value */  
};
static guint n_shape_entries = G_N_ELEMENTS (shape_entries);

static const gchar *ui_info = 
"<ui>"
"  <menubar name='MenuBar'>"
"    <menu action='FileMenu'>"
"      <menuitem action='New'/>"
"      <menuitem action='Open'/>"
"      <menuitem action='Save'/>"
"      <menuitem action='SaveAs'/>"
"      <separator/>"
"      <menuitem action='Quit'/>"
"    </menu>"
"    <menu action='PreferencesMenu'>"
"      <menu action='ColorMenu'>"
"	       <menuitem action='Red'/>"
"	       <menuitem action='Green'/>"
"	       <menuitem action='Blue'/>"
"      </menu>"
"      <menu action='ShapeMenu'>"
"        <menuitem action='Square'/>"
"        <menuitem action='Rectangle'/>"
"        <menuitem action='Oval'/>"
"      </menu>"
"      <menuitem action='Bold'/>"
"    </menu>"
"    <menu action='HelpMenu'>"
"      <menuitem action='About'/>"
"    </menu>"
"  </menubar>"
"  <toolbar  name='ToolBar'>"
"    <toolitem action='Open'/>"
"    <toolitem action='Quit'/>"
"    <separator action='Sep1'/>"
"    <toolitem action='Logo'/>"
"  </toolbar>"
"</ui>";





void InitUserInterface()
{
    GtkWidget*           WND;
    GtkUIManager*         ui;
    GtkActionGroup*  actions;
    GtkWidget*       MainBox;
    GtkWidget*          hBox;
    GtkWidget*          vBox;
    GtkWidget*       LeftBar;
    GtkWidget*  GridDataView;
    GtkWidget* GridDataFrame;
    GtkWidget*    ImageFrame;
    
    GError *error = NULL;
    // init icons
    register_stock_icons ();	
    // main window
    WND = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (WND , 800 , 600) ;
    gtk_window_set_title (GTK_WINDOW(WND), "UltraSonic");
    gtk_widget_modify_bg (WND , GTK_STATE_NORMAL, &color_green ) ;
    gtk_window_set_icon_from_file (GTK_WINDOW(WND),"res/OPMS.ico",NULL) ;	
    /* Get automatically redrawn if any of their children changed allocation. */
    gtk_container_set_reallocate_redraws (GTK_CONTAINER (WND), TRUE);
    gtk_window_maximize (GTK_WINDOW(WND)) ;
    //gtk_window_fullscreen (GTK_WINDOW(WND)) ;
    //gtk_window_set_decorated (GTK_WINDOW(WND) , FALSE) ;
    g_signal_connect (G_OBJECT(WND), "destroy", G_CALLBACK(AppExit) , NULL) ;
    
   
    // Actions Intialize
    actions = gtk_action_group_new ("Actions");
    gtk_action_group_add_actions (actions, entries, n_entries, NULL);
    gtk_action_group_add_toggle_actions (actions, 
					   toggle_entries, n_toggle_entries, 
					   NULL);
    gtk_action_group_add_radio_actions (actions, 
					  color_entries, n_color_entries, 
					  COLOR_RED,
					  G_CALLBACK (activate_radio_action), 
					  NULL);
    gtk_action_group_add_radio_actions (actions, 
					  shape_entries, n_shape_entries, 
					  SHAPE_OVAL,
					  G_CALLBACK (activate_radio_action), 
					  NULL);
    // ui manager
    ui = gtk_ui_manager_new ();
    gtk_ui_manager_insert_action_group (ui, actions, 0);
    g_object_unref (actions);
    gtk_window_add_accel_group (GTK_WINDOW (WND), 
				  gtk_ui_manager_get_accel_group (ui));
   
    gtk_container_set_border_width (GTK_CONTAINER (WND), 0);
   
    if (!gtk_ui_manager_add_ui_from_string (ui, ui_info, -1, &error))
	{
	  g_message ("building menus failed: %s", error->message);
	  g_error_free (error);
	}

    MainBox = gtk_vbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (WND), MainBox);
      
    gtk_box_pack_start (GTK_BOX (MainBox),
			  gtk_ui_manager_get_widget (ui, "/MenuBar"),
			  FALSE,FALSE,0);
	gtk_box_pack_start (GTK_BOX (MainBox),
			  gtk_ui_manager_get_widget (ui, "/ToolBar"),
			  FALSE,FALSE,0);
		  
    //*******Create left stock bar and main image view
	hBox = gtk_hbox_new(FALSE, 1);
	gtk_box_pack_start (GTK_BOX(MainBox),hBox,TRUE,TRUE,0);
	LeftBar = CreateLeftStockBar();
	gtk_box_pack_start (GTK_BOX(hBox),LeftBar,FALSE,FALSE,0);
	vBox = gtk_vbox_new(FALSE,3);
	gtk_box_pack_start (GTK_BOX(hBox),vBox, TRUE,TRUE,0);
	
	gtk_container_set_border_width (GTK_CONTAINER (vBox), 2);
    ImageFrame = OpenGLView();
    GridDataFrame = gtk_frame_new (NULL);
   	gtk_frame_set_shadow_type (GTK_FRAME(GridDataFrame),GTK_SHADOW_IN);
    gtk_box_pack_start (GTK_BOX(vBox), ImageFrame, TRUE,TRUE,0);
	gtk_box_pack_start (GTK_BOX(vBox), GridDataFrame, FALSE,FALSE,0);
	GridDataView = CreateDataView();
	gtk_container_add(GTK_CONTAINER(GridDataFrame), GridDataView);	
	//******************************************************************
	
   
    p_ui->MainWnd = WND ;
    p_ui->ui  =  ui;
    p_ui->actions = actions;
    p_ui->MainBox = MainBox;
    p_ui->hBox    = hBox;
    p_ui->vBox    = vBox;
    p_ui->LeftBar = LeftBar ;
    p_ui->GridDataView = GridDataFrame;
    p_ui->ImageFrame= ImageFrame;
    p_ui->GridDataFrame = GridDataFrame;
    

    gtk_widget_show_all(WND);
}
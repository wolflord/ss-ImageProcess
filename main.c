// WolfLord
// ultra sonic
// 2011/10/30

#include "project.h"

UI ui;
UI_P p_ui;

int ReadSettingFiles()
{
    int ret ;
    ret = read_parameter_file(".CONFIG" , &(p_ui->para));
    return ret ;
}

int SaveSettingFiles()
{
    int ret ;
    ret = write_parameter_file(".CONFIG" , &(p_ui->para));
    return ret ;
}

int InitParameters()
{
    PARA tmp =
    {
		.probe =
		{
			.Dimension   =  0     ,
			.RT_Model    =  0     ,
			.T_VelocityModel  =  0,
			.R_VelocityModel  =  0,
			/*transmitter*/
			.transmitter    =
			{
				.pb_skew_angle  =  0   ,
				.Frequency      =  5000,
				.pri_element_num=  32  ,        // primary axis element num
				.sec_element_num=   0  ,        // second  axis element num
				.pri_axis_pitch =   5  ,
				.sec_axis_pitch =   0  ,
				.pri_ele_size   =   2  ,
				.sec_ele_size   =  20  ,
			},
			/*receiver*/
			.receiver     =
			{
				.pb_skew_angle  =  0   ,
				.Frequency      =  5000,
				.pri_element_num=  32  ,        // primary axis element num
				.sec_element_num=   0  ,        // second  axis element num
				.pri_axis_pitch =   5  ,
				.sec_axis_pitch =   0  ,
				.pri_ele_size   =   2  ,
				.sec_ele_size   =  20  ,
			},
			.name  = "NULL"            ,
		},
		.wedge =
		{
			.WedgeAngle = 36.0,
			.RoofAngle  = 0.0 ,
			.VelocityLong= 3230,
			.VelocityVel = 2330,
			.Density     = 3000,
			.FirstElementHeight = 7.8,
			.FirstAxisOffset    = 12 ,
			.SecondAxisOffset   =  5 ,
			.FirstAxisReference =  20,
			.SecondAxisReference=  15,
			.Length =  80,
			.Width  =  30,
			.Height =  50,
			.RT_Distance = 0,
			.name  = "NULL",
		}
    };
#if 0
    WEDGE tmpW =
    {
	.WedgeAngle = 36.0,
	.RoofAngle  = 0.0 ,
	.VelocityLong= 3230,
	.VelocityVel = 2330,
	.Density     = 3000,
	.FirstElementHeight = 7.8,
	.FirstAxisOffset    = 12 ,
	.SecondAxisOffset   =  5 ,
	.FirstAxisReference =  20,
	.SecondAxisReference=  15,
	.Length =  80,
	.Width  =  30,
	.Height =  50,
	.RT_Distance = 0,
	.name  = "NULL",
    };

    PROBE tmpP =
    {
	.Dimension   =  0     ,
	.RT_Model    =  0     ,
	.T_VelocityModel  =  0,
	.R_VelocityModel  =  0,
	/*transmitter*/
	.transmitter    =
	{
	    .pb_skew_angle  =  0   ,
	    .Frequency      =  5000,
	    .pri_element_num=  32  ,        // primary axis element num
	    .sec_element_num=   0  ,        // second  axis element num
	    .pri_axis_pitch =   5  ,
	    .sec_axis_pitch =   0  ,
	    .pri_ele_size   =   2  ,
	    .sec_ele_size   =  20  ,
	},
	/*receiver*/
	.receiver     =
	{
	    .pb_skew_angle  =  0   ,
	    .Frequency      =  5000,
	    .pri_element_num=  32  ,        // primary axis element num
	    .sec_element_num=   0  ,        // second  axis element num
	    .pri_axis_pitch =   5  ,
	    .sec_axis_pitch =   0  ,
	    .pri_ele_size   =   2  ,
	    .sec_ele_size   =  20  ,
	},
	.name  = "NULL"            ,
    };
    memcpy (&p_ui->para.probe , &tmpP , sizeof(PROBE)) ;
    memcpy (&p_ui->para.wedge , &tmpW , sizeof(WEDGE)) ;
#endif
    memcpy (&p_ui->para , &tmp , sizeof(PARA) ) ;
    return 0;
}


int main(int argc, char* argv[])
{
    int ret ;

    p_ui = &ui  ;
    Debug("Read Setting Files") ;
    ret = ReadSettingFiles()    ;

    if(ret)
    {
		Debug("Initialize Parameters!") ;
		InitParameters() ;
    }
    /* Init Gtk. */
    g_thread_init(NULL);
	gdk_threads_init();
    gtk_init( &argc, &argv) ;

    Debug("Initialize the User Interface!") ;
    InitUserInterface();

    // 1 second
    // p_ui->TimerID[0] = g_timeout_add ( 1000, timmer_callback_1s,  NULL );
    // idle thread
    // gtk_idle_add  ( AppIdleFunction, NULL );
    // gtk_idle_add_full( G_PRIORITY_HIGH_IDLE, AppIdleFunction, NULL, NULL, NULL);
    gdk_threads_enter();
	gtk_main();
	gdk_threads_leave();
	
    return 0 ;
}

#ifndef ____DEFINES_H______
#define ____DEFINES_H______

typedef struct ___probe_rt
{
    double   pb_skew_angle;
    double   Frequency;
    int      pri_element_num;        // primary axis element num
    int      sec_element_num;        // second  axis element num
    double   pri_axis_pitch;
    double   sec_axis_pitch;
    double   pri_ele_size;
    double   sec_ele_size;
}RT_PROBE , *RT_PROBE_P  ;

typedef struct Probe
{
    /* 1-D Linear array */
    int      Dimension        ;
    int      RT_Model         ;
    int      T_VelocityModel  ;
    int      R_VelocityModel  ;
    /*transmitter*/
    RT_PROBE  transmitter     ;
    /*receiver*/
    RT_PROBE  receiver        ;
    char     name[20]         ;
} PROBE, *PROBE_P;

typedef struct Wedge
{
    double   WedgeAngle; /* 楔块角 */
    double   RoofAngle ; /* 顶角 */
    double   VelocityLong;/*纵波声速*/
    double   VelocityVel;/*横波声速*/
    int      Density;/* 密度 */
    double   FirstElementHeight;/*第一阵元高度*/
    double   FirstAxisOffset;/*第一主轴阵元偏移*/
    double   SecondAxisOffset;/*第一次轴阵元偏移*/
    double   FirstAxisReference;/*主轴楔块参考位置*/
    double   SecondAxisReference;/*次轴楔块参考位置*/
    double   Length;/*楔块长度*/
    double   Width;/*楔块宽度*/
    double   Height;/*楔块高度*/
    double   RT_Distance;
    char     name[50];
}WEDGE, *WEDGE_P;

typedef struct Parameters
{
    PROBE probe ;
    WEDGE wedge ;
}PARA, *PARA_P;



#endif

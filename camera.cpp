#include "camera.h"
void Camera::passive_motion(int x,int y)
{
    /* two variables to store X and Y coordinates, as observed from the center
      of the window
    */
    int dev_x,dev_y;
    dev_x = (width/2)-x;
    dev_y = (height/2)-y;

    /* apply the changes to pitch and yaw*/
    yaw+=(float)dev_x/10.0;
    pitch+=(float)dev_y/10.0;
}
Camera::Camera(int w,int h):width(w),height(h){

	motion = Motion{false,false,false,false};
}
void Camera::camera(void)
{

    if(motion.Forward)
    {
        camX += cos((yaw+90)*TO_RADIANS)/5.0;
        camZ -= sin((yaw+90)*TO_RADIANS)/5.0;
    }
    if(motion.Backward)
    {
        camX += cos((yaw+90+180)*TO_RADIANS)/5.0;
        camZ -= sin((yaw+90+180)*TO_RADIANS)/5.0;
    }
    if(motion.Left)
    {
        camX += cos((yaw+90+90)*TO_RADIANS)/5.0;
        camZ -= sin((yaw+90+90)*TO_RADIANS)/5.0;
    }
    if(motion.Right)
    {
        camX += cos((yaw+90-90)*TO_RADIANS)/5.0;
        camZ -= sin((yaw+90-90)*TO_RADIANS)/5.0;
    }

    /*limit the values of pitch
      between -60 and 70
    */
    if(pitch>=70)
        pitch = 70;
    if(pitch<=-60)
        pitch=-60;

    glRotatef(-pitch,1.0,0.0,0.0); // Along X axis
    glRotatef(-yaw,0.0,1.0,0.0);    //Along Y axis

    glTranslatef(-camX,0.0,-camZ);
}


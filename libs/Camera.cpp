#include "Camera.h"


Camera::Camera(){

        pos_x=500.0;
        pos_y=500.0;
        pos_z=5.0;
        look_x=0.0;
        look_y=0.0;
        look_z=0.0;
        speed=3.0;
        sensibilidade =0.004;
        last_x=prev_ww*razaoAspecto/2;
        last_y=prev_wh/2;
        fi=-89.9;
        theta=0.0;

}

void Camera::atualiza_camera(){


    //primeiramente atualizar a look at baseada no mouse
    //que tem um vetor de variação em relação ao centro da tela
    //usaremos coordenadas polares angulo theta e fi

    float offset_x = (xMouse - last_x)*sensibilidade;
    float offset_y = (yMouse - last_y)*sensibilidade;
    last_x = xMouse;
    last_y = yMouse;

    theta+=offset_x;
    fi-=offset_y;

    if(fi>89)
        fi = 89;
    if(fi < -89)
        fi = -89;

    look_x = cos(theta)*cos(fi);
    look_y = sin(fi);
    look_z = sin(theta)*cos(fi);
    

    pos_x +=(keyboard.w-keyboard.s)*speed*look_x +(keyboard.d-keyboard.a)*speed*sin(theta)*cos(fi); // + vetor normal a direta dele
    pos_y +=(keyboard.w-keyboard.s)*speed*look_y ; // + vetor normal a direta dele
    pos_z +=(keyboard.w-keyboard.s)*speed*look_z +(keyboard.d-keyboard.a)*speed*cos(theta)*cos(fi); // + vetor normal a direta dele (keyboard.d-keyboard.a)*speed


}
void Camera::lookAt_camera(){
    //printf("At pos(x=%0.1f,y=%0.1f,z=%0.1f) lookat(x=%0.1f,y=%0.1f,z=%0.1f) \n",pos_x,pos_y,pos_z,look_x,look_y,look_z);
    gluLookAt(pos_x,pos_y,pos_z,
              look_x+pos_x,look_y+pos_y, look_z+pos_z,
              0, 1, 0);
}
#ifndef __CAMERA__
#define __CAMERA__
#include "callback.h"
#include <cmath>

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

class Camera{


    protected:
        float pos_x;
        float pos_y;
        float pos_z;
        float look_x;
        float look_y;
        float look_z;
        float speed;
        float sensibilidade;
        int last_x;
        int last_y;
        float theta;
        float fi;


    public:
        Camera();
        void atualiza_camera();
        void lookAt_camera();


};




#endif
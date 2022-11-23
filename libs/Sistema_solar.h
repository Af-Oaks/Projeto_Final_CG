#ifndef __SISTEMASOL__
#define __SISTEMASOL__

#include "Sol.h"
#include "Astros.h"
#include "SOIL.h"
#include "callback.h"
#include "Camera.h"

class Sistema_solar
{ 
    private:
        //não contem o sol dentro da listas dos astros
        std::vector<std::shared_ptr<Astros>> planetas;
        std::shared_ptr<Sol> sol;
        std::shared_ptr<Camera>camera;
        float time;
        GLint space_texture;
        GLuint n_callist;
        //0=sol,1=mercu,2=venus,3=terra,4=mart,5=jupit,6=saturn,7=uranus,8=neutuno,9=moon,10=lua1,11=lua2;
        std::vector<std::pair<std::string,GLint>> vec_texture;
        GLfloat raio_sistema;

    public:
        //construtor
        Sistema_solar();

        //metodos
        void carregar_texture();
        void atualiza_sistema();
        void desenhar_sistema();
        void add_planeta(const char * nome);
        void criar_sol(const char * nome);

};

//inspirado no codigo do coutinho KEKW
void solidSphere_inside(int radius, int stacks, int columns);
//KEKW debug do coutinho
// Escreve as informações variáveis na tela nessa ordem:ambiente,difusa,especular,shine
void informacoesTela(float m, float d, float e,float s);
void escreveTextoNaTela(void *font, char *string);
void floatParaString(char * destStr, int precision, float val);


#endif
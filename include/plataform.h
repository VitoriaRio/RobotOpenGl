#include <GL/glut.h>
class Plataform{
    public:
        Plataform();    
		void draw(GLuint texture);

    private:
		void drawring();
		void drawplataform(GLuint texture);
};

#include <GL/glut.h>
class Robot{
    public:
        Robot();    
		void draw(GLuint head);
		void setDirection(int direction);
		void setPositionX(double x);
		void setPositionY(double y);
		double getPositionY();
		double getPositionX();
		void changeArm();
		void setAlpha(double angle);
		void setBeta(double angle);	
		void spinHands();
		void pick();
    private:
    	int delta;
    	int theta;
		double alphaR;
		double alphaL;
		double betaR;
		double betaL;
		int arm;
		double maxAlpha;
		double minAlpha;
		double maxBeta;
		double minBeta;
		double	pos_x;
		double pos_y;
		int current_direction;
		void drawbody();
		void drawhead( GLuint texture);
		void drawarm(int arm, double alpha, double beta);
	
};

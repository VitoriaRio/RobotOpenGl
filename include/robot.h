class Robot{
    public:
        Robot();    
		void draw();
		void setDirection(int direction);
		void setPositionX(double x);
		void setPositionY(double y);
    private:
		double current_alpha;
		double	pos_x;
		double pos_y;
		int current_direction;
        void drawplataform();
		void drawbody();
		void drawhead();
		void drawarm(int arm);
	
};

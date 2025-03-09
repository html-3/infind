class Ball {
public:
	double radius;
	double pos_x;
	double pos_y;
	double vel_x;
	double vel_y;
	double acc_x;
	double acc_y;

	double bounce = 1.0;

	unsigned char red;
	unsigned char blue;
	unsigned char green;

	void setRadius(double r);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setInitialState(double p_x, double p_y, double v_x, double v_y);
	void updateState();
	void render();
	void worldCollision(double world_height, double world_width);
	void worldGravity(double world_gravity);
};
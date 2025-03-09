class Player {
public:
	double radius;
	double pos_x;
	double pos_y;
	double vel_x;
	double vel_y;
	double acc_x;
	double acc_y;

	double bounce = 0.5;

	unsigned char red;
	unsigned char blue;
	unsigned char green;

	void setRadius(double r);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void updateState();
	void render();
	void movement(double a_x, double a_y);
	void worldCollision(double world_height, double world_width);
	void worldGravity(double world_gravity);
};
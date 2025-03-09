class World {
public:
	float height;
	float width;
	float gravity;
	unsigned char red;
	unsigned char blue;
	unsigned char green;

	void render();
	void setSize(float h, float w);
	void setGravity(float g);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
		
};
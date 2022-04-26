class Player
{
public:
	int x, y;
	Player()
	{
		x = 20;
		y = 7;
	}
	~Player()
	{

	}

	void isKeyPressed()
	{
		y = 5;
	}

	void isKeyUnpressed()
	{
		y = 7;
	}

};
class Monster
{
public:
	int x, y;
	Monster()
	{
		x = 50;
		y = 7;
	}
	~Monster()
	{

	}
	void MMove()
	{
		x--;
	}
};

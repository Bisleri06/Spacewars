class pos
{
 public:
 	int col,row;
	
	pos():col(0),row(0)
 	{}
 	
 	pos(int a,int b):col(a),row(b)
 	{}
 	
 	void down()
 	{
 		row++;
 	}
};



class obstacle
{
 private:
	bool created;
	window &screen;
 public:
	pos coord;
 	obstacle(window &s):screen(s)
 	{
 		created=true;
 		int i;
 		i=random()%79;
 		coord.col=i;
 		coord.row=0;
 		screen.change(coord.row,coord.col,STAR);
 	}

 	bool shift()
 	{
 		screen.change(coord.row,coord.col," ");
 		if(coord.row==23)
 		{
 			return false;
 		}
 		coord.down();
 		screen.change(coord.row,coord.col,STAR);
 		return true;
 	}
};



class ship
{
 private:
 	pos coord;
 	window &screen;
 public:
	int points;	 
	ship(window &s):screen(s)
	{
		coord.row=22;
		coord.col=39;
		screen.change(coord.row,coord.col,"^");
	}
	
	bool ishit(obstacle *obs)
	{
		 if((obs->coord.row==coord.row)&&(obs->coord.col==coord.col))
			return true;
		 else
			return false;
	}

	void left()
	{
		if(coord.col==0)
	 		return;

		screen.change(coord.row,coord.col," ");
		screen.change(coord.row+1,coord.col," ");
		coord.col--;
		screen.change(coord.row,coord.col,"^");
		screen.change(coord.row+1,coord.col,"|");

	}

	void right()
	{
		if(coord.col==79)
	 		return;

	 	screen.change(coord.row,coord.col," ");
	 	screen.change(coord.row+1,coord.col," ");
		coord.col++;
		screen.change(coord.row,coord.col,"^");
		screen.change(coord.row+1,coord.col,"|");
	}

	void redraw()
	{
		screen.change(coord.row,coord.col,"^");
		screen.change(coord.row+1,coord.col,"|");
	}
};
namespace worker
{


 void createnew(int outer)
 {
	for(int i=0;i<MAX;i++)
		obs[outer][i]=new obstacle(scr);
 }


 void clearnew(int outer)
 {
	for(int i=0;i<MAX;i++)
	{
		obs[outer][i]->shift();
		delete obs[outer][i];
		obs[outer][i]==nullptr;
	}
 }


 void cleanup()
 {
 	for(int i=0;i<=22;i++)
 	{
 		for(int j=0;j<MAX;j++)
 		{
 			if(obs[i][j]!=nullptr)
 				delete obs[i][j];
 		}
 	}
 	system("reset");
 	cout<<"GAME OVER"<<endl;
 	cout<<"Score: "<<::points<<endl;
 	exit(1);
 }


 void shifter(int outer)
 {
  bool a;
  for(int j=0;j<MAX;j++)
  {
  	a=obs[outer][j]->shift();
    if(!a)
    	return;
    if(spaceship.ishit(obs[outer][j]))
    {
    	cleanup();
    }
  }
 }

void moveship(ship *spaceship)
{
  scr.print();
    move=getch_(0);
    if(move=='d')
      spaceship->right();
    else if(move=='a')
      spaceship->left();
    else
      (spaceship)->redraw();
}
}
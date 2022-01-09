#include<iostream>
#include<cstring>
#include<cstdlib>
#include<thread>
#include<chrono>
using namespace std;

#define STAR "*"		//settings obstacle
#define COLOR 7			//settings color
#define MAX 25			//settings difficulty

#include "color.h"
#include "pixels.h"
#include "obj.h"

obstacle *obs[23][MAX];
window scr(" ");
ship spaceship(scr);
int points=0;

#include "worker.h"


int main()
{
 char move;
 cout<<color(COLOR);
 
 for(int i=0;i<=22;i++)
 {
 	worker::createnew(i);
 	for(int j=0;j<i;j++)
    { 
     worker::shifter(j);
  	}
    scr.print();
    move=getch_(0);
    if(move=='d')
    	spaceship.right();
    else if(move=='a')
    	spaceship.left();
    else
    	spaceship.redraw();
    cout<<'\a'<<endl;
 }

 points+=1;

 while(1)
 {
  
  for(int i=0;i<=22;i++)
  {
  	points++;
    worker::clearnew(i);
 	worker::createnew(i);
 	for(int j=0;j<=22;j++)
    { 
     worker::shifter(j);
  	}
  	spaceship.redraw();
    thread t1(worker::moveship,&spaceship);
    t1.detach();
    this_thread::sleep_for(chrono::seconds(1));
    cout<<'\a'<<endl;
  }
 }
}

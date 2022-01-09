#include<iostream>
#include<istream>
using namespace std;
class color
{
 private:
  int num;
 public:
	color(int var)
	{
	 num=var;
	}
	friend ostream & operator <<(ostream &o,color r)
	{
	 switch(r.num)
	 {
	  case 1:
	   o<<"\033[0;37m"; //WHITE
	   break;
	  case 2:
	   o<<"\033[0;35m"; //MAGENTA
	   break;
	  case 3:
	   o<<"\033[1;37m"; //WHITE BOLD
	   break;
	  case 4:
	   o<<"\033[1;31m"; //RED BOLD
	   break;
	  case 5:
	   o<<"\033[1;32m"; //GREEN BOLD
	   break;
	  case 6:
	   o<<"\033[1;33m"; //YELLOW BOLD
	   break;
	  case 7:
	   o<<"\033[0;36m"; //DARK BLUE
	   break;
	  case 8:
	   o<<"\033[0;33m"; //CAFE BROWN
	   break;
	  case 9:
	   o<<"\033[1;34m"; //BLUE BOLD
	   break;
	  case 10:
	   o<<"\e[0m";      //DEFAULT
	   break;
	 }
	 return o;
	}
};

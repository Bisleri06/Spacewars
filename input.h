#ifndef INC
#define INC
#include <termios.h>
#include <stdio.h>

static struct termios old, fresh;

/* Initialize fresh terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  fresh = old; /* make fresh settings same as old settings */
  fresh.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      fresh.c_lflag |= ECHO; /* set echo mode */
  } else {
      fresh.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &fresh); /* use these fresh terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
#endif
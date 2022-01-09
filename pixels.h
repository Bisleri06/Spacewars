class window
{
 private:
  char str[1921];
  int pos;
 public:
 
 window()
 {
  memset(str,0x00,1920);
 }
 
 window(char *s)
 {
  str[1920]=0;
  memset(str,*s,1920);
 }
 
 
 void print()
 {
  cout<<str;
 }
 
 
 void clear()
 {
  memset(str,0,1920);
 }
 
 void change(const char *c)
 {
  memset(str,*c,1920);
 }
 
 void change(int row,int col,const char *c)
 {
  pos=80*row+col;				//80x+y where x is row and y is column.
  str[pos]=*c;
 }
 
 
 
 void change(void (*callback)(int,int,char&))
 {
  int i,j;
  char c;
  
  for(i=0;i<24;i++)
  {
   for(j=0;j<80;j++)
   {
    callback(i,j,c);
    if(c!='\0')
    {
     pos=80*i+j;
     str[pos]=c;
 }}}}
};
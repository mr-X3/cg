
#include<graphics.h>
#include<iostream>
using namespace std;

class pt //base class
{
   protected: int xco,yco,color;
   public:
          pt()
          {
            xco=0;yco=0;color=15;
          }

          void setco(int x,int y)
          {
            xco=x;
            yco=y;
          }

          void setcolor(int c)
          {
            color=c;
          }

          void draw()
          {
            putpixel(xco,yco,color);
          }

};

class dline: public pt //derived class
{
    private: int x2,y2;
    public:
           dline():pt()
           {
             x2=0,y2=0;
           }

           void setline(int x, int y, int xx, int yy)
           {
             pt::setco(x,y);
             x2=xx;
             y2=yy;
           }


      
      void drawl(int colour) //DDA Line
      {
          float x,y,dx,dy,len;
          int i;
          int xmax,xmid,ymax,ymid;
          xmax = getmaxx();
          ymax = getmaxy();
          xmid = xmax /2;
          ymid = ymax /2;
          pt::setcolor(colour);
           
          
          //step2 
          dx=abs(x2-xco);    
          dy=abs(y2-yco);
cout<<dx<<"\t"<<dy<<"\n";
          //step3
          if(dx >= dy)
          {
             len=dx;
          }
          else
          {
             len=dy;
          }

          //step4
          dx=(x2-xco)/len;
          dy=(y2-yco)/len;
cout<<dx<<"\t"<<dy<<"\n";
          //step5
 cout<<"\n"<<xco<<"\t"<<yco<<"\n";         
          x = xco + 0.5;
          y = yco + 0.5;
 cout<<"\n"<<x<<"\t"<<y<<"\n";         
          pt::setco(x,y);
          pt::draw();
          cout<<"\t"<<1;
          cout<<"\t"<<x-xmid;
          cout<<"\t\t"<<ymid-y<<endl;

          //step6
          i=1;
          while(i<=len)
          {
               x = x + dx;
               y = y + dy;
               i = i + 1;
               pt::setco(x,y);
               pt::draw();               
               cout<<"\t"<<i;
               cout<<"\t"<<x;
               cout<<"\t\t"<<y<<endl;
         }

     
     }//function closed

};

int main()
{
    int gd=DETECT,gm=VGAMAX;
    int ch,x1,y1,x2,y2, xmax,ymax,xmid,ymid;
    char a;
    initgraph(&gd,&gm,NULL);
    pt p;
    dline dda;

    xmax = getmaxx();
    ymax = getmaxy();
    xmid = xmax /2;
    ymid = ymax /2;

    line(xmid,0,xmid,ymax); //Y-Axis
    line(0,ymid,xmax,ymid); //X-Axis 


cout<<xmax<<"\n";
cout<<ymax<<"\n";
cout<<xmid<<"\n";
cout<<ymid<<"\n";
       cout<<"\n.............DDA LINE.............";

                 cout<<"\nEnter the co-ordinates of the endpoints of line Below";
                 cout<<"\nEnter x1: "; cin>>x1;
                 cout<<"Enter y1: "; cin>>y1;
                 cout<<"Enter x2: "; cin>>x2;
                 cout<<"Enter y2: "; cin>>y2;
                 
                 cout<<"\nFollowing Result Table Shows Step-by-Step Processing\n"; 
                 cout<<"\n------------------------------------------------------------------\n";
                 cout<<"\ti\tx\t\ty\n";
                 cout<<"-----------------------------------------------------------------\n";
                 dda.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
                 dda.drawl(15);
        

      

   

   delay(300000);
   closegraph();
   return 0;


}


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

class bline: public pt //derived class
{
    private: int x2,y2;
    public:
           bline():pt()
           {
             x2=0,y2=0;
           }

           void setline(int x, int y, int xx, int yy)
           {
             pt::setco(x,y);
             x2=xx;
             y2=yy;
           }

           void drawl() //Bresenham's Line
           {
             float x,y,dx,dy,e,temp;
             int i,s1,s2,ex;
             int xmax,xmid,ymax,ymid;
             xmax = getmaxx();
             ymax = getmaxy();
             xmid = xmax /2;
             ymid = ymax /2;

             //Step2
             dx=abs(x2-xco);
             dy=abs(y2-yco);

             //Step3
             x=xco;
             y=yco;
             pt::setco(x,y);
             pt::draw();

             //Step4.....sign() function
             if(x2 > xco) 
             {
                s1=1;
             }
             if(x2 < xco)
             {
                s1=-1;
             }
             if(x2 == xco)
             {
                s1=0;
             }

              
             if(y2 > yco)
             {
                s2=1;
             }
             if(y2 < yco)
             {
                s2=-1;
             }
             if(y2 == yco)
             {
                s2=0;
             }
             
             //Step5
             if(dy > dx)
             {
                temp = dx;
                dx = dy;
                dy = temp;

                ex = 1;
             }
             else
             {
                ex=0;
             }

             //Step6
             e=2*dy-dx; //decision variable
             cout<<"\t"<<1;
             cout<<"\t"<<e;
             cout<<"\t"<<x-xmid;
             cout<<"\t"<<ymid-y<<endl;
            
             //Step7
             i=1;
             do
             {
                  while(e>=0)
                  {
                     if(ex==1)
                     {
                        x = x + s1;
                     }
                     else
                     {
                        y = y + s2;
                     }
                     e = e - 2*dx;
                  }
                  if(ex==1)
                  {
                     y = y + s2;
                  }
                  else
                  {
                     x = x + s1;
                  }
     
                  e = e + 2*dy;
                  //cout<<"\tdy==="<<dy<<"And e===<<"<<e;
                  pt::setco(x,y);
                  pt::draw();
                  i = i + 1;
                  cout<<"\t"<<i;
                  cout<<"\t"<<e;
                  cout<<"\t"<<x-xmid;
                  cout<<"\t"<<ymid-y<<endl;
                  
           }while(i<=dx);

      }//funciton closed

	void cal(int x1,int y1,int x3,int y3)
	{
		int xl1,xl2,xl3,xl4,yl1,yl2,yl3,yl4;
		xl1=x1;
		yl1=y1;
		
		xl3=x3;
		yl3=y3;
	
		yl2=yl1;
		xl2=xl3;
		
		yl4=yl3;
		xl4=xl1;
	delay(200);
		setline(xl1,yl1,xl2,yl2);
		drawl();delay(200);
		setline(xl2,yl2,xl3,yl3);
		drawl();delay(200);
		setline(xl3,yl3,xl4,yl4);
		drawl();delay(200);
		setline(xl4,yl4,xl1,yl1);
		drawl();delay(200);

		//rectangle 2
		
		int x5,x6,x7,x8,y5,y6,y7,y8;
		
		x5=xl4;
		y5=(yl1+yl4)/2;
	
		x6=xl3;
		y6=y5;
		
		x7=(xl1+xl2)/2;
		y7=yl2;
		
		x8=x7;
		y8=yl3;
		delay(200);
		setline(x5,y5,x7,y7);
		drawl();
delay(200);
		setline(x7,y7,x6,y6);
		drawl();
delay(200);
		setline(x6,y6,x8,y8);
		drawl();
delay(200);
		setline(x8,y8,x5,y5);
		drawl();
		

		///rectangle 3
		int x9,x12,x10,x11,y9,y10,y11,y12;
		
		x9=(x5+x7)/2;
		y9=(y5+y7)/2;
	
		x10=x9;
		y10=(y5+y8)/2;
		
		x11=(x6+x7)/2;
		y11=y9;
		
		x12=x11;
		y12=y10;
		delay(200);
		setline(x9,y9,x11,y11);
		drawl();delay(200);
		setline(x11,y11,x12,y12);
		drawl();delay(200);
		setline(x12,y12,x10,y10);
		drawl();delay(200);
		setline(x10,y10,x9,y9);
		drawl();
		
			
	}
      	
      
};

int main()
{
    	int gd=DETECT,gm=VGAMAX;
    	int x1,y1,x3,y3, xmax,ymax,xmid,ymid;
   	 char a;
    	initgraph(&gd,&gm,NULL);
    	pt p;
    	bline bb;

    	xmax = getmaxx();
    	ymax = getmaxy();
    	xmid = xmax /2;
    	ymid = ymax /2;

    	line(xmid,0,xmid,ymax); //Y-Axis
    	line(0,ymid,xmax,ymid); //X-Axis 
        
                 cout<<"\nEnter the co-ordinates of the endpoints of line Below\n";
                 cout<<"\nEnter x1: "; cin>>x1;
                 cout<<"\nEnter y1: "; cin>>y1;
                 cout<<"\nEnter x3: "; cin>>x3;
                 cout<<"\nEnter y3: "; cin>>y3;

		bb.cal(x1+xmid,ymid-y1,x3+xmid,ymid-y3);

        

   delay(50000);
   closegraph();
   return 0;


}

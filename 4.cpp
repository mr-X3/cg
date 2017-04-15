

#include<graphics.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

class pixel
{
	protected:
		int x1,y1,color;
	public:
		pixel()
		{
			x1=0;
			y1=0;
			color=15;
		}
		void setpixel(int x0,int y0)
		{
			x1=x0;
			y1=y0;
		}
		void setcolor(int c)
		{
			color=c;
		}

          void draw()
          {
            putpixel(x1,y1,color);
          }
		
};

class dcircle: public pixel
{
		public:int r;
	public:
		dcircle():pixel()
		{
			r=0;
		}
		void setrad(int rad)
		{
			r=rad;
		}
		void drawcircle()
		{
			int d,x,y;
			d=3-(2*r);
			x=0;
			y=r;
			do
			{
				putpixel(x+x1,y1+y,15);
				putpixel(x1+y,y1+x,15);
				putpixel(x1+y,y1-x,15);
				putpixel(x1+x,y1-y,15);
				putpixel(x1-x,y1-y,15);
				putpixel(x1-y,y1-x,15);
				putpixel(x1-y,y1+x,15);
				putpixel(x1-x,y1+y,15);
				if(d<0)
					d=d+(4*x)+6;
				else
				{
					d=d+(4*(x-y))+10;
					y=y-1;
				}
				x=x+1;
			}while(x<y);
		}
};
//line algo
class dline: public pixel //derived class
{
    private: int x2,y2;
    public:
           dline()
           {
             x2=0,y2=0;
           }

           void setline(int x, int y, int xx, int yy)
           {
             pixel::setpixel(x,y);
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
             dx=abs(x2-x1);
             dy=abs(y2-y1);

             //Step3
             x=x1;
             y=y1;
             pixel::setpixel(x,y);
             pixel::draw();

             //Step4.....sign() function
             if(x2 > x1)
             {
                s1=1;
             }
             if(x2 < x1)
             {
                s1=-1;
             }
             if(x2 == x1)
             {
                s1=0;
             }

              
             if(y2 > y1)
             {
                s2=1;
             }
             if(y2 < y1)
             {
                s2=-1;
             }
             if(y2 == y1)
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
                  pixel::setpixel(x,y);
                  pixel::draw();
                  i = i + 1;
                  cout<<"\t"<<i;
                  cout<<"\t"<<e;
                  cout<<"\t"<<x-xmid;
                  cout<<"\t"<<ymid-y<<endl;
                  
           }while(i<=dx);

      }//funciton closed
	   void calculate(int r1,int r2)
 	     {
   		    int x11,x12,x13,y11,y12,y13;
	            float e;
     		    x12=x1;
                    e=(r1+r2)/1.73;
                    x11=x1-e;
                    x13=x1+e;
                    y11=y1+r2;
                    y13=y11;
                    y12=y1-r1;
	            setline(x11,y11,x12,y12);
                    drawl();
        	    setline(x12,y12,x13,y13);
       		    drawl();
		    setline(x11,y11,x13,y13);
		    drawl();
		    delay(80000);
       }
};
int main()
{
	int gd=DETECT,gm=VGAMAX;
	int xco,yco,radius1,radius2;
	int xmax,ymax,xmid,ymid;
	
	initgraph(&gd,&gm,NULL);

	dline dl1;
	dcircle d;
	pixel p;

	cout<<"Enter x & y coordinates:\t";
	cin>>xco;
	cin>>yco;
	cout<<"Enter the 1st radius\t";
	cin>>radius1;
	cout<<"Enter the 2nd radius\t";
	cin>>radius2;
	xmax = getmaxx();
        ymax = getmaxy();
        xmid = xmax /2;
        ymid = ymax /2;
        line(xmid,0,xmid,ymax);
        line(0,ymid,xmax,ymid);
	d.setpixel(xco+xmid,ymid-yco);
	d.setrad(radius1);
	d.drawcircle();
	d.setpixel(xco+xmid,ymid-yco);
	d.setrad(radius2);
	d.drawcircle();
	dl1.setpixel(xco+xmid,ymid-yco);
	dl1.calculate(radius1,radius2);
	delay(10000);
	closegraph();
	return 0;
}


//Write program to implement Cohen Sutherland Hodgman algorithm to clip any polygon. Provide the vertices of the polygon to be clipped and pattern of clipping interactively.

#include<graphics.h>
#include<iostream>
using namespace std;
typedef struct
{
	float x;
	float y;
}pt;
int n;
void top(pt,pt[],pt[]);
void bottom(pt,pt[],pt[]);
void left(pt,pt[],pt[]);
void right(pt,pt[],pt[]);


int main()
{
        //Variable Declarations
        int gd=DETECT,gm=VGAMAX;
        int i,j,xmax,ymax,xmid,ymid;
        pt d,p1,p2,p[20],pi1,pi2,pp[20];

        cout<<"\n Enter cordinates (left,top)";
	cout<<"\n Enter X cordinates :";
	cin>>p1.x;
	cout<<"\n Enter Y cordinates :";
	cin>>p1.y;
	cout<<"\n Enter cordinates (right,bottom)"; 
	cout<<"\n Enter X cordinates :"; 
	cin >>p2.x;
	cout<<"\n Enter Y cordinates :"; 
	cin>>p2.y;

	cout<<"Enter number of vertex=";
	cin>>n;

	for(i=0;i<n;i++)
	{
		cout<<"\n Enter cordinates of vertex :";
		cout<<i+1;
		cout<<"\n Enter X cordinates :";
		cin>>p[i].x;
		cout<<"\n Enter Y cordinates :";
		cin>>p[i].y;
	}
	p[i].x=p[0].x;
	p[i].y=p[0].y;
      
        initgraph(&gd,&gm,NULL);
        xmax = getmaxx();
        ymax = getmaxy();
        xmid = xmax /2;
        ymid = ymax /2;

        line(xmid,0,xmid,ymax); //Y-Axis
        line(0,ymid,xmax,ymid); //X-Axis 
 
        //Draw Original Object      
        for(i=0;i<n-1;i++)
        {
		line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
        }
        line(p[i].x,p[i].y,p[0].x,p[0].y);

        rectangle(p1.x,p1.y,p2.x,p2.y);

        left(p1,p,pp);
        right(p2,p,pp);
        top(p1,p,pp);
        bottom(p2,p,pp);

       cleardevice();
         
        //Draw Original Object      
        for(i=0;i<n-1;i++)
        {
		line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
        }
        line(p[i].x,p[i].y,p[0].x,p[0].y);
      
        rectangle(p1.x,p1.y,p2.x,p2.y);
   
        delay(30000);
        closegraph();
        return 0;
}



void left(pt p1,pt p[20],pt pp[20])
{
	int i,j=0;
       	for(i=0;i<n;i++)
	{
             	if(p[i].x<p1.x && p[i+1].x>=p1.x)
		{
                       	if(p[i+1].x-p[i].x!=0)
			{
			pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p1.x-p[i].x)+p[i].y;
			}
			else
			{	
				pp[j].y=p[i].y;
			}
			pp[j].x=p1.x;
			j++;
			pp[j].x=p[i+1].x;
			pp[j].y=p[i+1].y;
			j++;
		}
		if(p[i].x>p1.x && p[i+1].x>=p1.x)
		{   
			pp[j].y=p[i+1].y;
			pp[j].x=p[i+1].x;
			j++;
		}
		if(p[i].x>p1.x && p[i+1].x<=p1.x)
		{    
			if(p[i+1].x-p[i].x!=0)
			{
				pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p1.x-p[i].x)+p[i].y;
			}
			else
			{
				pp[j].y=p[i].y;
			}
			pp[j].x=p1.x;
			j++;
		}
	}
 
        cout<<"\n\nModified Points at the end of Left Edge:\n";
	for(i=0;i<j;i++)
	{
		p[i].x=pp[i].x;
		p[i].y=pp[i].y;
                cout<<"\np["<<i<<"]: x="<<p[i].x<<" and y="<<p[i].y;
	}
	p[i].x=pp[0].x;
	p[i].y=pp[0].y;
	n=j;		
}

void right(pt p2,pt p[20],pt pp[20])
{
	int i,j=0;
	for(i=0;i<n;i++)
	{
		if(p[i].x>p2.x && p[i+1].x<=p2.x)
		{
                       	if(p[i+1].x-p[i].x!=0)
			{
				pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p2.x-p[i].x)+p[i].y;
			}
			else
			{
				pp[j].y=p[i].y;
			}
			pp[j].x=p2.x;
			j++;
			pp[j].x=p[i+1].x;
			pp[j].y=p[i+1].y;
			j++;
		}
		if(p[i].x<p2.x && p[i+1].x<=p2.x)
		{
                        pp[j].y=p[i+1].y;
			pp[j].x=p[i+1].x;
			j++;
		}
		if(p[i].x<p2.x && p[i+1].x>=p2.x)
		{
                        if(p[i+1].x-p[i].x!=0)
			{
				pp[j].y=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x)*(p2.x-p[i].x)+p[i].y;
			}
			else
			{
				pp[j].y=p[i].y;
			}
			pp[j].x=p2.x;
			j++;
		}
	}

        cout<<"\n\nModified Points at the end of Right Edge:\n";
	for(i=0;i<j;i++)
	{
		p[i].x=pp[i].x;
		p[i].y=pp[i].y;
                cout<<"\np["<<i<<"]: x="<<p[i].x<<" and y="<<p[i].y;
                
	}
	p[i].x=pp[0].x;
	p[i].y=pp[0].y;
	n=j;		
}
void top(pt p1,pt p[20],pt pp[20])
{
	int i,j=0;
	for(i=0;i<n;i++)
	{
              	if(p[i].y<p1.y && p[i+1].y>=p1.y)
		{
                      	if(p[i+1].y-p[i].y!=0)
			{
				pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p1.y-p[i].y)+p[i].x;
				
			}
			else
			{
				pp[j].x=p[i].x;
			}
			pp[j].y=p1.y;
			j++;
			pp[j].x=p[i+1].x;
			pp[j].y=p[i+1].y;
			j++;
		}
		if(p[i].y>p1.y && p[i+1].y>= p1.y)
		{
                      	pp[j].y=p[i+1].y;
			pp[j].x=p[i+1].x;
			j++;
		}
		if(p[i].y>p1.y && p[i+1].y<= p1.y)
		{
                    	if(p[i+1].y-p[i].y!=0)
			{
				pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p1.y-p[i].y)+p[i].x;
			}
			else
			{
				pp[j].x=p[i].x;
			}
			pp[j].y=p1.y;
			j++;
		}
	}

        cout<<"\n\nModified Points at the end of Top Edge:\n";
	for(i=0;i<j;i++)
	{
		p[i].x=pp[i].x;
		p[i].y=pp[i].y;	
                cout<<"\np["<<i<<"]: x="<<p[i].x<<" and y="<<p[i].y;
	}
	p[i].x=pp[0].x;
	p[i].y=pp[0].y;
	n=j;
}

void bottom(pt p2,pt p[20],pt pp[20])
{
	int i,j=0;
	for(i=0;i<n;i++)
	{
		if(p[i].y>p2.y && p[i+1].y <= p2.y)
		{
			if(p[i+1].y-p[i].y!=0)
			{
				pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p2.y-p[i].y)+p[i].x;	
			}
			else
			{
				pp[j].x=p[i].x;
			}
			pp[j].y=p2.y;
			j++;
			pp[j].x=p[i+1].x;
			pp[j].y=p[i+1].y;
			j++;
		}
		if(p[i].y<p2.y && p[i+1].y <= p2.y)
		{
			pp[j].y=p[i+1].y;
			pp[j].x=p[i+1].x;
			j++;
		}
		if(p[i].y<p2.y && p[i+1].y >= p2.y)
		{
			if(p[i+1].y-p[i].y!=0)
			{
				pp[j].x=(p[i+1].x-p[i].x)/(p[i+1].y-p[i].y)*(p2.y-p[i].y)+p[i].x;	
			}
			else
			{
				pp[j].x=p[i].x;
			}
			pp[j].y=p2.y;
			j++;
		}
	}
        cout<<"\n\nModified Points at the end of Bottom Edge:\n";
	for(i=0;i<j;i++)
	{
		p[i].x=pp[i].x;
		p[i].y=pp[i].y;
                cout<<"\np["<<i<<"]: x="<<p[i].x<<" and y="<<p[i].y;
	}
	p[i].x=pp[00].x;
	p[i].y=pp[00].y;
	n=j;
}


/*Output

gescoe@gescoe-OptiPlex-3020:~/Desktop$ g++ 9.cpp -lgraph
gescoe@gescoe-OptiPlex-3020:~/Desktop$ ./a.out

 Enter cordinates (left,top)
 Enter X cordinates :50

 Enter Y cordinates :50

 Enter cordinates (right,bottom)
 Enter X cordinates :150

 Enter Y cordinates :150
 Enter number of vertex=4

 Enter cordinates of vertex :1
 Enter X cordinates :30

 Enter Y cordinates :100

 Enter cordinates of vertex :2
 Enter X cordinates :100

 Enter Y cordinates :20

 Enter cordinates of vertex :3
 Enter X cordinates :180

 Enter Y cordinates :100

 Enter cordinates of vertex :4
 Enter X cordinates :100

 Enter Y cordinates :180


Modified Points at the end of Left Edge:

p[0]: x=50 and y=77.1429
p[1]: x=100 and y=20
p[2]: x=180 and y=100
p[3]: x=100 and y=180
p[4]: x=50 and y=122.857

Modified Points at the end of Right Edge:

p[0]: x=100 and y=20
p[1]: x=150 and y=70
p[2]: x=150 and y=130
p[3]: x=100 and y=180
p[4]: x=50 and y=122.857
p[5]: x=50 and y=77.1429

Modified Points at the end of Top Edge:

p[0]: x=130 and y=50
p[1]: x=150 and y=70
p[2]: x=150 and y=130
p[3]: x=100 and y=180
p[4]: x=50 and y=122.857
p[5]: x=50 and y=77.1429
p[6]: x=73.75 and y=50

Modified Points at the end of Bottom Edge:

p[0]: x=150 and y=70
p[1]: x=150 and y=130
p[2]: x=130 and y=150
p[3]: x=73.75 and y=150
p[4]: x=50 and y=122.857
p[5]: x=50 and y=77.1429
p[6]: x=73.75 and y=50
[xcb] Unknown sequence number while processing queue
[xcb] Most likely this is a multi-threaded client and XInitThreads has not been called
[xcb] Aborting, sorry about that.
a.out: ../../src/xcb_io.c:274: poll_for_event: Assertion `!xcb_xlib_threads_sequence_lost' failed.
p[7]: x=130 and y=50gescoe@gescoe-OptiPlex-3020:~/Desktop$ 


*/

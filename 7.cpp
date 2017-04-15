//Write C++/Java program to draw line using DDA and Bresenham‘s algorithm. Inherit pixel class and Use function overloading. 


#include<graphics.h>
#include<iostream>
using namespace std;

int main()
{
    //Variable Declarations
    int gd=DETECT,gm=VGAMAX;
    int ch,x1,y1,x2,y2, xmax,ymax,xmid,ymid;
  
    int p1[10][10]={0};
    int n,i,j,i1,j1,k1,r1,c1,c2;
    float ax,ay,type,Ang,Sinang,Cosang;
    int Reflection_result[10][10]={0},Reflection_matrix[10][10]={0};
    float Rotation_result[10][10]={0},Rotation_matrix[10][10]={0};
    //Accepting Original Object From User

    cout<<"\n\n *****************          2-D TRANSFORMATIONS            ***************";
	

    cout<<"\n\n\t\tEnter no.of vertices:";
    cin>>n;
    r1=n;c1=c2=3;

       for(i=0;i<n;i++)
	{
		cout<<"\n\n\t\tEnter (x,y)Co-ordinate of point P"<<i<<": ";
		cin >> p1[i][0] >> p1[i][1];
		p1[i][2] = 1;

	}
	
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<3;j++)
		{
			cout<<p1[i][j]<<"\t";
		}
	}


        

      
    initgraph(&gd,&gm,NULL);
   
    xmax = getmaxx();
    ymax = getmaxy();
    xmid = xmax /2;
    ymid = ymax /2;

    line(xmid,0,xmid,ymax); //Y-Axis
    line(0,ymid,xmax,ymid); //X-Axis 
 
    //Draw Original Object      
    for(i=0;i<n;i++)
    {
	   if(i<n-1)
	   {
		line(p1[i][0]+320, -p1[i][1]+240, p1[i+1][0]+320, -p1[i+1][1]+240);
	   }		
           else
		line(p1[i][0]+320, -p1[i][1]+240, p1[0][0]+320, -p1[0][1]+240);
     }

    while(1)
    {
       xmax = getmaxx();
       ymax = getmaxy();
       xmid = xmax /2;
       ymid = ymax /2;

            
       cout<<"\n\n\n1.Reflection About X Axis";
       cout<<"\n2.Reflection About Y Axis";
       cout<<"\n3.Reflection About X=Y Line";
       cout<<"\n4.Reflection About Origin";
       cout<<"\n5.Rotation About Arbitrary Point";
       cout<<"\n6.Exit";
       cout<<"\nEnter your choice: ";
       cin>>ch;

       switch(ch)
       {
       

         case 1: 
                 //Prepare Reflection About X Axis Matrix
                 for(i=0;i<3;i++)
		 for(j=0;j<3;j++)
		 {
			Reflection_matrix[i][j] = 0;
		 }
                 Reflection_matrix[0][0] = 1;
                 Reflection_matrix[1][1] = -1;
                 Reflection_matrix[2][2] = 1;
	
	

                 //Multiply Matrices
		  for(i1=0;i1<10;i1++)
		  for(j1=0;j1<10;j1++)
			Reflection_result[i1][j1] = 0;
		  for(i1=0;i1<r1;i1++)
		  for(j1=0;j1<c2;j1++)
		  for(k1=0;k1<c1;k1++)
			Reflection_result[i1][j1] = Reflection_result[i1][j1]+(p1[i1][k1] * Reflection_matrix[k1][j1]);

                 //Printing Resultant Reflected Matrix
                  cout<<"\n\n\t\t2-D Object after Reflection About X Axis:\n";
                  for(i=0;i<n;i++)
	         {
		     cout<<"\n\t\t";
		     for(int j=0;j<3;j++)
		     {  
			
			cout<<Reflection_result[i][j]<<"\t";
		     }
                
	         }


                 //Drawing Resultant Reflected Object
              
                 setcolor(BLUE);
		 for(i=0;i<n;i++)
		 {
			if(i<n-1)
			{
				line(Reflection_result[i][0]+320, -Reflection_result[i][1]+240, Reflection_result[i+1][0]+320, -  					Reflection_result[i+1][1]+240);
			
			}		
			else
			{
 				line(Reflection_result[i][0]+320, -Reflection_result[i][1]+240, Reflection_result[0][0]+320, -				Reflection_result[0][1]+240);
		        }
                 }
                  setcolor(WHITE);
                 break;


         case 2: 
                    //Prepare Reflection About Y Axis Matrix
                 for(i=0;i<3;i++)
		 for(j=0;j<3;j++)
		 {
			Reflection_matrix[i][j] = 0;
		 }
                 Reflection_matrix[0][0] = -1;
                 Reflection_matrix[1][1] = 1;
                 Reflection_matrix[2][2] = 1;
	
	

                 //Multiply Matrices
		  for(i1=0;i1<10;i1++)
		  for(j1=0;j1<10;j1++)
			Reflection_result[i1][j1] = 0;
		  for(i1=0;i1<r1;i1++)
		  for(j1=0;j1<c2;j1++)
		  for(k1=0;k1<c1;k1++)
			Reflection_result[i1][j1] = Reflection_result[i1][j1]+(p1[i1][k1] * Reflection_matrix[k1][j1]);

                 //Printing Resultant Reflected Matrix
                  cout<<"\n\n\t\t2-D Object after Reflection About Y Axis:\n";
                  for(i=0;i<n;i++)
	          {
		     cout<<"\n\t\t";
		     for(int j=0;j<3;j++)
		     {  
			
			cout<<Reflection_result[i][j]<<"\t";
		     }
                
	          }


                  //Drawing Resultant Reflected Object
              
                  setcolor(RED);
		  for(i=0;i<n;i++)
		  {
			if(i<n-1)
			{
				line(Reflection_result[i][0]+320, -Reflection_result[i][1]+240, Reflection_result[i+1][0]+320, -  					Reflection_result[i+1][1]+240);
			
			}		
			else
			{
 				line(Reflection_result[i][0]+320, -Reflection_result[i][1]+240, Reflection_result[0][0]+320, -				Reflection_result[0][1]+240);
		        }
                  }
                  setcolor(WHITE);
                
                    break;

         case 3: 
                 //Prepare Reflection About X=Y Line Matrix
                 for(i=0;i<3;i++)
		 for(j=0;j<3;j++)
		 {
			Reflection_matrix[i][j] = 0;
		 }
                 Reflection_matrix[0][1] = 1;
                 Reflection_matrix[1][0] = 1;
                 Reflection_matrix[2][2] = 1;
	
	

                 //Multiply Matrices
		  for(i1=0;i1<10;i1++)
		  for(j1=0;j1<10;j1++)
			Reflection_result[i1][j1] = 0;
		  for(i1=0;i1<r1;i1++)
		  for(j1=0;j1<c2;j1++)
		  for(k1=0;k1<c1;k1++)
			Reflection_result[i1][j1] = Reflection_result[i1][j1]+(p1[i1][k1] * Reflection_matrix[k1][j1]);

                 //Printing Resultant Reflected Matrix
                  cout<<"\n\n\t\t2-D Object after Reflection About X=Y Line:\n";
                  for(i=0;i<n;i++)
	         {
		     cout<<"\n\t\t";
		     for(int j=0;j<3;j++)
		     {  
			
			cout<<Reflection_result[i][j]<<"\t";
		     }
                
	         }


                 //Drawing Resultant Reflected Object
              
                 setcolor(YELLOW);
		 for(i=0;i<n;i++)
		 {
			if(i<n-1)
			{
				line(Reflection_result[i][0]+320, -Reflection_result[i][1]+240, Reflection_result[i+1][0]+320, -  					Reflection_result[i+1][1]+240);
			
			}		
			else
			{
 				line(Reflection_result[i][0]+320, -Reflection_result[i][1]+240, Reflection_result[0][0]+320, -				Reflection_result[0][1]+240);
		        }
                 }
                  setcolor(WHITE);
                 break;

         case 4: 
                 //Prepare Reflection About Origin Matrix
                 for(i=0;i<3;i++)
		 for(j=0;j<3;j++)
		 {
			Reflection_matrix[i][j] = 0;
		 }
                 Reflection_matrix[0][0] = -1;
                 Reflection_matrix[1][1] = -1;
                 Reflection_matrix[2][2] = 1;
	
	

                 //Multiply Matrices
		  for(i1=0;i1<10;i1++)
		  for(j1=0;j1<10;j1++)
			Reflection_result[i1][j1] = 0;
		  for(i1=0;i1<r1;i1++)
		  for(j1=0;j1<c2;j1++)
		  for(k1=0;k1<c1;k1++)
			Reflection_result[i1][j1] = Reflection_result[i1][j1]+(p1[i1][k1] * Reflection_matrix[k1][j1]);

                 //Printing Resultant Reflected Matrix
                  cout<<"\n\n\t\t2-D Object after Reflection About Origin:\n";
                  for(i=0;i<n;i++)
	         {
		     cout<<"\n\t\t";
		     for(int j=0;j<3;j++)
		     {  
			
			cout<<Reflection_result[i][j]<<"\t";
		     }
                
	         }


                 //Drawing Resultant Reflected Object
              
                 setcolor(GREEN);
		 for(i=0;i<n;i++)
		 {
			if(i<n-1)
			{
				line(Reflection_result[i][0]+320, -Reflection_result[i][1]+240, Reflection_result[i+1][0]+320, -  					Reflection_result[i+1][1]+240);
			
			}		
			else
			{
 				line(Reflection_result[i][0]+320, -Reflection_result[i][1]+240, Reflection_result[0][0]+320, -				Reflection_result[0][1]+240);
		        }
                 }
                  setcolor(WHITE);
                 break;
 
         case 5 : //Prepare Rotation About Arbitrary Point Matrix
                 cout<<"\n\n\t\tEnter Arbitrary Point of Rotation..\n";
                 cout<<"\n\t\tEnter X-coordinate: ";
                 cin>>ax;
                 cout<<"\n\t\tEnter Y-coordinate: ";
                 cin>>ay;

                 cout << "\n\n **** Rotation Types ****";
	 	 cout << "\n\n\t\t1.Clockwise Rotation \n\n\t\t2.Anti-Clockwise Rotation ";
		 cout << "\n\n\t\tEnter your choice(1-2): ";
		 cin >> type;

		 cout << "\n\n\t\tEnter the angle of rotation in degrees: ";
		 cin >> Ang;
	
		 Ang = (Ang * 6.2832)/360;
		 Sinang = sin(Ang);
		 Cosang = cos(Ang);
                 
                 Rotation_matrix[0][0] = Cosang;
                 Rotation_matrix[0][1] = -Sinang;
                 Rotation_matrix[0][2] = 0;
                 Rotation_matrix[1][0] = Sinang;
                 Rotation_matrix[1][1] = Cosang;
                 Rotation_matrix[1][2] = 0;
                 Rotation_matrix[2][0] = (-ax*Cosang)+(ay*Sinang)+ax;
                 Rotation_matrix[2][1] = (-ax*Sinang)-(ay*Cosang)+ay;
                 Rotation_matrix[2][2] = 1;
	
	         if(type == 1)
			Rotation_matrix[0][1] = -Sinang;
		 else
			Rotation_matrix[1][0] = -Sinang;

                   //Printing Resultant Rotated Matrix
                   cout<<"\n\n\t\t2-D  after Rotation for matrix:\n";
                   for(i=0;i<n;i++)
	           {
		     cout<<"\n\t\t";
		     for(int j=0;j<3;j++)
		     {  
			
			cout<<Rotation_matrix[i][j]<<"\t";
		     }
                
	           }

                 //Multiply Matrices
		    for(i1=0;i1<10;i1++)
		    for(j1=0;j1<10;j1++)
			Rotation_result[i1][j1] = 0;
		    for(i1=0;i1<r1;i1++)
		    for(j1=0;j1<c2;j1++)
	            for(k1=0;k1<c1;k1++)
			Rotation_result[i1][j1] = Rotation_result[i1][j1]+(p1[i1][k1] * Rotation_matrix[k1][j1]);

                 //Printing Resultant Rotated Matrix
                   cout<<"\n\n\t\t2-D  after Rotation:\n";
                   for(i=0;i<n;i++)
	           {
		     cout<<"\n\t\t";
		     for(int j=0;j<3;j++)
		     {  
			
			cout<<Rotation_result[i][j]<<"\t";
		     }
                
	           }

                    //Drawing Resultant Rotated Object
                   
                    setcolor(RED);
		    for(i=0;i<n;i++)
		    {
			if(i<n-1)
			{
		    line(Rotation_result[i][0]+320, -Rotation_result[i][1]+240, Rotation_result[i+1][0]+320, -Rotation_result[i+1][1]+240);
			}		
			else
		    line(Rotation_result[i][0]+320, -Rotation_result[i][1]+240, Rotation_result[0][0]+320, -Rotation_result[0][1] +240);
		    }
                    
                   setcolor(WHITE);
                    break;
         case 6:
                 exit(0);
                 break;

       }

      

   }

   delay(3000);
   closegraph();
   return 0;


}

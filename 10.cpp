//


#include<graphics.h>
#include<iostream>
using namespace std;

int main()
{
    //Variable Declarations
    int gd=DETECT,gm=VGAMAX;
    int ch,x1,y1,x2,y2,x3,y3,xmax,ymax,xmid,ymid,choice,area,height,centerx;
    float type,Ang,Sinang,Cosang;
    float Sx,Sy;
    int tx,ty;
    int p1[10][10]={0};
    int n,i,j,i1,j1,k1,r1,c1,c2;
    int Trans_result[10][10]={0},Trans_matrix[10][10]={0};
    float Rotation_result[10][10]={0},Rotation_matrix[10][10]={0};
    float Scaling_result[10][10]={0},Scaling_matrix[10][10]={0};
    float Shearing_result[10][10],Shearing_matrix[10][10];

    //Accepting Original Object From User

    cout<<"\n\n *****************          2-D TRANSFORMATIONS            ***************";
	

    cout<<"\n\n\t\tEnter your choice:- \n 1. Equilateral Triangle \n 2.Rhombus ";
    cin>>choice;
    initgraph(&gd,&gm,NULL);
    xmax = getmaxx();
    ymax = getmaxy();
    xmid = xmax /2;
    ymid = ymax /2;

    line(xmid,0,xmid,ymax); //Y-Axis
    line(0,ymid,xmax,ymid); //X-Axis 
 
    if(choice==1)
    {
		 n=3;
		 cout<<"\nEnter the co-ordinates of the endpoints of side for Triangle Below\n";
                 cout<<"\nEnter x1: "; cin>>x1;
                 cout<<"Enter y1: "; cin>>y1;
                 cout<<"Enter x2: "; cin>>x2;
                 cout<<"Enter y2: "; cin>>y2;
		 area= (sqrt(3)/4)*(x2-x1)*(x2-x1);
		 cout<<"\n Area is \t"<<area;
                 height= (2* area)/abs(x2-x1);
		 cout<<"\n Height is \t"<<height;
		 centerx=abs(x2-x1)/2;  
		 x3=x1+centerx;    
		 y3=y1+height;            
		
                 p1[0][0]=x1;
                 p1[0][1]=y1;
                 p1[0][2]=1;
		 p1[1][0]=x2;
                 p1[1][1]=y2;
                 p1[1][2]=1;
  		 p1[2][0]=x3;
                 p1[2][1]=y3;
                 p1[2][2]=1;
                  		
   }
   else if(choice==2)
   {
		cout<<"\nRohmbus";
		n=4;
                cout<<"\nEnter the co-ordinates of the endpoints of side for Rohmbus Below\n";
                cout<<"\nEnter x1: "; cin>>x1;
                cout<<"Enter y1: "; cin>>y1;
                cout<<"Enter x2: "; cin>>x2;
                cout<<"Enter y2: "; cin>>y2;
	        int xlength=abs(x2-x1);
		int ylength=abs(y2-y1);
		x3=x2+xlength;    
		y3=y2+xlength;
		int x4=x1+xlength;    
		int y4=y1+xlength;
		cout<<"\nx3 =: "<<x3; 
                cout<<"\n y3: "<<y3; 
                cout<<"\nx3 =: "<<x4; 
                cout<<"\n y3: "<<y4; 

		p1[0][0]=x1;
                p1[0][1]=y1;
                p1[0][2]=1;
		p1[1][0]=x2;
                p1[1][1]=y2;
                p1[1][2]=1;
  		p1[2][0]=x3;
                p1[2][1]=y3;
                p1[2][2]=1;
		p1[3][0]=x4;
                p1[3][1]=y4;
                p1[3][2]=1;
    }
    else
    {
         cout<<"\n\nSorry! You Entered Wrong Choice.\n\n";
         exit(0);
    }


    r1=n;c1=c2=3;
     	
    for(i=0;i<n;i++)
    {
		cout<<"\n";
		for(int j=0;j<3;j++)
		{
			cout<<p1[i][j]<<"\t";
		}
    }

  
    
    //Draw Original Object      
    for(i=0;i<n;i++)
    {
        cout<<"Value of n is ="<<n;
	   if(i<n-1)
	   {
		cout<<"i =\n"<<i;
          cout<<"p1[i][0]+320 =  "<<p1[i][0]+320;
          cout<<"\n -p1[i][1]+240 = "<<-p1[i][1]+240;
		cout<<"\n p1[i+1][0]+320 = "<<p1[i+1][0]+320; 
		cout<<"\n -p1[i+1][1]+240 = "<<-p1[i+1][1]+240;
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

      
       
       cout<<"\n\n\n1.Translation..";
       cout<<"\n2.Rotation..";
       cout<<"\n3.Scaling...";
       cout<<"\n4.Shearing";
       cout<<"\n5.Exit";
       cout<<"\nEnter your choice: ";
       cin>>ch;

       switch(ch)
       {
       

         case 1: 
                 //Prepare Translation Matrix
                 cout << "\n\n\t\tEnter X-Translation tx: ";
	         cin >>tx;
	         cout << "\n\n\t\tEnter Y-Translation ty: ";
		 cin >>ty;

		 Trans_matrix[0][0] = 1;
		 Trans_matrix[0][1] = 0;
		 Trans_matrix[0][2] = 0;
		 Trans_matrix[1][0] = 0;
		 Trans_matrix[1][1] = 1;
		 Trans_matrix[1][2] = 0;
		 Trans_matrix[2][0] = tx;
		 Trans_matrix[2][1] = ty;
		 Trans_matrix[2][2] = 1;

                 //Multiply Matrices
		 for(i1=0;i1<10;i1++)
		 for(j1=0;j1<10;j1++)
			Trans_result[i1][j1] = 0;

		 for(i1=0;i1<r1;i1++)
		 {
		 for(j1=0;j1<c2;j1++)
		 {
		 for(k1=0;k1<c1;k1++)
		 {	
			Trans_result[i1][j1] = Trans_result[i1][j1]+(p1[i1][k1] * Trans_matrix[k1][j1]);
		 }
		 }
		 }

                 //Printing Resultant Translated Matrix
                  cout<<"\n\n\t\t2-D Object after Translation:\n";
                  for(i=0;i<n;i++)
	         {
		     cout<<"\n\t\t";
		     for(int j=0;j<3;j++)
		     {  
			
			cout<<Trans_result[i][j]<<"\t";
		     }
                
	         }


                 //Drawing Resultant Translated Object
              
                 setcolor(BLUE);
		 for(i=0;i<n;i++)
		 {
			if(i<n-1)
			{
				line(Trans_result[i][0]+320, -Trans_result[i][1]+240, Trans_result[i+1][0]+320, -Trans_result[i+1][1]+240);
			
			}		
			else
				line(Trans_result[i][0]+320, -Trans_result[i][1]+240, Trans_result[0][0]+320, -Trans_result[0][1]+240);
		 }
     
                  setcolor(WHITE);
                 break;


         case 2: 
                    //Prepare Rotation Matrix
                    cout << "\n\n **** Rotation Types ****";
	 	    cout << "\n\n\t\t1.Clockwise Rotation \n\n\t\t2.Anti-Clockwise Rotation ";
		    cout << "\n\n\t\tEnter your choice(1-2): ";
		    cin >> type;

		    cout << "\n\n\t\tEnter the angle of rotation in degrees: ";
		    cin >> Ang;
	
		    Ang = (Ang * 6.2832)/360;
		    Sinang = sin(Ang);
		    Cosang = cos(Ang);
       
		    for(i=0;i<3;i++)
		    for(j=0;j<3;j++)
			Rotation_matrix[i][j] = 0;
       
		    Rotation_matrix[0][0] = Rotation_matrix[1][1] = Cosang;
	 	    Rotation_matrix[0][1] = Rotation_matrix[1][0] = Sinang;
		    Rotation_matrix[2][2] = 1;

		    if(type == 1)
			Rotation_matrix[0][1] = -Sinang;
		    else
			Rotation_matrix[1][0] = -Sinang;


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

         case 3: 
                 //Prepare Scaling Matrices
                 cout<<"\n\n\t\tEnter X-Scaling Sx: ";
	         cin>>Sx;
	         cout<<"\n\n\t\tEnter Y-Scaling Sy: ";
	         cin>>Sy;
        
		 for(i=0;i<3;i++)
		 {
			for(j=0;j<3;j++)
			{	
				Scaling_matrix[i][j] = 0;
			}
		 }

		 Scaling_matrix[0][0] = Sx;
		 Scaling_matrix[0][1] = 0;
		 Scaling_matrix[0][2] = 0;
		 Scaling_matrix[1][0] = 0;
		 Scaling_matrix[1][1] = Sy;
		 Scaling_matrix[1][2] = 0;
		 Scaling_matrix[2][0] = 0;
		 Scaling_matrix[2][1] = 0;
		 Scaling_matrix[2][2] = 1;

                 //Multiply Matrices
                 for(i1=0;i1<10;i1++)
	         for(j1=0;j1<10;j1++)
			Scaling_result[i1][j1] = 0;
		 for(i1=0;i1<r1;i1++)
		 for(j1=0;j1<c2;j1++)
		 for(k1=0;k1<c1;k1++)
			Scaling_result[i1][j1] = Scaling_result[i1][j1]+(p1[i1][k1] * Scaling_matrix[k1][j1]);

                  //Printing Resultant Scaled Matrix
                   cout<<"\n\n\t\tPolygon after Scaling:\n";
                   for(i=0;i<n;i++)
	           {
		     cout<<"\n\t\t";
		     for(int j=0;j<3;j++)
		     {  
			
			cout<<Scaling_result[i][j]<<"\t";
		     }
                
	           }

                 //Drawing Resultant Scaled Object
                 
                 setcolor(YELLOW);
		 for(i=0;i<n;i++)
		 {
		    if(i<n-1)
		    {
		        line(Scaling_result[i][0]+320, -Scaling_result[i][1]+240, Scaling_result[i+1][0]+320, -Scaling_result[i+1][1]+240);
	  	    }
   		    else
		    {
    	                line(Scaling_result[i][0]+320, -Scaling_result[i][1]+240, Scaling_result[0][0]+320, -Scaling_result[0][1]+240);
		    }
	         }
                  setcolor(WHITE);
                 break;

           case 4: 
                 //Prepare Shearing Matrices
                 for(i=0;i<3;i++)
	         for(j=0;j<3;j++)
		 {
			if(i == j)
				Shearing_matrix[i][j] = 1;
			else
				Shearing_matrix[i][j] = 0;
		}
		cout << "\n\n **** Shearing Types ****";
		cout << "\n\n\t\t1.X-Direction Shear \n\n\t\t2.Y-Direction Shear ";
		cout << "\n\n\t\tEnter your choice(1-2): ";
		cin >> type;
		if(type == 1)
		{
			cout << "\n\n\t\tEnter X-Shear Sx: ";
			cin >> Sx;
			Shearing_matrix[1][0] = Sx;
		}
		else
		{
			cout << "\n\n\t\tEnter Y-Shear Sy: ";
			cin >> Sy;
			Shearing_matrix[0][1] = Sy;
		}
	

                 //Multiply Matrices
                 for(i1=0;i1<10;i1++)
	         for(j1=0;j1<10;j1++)
			Shearing_result[i1][j1] = 0;
		 for(i1=0;i1<r1;i1++)
		 for(j1=0;j1<c2;j1++)
		 for(k1=0;k1<c1;k1++)
			Shearing_result[i1][j1] = Shearing_result[i1][j1]+(p1[i1][k1] * Shearing_matrix[k1][j1]);

                  //Printing Resultant Sheared Matrix
                   cout<<"\n\n\t\tPolygon after Shearing:\n";
                   for(i=0;i<n;i++)
	           {
		     cout<<"\n\t\t";
		     for(int j=0;j<3;j++)
		     {  
			
			cout<<Shearing_result[i][j]<<"\t";
		     }
                
	           }

                 //Drawing Resultant Sheared Object
                 
                 setcolor(GREEN);
		 for(i=0;i<n;i++)
		 {
		    if(i<n-1)
		    {
		    line(Shearing_result[i][0]+320, -Shearing_result[i][1]+240, Shearing_result[i+1][0]+320, -Shearing_result[i+1][1]+240);
	  	    }
   		    else
		    {
    	            line(Shearing_result[i][0]+320, -Shearing_result[i][1]+240, Shearing_result[0][0]+320, -Shearing_result[0][1]+240);
		    }
	         }
                 setcolor(WHITE);
                 break;

         case 5:
                 exit(0);
                 break;

       }

      

   }

   delay(3000);
   closegraph();
   return 0;


}

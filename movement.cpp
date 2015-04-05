#include<windows.h>
#include<unistd.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>



using namespace std;


const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char DELIMITER = ',';

void LeftClick ( )
{  
  INPUT    Input={0};
  // left down 
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
  SendInput(1,&Input,sizeof(INPUT));

  // left up
  ZeroMemory(&Input,sizeof(INPUT));
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
  SendInput(1,&Input,sizeof(INPUT));
}

void RightClick ( )
{  
  INPUT    Input={0};
  // Right down 
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;
  SendInput(1,&Input,sizeof(INPUT));

  // Right up
  ZeroMemory(&Input,sizeof(INPUT));
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;
  SendInput(1,&Input,sizeof(INPUT));
}

int main()

{	
	ofstream data;
	data.open("movement.log",ios::out);
	data.close();
	SetCursorPos(384,683);
    ifstream fin;
    fin.open("movement.log"); // open a file
    if (!fin.good())
        return 1; // exit if file not found

    double x,y,z,num;
    POINT cursor;
    int count=0;
    // read each line of the file
    bool k=false;
    while (1)
    {
    // read an entire line into memory

        char buf[MAX_CHARS_PER_LINE];
        fin.getline(buf, MAX_CHARS_PER_LINE, DELIMITER);
        fin.getline(buf, MAX_CHARS_PER_LINE, DELIMITER);
        num=atof(buf);
        fin.getline(buf, MAX_CHARS_PER_LINE, DELIMITER);
        x=atof(buf);
        fin.getline(buf, MAX_CHARS_PER_LINE, DELIMITER);
        y=atof(buf);
        fin.getline(buf, MAX_CHARS_PER_LINE, '>');
        z=atof(buf);
        //char c=fin.get();
        //cout<<num<<"  ";
        //cout <<setprecision(8)<<"x= "<<x<<" y= "<<y<<" z= "<<z<<endl<<endl;
        //usleep(70000);
        
        if (fin.get()==EOF){
        	fin.seekg(fin.end); 
        	fin.close();
        	//usleep(10000);
        	fin.open("movement.log"); // open a file
        	int lenght = fin.tellg();
        	fin.seekg(lenght,fin.end);
    		if (!fin.good())
        		return 1; // exit if file not found
        	usleep(50000);
		}
        	
        GetCursorPos(&cursor);
        
        if (z<=-9.5 && k==false && y<=5 && count==0){
        	 k = true;
        	 cout << "SpaceGlove: Armed";
        	//usleep(700000);
        	cout << " .";			 
			cout<< endl;
			x=0;
			y=0;
			count++;
		}	
		else if (z<=-9.5 && k==true && y<=4 && count==0){
        	 k = false;
        	 cout << "SpaceGlove: Disarmed";        	 
        	//usleep(700000);
        	cout << " .";
			 cout<< endl;
			 x=0;
			 y=0;
			 count++;
		}
			
		if (!k){
			continue;
    	}
    		if (count==1){
				count=0;
				x=0;
				y=0;
			}
        	if(x<=-4)
        	{
            	if(cursor.x<1400)
            		cursor.x+=60;
            		SetCursorPos(cursor.x,cursor.y);
        	}
        	if(x>-4 && x<=-3)
        	{
            	if(cursor.x<1400)
            		cursor.x+=20;
            		SetCursorPos(cursor.x,cursor.y);
        	}
        	if(x>-3 && x<=-2)
        	{
            	if(cursor.x<1400)
            		cursor.x+=10;
            		SetCursorPos(cursor.x,cursor.y);
        	}
        	if(x>4)
       		{
            	if(cursor.x>-40)
            		cursor.x-=60;
            		SetCursorPos(cursor.x,cursor.y);
        	}
        	if(x<=4 && x>3)
       		{
            	if(cursor.x>-40)
            		cursor.x-=20;
            		SetCursorPos(cursor.x,cursor.y);
        	}
        	if(x<=3 && x>=2)
       		{
            	if(cursor.x>-40)
            		cursor.x-=10;
            		SetCursorPos(cursor.x,cursor.y);
        	}
        	if(y>4)
        	{
            	if(cursor.y<800)
            		cursor.y+=80;
            		SetCursorPos(cursor.x,cursor.y);
        	}
        	if(y<=4 && y>3)
        	{
            	if(cursor.y<800)
            		cursor.y+=40;
            		SetCursorPos(cursor.x,cursor.y);
        	}
        	if(y<=3 && y>=2)
        	{
            	if(cursor.y<800)
            		cursor.y+=10;
            		SetCursorPos(cursor.x,cursor.y);
        	}
        	if(y<-4)
        	{
            	if(cursor.y>-40)
            		cursor.y-=80;
            		SetCursorPos(cursor.x,cursor.y);
        	}
        	if(y>=-4 && y<-3)
        	{
            	if(cursor.y > -80)
            		cursor.y-=40;
            		SetCursorPos(cursor.x,cursor.y);
        	}
        	if(y>=-3 && y<=-2)
        	{
            	if(cursor.y > -80)
            		cursor.y-=40;
            		SetCursorPos(cursor.x,cursor.y);
        	}		
        //Sleep(1);
    }


}


}

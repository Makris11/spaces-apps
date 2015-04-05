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
	data.open("clicks.log",ios::out);
	data.close();
	SetCursorPos(384,683);
    ifstream fin;
    fin.open("clicks.log"); // open a file
    if (!fin.good())
        return 1; // exit if file not found

    double x,y,z,num;
    POINT cursor;
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
        	fin.open("clicks.log"); // open a file
        	int lenght = fin.tellg();
        	fin.seekg(lenght,fin.end);
    		if (!fin.good())
        		return 1; // exit if file not found
        	usleep(80000);
		}
        	
        GetCursorPos(&cursor);
        
        if (z<=-10 && k==false){
        	 k = true;
        	 cout << "SpaceGlove: Selection/Scroll Mode";
        	 for (int i=0;i<=1;i++)
        	 {
        	 	sleep(1);
        	 	cout << " .";
			 }
			cout<< endl;
			x=0;
			y=0;
			z=0;
		}	
		else if (z<=-10 && k==true){
        	 k = false;
        	 cout << "SpaceGlove: Selection/Zoom Mode";
        	 for (int i=0;i<=1;i++)
        	 {
        	 	sleep(1);
        	 	cout << " .";
			 }
			 cout<< endl;
			 x=0;
			 y=0;
			 z=0;
		}
			
		if (k){
        	if(x<=-7)
        	{
            	RightClick();
            	cout << "Right Click Pressed" << endl;
       		 }
        	if(x>=7)
        	{
            	LeftClick();
            	cout << "Left Click Pressed" << endl;
        	}
        	if(y<=-3 && z<=6 && z>3)
        	{
            	keybd_event(VK_UP,0,KEYEVENTF_EXTENDEDKEY | 0,0 );
            	cout << "Up Arrow Pressed" << endl;
       		 }
        	if(y>=6 && z<=7 && z>=3)
        	{
            	keybd_event(VK_DOWN,0,KEYEVENTF_EXTENDEDKEY | 0,0 );
            	cout << "Down Arrow Pressed" << endl;
        	}
    	}
    	
    	
    	
    	else{
    		if(x<=-7)
        	{
            	RightClick();
            	cout << "Right Click Pressed" << endl;
       		 }
        	if(x>=7)
        	{
            	LeftClick();
            	cout << "Left Click Pressed" << endl;
        	}
        	if(y<=-3 && z<=6 && z>3)
        	{
            	//keybd_event(VK_UP,0,KEYEVENTF_EXTENDEDKEY | 0,0 );
            	keybd_event(VK_NEXT,0,KEYEVENTF_EXTENDEDKEY | 0,0 );
            	cout << "Zoom in" << endl;
       		 }
        	if(y>=6 && z<=7 && z>=3)
        	{
            	//keybd_event(VK_DOWN,0,KEYEVENTF_EXTENDEDKEY | 0,0 );
            	keybd_event(VK_PRIOR,0,KEYEVENTF_EXTENDEDKEY | 0,0 );
            	cout << "Zoom out" << endl;
        	}
    		
        	
    	}		
        //Sleep(1);
    }


}

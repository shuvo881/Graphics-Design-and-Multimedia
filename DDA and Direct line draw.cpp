#include <graphics.h>



void directLineDraw(int x1, int y1, int x2, int y2){
	int dx = x2 - x1, dy = y2-y1, x, y, xend;
	float m = dx/dy, b = y1 - m*x1;
	int xco , yco; 
	xco = getmaxx()/2;
	yco = getmaxy()/2;
	
    
    line(0, yco, getmaxx(), yco);
	line(xco,0,xco, getmaxy());
    rectangle(0,0,getmaxx(),getmaxy());
	
	if (dx < 0){
		x = x2, y = y2;
		xend = x1;
	}
	else{
		x = x1, y = y1, xend = x2;
	}
	outtextxy(xco+x, yco-y, "(10, 10)");
	while(x <= xend){
		putpixel(xco+x, yco-y, RED);
		x++;
		y = m*x + b+0.5;
	}
	outtextxy(xco+x, yco-y, "(100, 100)");
	while( !kbhit()){
		delay(100);
	}
}

void ddaLineDraw(int x1, int y1, int x2, int y2){
	int xco , yco; 
	float m = (x2-x1)/(y2-y1);
	int x, y;
	float yf, xf;
	
	
	initwindow(640, 480, "DDA");
	rectangle(0,0,getmaxx(),getmaxy());
	xco = getmaxx()/2;
	yco = getmaxy()/2;
	line(0, yco, getmaxx(), yco);
	line(xco,0,xco, getmaxy());
	
	
	if(m < 1){
		x = x1;
		yf = y1;

		while(x <= x2){
			y = yf + 0.5;
			putpixel(xco+x, yco - y, RED);
			x++;
			yf = yf + m;
		}

	}else{
		xf = x1;
		y = y1;

		while(y <= y2){
			x = xf + 0.5;
			putpixel(xco+x, yco - y, RED);
			y++;
			xf = xf + 1/m;
		}

	}
	

	
}

int main()
{

	initwindow(640, 480, "direct line draw");

   	directLineDraw(10,10,100,100);

	//ddaLineDraw(x1,y1,x2,y2);


   	while( !kbhit()){

		delay(100);
	}
	

   return 0;
}

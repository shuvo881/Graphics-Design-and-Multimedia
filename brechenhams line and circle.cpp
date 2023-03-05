#include <graphics.h>
void bresnhamsLineDraw(int x1, int y1, int x2, int y2){
	int dx, dy, inc1, inc2, d;
	float m;
	initwindow(640, 480, "Line");
	line(0, getmaxy()/2, getmaxx(),getmaxy()/2);
	line(getmaxx()/2, 0, getmaxx()/2,getmaxy());
	dx = x2 - x1;
	dy = y2 - y1;
	m = dy / dx;
	if(m < 1){
		outtextxy(0,0, "Line");
		outtextxy((getmaxx()/2)-x1, (getmaxx()/2) + y1, "POINT 1");
		d = 2 * dy - dx; inc1 = 2 * dy; inc2 = 2*(dy - dx);
		while(x1 <= x2){
			putpixel((getmaxx()/2)-x1, (getmaxx()/2) + y1, 7);
			if(d <= 0){
				d = d + inc1;
			}else{
				d = d + inc2;
				y1++;
			}
			x1++;
		}
		outtextxy((getmaxx()/2)-x1, (getmaxx()/2) + y1, "POINT 2");
	}else{
		d = 2 * dx - dy;
		inc1 = 2 * dx;
		inc2 = 2*(dx - dy);
		while(y1 <= y2){
			putpixel((getmaxx()/2)-x1, (getmaxx()/2) + y1, RED);
			if(d <= 0){
				d = d + inc1;
			}else{
				d = d + inc2;
				x1++;
			}
			y1++;
		}
	}
	while(!kbhit()){
   	delay(100);
   }
}

void BresnhamsCircleDraw(int h, int k, int r){
	initwindow(640, 480, "Circle");
	
	int d, x, y, midx, midy;
	d = 3 - 2*r;
	x = 0;
	y = r;
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	
	line(0, getmaxy()/2, getmaxx(),getmaxy()/2);
	line(getmaxx()/2, 0, getmaxx()/2,getmaxy());
	outtextxy(midx+h, midy+k, "c");
	
	while(x <= y){
		putpixel(x+h+midx, y+k+midy, 7);
		putpixel(-x+h+midx, y+k+midy, 7);
		putpixel(x+h+midx, -y+k+midy, 7);
		putpixel(-x+h+midx, -y+k+midy, 7);
		
		putpixel(y+h+midx, x+k+midy, 7);
		putpixel(-y+h+midx, x+k+midy, 7);
		putpixel(y+h+midx, -x+k+midy, 7);
		putpixel(-y+h+midx, -x+k+midy, 7); 
		if(d < 0){
			d += 4*x + 6;
			x++;
		}else{
			d += 4*(x - y) + 10;
			x++;
			y--;
		}
	}
	while(!kbhit()){
   	delay(100);
   }
}



int main()
{
   

   //bresnhamsLineDraw(5, 5, 80, 50);
   BresnhamsCircleDraw(0, 25, 100);

   closegraph();
   return 0;
}

#include <graphics.h>

void lineDraw(int x1, int y1, int x2, int y2){

	int dx = x2- x1, dy = y2 - y1, d ;
	float m = dy/dx;
	int midx = getmaxx()/2;
	int midy = getmaxy()/2;
	if(m<1){
		d = 2*dy - dx;
		int inc1 = 2*dy;
		int inc2 = 2*(dy - dx);
		while(x1 <= x2){
			putpixel(x1+midx, midy-y1, 7);
			if(d <= 0){
				d = d + inc1;
			}else{
				d = d + inc2;
				y1++;
			}
			x1++;
		}
	}else{
		d = 2*dx - dy;
		int inc1 = 2*dx;
		int inc2 = 2*(dx - dy);
		while(y1 <= y2){
			putpixel(x1+midx, midy-y1, 7);
			if(d <= 0){
				d = d + inc1;
			}else{
				d = d + inc2;
				x1++;
			}
			y1++;
		}
	}
	getch();
}


void circleDrawing(int h, int k, int r){
	//initwindow(480,500,"c");
	//line(0,0,100,100);
	int mx = getmaxx();
	int my = getmaxy();
	int x = 0, y = r;
	float d = 3 - 2*r, midx, midy;
	midx = mx/2, midy = my/2;
	while(x <= y){
		putpixel(x+h+midx, midy-(y+k),7);
		putpixel(-x+h+midx, midy-(y+k),7);
		putpixel(x+h+midx, midy-(-y+k),7);
		putpixel(-x+h+midx, midy-(-y+k),7);
		
		putpixel(y+h+midx, midy-(x+k),7);
		putpixel(-y+h+midx, midy-(x+k),7);
		putpixel(y+h+midx, midy-(-x+k),7);
		putpixel(-y+h+midx, midy-(-x+k),7);
		if (d<0){
			d = d+ 4*x + 6;
			x++;
		}else{
			d = d+4*(x-y)+10;
			x++;
			y--;
		}
	}
	//while(!kbhit()){
   	//delay(100);
   //}

}


int main(){

   initwindow(600,600,"main");
   int midx = getmaxx()/2;
   int midy = getmaxy()/2;
   line(0, midy, midx*2, midy);
   line(midx, 0, midx, midy*2);
   lineDraw(11,60,111,59);//up
   lineDraw(10,10,11,60);//left
   lineDraw(10,10,40,10);//down
   lineDraw(80,10,110,9);//down
   lineDraw(109,9,110,14);//right
   lineDraw(110,54,111,59);//right
   
   circleDrawing(60, 10, 20);
   circleDrawing(110, 34, 20);
   
   
   while(!kbhit()){
   	delay(10);
   }
   closegraph();
   return 0;
}

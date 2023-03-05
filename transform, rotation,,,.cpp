#include <graphics.h>
#include <iostream>
#include<math.h>
#include <stdio.h>
using namespace std;
void bresnhamsLineDraw(int x1, int y1, int x2, int y2){
	int dx, dy, inc1, inc2, d;
	float m;

	dx = x2 - x1;
	dy = y2 - y1;
	m = dy / dx;
	if(m < 1){
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
	
}





void drawTringle(float tringle[][2]){
	bresnhamsLineDraw(abs(round(tringle[0][0])),abs(round(tringle[0][1])),abs(round(tringle[1][0])),abs(round(tringle[1][1])));
	bresnhamsLineDraw(abs(round(tringle[0][0])),abs(round(tringle[0][1])),abs(round(tringle[2][0])),abs(round(tringle[2][1])));
	bresnhamsLineDraw(abs(round(tringle[1][0])),abs(round(tringle[1][1])),abs(round(tringle[2][0])),abs(round(tringle[2][1])));
}





int main(){
	initwindow(640, 480, "Line");


   int midx = getmaxx()/2;
   int midy = getmaxy()/2;
   line(0,midy, getmaxx(), midy);
   line(midx,0, midx, getmaxy());
   float tringle[3][2]={{0,0}, {20, 1}, {50,30}};
   drawTringle(tringle);
   
   //return 0;
   //line(0,0,30,30);
   /*for(int i=0; i<3; i++){
   	for(int j=0; j<2; j++){
   		scanf("%d", &tringle[i][j]);
	   }
   }*/
   //drawTringle(tringle);
   //line(tringle[0][0],tringle[0][1],tringle[1][0],tringle[1][1]);
	//line(tringle[0][0],tringle[0][1],tringle[2][0],tringle[2][1]);
	//line(tringle[1][0],tringle[1][1],tringle[2][0],tringle[2][1]);
	
	int traingleMatrix[3][3] = {{0,0,0}, {0,0,0}, {1,1,1}};
   	for(int i=0; i<3; i++){
   		for(int j=0; j<2; j++){
   			traingleMatrix[j][i] = tringle[i][j];
	   }
   }
   
   /// Translation///
   int transTringle[3][3];
   int transformation[3][3] = {{1,0,1}, {0,1,1}, {0,0,1}};//tx=ty=1
	int transformationInvert[3][3] = {{1,0,-1}, {0,1,-1}, {0,0,1}};  
	 
   for(int i=0;i<3; i++){
   	for(int j =0; j<3; j++){
   		transTringle[i][j] = 0;
   		for(int k=0; k<3; k++ ){
   			transTringle[i][j] += transformation[i][k] * traingleMatrix[k][j];
		   }
	   }
   }
   
   cout<<"Transletion"<<endl;
    for(int i=0; i<3; i++){
   		for(int j=0; j<2; j++){
   			tringle[i][j] = transTringle[j][i];
   			cout<<tringle[i][j]<<" ";
	   }
	   cout<<endl;
   }

   drawTringle(tringle);
   
   
   ///rotation///
	
	
	 cout<<"Rotation"<<endl;
   double rotationTrain[3][3], theta = 45;
   	double rotation[3][3] = {{cos(theta*3.14159/180), -sin(theta*3.14159/180),0}, {sin(theta*3.14159/180), cos(theta*3.14159/180),0}, {0,0,1}};
	double scaling[3][3] = {{2,0,0}, {0,2,0}, {0,0,1}};
	double scaleTrain[3][3];
	
	double searingTrai[3][3];
	double searing[3][3]={{1,0,0},{1,1,0},{0,0,1}};
	


   	for(int i=0;i<3; i++){
   		for(int j =0; j<3; j++){
   			rotationTrain[i][j] = 0;
   			scaleTrain[i][j] = 0;
   			searingTrai[i][j] = 0;
			for(int k=0; k<3; k++ ){
   				rotationTrain[i][j] += transformation[i][k] * rotation[k][j];
   				scaleTrain[i][j] += transformation[i][k] * scaling[k][j];
   				searingTrai[i][j] += transformation[i][k] * searing[k][j];
		   	}
	   }
   }






   double tmrot[3][3];
   double tsv[3][3];
   double tsrv[3][3];

   for(int i=0;i<3; i++){
   		for(int j =0; j<3; j++){
   			tmrot[i][j] = 0;
   			tsv[i][j] = 0;
   			tsrv[i][j] = 0;
   			for(int k=0; k<3; k++ ){
   				tmrot[i][j] += rotationTrain[i][k] * transformationInvert[k][j];
   				tsv[i][j] += scaleTrain[i][k] * transformationInvert[k][j];
   				tsrv[i][j] += searingTrai[i][k] * transformationInvert[k][j];
		   	}
	   }
   }






   double rot[3][3];
   double sacalingTringle[3][3];
   double shearingTringle[3][3];

   for(int i=0;i<3; i++){
   		for(int j =0; j<3; j++){
   			rot[i][j] = 0;
   			sacalingTringle[i][j]=0;
   			shearingTringle[i][j]=0;
   			for(int k=0; k<3; k++ ){
   				rot[i][j] += tmrot[i][k] * traingleMatrix[k][j];
   				sacalingTringle[i][j] += tsv[i][k] * traingleMatrix[k][j];
   				shearingTringle[i][j] += tsrv[i][k] * traingleMatrix[k][j];
		   	}
	   }
   }


   for(int i=0; i<3; i++){
   	for(int j=0; j<2; j++){
   		tringle[i][j] = rot[j][i];
   		cout<<tringle[i][j]<<" ";
	   }
	   cout<<endl;
   }
   drawTringle(tringle);
   
   
   cout<<"scaling"<<endl;
   for(int i=0; i<3; i++){
   	for(int j=0; j<2; j++){
   		tringle[i][j] = sacalingTringle[j][i];
   		cout<<tringle[i][j]<<" ";
	   }
	   cout<<endl;
   }
   drawTringle(tringle);
   
   cout<<"Shearing"<<endl;
   for(int i=0; i<3; i++){
   	for(int j=0; j<2; j++){
   		tringle[i][j] = shearingTringle[j][i];
   		cout<<tringle[i][j]<<" ";
	   }
	   cout<<endl;
   }
   drawTringle(tringle);
   
   
   
   
   
   
   while(!kbhit()){
   	delay(100);
   }
}



# include "iGraphics.h"
#include<stdlib.h>
#include<string.h>
int Nahid244;
int mouse_x;
int mouse_y;

int jhon=1;

int pum_x[2]={1040,-40};
int pum_y[2]={400,400};

int menu=1;

int pum1_x[2]={2, 2};
int pum1_y[2]={-20,-20};

int play=0;

int HighScore=0;
char UserScore[50]={0};

int pum1savepos_x=20;
int pum2savepos_x=20;

int j=0;

int witchcnt=0;
int witchpumcng=0;
int witchpuml=1;
int witchpumr=1;

void chngj(){
	srand(time(NULL));
	j=rand()%4;
	witchpumcng=rand()%10+1;
}


int level=1;
boolean ask=true;


int witch_x[2]={100,700};
int witch_y[2]={350,350};

int cloud_x[3]={150,350,650};
int cloud_y[3]={400,420,390};
int i;

int speed=8;
int speed2=9;

int egg_count=0;
int egg_break=0;

int mposx=0,  mposy;

int bucket_x=200;
int bucket_y=20;

int chicken_baby_x=bucket_x+20;
int chicken_baby_y=50;

char score[100]={0};
char score2[100]={0};

void eggchange(){

    time_t t;
    srand(time(&t));
    i=rand()%4;
	

}
int chicken_y=400;


struct egg{
   int egg_x;
   int egg_y;
   void eggfall(){
	  
       egg_y-=speed;
	   if(egg_count>=20){
		   egg_y-=speed2;
	   }

if(egg_x>=bucket_x+20 && egg_x<=bucket_x+95 && egg_y<=bucket_y+60 && egg_y>=30){
        egg_y=chicken_y;
        egg_count++;
       chicken_baby_y++;

       }
       if(egg_y<=-80){
        egg_y=chicken_y;

       }
       if(chicken_baby_y>50){
        chicken_baby_y+=10;
		if(egg_count>=20){
			chicken_baby_y+=speed2;
		}

       }
       if(chicken_baby_y>=512){
        chicken_baby_y=50;
        chicken_baby_x=bucket_x+20;
       }
	   if(egg_y<0){
		   egg_break++;
        iShowBMP2(egg_x,5,"image\\crack.bmp",0);
	   }

   }

}egg[4];
//////////////////////////////////////
struct player{
    char name[20];
    int scr;
 };
 typedef struct player pl;
  pl p[3];
  int k;
  char scr[10][10];
  char nam[20];
  int index=0;
  char namchng[10];
/////////////////////////////////////

int count=0;
void change(){
  srand(time(NULL));

  count=rand()%2+1;

}



void iDraw()
{
    iClear();
	
	if(jhon>12){
		jhon=1;
	}


	if(menu<1){
		menu=5;
	}
	if(menu>5){
		menu=1;
	}

	if(play==0){
	iShowBMP2(0,0,"image\\main1.bmp",0);

	if(menu!=1){
		iShowBMP2(350,400,"image\\play_sml.bmp",0);}
	if(menu==1){
		iShowBMP2(350,400,"image\\play_bg.bmp",0);}
	if(menu!=2){

		iShowBMP2(350,300,"image\\fame_sml.bmp",0);}
	if(menu==2){

		iShowBMP2(350,300,"image\\fame_bg.bmp",0);
	
	}
   if(menu!=3){
	   iShowBMP2(350,200,"image\\about_sml.bmp",0);}
   if(menu==3){
	   iShowBMP2(350,200,"image\\about_bg.bmp",0);}
   if(menu!=4){
	iShowBMP2(350,100,"image\\exit_sml.bmp",0);
   }
   if(menu==4){
	   iShowBMP2(350,100,"image\\exit_bg.bmp",0);}
	if(menu!=5){
         iShowBMP2(350,30,"image\\name.bmp",0);	
	}
	if(menu==5){
	     iShowBMP2(350,30,"image\\name_bg.bmp",0);	

		 

	}
	}
  
	if(play==2){
		iShowBMP2(0,0,"image\\fame.bmp",0);
//////////////////////////////////////////
		 FILE *fp=fopen("fame.dat","rb");
		 for(k=0;k<3;k++){
		    fread(&p[k],sizeof(p[0]),1,fp); 
		 }
		 fclose(fp);
		 iText(360,350,p[0].name,GLUT_BITMAP_TIMES_ROMAN_24);
		  iText(360,290,p[1].name,GLUT_BITMAP_TIMES_ROMAN_24);
		   iText(360,230,p[2].name,GLUT_BITMAP_TIMES_ROMAN_24);

		   itoa(p[0].scr,scr[0],10);
		    itoa(p[1].scr,scr[1],10);
			 itoa(p[2].scr,scr[2],10);

			 iText(460,350,scr[0],GLUT_BITMAP_TIMES_ROMAN_24);
			 iText(460,290,scr[1],GLUT_BITMAP_TIMES_ROMAN_24);
			 iText(460,230,scr[2],GLUT_BITMAP_TIMES_ROMAN_24);
   ///////////
		    iText(460,100,nam,GLUT_BITMAP_TIMES_ROMAN_24);
			if(egg_count>p[2].scr && egg_count<p[1].scr && egg_count<p[0].scr){
				
				p[2].scr=egg_count;
				strcpy(p[2].name,nam);
				fp=fopen("fame.dat","wb");
				for(k=0;k<3;k++){
				  fwrite(&p[k],sizeof(p[k]),1,fp);
				}

				fclose(fp);

			}
			if(egg_count>p[1].scr && egg_count>p[2].scr && egg_count<p[0].scr){

				p[2].scr=p[1].scr;
				strcpy(p[2].name,p[1].name);

				p[1].scr=egg_count;
				strcpy(p[1].name,nam);
				fp=fopen("fame.dat","wb");
				for(k=0;k<3;k++){
				  fwrite(&p[k],sizeof(p[k]),1,fp);
				}

				fclose(fp);

			}
			if(egg_count>p[0].scr){

				p[2].scr=p[1].scr;
				strcpy(p[2].name,p[1].name);

				p[1].scr=p[0].scr;
				strcpy(p[1].name,p[0].name);

			p[0].scr=egg_count;
				strcpy(p[0].name,nam);
				fp=fopen("fame.dat","wb");
				for(k=0;k<3;k++){
				  fwrite(&p[k],sizeof(p[k]),1,fp);
				}

				fclose(fp);
			}
	}
	if(play==3){
		iShowBMP2(0,0,"image\\about.bmp",0);
	}
	if(play==5){
	   iShowBMP2(0,0,"image\\main1.bmp",0);
	      iText(460,100,nam,GLUT_BITMAP_TIMES_ROMAN_24);

	}
	if(play==4){
		exit(0);
	}

	if(play==1){

	if(egg_count<0){
	ask=false;
	egg_count=0;
	
	}
	
	if(witchpuml>17){
		witchpuml=1;
	}
	if(witchpumr>17){
		witchpumr=1;
	}

	 witchcnt++;
	 if( witchcnt>=7){
		  witchcnt=0;
	 }

	if(egg_count==20){
		level=2;
	}
	if((egg_break-36)/9>=10){
		ask=false;
		
	}

   if(level==1){

	iShowBMP2(0,0,"image\\background.bmp",0);
	

	if(ask==true){
	cloud_x[0]++;
	cloud_x[1]++;
	cloud_x[2]++;


if(cloud_x[0]>=1030){
    cloud_x[0]=-20;
}
if(cloud_x[1]>=1030){
    cloud_x[1]=-20;
}
if(cloud_x[2]>=1030){
    cloud_x[2]=-20;
}
iShowBMP2(cloud_x[0],cloud_y[0],"image\\cloud.bmp",0);
iShowBMP2(cloud_x[1],cloud_y[1],"image\\cloud.bmp",0);
iShowBMP2(cloud_x[2],cloud_y[2],"image\\cloud.bmp",0);


    egg[0].egg_x=100;
egg[1].egg_x=300;
egg[2].egg_x=600;
egg[3].egg_x=800;
   if(i==0||egg[0].egg_y<=chicken_y-20){
    egg[0].eggfall();
   }
   if(i==1||egg[1].egg_y<=chicken_y-20){
    egg[1].eggfall();

   }
   if(i==2||egg[2].egg_y<=chicken_y-20){
    egg[2].eggfall();

   }
   if(i==3||egg[3].egg_y<=chicken_y-20){
    egg[3].eggfall();


   }

iShowBMP2(egg[0].egg_x,egg[0].egg_y,"image\\egg.bmp",0);
iShowBMP2(egg[1].egg_x,egg[1].egg_y,"image\\egg.bmp",0);
iShowBMP2(egg[2].egg_x,egg[2].egg_y,"image\\egg.bmp",0);
iShowBMP2(egg[3].egg_x,egg[3].egg_y,"image\\egg.bmp",0);
if(count==1){
    iShowBMP2(100,chicken_y,"image\\ckin.bmp",0);
    iShowBMP2(300,chicken_y,"image\\ckin_2.bmp",0);
    iShowBMP2(600,chicken_y,"image\\ckin.bmp",0);
     iShowBMP2(800,chicken_y,"image\\ckin_2.bmp",0);

}
if(count==2){
    iShowBMP2(100,chicken_y,"image\\ckin_2.bmp",0);
    iShowBMP2(300,chicken_y,"image\\ckin.bmp",0);
    iShowBMP2(600,chicken_y,"image\\ckin_2.bmp",0);
    iShowBMP2(800,chicken_y,"image\\ckin.bmp",0);
}
iShowBMP2(90,chicken_y-45,"image\\box.bmp",0);
iShowBMP2(290,chicken_y-45,"image\\box.bmp",0);
iShowBMP2(590,chicken_y-45,"image\\box.bmp",0);
iShowBMP2(790,chicken_y-45,"image\\box.bmp",0);

iShowBMP2(chicken_baby_x,chicken_baby_y,"image\\chicken_baby.bmp",0);
iShowBMP2(bucket_x,bucket_y,"image\\bucket.bmp",0);}}
   if(level==2){
	   iShowBMP(0,0,"image\\back2.bmp");
	  
	   if(ask==true){
	   witch_x[0]++;
	   witch_x[1]--;
	   if(witch_x[0]>=1030){
		   witch_x[0]=0;
	   }
	   if(witch_x[1]<=-10){
		   witch_x[1]=1030;
	   }

	



    egg[0].egg_x=100;
egg[1].egg_x=300;
egg[2].egg_x=600;
egg[3].egg_x=800;
   if(i==0||egg[0].egg_y<=chicken_y-20){
    egg[0].eggfall();
   }
   if(i==1||egg[1].egg_y<=chicken_y-20){
    egg[1].eggfall();

   }
   if(i==2||egg[2].egg_y<=chicken_y-20){
    egg[2].eggfall();

   }
   if(i==3||egg[3].egg_y<=chicken_y-20){
    egg[3].eggfall();


   }

iShowBMP2(egg[0].egg_x,egg[0].egg_y,"image\\egg.bmp",0);
iShowBMP2(egg[1].egg_x,egg[1].egg_y,"image\\egg.bmp",0);
iShowBMP2(egg[2].egg_x,egg[2].egg_y,"image\\egg.bmp",0);
iShowBMP2(egg[3].egg_x,egg[3].egg_y,"image\\egg.bmp",0);
if(count==1){
    iShowBMP2(100,chicken_y,"image\\ckin.bmp",0);
    iShowBMP2(300,chicken_y,"image\\ckin_2.bmp",0);
    iShowBMP2(600,chicken_y,"image\\ckin.bmp",0);
     iShowBMP2(800,chicken_y,"image\\ckin_2.bmp",0);

}
if(count==2){
    iShowBMP2(100,chicken_y,"image\\ckin_2.bmp",0);
    iShowBMP2(300,chicken_y,"image\\ckin.bmp",0);
    iShowBMP2(600,chicken_y,"image\\ckin_2.bmp",0);
    iShowBMP2(800,chicken_y,"image\\ckin.bmp",0);
}
iShowBMP2(90,chicken_y-45,"image\\box.bmp",0);
iShowBMP2(290,chicken_y-45,"image\\box.bmp",0);
iShowBMP2(590,chicken_y-45,"image\\box.bmp",0);
iShowBMP2(790,chicken_y-45,"image\\box.bmp",0);

 if( witchcnt>=0 && witchcnt<=3 && !(witchpumcng==10 || witchpumr>=2 )){
		   iShowBMP2(witch_x[0],witch_y[0],"image\\witch_r.bmp",0);
	   }
	   if( witchcnt>=4 && witchcnt<=6 && !(witchpumcng==10 || witchpumr>=2 )){
		   iShowBMP2(witch_x[0],witch_y[0],"image\\witch_r1.bmp",0);
	   }

	   if( witchcnt>=0 && witchcnt<=3 && !(witchpumcng==5 || witchpuml>=2 ) ){
		   iShowBMP2(witch_x[1],witch_y[1],"image\\witch_l1.bmp",0);
	   }

	    if( witchcnt>=4 && witchcnt<=6 && !(witchpumcng==5 || witchpuml>=2 )){
		   iShowBMP2(witch_x[1],witch_y[1],"image\\witch_l.bmp",0);
	   }
	   if(witchpumcng==5 || witchpuml>=2 ){
		   if(witchpuml>=1 && witchpuml<=5){
			   iShowBMP2(witch_x[1],witch_y[1],"image\\witch11.bmp",0);
		   }
		    if(witchpuml>=6 && witchpuml<=11){
			   iShowBMP2(witch_x[1],witch_y[1],"image\\witch12.bmp",0);
		   }
			 if(witchpuml>=12 && witchpuml<=16){
			   iShowBMP2(witch_x[1],witch_y[1],"image\\witch13.bmp",0);
		   }
		 if(witchpuml>16){
			   iShowBMP2(witch_x[1],witch_y[1],"image\\witch14.bmp",0);
		   }
		  witchpuml++;
	}

	   if(witchpuml==16){
	       pum1savepos_x=witch_x[1];
		   pum1_y[0]=witch_y[1]+50;
	   }
	   if(pum1_y[0]<401){
	       pum1_y[0]-=6;
		   pum1_x[0]= pum1savepos_x;
	   }

	   iShowBMP2(pum1_x[0],pum1_y[0],"image\\pum.bmp",0);


	    if(witchpumcng==10 || witchpumr>=2 ){
		   if(witchpumr>=1 && witchpumr<=6){
			   iShowBMP2(witch_x[0],witch_y[0],"image\\witch1.bmp",0);
		   }
		    if(witchpumr>=7 && witchpumr<=11){
			   iShowBMP2(witch_x[0],witch_y[0],"image\\witch2.bmp",0);
		   }
			 if(witchpumr>=12 && witchpumr<=16){
			   iShowBMP2(witch_x[0],witch_y[0],"image\\witch3.bmp",0);
		   }
		 if(witchpumr==17){
			   iShowBMP2(witch_x[0],witch_y[0],"image\\witch4.bmp",0);
		   }
		  witchpumr++;
	}
		if(witchpumr==16){
	       pum2savepos_x=witch_x[0];
		   pum1_y[1]=witch_y[0]+30;
	   }
	   if(pum1_y[1]<401){
	       pum1_y[1]-=6;
		   pum1_x[1]= pum2savepos_x+50;
	   }

	   iShowBMP2(pum1_x[1],pum1_y[1],"image\\pum.bmp",0);

iShowBMP2(chicken_baby_x,chicken_baby_y,"image\\chicken_baby.bmp",0);
iShowBMP2(bucket_x,bucket_y,"image\\bucket.bmp",0);

if(j==0 || pum_y[0]<399){
	pum_x[0]-=4;
	pum_y[0]-=5;

}
if(pum_y[0]<-20){
	pum_x[0]=1040;
    pum_y[0]=500;
}

if(j==1 || pum_y[1]<399){
	pum_x[1]+=4;
	pum_y[1]-=5;

}
if(pum_y[1]<-20){
	pum_x[1]=-40;
    pum_y[1]=500;
}



if(pum_x[0]>=bucket_x+20 && pum_x[0]<=bucket_x+95 && pum_y[0]<=bucket_y+60 && pum_y[0]>=30){
	
	egg_count-=1;
	 iShowBMP2(pum_x[0]-50,pum_y[0]-50,"image\\boom.bmp",0);
	
}
if(pum_x[1]>=bucket_x+20 && pum_x[1]<=bucket_x+95 && pum_y[1]<=bucket_y+60 && pum_y[1]>=30){
	
	egg_count-=1;
	 iShowBMP2(pum_x[1]-50,pum_y[1]-50,"image\\boom.bmp",0);
}
if(pum1_x[0]>=bucket_x+20 && pum1_x[0]<=bucket_x+95 && pum1_y[0]<=bucket_y+60 && pum1_y[0]>=30){
	
	egg_count-=1;
	iShowBMP2(pum1_x[0]-50,pum1_y[0]-50,"image\\boom.bmp",0);
}
if(pum1_x[1]>=bucket_x+20 && pum1_x[1]<=bucket_x+95 && pum1_y[1]<=bucket_y+60 && pum1_y[1]>=30){
	
	egg_count-=1;
	iShowBMP2(pum1_x[1]-50,pum1_y[1]-50,"image\\boom.bmp",0);
}



iShowBMP2(pum_x[0],pum_y[0],"image\\pum.bmp",0);
iShowBMP2(pum_x[1],pum_y[1],"image\\pum.bmp",0);


	   }}
itoa(egg_count,score,10);


	itoa((egg_break-36)/9,score2,10);


iShowBMP2(5,5,"image\\score.bmp",0);

iText(90,84,score,GLUT_BITMAP_TIMES_ROMAN_24);
iText(90,33,score2,GLUT_BITMAP_TIMES_ROMAN_24);

if(ask==false){
	 iShowBMP2(400,200,"image\\Scoreboard1.bmp",0);}

 if(ask==false){
 FILE *fp=fopen("gameScore.dat","rb");
 fread(&HighScore,sizeof(HighScore),1,fp);
// iText(430,270,"press n to exit",GLUT_BITMAP_TIMES_ROMAN_24);
 fclose(fp);
 if(HighScore>egg_count){
	 
 }
 else{
	 fp=fopen("gameScore.dat","wb");
	 fwrite(&egg_count,sizeof(egg_count),1,fp);
	 
	 HighScore=egg_count;
	
	 fclose(fp);

 }
		itoa(HighScore,UserScore,10);
	 iText(560,420,UserScore,GLUT_BITMAP_TIMES_ROMAN_24);
	 iText(560,390,score,GLUT_BITMAP_TIMES_ROMAN_24);

	 if(jhon>=1 && jhon<=4 ){
		 iShowBMP2(5,5,"image\\jhoncena1.bmp",0);
	 }
	  if(jhon>=5 && jhon<=8 ){
		 iShowBMP2(5,5,"image\\jhoncena2.bmp",0);
	 }
	   if(jhon>=8 && jhon<=12 ){
		 iShowBMP2(5,5,"image\\jhoncena3.bmp",0);
	 }
	   jhon++;

	 // fclose(fp);
	}
  
 }
}

void iMouseMove(int mx, int my)
{
bucket_x=mx;
if(chicken_baby_y<100){
chicken_baby_x=mx+10;}


}


void iMouse(int button, int state, int mx, int my)
{
	

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>=350 && mx<=606 && my>=400 && my<=435)
	{
		
		
	}
	
}


void iPassiveMouseMove(int mx,int my)
{
	mouse_x=mx;
	mouse_y=my;

	
}


void iKeyboard(unsigned char key)
{
	if(play==5){
	    nam[index]=key;
		index++;
	}
	
}


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_DOWN)
	{
		menu++;

	}
	if(key == GLUT_KEY_UP)
	{
		menu--;

	}
	if(key == GLUT_KEY_RIGHT && menu==1)
	{
		play=1;

	}
	if(key == GLUT_KEY_RIGHT && menu==2)
	{
		play=2;

	}
	if(key == GLUT_KEY_RIGHT && menu==3)
	{
		play=3;

	}
	if(key == GLUT_KEY_RIGHT && menu==4)
	{
		play=4;

	}
	if(key == GLUT_KEY_RIGHT && menu==5)
	{
		play=5;

	}
	if(key == GLUT_KEY_LEFT)
	{
		play=0;

	}

}

int main()
{
    iSetTimer(500,change);
    iSetTimer(50,eggchange);
	iSetTimer(500,chngj);

	iInitialize(1024,512, "CATCH THE EGG");
	return 0;
}

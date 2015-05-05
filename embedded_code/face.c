#include<at89x51.h>
#define LCDPort P1
  sbit RS=P0^0;
  sbit RW=P0^1;
  sbit EN=P0^2;
  sbit RELAY1=P2^0;
	sbit RELAY2=P2^1;
	sbit MOTOR1=P2^2;
  sbit MOTOR2=P2^3;
void delay(int t)
{
  int i;
  while(t>0)
  {
   i=1275;
   while(i>0)i--;t--;
   }
   }
void LCDCommand(char c)
   {
		 
    RS=0;
	RW=0;
	LCDPort=c;
	EN=1;
	delay(1);
	EN=0;
	return;
	}
void LCDData(char c)
	{
	 RS=1;
	 RW=0;
	 LCDPort=c;
	 EN=1;
	 delay(1);
	 EN=0;
	 return;
	 }
	 
void LCDInit()
	   {
	        LCDCommand(0x38);
	        LCDCommand(0x06);
          LCDCommand(0x0c);
          LCDCommand(0x01);
     }			 
void LCDPuts(char *s)
	    {
				int i;
				for(i=0;s[i];i++) LCDData(s[i]);
		  }		
void ini()
 {
  TMOD=0X20;
  SCON=0X50;
  TH1=0Xfd;
  TR1=1;
 }
char rx()
	 {
	  char c;
	  while(RI==0);
	  c=SBUF;
	  RI=0;
	  return c;
	 }
void tx(char c)
  {
    SBUF=c;
	  while(TI==0);
	  TI=0;
  }
void main()
    {
	    char c;
			int cnt1;
			int cnt2;
			int cnt3;
			int cnt4;
			int cnt5;
			cnt1=0;
			cnt2=0;
			cnt3=0;
			cnt4=0;
			cnt5=0;
		  RELAY1=0;
      RELAY2=0;
			MOTOR1=0;
			MOTOR2=0;
			LCDInit();
      LCDPuts("ALL DEVICES OFF ");		
		  ini();
      while(1)
       {
        c=rx();
        tx(c);
			  if(c=='A'||c=='a')
				   {
				   RELAY1=1;
					 RELAY2=1;
					 cnt1=cnt1+1;
						 
						{
						 MOTOR1=1;
					   MOTOR2=0;
						 delay(12);
						 MOTOR1=0;
			       MOTOR2=0;
					 }
					 LCDCommand(0x80);
					 LCDPuts(" ROOM 1 ACTIVE");
					}
					if(c=='A'||c=='a')
					{	
		      if(cnt1==2)
			     { cnt1=0;
					   RELAY1=0;
					   RELAY2=0;
             {
							 MOTOR1=0;
               MOTOR2=1;
               delay(12);
						   MOTOR1=0;
			         MOTOR2=0;
						 }							 
						 LCDCommand(0x80);
					   LCDPuts("ROOM 1 DE-ACTIVE");
					  }
        }
           if(c=='B'||c=='b')
				   {
				   RELAY1=1;
					 RELAY2=1;
					 cnt2=cnt2+1;
						 
						{
						 MOTOR1=1;
					   MOTOR2=0;
						 delay(12);
						 MOTOR1=0;
			       MOTOR2=0;
					 }
					 LCDCommand(0x80);
					 LCDPuts("ROOM 2 ACTIVE");
    }
         if(c=='B'||c=='b')
					{	
		      if(cnt2==2)
			     { cnt2=0;
					   RELAY1=0;
					   RELAY2=0;
             {
							 MOTOR1=0;
               MOTOR2=1;
               delay(12);
						   MOTOR1=0;
			         MOTOR2=0;
						 }							 
						 LCDCommand(0x80);
					   LCDPuts("ROOM 1 DE-ACTIVE");
					  }
        }   	
			if(c=='C'||c=='c')
				   {
				   RELAY1=1;
					 RELAY2=1;
					 cnt3=cnt3+1;
						 
						{
						 MOTOR1=1;
					   MOTOR2=0;
						 delay(12);
						 MOTOR1=0;
			       MOTOR2=0;
					 }
					 LCDCommand(0x80);
					 LCDPuts("ROOM 3 ACTIVE");
    }	
		    if(c=='C'||c=='c')
					{	
		      if(cnt3==2)
			     { cnt3=0;
					   RELAY1=0;
					   RELAY2=0;
             {
							 MOTOR1=0;
               MOTOR2=1;
               delay(12);
						   MOTOR1=0;
			         MOTOR2=0;
						 }							 
						 LCDCommand(0x80);
					   LCDPuts("ROOM 3 DE-ACTIVE");
					  }
        }   	
			if(c=='D'||c=='d')
				   {
				   RELAY1=1;
					 RELAY2=1;
					 cnt4=cnt4+1;
						 
						{
						 MOTOR1=1;
					   MOTOR2=0;
						 delay(12);
						 MOTOR1=0;
			       MOTOR2=0;
					 }
					 LCDCommand(0x80);
					 LCDPuts("ROOM 4 ACTIVE");
    }		
		      if(c=='D'||c=='d')
					{	
		      if(cnt4==2)
			     { cnt4=0;
					   RELAY1=0;
					   RELAY2=0;
             {
							 MOTOR1=0;
               MOTOR2=1;
               delay(12);
						   MOTOR1=0;
			         MOTOR2=0;
						 }							 
						 LCDCommand(0x80);
					   LCDPuts("ROOM 4 DE-ACTIVE");
					  }
        }   	
				if(c=='E'||c=='e')
				   {
				   RELAY1=1;
					 RELAY2=1;
					 cnt5=cnt5+1;
						 
						{
						 MOTOR1=1;
					   MOTOR2=0;
						 delay(12);
						 MOTOR1=0;
			       MOTOR2=0;
					 }
					 LCDCommand(0x80);
					 LCDPuts("ROOM 5 ACTIVE");
    }		
		    if(c=='E'||c=='e')
					{	
		      if(cnt5==2)
			     { cnt5=0;
					   RELAY1=0;
					   RELAY2=0;
             {
							 MOTOR1=0;
               MOTOR2=1;
               delay(12);
						   MOTOR1=0;
			         MOTOR2=0;
						 }							 
						 LCDCommand(0x80);
					   LCDPuts("ROOM 5 DE-ACTIVE");
					  }
        }   	
	}
	}
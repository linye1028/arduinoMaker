#define L1 262
#define L2 294
#define L3 330
#define L4 349
#define L5 392
#define L6 440
#define L7 494
#define M1 523
#define M2 587
#define M3 659
#define M4 698
#define M5 784
#define M6 880
#define M7 968
#define H1 1046
#define H2 1175
#define H3 1318
#define H4 1397
#define H5 1568
#define H6 1760
#define H7 1967
#define M0 0
unsigned int song[28]={M5,M5,M6,M5,H1,M7,
                       M5,M5,M6,M5,H2,
                       H1,M5,M5,H5,H3,H1,M7,M6,M0,M0,H4,H4,
                       H3,H1,H2,H1,H1
                      };
unsigned char time1[28]={1,1,2,2,2,4,
					   1,1,2,2,2,
					   4,1,1,2,2,2,2,4,2,2,1,1,
					   2,2,2,6,6,
					  };
void setup() {
	// put your setup code here, to run once:
	pinMode(8,OUTPUT);
  tone(8,song[0]);
}
unsigned song_i=0;
unsigned long preMs=0;
void loop() {
	// put your main code here, to run repeatedly:
	if(millis()-preMs>=200*time1[song_i])
	{
		noTone(8);
		preMs=millis();
    song_i++;
		if(song[song_i]!=M0) 
		{
			delay(50);
			tone(8,song[song_i]);
		} 
			
		
		if(song_i>=28)
		{
      noTone(8);
			song_i=0; 
			tone(8,song[song_i]);
		}
	}
}

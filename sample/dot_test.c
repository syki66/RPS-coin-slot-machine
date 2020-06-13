#include    <stdio.h>
#include    <stdlib.h>
#include    <fcntl.h>
#include    <string.h>

#define dot_dev 	"/dev/dot"

unsigned char row[36][8] ={
	{0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C},   //0
	{0x08, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x1C},   //1
	{0x1C, 0x22, 0x02, 0x02, 0x1C, 0x20, 0x20, 0x3E},   //2
	{0x1C, 0x22, 0x02, 0x1C, 0x02, 0x02, 0x22, 0x1C},   //3
	{0x04, 0x0C, 0x14, 0x24, 0x44, 0x3E, 0x04, 0x04},   //4
	{0x1E, 0x20, 0x20, 0x1C, 0x02, 0x02, 0x22, 0x1C},   //5
	{0x3C, 0x40, 0x40, 0x7C, 0x42, 0x42, 0x42, 0x3C},   //6
	{0x3E, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02},   //7
	{0x1C, 0x22, 0x22, 0x1C, 0x22, 0x22, 0x22, 0x1C},   //8
	{0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C},   //0
	{0x18, 0x24, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42},   //A
	{0x1E, 0x22, 0x22, 0x1E, 0x22, 0x22, 0x22, 0x1E},   //B
	{0x1C, 0x22, 0x02, 0x02, 0x02, 0x02, 0x22, 0x1C},   //C
	{0x38, 0x44, 0x42, 0x42, 0x42, 0x42, 0x44, 0x38},   //D
	{0x3E, 0x20, 0x20, 0x3E, 0x20, 0x20, 0x20, 0x3E},   //E
	{0x3E, 0x20, 0x20, 0x3E, 0x20, 0x20, 0x20, 0x20},   //F
	{0x1C, 0x22, 0x42, 0x40, 0x40, 0x47, 0x42, 0x3C},   //G
	{0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42},   //H
	{0x1C, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x1C},   //I
	{0x1C, 0x08, 0x08, 0x08, 0x08, 0x48, 0x48, 0x30},   //J
	{0x44, 0x48, 0x50, 0x60, 0x50, 0x48, 0x44, 0x44},   //K
	{0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3E},   //L
	{0x81, 0xC3, 0xA5, 0x99, 0x81, 0x81, 0x81, 0x81},   //M
	{0x42, 0x62, 0x52, 0x4A, 0x46, 0x42, 0x42, 0x42},   //N
	{0x3C, 0x42, 0x81, 0x81, 0x81, 0x81, 0x42, 0x3C},   //O
	{0x7C, 0x42, 0x42, 0x42, 0x7C, 0x40, 0x40, 0x40},   //P
	{0x38, 0x44, 0x82, 0x82, 0x82, 0x8A, 0x44, 0x3A},   //Q
	{0x7C, 0x42, 0x42, 0x42, 0x7C, 0x48, 0x44, 0x42},   //R
	{0x3C, 0x42, 0x40, 0x3C, 0x02, 0x02, 0x42, 0x3C},   //S
	{0x3E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08},   //T
	{0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C},   //U
	{0x81, 0x42, 0x42, 0x42, 0x24, 0x24, 0x24, 0x18},   //V
	{0x81, 0x99, 0x99, 0x99, 0x99, 0x99, 0x5A, 0x24},   //W
	{0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81},   //X
	{0x81, 0x81, 0x42, 0x42, 0x3C, 0x18, 0x18, 0x18},   //Y
	{0xFF, 0x03, 0x02, 0x04, 0x08, 0x10, 0x60, 0xFF},   //Z
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}	//blank
};

unsigned int DOTTest(int val){

	unsigned char dot_data[8];
	int dot_fd = 0;

	memcpy(dot_data, row[val], 8);

	dot_fd = open(dot_dev, O_RDWR);
	if(dot_fd <0){
		printf("Can't Open Device\n");
	}

	write(dot_fd, &dot_data, sizeof(dot_data));

	return 0;
}
int main()
{
	int i;
	
	for(i=0; i<37; i++){
		DOTTest(i);
		sleep(1);
	}

	return 0;
}

/* EOF */

/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(void)
{

		FILE* file = fopen("card.raw", "r");	



		uint8_t checkimg1[4] = {0xff, 0xd8, 0xff, 0xe0};
		uint8_t checkimg2[4] = {0xff, 0xd8, 0xff, 0xe1};

		
		int count = 0;

		int open = 0;
		FILE* img;

		uint8_t buffer[512];
		uint8_t check[4];
		fread(buffer, 512, 1, file);	

		while(fread(buffer, 512, 1, file) > 0)
		{

				for(int i = 0; i < 4; i++)
				{
						check[i] = buffer[i];
				}


				if((memcmp(checkimg1, check, 4) == 0 ) || (memcmp(checkimg2, check, sizeof(check)) == 0))
				{

						char filename[8];
						sprintf(filename, "%03d.jpg", count);

						if(open == 0)
						{
								img = fopen(filename, "w");
								fwrite(buffer, sizeof(buffer), 1, img);
								open = 1;
						}
						if(open == 1)
						{
								fclose(img);
								img = fopen(filename, "w");
								fwrite(buffer, sizeof(buffer), 1, img);
								count++;
						}
				}
				else
				{
						if(open == 1)
						{
								fwrite(buffer, sizeof(buffer), 1, img);
						}
				}
		}
    

    if(img)
    {
      fclose(img);
    }

		fclose(file);
		return 0;
}



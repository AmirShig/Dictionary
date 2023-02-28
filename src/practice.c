#include <stdio.h>
#include <string.h>

void read();
void add();

int main()
{   
    int mode;
    scanf("%d", &mode);
    while(getchar() != '\n');
    switch (mode)
    {
    case 1:   
        read();
        break;
    case 2: 
        add();
        break;
    default:
        break;
    }
    return 0;
}

void read(){
    
    FILE* fp = fopen("eng_rus/words.csv", "r");
 
    if (!fp)
        printf("Can't open file\n");
 
    else {
     
        char buffer[1024];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
 
            char* value = strtok(buffer, ", ");
 
            while (value) {
                // Column 1
                if (column == 0) {
                    printf("Eng :");
                }
 
                // Column 2
                if (column == 1) {
                    printf("\tRus :");
                }
 
                // Column 3
                if (column == 2) {
                    printf("\tStatus :");
                }
 
                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }
 
            printf("\n");
        }
        fclose(fp);
    }
}

void add(){
	
	FILE* fp = fopen("eng_rus/words.csv", "a+");

	char eng[50], rus[50];
	int status;

	if (fp != NULL) {
		
        printf("\nEnter english word\n");
        scanf("%s", eng);
        printf("\n%s\nEnter translate\n", eng);
        scanf("%s", rus);
        printf("\nEnter learn-status\n");
        scanf("%d", &status);

        
        fprintf(fp, "%s, %s, %d\n", eng,
                rus, status);

        printf("\nNew word added");

        fclose(fp);
	} else {
        
		printf("Can't open file\n");
    }	
}
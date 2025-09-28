#include<stdio.h>
#include<string.h>

struct Data {
    char location[110], city[110], type[110], furnish[110];
    long long int price;
    int rooms, bathroom, carpark;
};

struct Data list[5000];
int total = 0;

//DISPLAYING DATA:
void DisplayData(int numOfRows){
	int i;
	 printf("%-25s %-15s %-10s %-6s %-10s %-9s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");

            for (i = 0; i < numOfRows ; i++) {
                printf("%-25s %-15s %-10lld %-6d %-10d %-9d %-10s %-10s\n",
                       list[i].location, list[i].city, list[i].price, list[i].rooms,
                       list[i].bathroom, list[i].carpark, list[i].type, list[i].furnish);
            }
         printf("\n");
}

//CHANGE CASE: Change first letter from lower case to upper case, and after '-'
void UpperCase(char changeCase[], int len){
	int i;
	for(i=0;i<len-1;i++){
		if(changeCase[0] >= 'a' && changeCase[0] <= 'z'){
			changeCase[0] -= 32;
		}
		
		
		if(changeCase[i] == '-'){
			if(!strcmp("Land-area", changeCase) == 0 && !strcmp("Built-up", changeCase) == 0){
				if(changeCase[i+1] >= 'a' && changeCase[i+1] <= 'z'){
				changeCase[i+1] -= 32;
				}
			}
		}
	}
}

//Printing For SortData
void PrintSort(){
	int j;
	for(j=0;j<10;j++){
		printf("%-25s %-15s %-10lld %-6d %-10d %-9d %-10s %-10s\n",
		list[j].location, list[j].city, list[j].price, list[j].rooms,
		list[j].bathroom, list[j].carpark, list[j].type, list[j].furnish);
		}
	printf("\n");
				
				
}

//Display The Title Of The Data
void DisplayDatas(){
	printf("%-25s %-15s %-10s %-6s %-10s %-9s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
}

//To Remove '-' and '_' in ExportData
void HilangElemen(char fileName[], int len){
	int i;
	for(i=0;i<len-1;i++){
		if(fileName[i] == '-' || fileName[i] == '_'){
			fileName[i] = ' ';
		}
	}
}

//Exporting Data
void ExportData(){
	int i;
	char fileName[50];
	printf("File Name: "); scanf(" %s", fileName);
	int len = strlen(fileName);
	HilangElemen(fileName, len);
	if(strstr(fileName, ".csv")==NULL){
		strcat(fileName, ".csv");
	}
	
	FILE *exFile = fopen(fileName, "w");
	
	if (exFile == NULL) {
        printf("Error Opening File for Export\n");
        return;
    }

    fprintf(exFile, "Location,City,Price,Rooms,Bathroom,Carpark,Type,Furnish\n");
    
    for (i = 0; i < total; i++) {
        fprintf(exFile, "%s,%s,%lld,%d,%d,%d,%s,%s\n",
                list[i].location, list[i].city, list[i].price, list[i].rooms,
                list[i].bathroom, list[i].carpark, list[i].type, list[i].furnish);
    }

    fclose(exFile);

    printf("Data Successfully Written To File %s\n\n", fileName);
}

//Searching Data
void SearchData(char chooseColumn[], char searchData[]){
	int i, j;
	int len = strlen(chooseColumn);
	UpperCase(chooseColumn, len);
	
	int searchD, searchLld; searchD =0, searchLld = 0;
//	printf("%s\n", chooseColumn);

	if(strcmp("Location", chooseColumn) == 0 || strcmp("City", chooseColumn) == 0 || strcmp("Price", chooseColumn) == 0 || 
	strcmp("Rooms", chooseColumn) == 0 || strcmp("Bathroom", chooseColumn) == 0 || strcmp("Carpark", chooseColumn) == 0 || 
	strcmp("Type", chooseColumn) == 0 || strcmp("Furnish", chooseColumn) == 0) {
		
		int totalData; totalData=0;
			
		
		
		if(strcmp("Location", chooseColumn) == 0 || strcmp("City", chooseColumn) == 0 || strcmp("Type", chooseColumn) == 0 || strcmp("Furnish", chooseColumn) == 0){
			printf("What data do you want to find? "); scanf(" %s", searchData);
			
			
				int len2 = strlen(searchData);
				UpperCase(searchData, len2);
			
//			printf("%s\n", searchData);
			
			//LOCATION
			if(strcmp("Location", chooseColumn) == 0){
				for(i=0;i<total;i++){
					if(strcmp(list[i].location, searchData) == 0){
						totalData++;
				}
			}
			
				if(totalData == 0){
					printf("Data Not Found!\n"); 
				}
				
				else if(totalData >= 0){
					DisplayDatas();
				}
				
				
				for(j=0;j<total;j++){
					if(strcmp(list[j].location, searchData) == 0){
						printf("%-25s %-15s %-10lld %-6d %-10d %-9d %-10s %-10s\n",
		            	list[j].location, list[j].city, list[j].price, list[j].rooms,
		            	list[j].bathroom, list[j].carpark, list[j].type, list[j].furnish);
	           			}
					}
					printf("\n");	
			}
			
			//CITY
			if(strcmp("City", chooseColumn) == 0){
				for(i=0;i<total;i++){
					if(strcmp(list[i].city, searchData) == 0){
						totalData++;
				}
			}
			
				if(totalData == 0){
					printf("Data Not Found!\n"); 
				}
				
				else if(totalData >= 0){
					DisplayDatas();
				}
				
				for(j=0;j<total;j++){
					if(strcmp(list[j].city, searchData) == 0){
						printf("%-25s %-15s %-10lld %-6d %-10d %-9d %-10s %-10s\n",
		            	list[j].location, list[j].city, list[j].price, list[j].rooms,
		            	list[j].bathroom, list[j].carpark, list[j].type, list[j].furnish);
	           			}
					}
					printf("\n");	
			}
			
			
			//TYPE
			if(strcmp("Type", chooseColumn) == 0){
				for(i=0;i<total;i++){
					if(strcmp(list[i].type, searchData) == 0){
						totalData++;
				}
			}
			
				if(totalData == 0){
					printf("Data Not Found!\n"); 
				}
				
				else if(totalData >= 0){
					DisplayDatas();
				}
				
				for(j=0;j<total;j++){
					if(strcmp(list[j].type, searchData) == 0){
						printf("%-25s %-15s %-10lld %-6d %-10d %-9d %-10s %-10s\n",
		            	list[j].location, list[j].city, list[j].price, list[j].rooms,
		            	list[j].bathroom, list[j].carpark, list[j].type, list[j].furnish);
	           			}
					}
					printf("\n");	
			}
			
			//FURNISH
			if(strcmp("Furnish", chooseColumn) == 0){
				for(i=0;i<total;i++){
					if(strcmp(list[i].furnish, searchData) == 0){
						totalData++;
				}
			}
			
				if(totalData == 0){
					printf("Data Not Found!\n"); 
				}
				
				else if(totalData >= 0){
					DisplayDatas();
				}
				
				for(j=0;j<total;j++){
					if(strcmp(list[j].furnish, searchData) == 0){
						printf("%-25s %-15s %-10lld %-6d %-10d %-9d %-10s %-10s\n",
		            	list[j].location, list[j].city, list[j].price, list[j].rooms,
		            	list[j].bathroom, list[j].carpark, list[j].type, list[j].furnish);
	           			}
					}
					printf("\n");	
			}
		}
		
		else if(strcmp("Rooms", chooseColumn) == 0 || strcmp("Bathroom", chooseColumn) == 0 || strcmp("Carpark", chooseColumn) == 0){
			printf("What data do you want to find? "); scanf(" %d", &searchD); 
			
			//ROOMS
			if(strcmp("Rooms", chooseColumn)==0){
				for(i=0;i<total;i++){
					if(searchD == list[i].rooms){
						totalData++;
					}
				}
				
				if(totalData == 0){
					printf("Data Not Found!\n"); 
				}
				
				else if(totalData >= 0){
					DisplayDatas();
				}
				
				for(j=0;j<total;j++){
					if(searchD == list[j].rooms){
						printf("%-25s %-15s %-10lld %-6d %-10d %-9d %-10s %-10s\n",
		            	list[j].location, list[j].city, list[j].price, list[j].rooms,
		            	list[j].bathroom, list[j].carpark, list[j].type, list[j].furnish);
					}
				}
				printf("\n");
			}
			
			//BATHROOM
			if(strcmp("Bathroom", chooseColumn)==0){
				for(i=0;i<total;i++){
					if(searchD == list[i].bathroom){
						totalData++;
					}
				}
				
				if(totalData == 0){
					printf("Data Not Found!\n"); 
				}
				
				else if(totalData >= 0){
					DisplayDatas();
				}
				
				for(j=0;j<total;j++){
					if(searchD == list[j].bathroom){
						printf("%-25s %-15s %-10lld %-6d %-10d %-9d %-10s %-10s\n",
		            	list[j].location, list[j].city, list[j].price, list[j].rooms,
		            	list[j].bathroom, list[j].carpark, list[j].type, list[j].furnish);
					}
				}
				printf("\n");
			}
			
			//CARPARK
			if(strcmp("Carpark", chooseColumn)==0){
				for(i=0;i<total;i++){
					if(searchD == list[i].carpark){
						totalData++;
					}
				}
				
				if(totalData == 0){
					printf("Data Not Found!\n"); 
				}
				
				else if(totalData >= 0){
					DisplayDatas();
				}
				
				for(j=0;j<total;j++){
					if(searchD == list[j].carpark){
						printf("%-25s %-15s %-10lld %-6d %-10d %-9d %-10s %-10s\n",
		            	list[j].location, list[j].city, list[j].price, list[j].rooms,
		            	list[j].bathroom, list[j].carpark, list[j].type, list[j].furnish);
					}
				}
				printf("\n"); 
			}
		}
		
		else if(strcmp("Price", chooseColumn) == 0){
			printf("What data do you want to find? "); scanf(" %lld", &searchLld); 
			
			if(strcmp("Price", chooseColumn)==0){
				for(i=0;i<total;i++){
					if(searchLld == list[i].price){
						totalData++;
					}
				}
				
//				printf("%d\n", totalData);

				if(totalData == 0){
					printf("Data Not Found!\n"); 
				}
				
				else if(totalData >= 0){
					DisplayDatas();
				}
				
				for(j=0;j<total;j++){
					if(list[j].price == searchLld){
						printf("%-25s %-15s %-10lld %-6d %-10d %-9d %-10s %-10s\n",
		            	list[j].location, list[j].city, list[j].price, list[j].rooms,
		            	list[j].bathroom, list[j].carpark, list[j].type, list[j].furnish);
					}
				}
				printf("\n");
			}	
		}
	}
	
	else{
		printf("Column Not Found!\n\n");	
	}
}

//For Sorting and Swapping Location
void SwapLocation(struct Data *a, struct Data *b) {
    struct Data temp;
    strcpy(temp.location, a->location);
    strcpy(a->location, b->location);
    strcpy(b->location, temp.location);
}

//For Sorting and Swapping City
void SwapCity(struct Data *a, struct Data *b) {
    struct Data temp;
    strcpy(temp.city, a->city);
    strcpy(a->city, b->city);
    strcpy(b->city, temp.city);
}

//For Sorting Type
void SwapType(struct Data *a, struct Data *b) {
    struct Data temp;
    strcpy(temp.type, a->type);
    strcpy(a->type, b->type);
    strcpy(b->type, temp.type);
}

//For Sorting and Swapping Furnish
void SwapFurnish(struct Data *a, struct Data *b) {
    struct Data temp;
    strcpy(temp.furnish, a->furnish);
    strcpy(a->furnish, b->furnish);
    strcpy(b->furnish, temp.furnish);
}

//For Sorting and Swapping Number
void SwapInt(struct Data *a, struct Data *b) {
    struct Data temp = *a;
    *a = *b;
    *b = temp;
}

//Sorting Data
void SortData(char chooseColumn[], char sortData[], struct Data location[]){
	int i, j;
    int len = strlen(chooseColumn);
    UpperCase(chooseColumn, len);

    if(strcmp("Location", chooseColumn) == 0 || strcmp("City", chooseColumn) == 0 || strcmp("Price", chooseColumn) == 0 || 
        strcmp("Rooms", chooseColumn) == 0 || strcmp("Bathroom", chooseColumn) == 0 || strcmp("Carpark", chooseColumn) == 0 || 
        strcmp("Type", chooseColumn) == 0 || strcmp("Furnish", chooseColumn) == 0) {
        
        printf("Sort Ascending Or Descending? "); scanf(" %s", sortData);
        int len2 = strlen(sortData);
        UpperCase(sortData, len2);

        if(strcmp("Ascending", sortData) == 0 || strcmp("Asc", sortData) == 0){
            printf("Data Found. Detail Of Data:\n");
            
            //SORT LOCATION
            if(strcmp("Location", chooseColumn) == 0){
                for (i = 0; i < total-1; i++) {
                    for (j = 0; j < total-i-1; j++) {
                        if (strcmp(list[j].location, list[j+1].location) > 0) {
                            SwapLocation(&list[j], &list[j+1]);
                        }
                    }
                }
                DisplayDatas();
                PrintSort();
            }
			
			//SORT CITY
			else if(strcmp("City", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if (strcmp(list[j].city, list[j+1].city) > 0) {
	            	    	SwapCity(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
				
			//SORT TYPE
			else if(strcmp("Type", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if (strcmp(list[j].type, list[j+1].type) > 0) {
	            	    	SwapType(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
				
				
			//SORT FURNISH
			else if(strcmp("Furnish", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if (strcmp(list[j].furnish, list[j+1].furnish) > 0) {
	            	    	SwapFurnish(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
				
			//SORT ROOMS
			else if(strcmp("Rooms", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if(list[j].rooms > list[j+1].rooms) {
	            	    	SwapInt(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
			
			//SORT BATHROOM
			else if(strcmp("Bathroom", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if(list[j].bathroom > list[j+1].bathroom) {
	            	    	SwapInt(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
					
			//SORT CARPARK
			else if(strcmp("Carpark", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if(list[j].carpark > list[j+1].carpark) {
	            	    	SwapInt(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
				
			//SORT PRICE
			else if(strcmp("Price", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if(list[j].price > list[j+1].price) {
	            	    	SwapInt(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
				
			}
			
		 else if(strcmp("Descending", sortData) == 0 || strcmp("Desc", sortData) == 0){
            printf("Data Found. Detail Of Data:\n");
            
            //SORT LOCATION
            if(strcmp("Location", chooseColumn) == 0){
                for (i = 0; i < total-1; i++) {
                    for (j = 0; j < total-i-1; j++) {
                        if (strcmp(list[j].location, list[j+1].location) < 0) {
                            SwapLocation(&list[j], &list[j+1]);
                        }
                    }
                }
                DisplayDatas();
                PrintSort();
            }
            
            //SORT CITY
			else if(strcmp("City", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if (strcmp(list[j].city, list[j+1].city) < 0) {
	            	    	SwapCity(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
				
			//SORT TYPE
			else if(strcmp("Type", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if (strcmp(list[j].type, list[j+1].type) < 0) {
	            	    	SwapType(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
			
			//SORT FURNISH
			else if(strcmp("Furnish", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if (strcmp(list[j].furnish, list[j+1].furnish) < 0) {
	            	    	SwapFurnish(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
				
			//SORT ROOMS
			else if(strcmp("Rooms", chooseColumn) == 0){
    			for (i = 0; i < total-1; i++) {
       				for (j = 0; j < total-i-1; j++) {
            			if(list[j].rooms < list[j+1].rooms) {
                			SwapInt(&list[j], &list[j+1]);
          					  }			
        					}
    					}
					    DisplayDatas();
					    PrintSort();
					}
			
			//SORT BATHROOM
			else if(strcmp("Bathroom", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if(list[j].bathroom < list[j+1].bathroom) {
	            	    	SwapInt(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
			
			//SORT CARPARK
			else if(strcmp("Carpark", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if(list[j].carpark < list[j+1].carpark) {
	            	    	SwapInt(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
			
			//SORT PRICE
			else if(strcmp("Price", chooseColumn) == 0){
				for (i = 0; i < total-1; i++) {
	        		for (j = 0; j < total-i-1; j++) {
	            		if(list[j].price < list[j+1].price) {
	            	    	SwapInt(&list[j], &list[j+1]);
	            			}
	       				}
	  				}
					DisplayDatas();
					PrintSort();
				}
		}
	
		else{
            printf("Data Not Found! Please Try Again\n\n");
        }
    }
    else{
        printf("Column Not Found!\n\n");
    }
}


int main() {
    FILE *file = fopen("file.csv", "r");
    if (file == NULL) {
        printf("Error Opening File\n");
        return 1;
    }
    
	fscanf(file, "%*[^\n]\n");
	
    while (fscanf(file, "%[^,],%[^,],%lld,%d,%d,%d,%[^,],%[^\n]\n", list[total].location, list[total].city, &list[total].price,
                  &list[total].rooms, &list[total].bathroom, &list[total].carpark, list[total].type, list[total].furnish) == 8) {
        total++;
    }
    fclose(file);

    // Deklarasi Variabel
    int selectNum;
    int numOfRows;
    char chooseColumn[20];
    char searchData[60]; searchData[60] = '\0';
    char sortData[30]; sortData[30] = '\0';


    do {
        printf("What do you want to do?\n");
        printf("1. Display Data\n");
        printf("2. Search Data\n");
        printf("3. Sort Data\n");
        printf("4. Export Data\n");
        printf("5. Exit\n");
        printf("Your Choice: "); scanf(" %d", &selectNum);
        
        if (selectNum == 1) {
            printf("Number Of Rows: ");
            scanf(" %d", &numOfRows); 

           DisplayData(numOfRows);
        }
        
        else if(selectNum == 2) {
        	printf("Choose Column: "); scanf(" %s", chooseColumn);
        	SearchData(chooseColumn, searchData);
		}
		
		else if(selectNum == 3) {
			printf("Choose Column: "); scanf(" %s", chooseColumn);
			SortData(chooseColumn, sortData, list);
		}
		
		else if(selectNum == 4) {
			ExportData();
		}
		
		else if(selectNum > 5 || selectNum < 1){
			printf("Please Input The Right Value...\n\n");
		}
		
    } while (selectNum != 5);
    
    if(selectNum == 5){
    	printf("Exiting...\n");
	}

    return 0;
}


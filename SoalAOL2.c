#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
    char loc[101];
    char city[101];
    long long int price;
    int rooms;
    int bathrooms;
    int carparks;
    char type[101];
    char furnish[101];
}dataa[3941];

void swap(struct data *a, struct data *b){
    struct data temp = *a;
    *a = *b;
    *b = temp;
}

void print(struct data dataa[], int nums){
    int head = 1;

     for (int i = 0; i < 10; i++){
                if (head == 1){
                    printf("Data found. Detail of data: \n");
                    printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s %-25s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");
                }

                printf("%-25s %-25s %-25lld %-25d %-25d %-25d %-25s %-25s\n", dataa[i].loc, dataa[i].city, dataa[i].price, dataa[i].rooms, dataa[i].bathrooms, dataa[i].carparks, dataa[i].type, dataa[i].furnish);
                head = 0;
            }
}

void display(struct data dataa[], int nums){

    printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");
        for (int i = 0; i < nums; i++){
            printf("%-15s %-15s %-15lld %-15d %-15d %-15d %-15s %-15s\n", dataa[i].loc, dataa[i].city, dataa[i].price, dataa[i].rooms, dataa[i].bathrooms, dataa[i].carparks, dataa[i].type, dataa[i].furnish);
        }
}

void export (struct data dataa[], int nums){

    FILE *fp;
    char filename[101];

    printf("File name: ");

    scanf("%[^\n]", filename);
    getchar();

    strcat(filename, ".csv");

    fp = fopen (filename, "w");
        fprintf(fp, "Location,City,Price,Rooms,Bathrooms,CarParks,Type,Furnish\n");

            for (int i = 0; i < nums; i++){
                fprintf(fp, "%s,%s,%lld,%d,%d,%d,%s,%s\n", dataa[i].loc, dataa[i].city, dataa[i].price, dataa[i].rooms, dataa[i].bathrooms, dataa[i].carparks, dataa[i].type, dataa[i].furnish);
                }

    fclose(fp);

    printf("Data sucessfully written to file %s!\n", filename);

}

void search (struct data dataa[], int nums){

    char find[1001];
    int num;
    char col[1001];

    printf("Choose column : ");
    scanf("%s", col);
    getchar();

    int cek = 0;
    int head = 1;

    if (strcmp(col, "Location") == 0){

        printf("What data do you want to find? ");
        scanf("%[^\n]", find);
        getchar();

        for (int i = 0; i < nums; i++){
            
            if (strcmp(dataa[i].loc, find) == 0){

                if (head == 1){
                    printf("Data found. Detail of data: \n");
                    printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s %-25s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");
                }

                printf("%-25s %-25s %-25lld %-25d %-25d %-25d %-25s %-25s\n", dataa[i].loc, dataa[i].city, dataa[i].price, dataa[i].rooms, dataa[i].bathrooms, dataa[i].carparks, dataa[i].type, dataa[i].furnish);
                cek = 1;
                head = 0;
            }

            }

               if (cek == 0){
                printf("Data not found!\n");
            }

    } else if (strcmp(col, "City") == 0){
        printf("What data do you want to find? ");
        scanf("%[^\n]", find);
        getchar();

        for (int i = 0; i < nums; i++){
            
            if (strcmp(dataa[i].city, find) == 0){

                if (head == 1){
                    printf("Data found. Detail of data: \n");
                    printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s %-25s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");
                }

                printf("%-25s %-25s %-25lld %-25d %-25d %-25d %-25s %-25s\n", dataa[i].loc, dataa[i].city, dataa[i].price, dataa[i].rooms, dataa[i].bathrooms, dataa[i].carparks, dataa[i].type, dataa[i].furnish);
                cek = 1;
                head = 0;
            }

            }

               if (cek == 0){
                printf("Data not found!\n");
            }
       
    } else if (strcmp(col, "Price") == 0){
        printf("What data do you want to find? ");
        scanf("%d", &num);
        getchar();

        for (int i = 0; i < nums; i++){
            
            if (dataa[i].price == num){

                if (head == 1){
                    printf("Data found. Detail of data: \n");
                    printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s %-25s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");
                }

                printf("%-25s %-25s %-25lld %-25d %-25d %-25d %-25s %-25s\n", dataa[i].loc, dataa[i].city, dataa[i].price, dataa[i].rooms, dataa[i].bathrooms, dataa[i].carparks, dataa[i].type, dataa[i].furnish);
                cek = 1;
                head = 0;
            }

            }

               if (cek == 0){
                printf("Data not found!\n");
            }

    } else if (strcmp(col, "Rooms") == 0){
        printf("What data do you want to find? ");
        scanf("%d", &num);
        getchar();

          for (int i = 0; i < nums; i++){
            
            if (dataa[i].rooms == num){

                if (head == 1){
                    printf("Data found. Detail of data: \n");
                    printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s %-25s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");
                }

                printf("%-25s %-25s %-25lld %-25d %-25d %-25d %-25s %-25s\n", dataa[i].loc, dataa[i].city, dataa[i].price, dataa[i].rooms, dataa[i].bathrooms, dataa[i].carparks, dataa[i].type, dataa[i].furnish);
                cek = 1;
                head = 0;
            }

            }

               if (cek == 0){
                printf("Data not found!\n");
            }

    } else if (strcmp(col, "Bathrooms") == 0){
        printf("What data do you want to find? ");
        scanf("%d", &num);
        getchar();

          for (int i = 0; i < nums; i++){
            
            if (dataa[i].bathrooms == num){

                if (head == 1){
                    printf("Data found. Detail of data: \n");
                    printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s %-25s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");
                }

                printf("%-25s %-25s %-25lld %-25d %-25d %-25d %-25s %-25s\n", dataa[i].loc, dataa[i].city, dataa[i].price, dataa[i].rooms, dataa[i].bathrooms, dataa[i].carparks, dataa[i].type, dataa[i].furnish);
                cek = 1;
                head = 0;
            }

            }

               if (cek == 0){
                printf("Data not found!\n");
               }

    } else if (strcmp(col, "CarParks") == 0){
        printf("What data do you want to find? ");
        scanf("%d", &num);
        getchar();

          for (int i = 0; i < nums; i++){
            
            if (dataa[i].carparks == num){

                if (head == 1){
                    printf("Data found. Detail of data: \n");
                    printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s %-25s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");
                }

                printf("%-25s %-25s %-25lld %-25d %-25d %-25d %-25s %-25s\n", dataa[i].loc, dataa[i].city, dataa[i].price, dataa[i].rooms, dataa[i].bathrooms, dataa[i].carparks, dataa[i].type, dataa[i].furnish);
                cek = 1;
                head = 0;
            }

            }

               if (cek == 0){
                printf("Data not found!\n");
            }

    } else if (strcmp(col, "Type") == 0){
        printf("What data do you want to find? ");
        scanf("%[^\n]", find);
        getchar();

        for (int i = 0; i < nums; i++){
            
            if (strcmp(dataa[i].type, find) == 0){

                if (head == 1){
                    printf("Data found. Detail of data: \n");
                    printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s %-25s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");
                }

                printf("%-25s %-25s %-25lld %-25d %-25d %-25d %-25s %-25s\n", dataa[i].loc, dataa[i].city, dataa[i].price, dataa[i].rooms, dataa[i].bathrooms, dataa[i].carparks, dataa[i].type, dataa[i].furnish);
                cek = 1;
                head = 0;
            }

            }

               if (cek == 0){
                printf("Data not found!\n");
            }

    } else if (strcmp(col, "Furnish") == 0){
        printf("What data do you want to find? ");
        scanf("%[^\n]", find);
        getchar();

        for (int i = 0; i < nums; i++){
            
            if (strcmp(dataa[i].furnish, find) == 0){

                if (head == 1){
                    printf("Data found. Detail of data: \n");
                    printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s %-25s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");
                }

                printf("%-25s %-25s %-25lld %-25d %-25d %-25d %-25s %-25s\n", dataa[i].loc, dataa[i].city, dataa[i].price, dataa[i].rooms, dataa[i].bathrooms, dataa[i].carparks, dataa[i].type, dataa[i].furnish);
                cek = 1;
                head = 0;
            }

            }

               if (cek == 0){
                printf("Data not found!\n");
            }

    } else {
        printf("Pick a valid column!\n");
    }

}

void sort (struct data dataa[], int nums){

    int head = 1;

    char columnn[1001];

    printf("Choose column: ");
    scanf("%[^\n]", columnn);
    getchar();

    char sortby[1001];
    printf("Sort ascending or descending? ");
    scanf("%s", sortby);
    getchar();

    if (strcmp(columnn, "Location") == 0){

    if (strcmp(sortby, "asc") == 0){
            
            for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (strcmp(dataa[i].loc, dataa[j].loc) > 0){
                        swap(&dataa[i], &dataa[j]);
                    }
                }
            }

        } else if (strcmp(sortby, "des") == 0){

             for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (strcmp(dataa[i].city, dataa[j].city) < 0){
                       swap(&dataa[i], &dataa[j]);
                    }
                }
             }
        }

        print(dataa, 10);
        
    } else if(strcmp(columnn, "Price") == 0){
        if (strcmp(sortby, "asc") == 0){
            
            for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (dataa[i].price > dataa[j].price){
                        swap(&dataa[i], &dataa[j]);
                    }
                }
            }

        } else if (strcmp(sortby, "des") == 0){

             for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (dataa[i].price < dataa[j].price){
                       swap(&dataa[i], &dataa[j]);
                    }
                }
             }
        }

        print(dataa, 10);

    } else if (strcmp(columnn, "Rooms") == 0){
        if (strcmp(sortby, "asc") == 0){
            
            for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (dataa[i].rooms > dataa[j].rooms){
                        swap(&dataa[i], &dataa[j]);
                    }
                }
            }

        } else if (strcmp(sortby, "des") == 0){

             for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (dataa[i].rooms < dataa[j].rooms){
                       swap(&dataa[i], &dataa[j]);
                    }
                }
             }
        }

        print(dataa, 10);

    } else if(columnn, "Bathrooms"){
        if (strcmp(sortby, "asc") == 0){
            
            for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (dataa[i].bathrooms > dataa[j].bathrooms){
                        swap(&dataa[i], &dataa[j]);
                    }
                }
            }

        } else if (strcmp(sortby, "des") == 0){

             for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (dataa[i].bathrooms > dataa[j].bathrooms){
                       swap(&dataa[i], &dataa[j]);
                    }
                }
             }
        }

        print(dataa, 10);
    } else if (strcmp(columnn, "CarParks")){

        if (strcmp(sortby, "asc") == 0){

            for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (dataa[i].carparks > dataa[j].carparks){
                        swap(&dataa[i], &dataa[j]);
                    }
                }
            }

        } else if (strcmp(sortby, "des") == 0){

             for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (dataa[i].carparks > dataa[j].carparks){
                       swap(&dataa[i], &dataa[j]);
                    }
                }
             }
        }

        print(dataa, 10);
    } else if (strcmp(columnn, "Type") == 0){
        if (strcmp(sortby, "asc") == 0){
            
            for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (strcmp(dataa[i].type, dataa[j].type) > 0){
                        swap(&dataa[i], &dataa[j]);
                    }
                }
            }

        } else if (strcmp(sortby, "des") == 0){

             for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (strcmp(dataa[i].type, dataa[j].type) < 0){
                       swap(&dataa[i], &dataa[j]);
                    }
                }
             }
        }

        print(dataa, 10);
    } else if (strcmp(columnn, "Furnish") == 0) {
        if (strcmp(sortby, "asc") == 0){
            
            for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (strcmp(dataa[i].furnish, dataa[j].furnish) > 0){
                        swap(&dataa[i], &dataa[j]);
                    }
                }
            }

        } else if (strcmp(sortby, "des") == 0){

             for (int i = 0; i < nums; i++){
                for (int j = i+1; j < nums; j++){
                    if (strcmp(dataa[i].furnish, dataa[j].furnish) < 0){
                       swap(&dataa[i], &dataa[j]);
                    }
                }
             }
        }

        print(dataa, 10);
    }

}
    

int main (){

    FILE *fp;

    fp = fopen ("file.csv", "r");
    char header[101];

    if (fp == NULL){
        printf("File cannot be opened!\n");
        return 0;
    }

    int choice;
    int loop = 1;
    int i = 0;

    fscanf(fp, "%[^\n]\n", header);

    while(!feof(fp)){
        fscanf(fp, "%[^,],%[^,],%lld,%d,%d,%d,%[^,],%[^\n]\n", dataa[i].loc, dataa[i].city, &dataa[i].price, &dataa[i].rooms, &dataa[i].bathrooms, &dataa[i].carparks, dataa[i].type, dataa[i].furnish);
        i++;
    }

    while(loop == 1){

    printf("What do you want to do?\n");
    printf("1. Display data\n");
    printf("2. Search data\n");
    printf("3. Sort data\n");
    printf("4. Export data\n");
    printf("5. Exit \n");
    printf("Your choice : ");
    scanf("%d", &choice);
    getchar();

    switch(choice){

        case 1:

        printf("Number of rows : ");
        int rows;
        scanf("%d", &rows);
        getchar();

        display(dataa, rows);
        break;

        case 2:

        search(dataa, i);
        break;

        case 3:

        sort(dataa, i);
        break;

        case 4:

        export(dataa, i);
        break;

        case 5:
            system("cls");
            printf("Program Ended!\n");
            loop = 0;
            break;

        default:
            printf("Pick a valid choice\n\n");

    }

    }

    fclose(fp);

    return 0;
}
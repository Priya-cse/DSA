#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Declaring structure for Electronic Appliances
typedef struct Electronics
{
    char name[20];
    int productNo;
    float price;
    char brand[10];
    float rating;
    char extra[30];
    int type;
}EA;

// Declaring structure array for Electronic Appliances
EA elec[200];
int count1 = 0;

// Declaring structure array for found products from sub-string search
EA found1[100];

// Declaring structure for Clothing and Accessories
typedef struct Clothing
{
    char name[15];
    int productNo;
    float price;
    char color[5];
    char brand[10];
    float rating;
    char size[5];
    char user[5];
    int type;
}CA;

// Declaring structure array for Clothing and Accessories
CA cloth[200];
int count2 = 0;

// Declaring structure array for found products from sub-string search
CA found2[100];

// Declaring structure for Furnitures
typedef struct Furniture
{
    char name[15];
    int productNo;
    float price;
    char color[5];
    char brand[10];
    float rating;
    char size[5];
    int type;
}FN;

// Declaring structure array for Furnitures
FN furn[200];
int count3 = 0;

// Declaring structure array for found products from sub-string search
FN found3[100];

// Declaring structure for Sports and Fitness
typedef struct Sports
{
    char name[15];
    int productNo;
    float price;
    char color[5];
    char brand[10];
    float rating;
    char extra[25];
    int type;
}SF;

// Declaring structure array for Sports and Fitness
SF sport[200];
int count4 = 0;

// Declaring structure array for found products from sub-string search
SF found4[100];

// Declaring structure for Healthcare and Cosmetics
typedef struct Healthcare
{
    char name[15];
    int productNo;
    float price;
    char color[5];
    char brand[10];
    float rating;
    int type;
}HC;

// Declaring structure array for Healthcare and Cosmetics
HC heal[100];
int count5 = 0;

// Declaring structure array for found products from sub-string search
HC found5[100];

// Declaring structure for Grocery
typedef struct Grocery
{
    char name[15];
    int productNo;
    float price;
    char brand[10];
    float rating;
    char quantity[5];
    int type;
}GR;

// Declaring structure array for Grocery
GR groc[100];
int count6 = 0;

// Declaring structure array for found products from sub-string search
GR found6[100];

// Declaring structure for cart
typedef struct cart
{
    char productName[15];
    int productNo;
    float price;
    char brand[15];
    int quantity;
    struct cart *next;
}CART;

// Pointer to initialize
CART *start = NULL;

// Function Prototyping
void load_from_file();
void menu();
void electronics();
void clothing();
void furniture();
void sports();
void healthcare();
void grocery();
void sort_elec1(EA a[], int);
void sort_elec2(EA a[], int);
void sort_cloth1(CA a[], int);
void sort_cloth2(CA a[], int);
void sort_furn1(FN a[], int);
void sort_furn2(FN a[], int);
void sort_sport1(SF a[], int);
void sort_sport2(SF a[], int);
void sort_heal1(HC a[], int);
void sort_heal2(HC a[], int);
void sort_groc1(GR a[], int);
void sort_groc2(GR a[], int);
void search();
void displayCart();
void addToCart(char *, int, float, char *, int);
void discount();
void order();

// Main Function
int main()
{
    // Loads products from files
    load_from_file();
    // Welcome note
    printf("----------------AMAZON----------------\n");
    printf("Earth's most customer centric company\n");
    // Displays main menu
    menu();
    return 0;
}

/**
Function Name: load_from_file
Input Params: NILL
Return Type: void
Description: Loads all the products from the files to the data structures
**/
void load_from_file()
{
    FILE *fp1;

    // Open the file in read mode
    fp1 = fopen("electronics.txt", "r");

    // Check if the file was successfully opened
    if (fp1 == NULL)
    {
        printf("File Not found\n");
        return;
    }

    // Until the end of the file, read all the file data
    while(!feof(fp1))
    {
        fscanf(fp1,"%[^\n]s%[^\n]d%[^\n]f%[^\n]s%[^\n]f%[^\n]s%[^\n]d", elec[count1].name, &elec[count1].productNo, &elec[count1].price, elec[count1].brand, &elec[count1].rating, elec[count1].extra, &elec[count1].type );
        count1 ++;
    }
    count1 --;
    fclose(fp1);

    FILE *fp2;

    // Open the file in read mode
    fp2 = fopen("clothing.txt", "r");

    // Check if the file was successfully opened
    if (fp2 == NULL)
    {
        printf("File Not found\n");
        return;
    }

    // Until the end of the file, read all the file data
    while(!feof(fp2))
    {
        fscanf(fp2,"%[^\n]s%[^\n]d%[^\n]f%[^\n]s%[^\n]s%[^\n]f%[^\n]s%[^\n]s%[^\n]d", cloth[count2].name, &cloth[count2].productNo, &cloth[count2].price, cloth[count2].color, cloth[count2].brand, &cloth[count2].rating, cloth[count2].size, cloth[count2].user, &cloth[count2].type );
        count2 ++;
    }
    count2 --;
    fclose(fp2);

    FILE *fp3;

    // Open the file in read mode
    fp3 = fopen("furniture.txt", "r");

    // Check if the file was successfully opened
    if (fp3 == NULL)
    {
        printf("File Not found\n");
        return;
    }

    // Until the end of the file, read all the file data
    while(!feof(fp3))
    {
        fscanf(fp3,"%[^\n]s%[^\n]d%[^\n]f%[^\n]s%[^\n]s%[^\n]f%[^\n]s%[^\n]d", furn[count3].name, &furn[count3].productNo, &furn[count3].price, furn[count3].color, furn[count3].brand, &furn[count3].rating, furn[count3].size, &furn[count3].type );
        count3 ++;
    }
    count3 --;
    fclose(fp3);

    FILE *fp4;

    // Open the file in read mode
    fp4 = fopen("sports.txt", "r");

    // Check if the file was successfully opened
    if (fp4 == NULL)
    {
        printf("File Not found\n");
        return;
    }

    // Until the end of the file, read all the file data
    while(!feof(fp4))
    {
        fscanf(fp4,"%[^\n]s%[^\n]d%[^\n]f%[^\n]s%[^\n]s%[^\n]f%[^\n]s%[^\n]d", sport[count4].name, &sport[count4].productNo, &sport[count4].price, sport[count4].color, sport[count4].brand, &sport[count4].rating, sport[count4].extra, &sport[count4].type );
        count4 ++;
    }
    count4 --;
    fclose(fp4);

    FILE *fp5;

    // Open the file in read mode
    fp5 = fopen("healthcare.txt", "r");

    // Check if the file was successfully opened
    if (fp5 == NULL)
    {
        printf("File Not found\n");
        return;
    }

    // Until the end of the file, read all the file data
    while(!feof(fp5))
    {
        fscanf(fp5,"%[^\n]s%[^\n]d%[^\n]f%[^\n]s%[^\n]s%[^\n]f%[^\n]d", heal[count5].name, &heal[count5].productNo, &heal[count5].price, heal[count5].color, heal[count5].brand, &heal[count5].rating, &heal[count5].type );
        count5 ++;
    }
    count5 --;
    fclose(fp5);

    FILE *fp6;

    // Open the file in read mode
    fp6 = fopen("grocery.txt", "r");

    // Check if the file was successfully opened
    if (fp6 == NULL)
    {
        printf("File Not found\n");
        return;
    }

    // Until the end of the file, read all the file data
    while(!feof(fp6))
    {
        fscanf(fp6,"%[^\n]s%[^\n]d%[^\n]f%[^\n]s%[^\n]f%[^\n]s%[^\n]d", groc[count6].name, &groc[count6].productNo, &groc[count6].price, groc[count6].brand, &groc[count6].rating, groc[count6].quantity, &groc[count6].type);
        count6 ++;
    }
    count6 --;
    fclose(fp6);
}

/**
Function Name: menu
Input Params: NILL
Return Type: void
Description: To display the menu and to choose categories of products
**/
void menu()
{
    int choice;
    // Display all categories of products
    printf("---------------Categories-------------");
    printf("\n1. Electronic Appliances");
    printf("\n2. Clothing and Accessories");
    printf("\n3. Furniture");
    printf("\n4. Sports and Fitness");
    printf("\n5. Healthcare and Cosmetics");
    printf("\n6. Grocery");
    printf("\n7. Search product");
    printf("\n8. Cart");
    printf("\n9. Exit");

    // To choose from the given options
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Switch
    switch(choice)
                {
                        case 1:
                                        electronics();
                                        break;
                        case 2:
                                        clothing();
                                        break;
                        case 3:
                                        furniture();
                                        break;
                        case 4:
                                        sports();
                                        break;
                        case 5:
                                        healthcare();
                                        break;
                        case 6:
                                        grocery();
                                        break;
                        case 7:
                                        search();
                                        break;
                        case 8:
                                        displayCart();
                                        break;
                        case 9:
                                        exit(0);
                                        break;

                        default:
                                        printf("\nIncorrect Choice");
                                        break;
                }
}

/**
Function Name: menu
Input Params: NILL
Return Type: void
Description: To display and choose products from Electronic Appliances
**/
void electronics()
{
    int choice, i, j, choice1, choice2, choice3, pNo, quantity;
    float pr1, pr2;
    char bname[10];

    // Display all sub-categories of Electronic Appliances
    printf("----------Sub-Categories--------");
    printf("\n1. Laptops and Desktops");
    printf("\n2. Headphones and Speakers");
    printf("\n3. Mobiles");
    printf("\n4. Gaming accessories");
    printf("\n5. Styling devices");
    printf("\n6. Main menu");

    // To choose from the given options
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Return to main menu
    if( choice == 6)
        menu();

    // Choosing from Electronic Appliances
    else
    {
    // Display sorting criterias to apply
    printf("--------Sorting Criteria--------");
    printf("\n1. Latest Arrival");
    printf("\n2. Rating");
    printf("\n3. None");
    printf("\nEnter choice: ");
    scanf("%d", &choice1);

    // Display filters to apply
    printf("-------Filter------");
    printf("\n1. Brand");
    printf("\n2. Price Range");
    printf("\n3. None");
    printf("\nEnter choice: ");
    scanf("%d", &choice2);

    // Sort products by latest arrival
    if( choice1 == 1)
    {
        sort_elec1(elec, count1);
    }

    // Sort products by rating
    else if( choice1 == 2)
    {
        sort_elec2(elec, count1);
    }

    // Continue with default order
    else
    {

    }

    // Choose brand name for filter
    if( choice2 == 1)
    {
        printf("Enter the brand name: ");
        scanf("%s", bname);
    }

    // Choose price range for filter
    else if( choice2 == 2)
    {
        printf("Enter the price range: ");
        scanf("%f %f", &pr1, &pr2);
    }

    // Continue with no filters
    else
    {

    }

    // Sub-category is Laptops and Desktops
    if( choice == 1)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count1; i++)
            {
                if( elec[i].type == 1 && elec[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count1; i++)
            {
               if( elec[i].type == 1 && elec[i].price > pr1 && elec[i].price < pr2)
                printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }

        }

        // Apply no filter
        else
        {
            for(i=0; i <= count1; i++)
            {
                if(elec[i].type == 1)
                printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }
    }

    // Sub-category is Headphones and Speakers
    else if( choice == 2)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count1; i++)
            {
                if( elec[i].type == 2 && elec[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count1; i++)
            {
               if( elec[i].type == 2 && elec[i].price > pr1 && elec[i].price < pr2)
                printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count1; i++)
            {
                if(elec[i].type == 2)
                printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }
    }

    // Sub-category is Headphones and Speakers
    else if( choice == 3)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count1; i++)
            {
                if( elec[i].type == 3 && elec[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count1; i++)
            {
               if( elec[i].type == 3 && elec[i].price > pr1 && elec[i].price < pr2)
                printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }

        }

        // Apply no filter
        else
        {
            for(i=0; i <= count1; i++)
            {
                if(elec[i].type == 3)
                printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }
    }

    // Sub-category is Headphones and Speakers
    else if( choice == 4)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count1; i++)
            {
                if( elec[i].type == 4 && elec[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count1; i++)
            {
               if( elec[i].type == 4 && elec[i].price > pr1 && elec[i].price < pr2)
                printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count1; i++)
            {
                if(elec[i].type == 4)
                printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }
    }

    // Sub-category is Headphones and Speakers
    else
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count1; i++)
            {
                if( elec[i].type == 5 && elec[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count1; i++)
            {
               if( elec[i].type == 5 && elec[i].price > pr1 && elec[i].price < pr2)
                printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count1; i++)
            {
                if(elec[i].type == 5)
                printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", elec[count1].name, elec[count1].productNo, elec[count1].price, elec[count1].brand, elec[count1].rating, elec[count1].extra );
            }
        }

        // To choose to add product to cart or to return to main menu
        printf("Press 1 to add product to cart, 0 for main menu");
        scanf("%d", &choice3);

        // To add products to cart
        if(choice3 == 1)
        {
            printf("Enter productNo to add to cart: ");
            scanf("%d", &pNo);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            for(j=0; j <= count1; j++)
            {
                if(elec[j].productNo == pNo)
                  addToCart(elec[j].name, pNo, elec[j].price, elec[j].brand, quantity);
            }
        }

        // Return to main menu
        else
            menu();
    }
    }
}

/**
Function Name: menu
Input Params: NILL
Return Type: void
Description: To display and choose products from Clothing and Accessories
**/
void clothing()
{
    int choice, i, j, choice1, choice2, choice3, pNo, quantity;
    float pr1, pr2;
    char bname[10], color[10];

    // Display all sub-categories of Clothing and Accessories
    printf("----------Sub-Categories--------");
    printf("\n1. Tops and dresses");
    printf("\n2. T-shirts and shirts");
    printf("\n3. Suits and Blazers");
    printf("\n4. Sarees, Kurtas and more");
    printf("\n5. Bottom Wear");
    printf("\n6. Jackets and coats");
    printf("\n7. Boots, Casuals, Flipflops and more");
    printf("\n8. Bags");
    printf("\n9. Watches, Wallets and Sunglasses");
    printf("\n10. Jewellery");
    printf("\n11. Main menu");

    // To choose from the given options
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Return to main menu
    if( choice == 11)
        menu();

    // Choosing from Clothing and Accessories
    else
    {
    // Display sorting criterias to apply
    printf("--------Sorting Criteria--------");
    printf("\n1. Latest Arrival");
    printf("\n2. Rating");
    printf("\n3. None");
    printf("\nEnter choice: ");
    scanf("%d", &choice1);

    // Display filters to apply
    printf("-------Filter------");
    printf("\n1. Brand");
    printf("\n2. Price Range");
    printf("\n3. Color");
    printf("\n4. None");
    printf("\nEnter choice: ");
    scanf("%d", &choice2);

    // Sort products by latest arrival
    if( choice1 == 1)
    {
        sort_cloth1(cloth, count2);
    }

    // Sort products by rating
    else if( choice1 == 2)
    {
        sort_cloth2(cloth, count2);
    }

    // Continue with default order
    else
    {

    }

    // Choose brand name for filter
    if( choice2 == 1)
    {
        printf("Enter the brand name: ");
        scanf("%s", bname);
    }

    // Choose price range for filter
    else if( choice2 == 2)
    {
        printf("Enter the price range: ");
        scanf("%f %f", &pr1, &pr2);
    }

    // Choose color for filter
    else if( choice2 == 3)
    {
        printf("Enter the color: ");
        scanf("%s", color);
    }

    // Continue with no filters
    else
    {

    }

    // Sub-category is Tops and dresses
    if( choice == 1)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count2; i++)
            {
                if( cloth[i].type == 1 && cloth[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 1 && cloth[i].price > pr1 && cloth[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 1 && cloth[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count2; i++)
            {
                if(cloth[i].type == 1)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }
    }

    // Sub-category is T-shirts and shirts
    else if( choice == 2)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count2; i++)
            {
                if( cloth[i].type == 2 && cloth[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 2 && cloth[i].price > pr1 && cloth[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 2 && cloth[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count2; i++)
            {
                if(cloth[i].type == 2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }
    }

    // Sub-category is Suits and Blazers
    else if( choice == 3)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count2; i++)
            {
                if( cloth[i].type == 3 && cloth[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 3 && cloth[i].price > pr1 && cloth[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 3 && cloth[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count2; i++)
            {
                if(cloth[i].type == 3)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }
    }

    // Sub-category is Sarees, Kurtas and more
    else if( choice == 4)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count2; i++)
            {
                if( cloth[i].type == 4 && cloth[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 4 && cloth[i].price > pr1 && cloth[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 4 && cloth[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count2; i++)
            {
                if(elec[i].type == 4)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }
    }

    // Sub-category is Bottom wear
    else if( choice == 5)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count2; i++)
            {
                if( cloth[i].type == 5 && cloth[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 5 && cloth[i].price > pr1 && cloth[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 5 && cloth[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count2; i++)
            {
                if(cloth[i].type == 5)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }
    }

    // Sub-category is Jackets and coats
    else if( choice == 6)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count2; i++)
            {
                if( cloth[i].type == 6 && cloth[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 6 && cloth[i].price > pr1 && cloth[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i<= count2; i++)
            {
               if( cloth[i].type == 6 && cloth[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count2; i++)
            {
                if(cloth[i].type == 6)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }
    }

    // Sub-category is Boots, Casuals, Flipflops and more
    else if( choice == 7)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count2; i++)
            {
                if( cloth[i].type == 7 && cloth[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 7 && cloth[i].price > pr1 && cloth[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 7 && cloth[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count2; i++)
            {
                if(cloth[i].type == 7)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }
    }

    // Sub-category is Bags
    else if( choice == 8)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count2; i++)
            {
                if( cloth[i].type == 8 && cloth[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 8 && cloth[i].price > pr1 && cloth[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 8 && cloth[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count2; i++)
            {
                if(cloth[i].type == 8)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }
    }

    // Sub-category is Watches, Wallets and Sunglasses
    else if( choice == 9)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count2; i++)
            {
                if( cloth[i].type == 9 && cloth[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 9 && cloth[i].price > pr1 && cloth[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 9 && cloth[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count2; i++)
            {
                if(cloth[i].type == 9)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }
    }

    // Sub-category is Jewellery
    else
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count2; i++)
            {
                if( cloth[i].type == 10 && cloth[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 10 && cloth[i].price > pr1 && cloth[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count2; i++)
            {
               if( cloth[i].type == 10 && cloth[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // Apply no filter
        else
        {
            for(i=0; i <= count2; i++)
            {
                if(cloth[i].type == 10)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", cloth[count2].name, cloth[count2].productNo, cloth[count2].price, cloth[count2].color, cloth[count2].brand, cloth[count2].rating, cloth[count2].size, cloth[count2].user );
            }
        }

        // To choose to add product to cart or to return to main menu
        printf("Press 1 to add product to cart, 0 for main menu");
        scanf("%d", &choice3);

        // To add products to cart
        if(choice3 == 1)
        {
            printf("Enter productNo to add to cart: ");
            scanf("%d", &pNo);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            for(j=0; j <= count2; j++)
            {
                if(cloth[j].productNo == pNo)
                  addToCart(cloth[j].name, pNo, cloth[j].price, cloth[j].brand, quantity);
            }
        }

        // Return to main menu
        else
            menu();
    }
    }
}

/**
Function Name: menu
Input Params: NILL
Return Type: void
Description: To display and choose products from Furniture
**/
void furniture()
{
    int choice, i, j, choice1, choice2, choice3, pNo, quantity;
    float pr1, pr2;
    char bname[10], color[10];

    // Display all sub-categories of Furniture
    printf("----------Sub-Categories--------");
    printf("\n1. Mattresses");
    printf("\n2. Dining sets");
    printf("\n3. Sofas and recliners");
    printf("\n4. Beds");
    printf("\n5. Chairs, Tables and office desks");
    printf("\n6. Main menu");

    // To choose from the given options
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Return to main menu
    if( choice == 6)
        menu();

    // Choosing from Furniture
    else
    {
    // Display sorting criterias to apply
    printf("--------Sorting Criteria--------");
    printf("\n1. Latest Arrival");
    printf("\n2. Rating");
    printf("\n3. None");
    printf("\nEnter choice: ");
    scanf("%d", &choice1);

    // Display filters to apply
    printf("-------Filter------");
    printf("\n1. Brand");
    printf("\n2. Price Range");
    printf("\n3. Color");
    printf("\n4. None");
    printf("\nEnter choice: ");
    scanf("%d", &choice2);

    // Sort products by latest arrival
    if( choice1 == 1)
    {
        sort_furn1(furn, count3);
    }

    // Sort products by rating
    else if( choice1 == 2)
    {
        sort_furn2(furn, count3);
    }

    // Continue with default order
    else
    {

    }

    // Choose brand name for filter
    if( choice2 == 1)
    {
        printf("Enter the brand name: ");
        scanf("%s", bname);
    }

    // Choose price range for filter
    else if( choice2 == 2)
    {
        printf("Enter the price range: ");
        scanf("%f %f", &pr1, &pr2);
    }

    // Choose color for filter
    else if( choice2 == 3)
    {
        printf("Enter the color: ");
        scanf("%s", color);
    }

    // Apply no filter
    else
    {

    }

    // Sub-category is Mattresses
    if( choice == 1)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count3; i++)
            {
                if( furn[i].type == 1 && furn[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count3; i++)
            {
               if( furn[i].type == 1 && furn[i].price > pr1 && furn[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count3; i++)
            {
               if( furn[i].type == 1 && furn[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count3; i++)
            {
                if(furn[i].type == 1)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }
    }

    // Sub-category is Dining sets
    else if( choice == 2)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count3; i++)
            {
                if( furn[i].type == 2 && furn[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count3; i++)
            {
               if( furn[i].type == 2 && furn[i].price > pr1 && furn[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count3; i++)
            {
               if( furn[i].type == 2 && furn[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count3; i++)
            {
                if(furn[i].type == 2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }
    }

    // Sub-category is Tops and dresses
    else if( choice == 3)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count3; i++)
            {
                if( furn[i].type == 3 && furn[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count3; i++)
            {
               if( furn[i].type == 3 && furn[i].price > pr1 && furn[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count3; i++)
            {
               if( furn[i].type == 3 && furn[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count3; i++)
            {
                if(furn[i].type == 3)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }
    }

    // Sub-category is Sofas and recliners
    else if( choice == 4)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count3; i++)
            {
                if( furn[i].type == 4 && furn[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count3; i++)
            {
               if( furn[i].type == 4 && furn[i].price > pr1 && furn[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count3; i++)
            {
               if( furn[i].type == 4 && furn[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count3; i++)
            {
                if(furn[i].type == 4)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }
    }

    // Sub-category is Beds
    else
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count3; i++)
            {
                if( furn[i].type == 5 && furn[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count3; i++)
            {
               if( furn[i].type == 5 && furn[i].price > pr1 && furn[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Apply filter by color
        else if(choice2 == 3)
        {
            for(i=0; i <= count3; i++)
            {
               if( furn[i].type == 5 && furn[i].color == color)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count3; i++)
            {
                if(elec[i].type == 5)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", furn[count1].name, furn[count1].productNo, furn[count1].price, furn[count1].color, furn[count1].brand, furn[count1].rating, furn[count1].size );
            }
        }
    }

        // To choose to add product to cart or to return to main menu
        printf("Press 1 to add product to cart, 0 for main menu");
        scanf("%d", &choice3);

        // To add products to cart
        if(choice3 == 1)
        {
            printf("Enter productNo to add to cart: ");
            scanf("%d", &pNo);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            for(j=0; j <= count1; j++)
            {
                if(elec[j].productNo == pNo)
                  addToCart(furn[j].name, pNo, furn[j].price, furn[j].brand, quantity);
            }
        }

        // Return to main menu
        else
            menu();
    }
}

/**
Function Name: menu
Input Params: NILL
Return Type: void
Description: To display and choose products from Sports
**/
void sports()
{
    int choice, i, j, choice1, choice2, choice3, pNo, quantity;
    float pr1, pr2;
    char bname[10];

    // Display all sub-categories of Furniture
    printf("----------Sub-Categories--------");
    printf("\n1. Balls and Bats");
    printf("\n2. Nets and Racquets");
    printf("\n3. Elbow pads and Gloves");
    printf("\n4. Skating shoes");
    printf("\n5. Treadmills");
    printf("\n6. Dumbells");
    printf("\n7. Skipping ropes");
    printf("\n8. Main menu");

    // To choose from the given options
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Return to main menu
    if( choice == 8)
        menu();

    // Choosing from Furniture
    else
    {
    // Display sorting criterias to apply
    printf("--------Sorting Criteria--------");
    printf("\n1. Latest Arrival");
    printf("\n2. Rating");
    printf("\n3. None");
    printf("\nEnter choice: ");
    scanf("%d", &choice1);

    // Display filters to apply
    printf("-------Filter------");
    printf("\n1. Brand");
    printf("\n2. Price Range");
    printf("\n3. None");
    printf("\nEnter choice: ");
    scanf("%d", &choice2);

    // Sort products by latest arrival
    if( choice1 == 1)
    {
        sort_sport1(sport, count5);
    }

    // Sort products by rating
    else if( choice1 == 2)
    {
        sort_sport2(sport, count5);
    }

    // Continue with default order
    else
    {

    }

    // Choose brand name for filter
    if( choice2 == 1)
    {
        printf("Enter the brand name: ");
        scanf("%s", bname);
    }

    // Choose price range for filter
    else if( choice2 == 2)
    {
        printf("Enter the price range: ");
        scanf("%f %f", &pr1, &pr2);
    }

    // Apply no filter
    else
    {

    }

    // Sub-category is Balls and Bats
    if( choice == 1)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count4; i++)
            {
                if( sport[i].type == 1 && sport[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count4; i++)
            {
               if( sport[i].type == 1 && sport[i].price > pr1 && sport[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count4; i++)
            {
                if(sport[i].type == 1)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }
    }

    // Sub-category is Nets and Racquets
    else if( choice == 2)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count4; i++)
            {
                if( sport[i].type == 2 && sport[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count4; i++)
            {
               if( sport[i].type == 2 && sport[i].price > pr1 && sport[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count4; i++)
            {
                if(sport[i].type == 2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }
    }

    // Sub-category is Elbow pads and Gloves
    else if( choice == 3)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count4; i++)
            {
                if( sport[i].type == 3 && sport[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count4; i++)
            {
               if( sport[i].type == 3 && sport[i].price > pr1 && sport[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count4; i++)
            {
                if(sport[i].type == 3)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }
    }

    // Sub-category is Skating shoes
    else if( choice == 4)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count4; i++)
            {
                if( sport[i].type == 4 && sport[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count4; i++)
            {
               if( sport[i].type == 4 && sport[i].price > pr1 && sport[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count4; i++)
            {
                if(sport[i].type == 4)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }
    }

    // Sub-category is Treadmills
    else if( choice == 5)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count4; i++)
            {
                if( sport[i].type == 5 && sport[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count4; i++)
            {
               if( sport[i].type == 5 && sport[i].price > pr1 && sport[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count4; i++)
            {
                if(sport[i].type == 5)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }
    }

    // Sub-category is Dumbells
    else if( choice == 6)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count4; i++)
            {
                if( sport[i].type == 6 && sport[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count4; i++)
            {
               if( sport[i].type == 6 && sport[i].price > pr1 && sport[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count4; i++)
            {
                if(sport[i].type == 6)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }
    }

    // Sub-category is Skipping ropes
    else
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count4; i++)
            {
                if( sport[i].type == 7 && sport[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count4; i++)
            {
               if( sport[i].type == 7 && sport[i].price > pr1 && sport[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count4; i++)
            {
                if(sport[i].type == 7)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", sport[count1].name, &sport[count1].productNo, &sport[count1].price, sport[count1].color, sport[count1].brand, sport[count1].rating, sport[count1].extra );
            }
        }
    }

        // To choose to add product to cart or to return to main menu
        printf("Press 1 to add product to cart, 0 for main menu");
        scanf("%d", &choice3);

        // To add products to cart
        if(choice3 == 1)
        {
            printf("Enter productNo to add to cart: ");
            scanf("%d", &pNo);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            for(j=0; j <= count4; j++)
            {
                if(sport[j].productNo == pNo)
                  addToCart(sport[j].name, pNo, sport[j].price, sport[j].brand, quantity);
            }
        }

        // Return to main menu
        else
            menu();
    }
}

/**
Function Name: menu
Input Params: NILL
Return Type: void
Description: To display and choose products from Healthcare and Cosmetics
**/
void healthcare()
{
    int choice, i, j, choice1, choice2, choice3, pNo, quantity;
    float pr1, pr2;
    char bname[10];

    // Display all sub-categories of Furniture
    printf("----------Sub-Categories--------");
    printf("\n1. Facial steamer");
    printf("\n2. Slimming Oil");
    printf("\n3. Gels");
    printf("\n4. Skin Care and Creams");
    printf("\n5. Lotions");
    printf("\n6. Lipsticks");
    printf("\n7. Nail polishes");
    printf("\n8. Hair Colourants and Sprays");
    printf("\n9. Main menu");

    // To choose from the given options
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Return to main menu
    if( choice == 9)
        menu();

    // Choosing from Furniture
    else
    {
    // Display sorting criterias to apply
    printf("--------Sorting Criteria--------");
    printf("\n1. Latest Arrival");
    printf("\n2. Rating");
    printf("\n3. None");
    printf("\nEnter choice: ");
    scanf("%d", &choice1);

    // Display filters to apply
    printf("-------Filter------");
    printf("\n1. Brand");
    printf("\n2. Price Range");
    printf("\n3. None");
    printf("\nEnter choice: ");
    scanf("%d", &choice2);

    // Sort products by latest arrival
    if( choice1 == 1)
    {
        sort_heal1(heal, count5);
    }

    // Sort products by rating
    else if( choice1 == 2)
    {
        sort_heal2(heal, count5);
    }

    // Continue with default order
    else
    {

    }

    // Choose brand name for filter
    if( choice2 == 1)
    {
        printf("Enter the brand name: ");
        scanf("%s", bname);
    }

    // Choose price range for filter
    else if( choice2 == 2)
    {
        printf("Enter the price range: ");
        scanf("%f %f", &pr1, &pr2);
    }

    // Apply no filter
    else
    {

    }

    // Sub-category is Facial steamer
    if( choice == 1)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count5; i++)
            {
                if( heal[i].type == 1 && heal[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count5; i++)
            {
               if( heal[i].type == 1 && heal[i].price > pr1 && heal[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count5; i++)
            {
                if(heal[i].type == 1)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }
    }

    // Sub-category is Slimming oil
    else if( choice == 2)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count5; i++)
            {
                if( heal[i].type == 2 && heal[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count5; i++)
            {
               if( heal[i].type == 2 && heal[i].price > pr1 && heal[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count5; i++)
            {
                if(heal[i].type == 2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }
    }

    // Sub-category is Gels
    else if( choice == 3)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count5; i++)
            {
                if( heal[i].type == 3 && heal[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count5; i++)
            {
               if( heal[i].type == 3 && heal[i].price > pr1 && heal[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count5; i++)
            {
                if(heal[i].type == 3)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }
    }

    // Sub-category is Skin care and creams
    else if( choice == 4)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count5; i++)
            {
                if( heal[i].type == 4 && heal[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count5; i++)
            {
               if( heal[i].type == 4 && heal[i].price > pr1 && heal[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count5; i++)
            {
                if(heal[i].type == 4)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }
    }

    // Sub-category is Lotions
    else if( choice == 5)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count5; i++)
            {
                if( heal[i].type == 5 && heal[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count5; i++)
            {
               if( heal[i].type == 5 && heal[i].price > pr1 && heal[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count5; i++)
            {
                if(heal[i].type == 5)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }
    }

    // Sub-category is Lipsticks
    else if( choice == 6)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count5; i++)
            {
                if( heal[i].type == 6 && heal[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count5; i++)
            {
               if( heal[i].type == 6 && heal[i].price > pr1 && heal[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count5; i++)
            {
                if(heal[i].type == 6)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }
    }

    // Sub-category is Nail polishes
    else if( choice == 7)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count5; i++)
            {
                if( heal[i].type == 7 && heal[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count5; i++)
            {
               if( heal[i].type == 7 && heal[i].price > pr1 && heal[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count5; i++)
            {
                if(heal[i].type == 7)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }
    }

    // Sub-category is Hair colourants and sprays
    else
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count5; i++)
            {
                if( heal[i].type == 8 && heal[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count5; i++)
            {
               if( heal[i].type == 8 && heal[i].price > pr1 && heal[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count5; i++)
            {
                if(heal[i].type == 8)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", heal[count5].name, heal[count5].productNo, heal[count5].price, heal[count5].color, heal[count5].brand, heal[count5].rating );
            }
        }
    }

        // To choose to add product to cart or to return to main menu
        printf("Press 1 to add product to cart, 0 for main menu");
        scanf("%d", &choice3);

        // To add products to cart
        if(choice3 == 1)
        {
            printf("Enter productNo to add to cart: ");
            scanf("%d", &pNo);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            for(j=0; j <= count5; j++)
            {
                if(heal[j].productNo == pNo)
                  addToCart(heal[j].name, pNo, heal[j].price, heal[j].brand, quantity);
            }
        }

        // Return to main menu
        else
            menu();
    }
}

/**
Function Name: menu
Input Params: NILL
Return Type: void
Description: To display and choose products from Grocery
**/
void grocery()
{
    int choice, i, j, choice1, choice2, choice3, pNo, quantity;
    float pr1, pr2;
    char bname[10];

    // Display all sub-categories of Furniture
    printf("----------Sub-Categories--------");
    printf("\n1. Grains");
    printf("\n2. Dairy products");
    printf("\n3. Dry fruits");
    printf("\n4. Snacks");
    printf("\n5. Drinks");
    printf("\n6. Bread and Bakery");
    printf("\n7. Main menu");

    // To choose from the given options
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Return to main menu
    if( choice == 7)
        menu();

    // Choosing from Furniture
    else
    {
    // Display sorting criterias to apply
    printf("--------Sorting Criteria--------");
    printf("\n1. Latest Arrival");
    printf("\n2. Rating");
    printf("\n3. None");
    printf("\nEnter choice: ");
    scanf("%d", &choice1);

    // Display filters to apply
    printf("-------Filter------");
    printf("\n1. Brand");
    printf("\n2. Price Range");
    printf("\n3. None");
    printf("\nEnter choice: ");
    scanf("%d", &choice2);

    // Sort products by latest arrival
    if( choice1 == 1)
    {
        sort_groc1(groc, count6);
    }

    // Sort products by rating
    else if( choice1 == 2)
    {
        sort_groc2(groc, count6);
    }

    // Continue with default order
    else
    {

    }

    // Choose brand name for filter
    if( choice2 == 1)
    {
        printf("Enter the brand name: ");
        scanf("%s", bname);
    }

    // Choose color for filter
    else if( choice2 == 2)
    {
        printf("Enter the price range: ");
        scanf("%f %f", &pr1, &pr2);
    }

    // Apply no filter
    else
    {

    }

    // Sub-category is Grains
    if( choice == 1)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count6; i++)
            {
                if( groc[i].type == 1 && groc[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count6; i++)
            {
               if( groc[i].type == 1 && groc[i].price > pr1 && groc[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }

        }

        // Default order
        else
        {
            for(i=0; i <= count6; i++)
            {
                if(groc[i].type == 1)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }
    }

    // Sub-category is Dairy products
    else if( choice == 2)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count6; i++)
            {
                if( groc[i].type == 2 && groc[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count6; i++)
            {
               if( groc[i].type == 2 && groc[i].price > pr1 && groc[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count6; i++)
            {
                if(groc[i].type == 2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }
    }

    // Sub-category is Dry fruits
    else if( choice == 3)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count6; i++)
            {
                if( groc[i].type == 3 && groc[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count6; i++)
            {
               if( groc[i].type == 3 && groc[i].price > pr1 && groc[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count6; i++)
            {
                if(groc[i].type == 3)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }
    }

    // Sub-category is Snacks
    else if( choice == 4)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count6; i++)
            {
                if( groc[i].type == 4 && groc[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count6; i++)
            {
               if( groc[i].type == 4 && groc[i].price > pr1 && groc[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count6; i++)
            {
                if(groc[i].type == 4)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }
    }

    // Sub-category is Drinks
    else if( choice == 5)
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count6; i++)
            {
                if( groc[i].type == 5 && groc[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count6; i++)
            {
               if( groc[i].type == 5 && groc[i].price > pr1 && groc[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count6; i++)
            {
                if(groc[i].type == 5)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }
    }

    // Sub-category is Bread and Bakery
    else
    {
        // Apply filter by brand name
        if( choice2 == 1)
        {
            for(i=0; i <= count6; i++)
            {
                if( groc[i].type == 6 && groc[i].brand == bname)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }

        // Apply filter by price range
        else if(choice2 == 2)
        {
            for(i=0; i <= count6; i++)
            {
               if( groc[i].type == 6 && groc[i].price > pr1 && groc[i].price < pr2)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }

        // Default order
        else
        {
            for(i=0; i <= count6; i++)
            {
                if(groc[i].type == 6)
                  printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", groc[count6].name, groc[count6].productNo, groc[count6].price, groc[count6].brand, groc[count6].rating, groc[count6].quantity );
            }
        }
    }

        // To choose to add product to cart or to return to main menu
        printf("Press 1 to add product to cart, 0 for main menu");
        scanf("%d", &choice3);

        // To add products to cart
        if(choice3 == 1)
        {
            printf("Enter productNo to add to cart: ");
            scanf("%d", &pNo);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            for(j=0; j<= count1; j++)
            {
                if(groc[j].productNo == pNo)
                  addToCart(groc[j].name, pNo, groc[j].price, groc[j].brand, quantity);
            }
        }

        // Return to main menu
        else
            menu();
    }
}

/**
Function Name: menu
Input Params: EA, int
Return Type: void
Description: To sort Electronic Appliances by latest arrival criteria
**/
void sort_elec1(EA a[], int count)
{
    int i, j, max, index;
    // Sort by productNo for latest arrival using insertion sort
    for(i=0; i <= count-1; i++)
    {
        index = i;
        for(j= j+1; j <= count; j++)
        {
            if(a[j].productNo > a[index].productNo)
            {
                index = j;
            }
        }

        // Swapping products
        EA temp;
        strcpy(temp.name, a[i].name);
        temp.productNo = a[i].productNo;
        temp.price = a[i].price;
        strcpy(temp.brand, a[i].brand);
        temp.rating = a[i].rating;
        strcpy(temp.extra, a[i].extra);
        temp.type = a[i].type;

        strcpy(a[i].name, a[index].name);
        a[i].productNo = a[index].productNo;
        a[i].price = a[index].price;
        strcpy(a[i].brand, a[index].brand);
        a[i].rating = a[index].rating;
        strcpy(a[i].extra, a[index].extra);
        a[i].type = a[index].type;

        strcpy(a[index].name, temp.name);
        a[index].productNo = temp.productNo;
        a[index].price = temp.price;
        strcpy(a[index].brand, temp.brand);
        a[index].rating = temp.rating;
        strcpy(a[index].extra, temp.extra);
        a[index].type = temp.type;
    }
}

/**
Function Name: menu
Input Params: EA, int
Return Type: void
Description: To sort Electronic Appliances by rating criteria
**/
void sort_elec2(EA a[], int count)
{
    int i, j, index;
    // Sort by rating using insertion sort
    for(i=0; i <= count-1; i++)
    {
        index = i;
        for(j= j+1; j <= count; j++)
        {
            if(a[j].rating > a[index].rating)
            {
                index = j;
            }
        }

        // Swapping products
        EA temp;
        strcpy(temp.name, a[i].name);
        temp.productNo = a[i].productNo;
        temp.price = a[i].price;
        strcpy(temp.brand, a[i].brand);
        temp.rating = a[i].rating;
        strcpy(temp.extra, a[i].extra);
        temp.type = a[i].type;

        strcpy(a[i].name, a[index].name);
        a[i].productNo = a[index].productNo;
        a[i].price = a[index].price;
        strcpy(a[i].brand, a[index].brand);
        a[i].rating = a[index].rating;
        strcpy(a[i].extra, a[index].extra);
        a[i].type = a[index].type;

        strcpy(a[index].name, temp.name);
        a[index].productNo = temp.productNo;
        a[index].price = temp.price;
        strcpy(a[index].brand, temp.brand);
        a[index].rating = temp.rating;
        strcpy(a[index].extra, temp.extra);
        a[index].type = temp.type;
    }
}

/**
Function Name: menu
Input Params: EA, int
Return Type: void
Description: To sort Clothing and Accessories by latest arrival criteria
**/
void sort_cloth1(CA a[], int count)
{
    int i, j, max, index;
    // Sort by productNo for latest arrival using insertion sort
    for(i=0; i <= count-1; i++)
    {
        index = i;
        for(j=j+1; j <= count; j++)
        {
            if(a[j].productNo > a[index].productNo)
            {
                index = j;
            }
        }

        // Swapping products
        CA temp;
        strcpy(temp.name, a[i].name);
        temp.productNo = a[i].productNo;
        temp.price = a[i].price;
        strcpy(temp.color, a[i].color);
        strcpy(temp.brand, a[i].brand);
        temp.rating = a[i].rating;
        strcpy(temp.size, a[i].user);
        strcpy(temp.user, a[i].user);
        temp.type = a[i].type;

        strcpy(a[i].name, a[index].name);
        a[i].productNo = a[index].productNo;
        a[i].price = a[index].price;
        strcpy(a[i].color, a[index].color);
        strcpy(a[i].brand, a[index].brand);
        a[i].rating = a[index].rating;
        strcpy(a[i].size, a[index].size);
        strcpy(a[i].user, a[index].user);
        a[i].type = a[index].type;

        strcpy(a[index].name, temp.name);
        a[index].productNo = temp.productNo;
        a[index].price = temp.price;
        strcpy(a[index].color, temp.color);
        strcpy(a[index].brand, temp.brand);
        a[index].rating = temp.rating;
        strcpy(a[index].size, temp.size);
        strcpy(a[index].user, temp.user);
        a[index].type = temp.type;
    }
}

/**
Function Name: menu
Input Params: CA, int
Return Type: void
Description: To sort Clothing and Accessories by rating criteria
**/
void sort_cloth2(CA a[], int count)
{
    int i, j, index;
    // Sort by rating using insertion sort
    for(i=0; i <= count-1; i++)
    {
        index = i;
        for(j=j+1; j <= count; j++)
        {
            if(a[j].rating > a[index].rating)
            {
                index = j;
            }
        }

        // Swapping products
        CA temp;
        strcpy(temp.name, a[i].name);
        temp.productNo = a[i].productNo;
        temp.price = a[i].price;
        strcpy(temp.color, a[i].color);
        strcpy(temp.brand, a[i].brand);
        temp.rating = a[i].rating;
        strcpy(temp.size, a[i].user);
        strcpy(temp.user, a[i].user);
        temp.type = a[i].type;

        strcpy(a[i].name, a[index].name);
        a[i].productNo = a[index].productNo;
        a[i].price = a[index].price;
        strcpy(a[i].color, a[index].color);
        strcpy(a[i].brand, a[index].brand);
        a[i].rating = a[index].rating;
        strcpy(a[i].size, a[index].size);
        strcpy(a[i].user, a[index].user);
        a[i].type = a[index].type;

        strcpy(a[index].name, temp.name);
        a[index].productNo = temp.productNo;
        a[index].price = temp.price;
        strcpy(a[index].color, temp.color);
        strcpy(a[index].brand, temp.brand);
        a[index].rating = temp.rating;
        strcpy(a[index].size, temp.size);
        strcpy(a[index].user, temp.user);
        a[index].type = temp.type;
    }
}

/**
Function Name: menu
Input Params: CA, int
Return Type: void
Description: To sort Furniture by latest arrival criteria
**/
void sort_furn1(FN a[], int count)
{
    int i, j, max, index;
    // Sort by productNo for latest arrival using insertion sort
    for(i=0; i <= count-1; i++)
    {
        index = i;
        for(j=j+1; j <= count; j++)
        {
            if(a[j].productNo > a[index].productNo)
            {
                index = j;
            }
        }

        // Swapping products
        FN temp;
        strcpy(temp.name, a[i].name);
        temp.productNo = a[i].productNo;
        temp.price = a[i].price;
        strcpy(temp.color, a[i].color);
        strcpy(temp.brand, a[i].brand);
        temp.rating = a[i].rating;
        temp.type = a[i].type;

        strcpy(a[i].name, a[index].name);
        a[i].productNo = a[index].productNo;
        a[i].price = a[index].price;
        strcpy(a[i].color, a[index].color);
        strcpy(a[i].brand, a[index].brand);
        a[i].rating = a[index].rating;
        strcpy(a[i].size, a[index].size);
        a[i].type = a[index].type;

        strcpy(a[index].name, temp.name);
        a[index].productNo = temp.productNo;
        a[index].price = temp.price;
        strcpy(a[index].color, temp.color);
        strcpy(a[index].brand, temp.brand);
        a[index].rating = temp.rating;
        strcpy(a[index].size, temp.size);
        a[index].type = temp.type;
    }
}

/**
Function Name: menu
Input Params: FN, int
Return Type: void
Description: To sort Furniture by rating criteria
**/
void sort_furn2(FN a[], int count)
{
    int i, j, index;
    // Sort by rating using insertion sort
    for(i=0; i <= count-1; i++)
    {
        index = i;
        for(j=j+1; j<=count; j++)
        {
            if(a[j].rating > a[index].rating)
            {
                index = j;
            }
        }

        // Swapping products
        FN temp;
        strcpy(temp.name, a[i].name);
        temp.productNo = a[i].productNo;
        temp.price = a[i].price;
        strcpy(temp.color, a[i].color);
        strcpy(temp.brand, a[i].brand);
        temp.rating = a[i].rating;
        temp.type = a[i].type;

        strcpy(a[i].name, a[index].name);
        a[i].productNo = a[index].productNo;
        a[i].price = a[index].price;
        strcpy(a[i].color, a[index].color);
        strcpy(a[i].brand, a[index].brand);
        a[i].rating = a[index].rating;
        strcpy(a[i].size, a[index].size);
        a[i].type = a[index].type;

        strcpy(a[index].name, temp.name);
        a[index].productNo = temp.productNo;
        a[index].price = temp.price;
        strcpy(a[index].color, temp.color);
        strcpy(a[index].brand, temp.brand);
        a[index].rating = temp.rating;
        strcpy(a[index].size, temp.size);
        a[index].type = temp.type;
    }
}

/**
Function Name: menu
Input Params: FN, int
Return Type: void
Description: To sort Sports by latest arrival criteria
**/
void sort_sport1(SF a[], int count)
{
    int i, j, max, index;
    // Sort by productNo for latest arrival using insertion sort
    for(i=0; i <= count-1; i++)
    {
        index = i;
        for(j=j+1; j <= count; j++)
        {
            if(a[j].productNo > a[index].productNo)
            {
                index = j;
            }
        }

        // Swapping products
        SF temp;
        strcpy(temp.name, a[i].name);
        temp.productNo = a[i].productNo;
        temp.price = a[i].price;
        strcpy(temp.color, a[i].color);
        strcpy(temp.brand, a[i].brand);
        temp.rating = a[i].rating;
        strcpy(temp.extra, a[i].extra);
        temp.type = a[i].type;

        strcpy(a[i].name, a[index].name);
        a[i].productNo = a[index].productNo;
        a[i].price = a[index].price;
        strcpy(a[i].color, a[index].color);
        strcpy(a[i].brand, a[index].brand);
        a[i].rating = a[index].rating;
        strcpy(a[i].extra, a[index].extra);
        a[i].type = a[index].type;

        strcpy(a[index].name, temp.name);
        a[index].productNo = temp.productNo;
        a[index].price = temp.price;
        strcpy(a[index].color, temp.color);
        strcpy(a[index].brand, temp.brand);
        a[index].rating = temp.rating;
        strcpy(a[index].extra, temp.extra);
        a[index].type = temp.type;
    }
}

/**
Function Name: menu
Input Params: SF, int
Return Type: void
Description: To sort Sports by rating criteria
**/
void sort_sport2(SF a[], int count)
{
    int i, j, index;
    // Sort by rating using insertion sort
    for(i=0; i <= count-1; i++)
    {
        index = i;
        for(j= j+1; j <= count; j++)
        {
            if(a[j].rating>a[index].rating)
            {
                index = j;
            }
        }

        // Swapping products
        SF temp;
        strcpy(temp.name,a[i].name);
        temp.productNo=a[i].productNo;
        temp.price=a[i].price;
        strcpy(temp.color,a[i].color);
        strcpy(temp.brand,a[i].brand);
        temp.rating=a[i].rating;
        strcpy(temp.extra,a[i].extra);
        temp.type=a[i].type;

        strcpy(a[i].name,a[index].name);
        a[i].productNo=a[index].productNo;
        a[i].price=a[index].price;
        strcpy(a[i].color,a[index].color);
        strcpy(a[i].brand,a[index].brand);
        a[i].rating=a[index].rating;
        strcpy(a[i].extra,a[index].extra);
        a[i].type=a[index].type;

        strcpy(a[index].name,temp.name);
        a[index].productNo=temp.productNo;
        a[index].price=temp.price;
        strcpy(a[index].color,temp.color);
        strcpy(a[index].brand,temp.brand);
        a[index].rating=temp.rating;
        strcpy(a[index].extra,temp.extra);
        a[index].type=temp.type;
    }
}

/**
Function Name: menu
Input Params: SF, int
Return Type: void
Description: To sort Healthcare and Cosmetics by latest arrival criteria
**/
void sort_heal1(HC a[], int count)
{
    int i, j, max, index;
    // Sort by productNo for latest arrival using insertion sort
    for(i=0; i <= count-1; i++)
    {
        index = i;
        for(j= j+1; j <= count; j++)
        {
            if(a[j].productNo > a[index].productNo)
            {
                index = j;
            }
        }

        // Swapping products
        HC temp;
        strcpy(temp.name, a[i].name);
        temp.productNo = a[i].productNo;
        temp.price = a[i].price;
        strcpy(temp.color, a[i].color);
        strcpy(temp.brand, a[i].brand);
        temp.rating = a[i].rating;
        temp.type = a[i].type;

        strcpy(a[i].name, a[index].name);
        a[i].productNo = a[index].productNo;
        a[i].price = a[index].price;
        strcpy(a[i].color, a[index].color);
        strcpy(a[i].brand, a[index].brand);
        a[i].rating = a[index].rating;
        a[i].type = a[index].type;

        strcpy(a[index].name, temp.name);
        a[index].productNo = temp.productNo;
        a[index].price = temp.price;
        strcpy(a[index].color, temp.color);
        strcpy(a[index].brand, temp.brand);
        a[index].rating = temp.rating;
        a[index].type = temp.type;
    }
}

/**
Function Name: menu
Input Params: HC, int
Return Type: void
Description: To sort Healthcare and Cosmetics by rating criteria
**/
void sort_heal2(HC a[],int count)
{
    int i, j, index;
    // Sort by rating using insertion sort
    for(i=0; i <= count-1; i++)
    {
        index = i;
        for(j= j+1; j <= count; j++)
        {
            if(a[j].rating > a[index].rating)
            {
                index=j;
            }
        }

        // Swapping products
        HC temp;
        strcpy(temp.name, a[i].name);
        temp.productNo = a[i].productNo;
        temp.price = a[i].price;
        strcpy(temp.color, a[i].color);
        strcpy(temp.brand, a[i].brand);
        temp.rating = a[i].rating;
        temp.type = a[i].type;

        strcpy(a[i].name, a[index].name);
        a[i].productNo = a[index].productNo;
        a[i].price = a[index].price;
        strcpy(a[i].color, a[index].color);
        strcpy(a[i].brand, a[index].brand);
        a[i].rating = a[index].rating;
        a[i].type = a[index].type;

        strcpy(a[index].name, temp.name);
        a[index].productNo = temp.productNo;
        a[index].price = temp.price;
        strcpy(a[index].color, temp.color);
        strcpy(a[index].brand, temp.brand);
        a[index].rating = temp.rating;
        a[index].type = temp.type;
    }
}

/**
Function Name: menu
Input Params: HC, int
Return Type: void
Description: To sort Grocery by latest arrival criteria
**/
void sort_groc1(GR a[], int count)
{
    int i, j, max, index;
    // Sort by productNo for latest arrival using insertion sort
    for(i=0; i <= count-1; i++)
    {
        index = i;
        for(j= j+1; j <= count; j++)
        {
            if(a[j].productNo > a[index].productNo)
            {
                index = j;
            }
        }

        // Swapping products
        GR temp;
        strcpy(temp.name, a[i].name);
        temp.productNo = a[i].productNo;
        temp.price = a[i].price;
        strcpy(temp.brand, a[i].brand);
        temp.rating = a[i].rating;
        strcpy(temp.quantity, a[i].quantity);
        temp.type = a[i].type;

        strcpy(a[i].name, a[index].name);
        a[i].productNo = a[index].productNo;
        a[i].price = a[index].price;
        strcpy(a[i].brand, a[index].brand);
        a[i].rating = a[index].rating;
        strcpy(a[i].quantity, a[index].quantity);
        a[i].type = a[index].type;

        strcpy(a[index].name, temp.name);
        a[index].productNo = temp.productNo;
        a[index].price = temp.price;
        strcpy(a[index].brand, temp.brand);
        a[index].rating = temp.rating;
        strcpy(a[index].quantity, temp.quantity);
        a[index].type = temp.type;
    }
}

/**
Function Name: menu
Input Params: GR, int
Return Type: void
Description: To sort Grocery by rating criteria
**/
void sort_groc2(GR a[], int count)
{
    int i, j, index;
    // Sort by rating using insertion sort
    for(i=0; i <= count-1; i++)
    {
        index = i;
        for(j= j+1; j <= count; j++)
        {
            if(a[j].rating > a[index].rating)
            {
                index = j;
            }
        }

        // Swapping products
        GR temp;
        strcpy(temp.name, a[i].name);
        temp.productNo = a[i].productNo;
        temp.price = a[i].price;
        strcpy(temp.brand, a[i].brand);
        temp.rating = a[i].rating;
        strcpy(temp.quantity, a[i].quantity);
        temp.type = a[i].type;

        strcpy(a[i].name, a[index].name);
        a[i].productNo = a[index].productNo;
        a[i].price = a[index].price;
        strcpy(a[i].brand, a[index].brand);
        a[i].rating = a[index].rating;
        strcpy(a[i].quantity, a[index].quantity);
        a[i].type = a[index].type;

        strcpy(a[index].name, temp.name);
        a[index].productNo = temp.productNo;
        a[index].price = temp.price;
        strcpy(a[index].brand, temp.brand);
        a[index].rating = temp.rating;
        strcpy(a[index].quantity, temp.quantity);
        a[index].type = temp.type;
    }
}

/**
Function Name: menu
Input Params: NILL
Return Type: void
Description: For sub-string search of product names
**/
void search()
{
    char input[50], t[300], p[50];
    int i=0, num=0, j, k, flag, z1=0, z2=0, z3=0, z4=0, z5=0, z6=0, pNo, quantity, choice;
    int t_size1, t_size2, t_size3, t_size4, t_size5, t_size6, p_size;

    // Product name to be searched
    printf("\nEnter the product name : ");
    scanf("%[^\n]s", input);

    // Comparing the input product name with all the products of Electronic Appliances
    for(i=0; i <= count1; i++)
    {
        flag = 0;
        t_size1 = strlen(elec[i].name);
        p_size = strlen(input);
        for(j=0; j < t_size1 - p_size; j++)
        {
            k=0;
            while((k < p_size) && (input[k] == (elec[i].name)[j+k]))
            {
                k=k+1;
            }

            if(k == p_size)
            {
                strcpy(found1[z1].name, elec[i].name);
                found1[z1].productNo = elec[i].productNo;
                found1[z1].price = elec[i].price;
                strcpy(found1[z1].brand, elec[i].brand);
                found1[z1].rating = elec[i].rating;
                strcpy(found1[z1].extra, found1[z1].extra);
                z1++;
                break;
            }
        }
    }
    z1--;
    printf("\n\n");

    // Display information of the matched product
    if(z1 =! -1)
    {
    printf("\n\nRESULTS :\n");
    for(i=0; i <= z1; i++)
    {
        printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nInfo: %s\n", found1[z1].name, found1[z1].productNo, found1[z1].price, found1[z1].brand, found1[z1].rating, found1[z1].extra );
    }

    // To choose to add product to cart or to return to main menu
    printf("Press 1 to add product to cart, 0 for main menu");
    scanf("%d", &choice);

    // To add products to cart
    if(choice == 1)
    {
        printf("Enter productNo to add to cart: ");
        scanf("%d", &pNo);
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        for(j=0; j <= z1; j++)
        {
            if(found1[j].productNo == pNo)
            addToCart(found1[j].name, pNo, found1[j].price, found1[j].brand, quantity);
        }
    }

    else
        menu();
    }

    // Comparing the input product name with all the products of Clothing and Accessories
    for(i=0; i <= count2; i++)
    {
        flag =0;
        t_size2 = strlen(cloth[i].name);
        for(j=0; j < t_size2 - p_size; j++)
        {
            k=0;
            while((k < p_size) && (input[k] == (cloth[i].name)[j+k]))
            {
                k = k + 1;
            }

            if(k == p_size)
            {
                strcpy(found2[z2].name, cloth[i].name);
                found2[z2].productNo = cloth[i].productNo;
                found2[z2].price = cloth[i].price;
                strcpy(found2[z2].color, cloth[i].color);
                strcpy(found2[z2].brand, cloth[i].brand);
                found2[z2].rating = cloth[i].rating;
                strcpy(found2[z2].size, cloth[i].size);
                strcpy(found2[z2].user, cloth[i].user);
                z2++;
                break;
            }
        }
    }
    z2--;
    printf("\n\n");

    // Display information of the matched product
    if(z2 =! -1)
    {
    printf("\n\nRESULTS :\n");
    for(i=0; i <= z2; i++)
    {
        printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\nUser: %s\n", found2[z2].name, found2[z2].productNo, found2[z2].price, found2[z2].color, found2[z2].brand, found2[z2].rating, found2[z2].size, found2[z2].user );
    }

    // To choose to add product to cart or to return to main menu
    printf("Press 1 to add product to cart, 0 for main menu");
    scanf("%d", &choice);

    // To add products to cart
    if(choice == 1)
    {
        printf("Enter productNo to add to cart: ");
        scanf("%d", &pNo);
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        for(j=0; j <= z2; j++)
        {
            if(found2[j].productNo == pNo)
            addToCart(found2[j].name, pNo, found2[j].price, found2[j].brand, quantity);
        }
    }

    // Return to main menu
    else
        menu();
    }

    // Comparing the input product name with all the products of Furniture
    for(i=0; i <= count3; i++)
    {
        flag =0;
        t_size3 = strlen(furn[i].name);
        for(j=0; j< t_size3 - p_size; j++)
        {
            k=0;
            while((k < p_size) && (input[k] == (furn[i].name)[j+k]))
            {
                k=k+1;
            }
            if(k == p_size)
            {
                strcpy(found3[z3].name, furn[i].name);
                found3[z3].productNo = furn[i].productNo;
                found3[z3].price = furn[i].price;
                strcpy(found3[z3].color, furn[i].color);
                strcpy(found3[z3].brand, furn[i].brand);
                found3[z3].rating = furn[i].rating;
                strcpy(found3[z3].size, furn[i].size);
                z3++;
                break;
            }
        }
    }
    z3--;
    printf("\n\n");

    // Display information of the matched product
    if(z3 =! -1)
    {
    printf("\n\nRESULTS :\n");
    for(i=0; i <= z3; i++)
    {
        printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nSize: %s\n", found3[z3].name, found3[z3].productNo, found3[z3].price, found3[z3].color, found3[z3].brand, found3[z3].rating, found3[z3].size );
    }

    // To choose to add product to cart or to return to main menu
    printf("Press 1 to add product to cart, 0 for main menu");
    scanf("%d", &choice);

    // To add products to cart
    if(choice == 1)
    {
        printf("Enter productNo to add to cart: ");
        scanf("%d", &pNo);
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        for(j=0; j <= z3; j++)
        {
            if(found3[j].productNo == pNo)
            addToCart(found3[j].name, pNo, found3[j].price, found3[j].brand, quantity);
        }
    }

    // Return to main menu
    else
        menu();
    }

    // Comparing the input product name with all the products of Sports and Fitness
    for(i=0; i <= count4; i++)
    {
        flag =0;
        t_size4 = strlen(sport[i].name);
        for(j=0; j< t_size4 - p_size; j++)
        {
            k=0;
            while((k < p_size) && (input[k] == (sport[i].name)[j+k]))
            {
                k=k+1;
            }

            if(k == p_size)
            {
                strcpy(found4[z4].name, sport[i].name);
                found4[z4].productNo = sport[i].productNo;
                found4[z4].price = sport[i].price;
                strcpy(found4[z4].color, sport[i].color);
                strcpy(found4[z4].brand, sport[i].brand);
                found4[z4].rating = sport[i].rating;
                strcpy(found4[z4].extra, sport[i].extra);
                z4++;
                break;
            }
        }
    }
    z4--;
    printf("\n\n");

    // Display information of the matched product
    if(z4 =! -1)
    {
    printf("\n\nRESULTS :\n");
    for(i=0; i <= z4; i++)
    {
        printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\nInfo: %s\n", found4[z4].name, found4[z4].productNo, found4[z4].price, found4[z4].color, found4[z4].brand, found4[z4].rating, found4[z4].extra );
    }

    // To choose to add product to cart or to return to main menu
    printf("Press 1 to add product to cart, 0 for main menu");
    scanf("%d", &choice);

    // To add products to cart
    if(choice == 1)
    {
        printf("Enter productNo to add to cart: ");
        scanf("%d", &pNo);
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        for(j=0; j <= z4; j++)
        {
            if(found4[j].productNo == pNo)
            addToCart(found4[j].name, pNo, found4[j].price, found4[j].brand, quantity);
        }
    }

    // Return to main menu
    else
        menu();
    }

    // Comparing the input product name with all the products of Healthcare and Cosmetics
    for(i=0; i <= count5; i++)
    {
        flag=0;
        t_size5 = strlen(heal[i].name);
        for(j=0; j< t_size5 - p_size; j++)
        {
            k=0;
            while((k < p_size) && (input[k] == (heal[i].name)[j+k]))
            {
                k=k+1;
            }

            if(k == p_size)
            {
                strcpy(found5[z5].name, heal[i].name);
                found5[z5].productNo = heal[i].productNo;
                found5[z5].price = heal[i].price;
                strcpy(found5[z5].color, heal[i].color);
                strcpy(found5[z5].brand, heal[i].brand);
                found5[z5].rating = heal[i].rating;
                z5++;
                break;
            }
        }
    }
    z5--;
    printf("\n\n");

    // Display information of the matched product
    if(z5 =! -1)
    {
    printf("\n\nRESULTS :\n");
    for(i=0; i <= z5; i++)
    {
        printf("Name: %s\nProduct No: %d\nPrice: %f\nColor: %s\nBrand: %s\nRating: %f\n", found5[z5].name, found5[z5].productNo, found5[z5].price, found5[z5].color, found5[z5].brand, found5[z5].rating );
    }

    // To choose to add product to cart or to return to main menu
    printf("Press 1 to add product to cart, 0 for main menu");
    scanf("%d", &choice);

    // To add products to cart
    if(choice == 1)
    {
        printf("Enter productNo to add to cart: ");
        scanf("%d", &pNo);
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        for(j=0; j<= z5; j++)
        {
            if(found5[j].productNo == pNo)
            addToCart(found5[j].name, pNo, found5[j].price, found5[j].brand, quantity);
        }
    }

    // Return to main menu
    else
        menu();
    }

    // Comparing the input product name with all the products of Grocery
    for(i=0; i <= count6; i++)
    {
        flag =0;
        t_size6 = strlen(groc[i].name);
        for(j=0; j < t_size6 - p_size; j++)
        {
            k=0;
            while((k < p_size) && (input[k]==(groc[i].name)[j+k]))
            {
                k=k+1;
            }

            if(k == p_size)
            {
                strcpy(found6[z6].name, groc[i].name);
                found6[z6].productNo = groc[i].productNo;
                found6[z6].price = groc[i].price;
                strcpy(found6[z6].brand, groc[i].brand);
                found6[z6].rating = groc[i].rating;
                strcpy(found6[z6].quantity, groc[i].quantity);
                z6++;
                break;
            }
        }
    }
    z6--;
    printf("\n\n");

    // Display information of the matched product
    if(z6 =! -1)
    {
    printf("\n\nRESULTS :\n");
    for(i=0; i <= z6; i++)
    {
        printf("Name: %s\nProduct No: %d\nPrice: %f\nBrand: %s\nRating: %f\nQuantity: %s\n", found6[z6].name, found6[z6].productNo, found6[z6].price, found6[z6].brand, found6[z6].rating, found6[z6].quantity );
    }

    // To choose to add product to cart or to return to main menu
    printf("Press 1 to add product to cart, 0 for main menu");
    scanf("%d", &choice);

    // To add products to cart
    if(choice == 1)
    {
        printf("Enter productNo to add to cart: ");
        scanf("%d", &pNo);
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        for(j=0; j<= z6; j++)
        {
            if(found6[j].productNo == pNo)
            addToCart(found6[j].name, pNo, found6[j].price, found6[j].brand, quantity);
        }
    }

    // Return to main menu
    else
        menu();
    }

    if( z1 == -1 && z2 == -1 && z3 == -1 && z4 == -1 && z5 == -1 && z6 == -1 )
    {
        printf("\nNO RESULTS\n");
    }
}

/**
Function Name: menu
Input Params: NILL
Return Type: void
Description: To display products in the cart
**/
void displayCart()
{
    int choice;
    CART *ptr;

    // If cart is empty
    if(start == NULL)
    {
        printf("\nCart is empty");
        return;
    }

    // Display information of the prodcts in the cart
    else
    {
        ptr = start;
        printf("\nCart products are: ");
        while(ptr!=NULL)
        {
            printf("\nName: %s", ptr->productName);
            printf("\nPNumber: %d", ptr->productNo);
            printf("\nPrice: %f", ptr->price);
            printf("\nBrand: %s", ptr->brand);
            printf("\nQuantity: %d", ptr->quantity);
            ptr=ptr->next ;
        }

        // To place final order or continue shopping
        printf("\n To order the products, press 1. To continue shopping, press 0");
        scanf("%d", &choice);

        // To place final order and applying discounts
        if( choice == 1)
        {
            discount();
        }

        // To continue shopping and return to main menu
        else
        {
            menu();
        }
    }
}

/**
Function Name: menu
Input Params: char, int, float
Return Type: void
Description: To add products to cart
**/
void addToCart(char name[20], int pNo, float price, char brand[15], int quantity)
{
    CART *temp, *ptr;
    ptr = (CART *) malloc(sizeof(CART));
    int item;

    // To check if contents are empty
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }

    // To add product information to the cart
    else
    {
        strcpy(ptr->productName, name);
        ptr->productNo = pNo;
        ptr->price = price;
        strcpy(ptr->brand, brand);
        ptr->quantity = quantity;

        if(start == NULL)
        {
            ptr -> next = NULL;
            start = ptr;
            printf("\nProduct added to cart");
        }

        else
        {
            temp = start;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nProduct added to cart");
        }
    }
}

/**
Function Name: menu
Input Params: NILL
Return Type: void
Description: To apply discounts and offers
**/
void discount()
{
    CART *temp=start;
    float p,d;
    int q,n;
    int an, ka, lk, ly;
    an = ka = lk = ly = 0;

    // Updating the prices of the products by applying discounts and offers
    while(temp!=NULL)
    {
        // 7% OFF on HP products
        if(strcmp(temp->brand, "HP") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.07*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 10% OFF on Lenovo products
        else if(strcmp(temp->brand, "Lenovo") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.1*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 15% OFF on boAt products
        else if(strcmp(temp->brand, "boAt") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.15*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 7% OFF on OnePlus products
        else if(strcmp(temp->brand, "OnePlus") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.07*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 5% OFF on Samsung products
        else if(strcmp(temp->brand, "Samsung") == 0)
        {
            q=temp->quantity;
            p = temp->price;
            d = (0.05*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 30% OFF on Jockey products
        else if(strcmp(temp->brand, "Jockey") == 0)
        {
            q=temp->quantity;
            p = temp->price;
            d = (0.3*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 25% OFF on Puma products
        else if(strcmp(temp->brand, "Puma") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.25*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 40% OFF on Fastrack products
        else if(strcmp(temp->brand, "Fastrack") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.4*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 20% OFF on SONATA products
        else if(strcmp(temp->brand, "SONATA") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.2*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 15% OFF on TIMEX products
        else if(strcmp(temp->brand, "TIMEX") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.15*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 30% OFF on SPRINGTEK products
        else if(strcmp(temp->brand, "SPRINGTEK") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.3*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 10% OFF on OAK products
        else if(strcmp(temp->brand, "OAK") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.1*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 15% OFF on MEZIRE products
        else if(strcmp(temp->brand, "MEZIRE") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.15*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 10% OFF on GODREJ products
        else if(strcmp(temp->brand, "GODREJ") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.1*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 20% OFF on NILKAMAL products
        else if(strcmp(temp->brand, "NILKAMAL") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.2*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 10% OFF on Belco products
        else if(strcmp(temp->brand, "Belco") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.1*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 30% OFF on Cosco products
        else if(strcmp(temp->brand, "Cosco") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.3*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 25% OFF on Sparnod Fitness products
        else if(strcmp(temp->brand, "Sparnod Fitness") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.25*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 15% OFF on MoonEyes products
        else if(strcmp(temp->brand, "MoonEyes") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.15*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 20% OFF on Navaratna products
        else if(strcmp(temp->brand, "Navaratna") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.2*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 10% OFF on Garnier products
        else if(strcmp(temp->brand, "Garnier") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.1*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 50% OFF on Presto products
        else if(strcmp(temp->brand, "Presto") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.5*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 5% OFF on Himalaya products
        else if(strcmp(temp->brand, "Himalaya") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.05*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 30% OFF on Nutraj products
        else if(strcmp(temp->brand, "Nutraj") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.3*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // 10% OFF on Rostaa products
        else if(strcmp(temp->brand, "Rostaa") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            d = (0.1*p)*q;
            p = p*q - d;
            temp->price = p;
        }

        // Buy 1 get 1 free on Anand products
        else if(strcmp(temp->brand, "Anand") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            n = q/2;
            p = p*q - p*n;
            temp->price = p;
        }

        // Buy 1 get 1 free on Lakme products
        else if(strcmp(temp->brand, "Lakme") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            n = q/2;
            p = p*q - p*n;
            temp->price = p;
        }

        // Buy 2 get 1 free on Lays products
        else if(strcmp(temp->brand, "Lays") == 0)
        {
            q = temp->quantity;
            p = temp->price;
            n = q/3;
            p = p*q - p*n;
            temp->price = p;
        }
        temp=temp->next;
    }
}

/**
Function Name: menu
Input Params: NILL
Return Type: void
Description: To finalize the order
**/
void order()
{
    CART *ptr;
    float total = 0;
    int pay_mode, c_no, cvv, otp;
    char address[50], card_name[20], validity[5], bank_name[15], username[20], password[10], upi[10], tenure[15];
    ptr = start;

    // Calculate total amount of the order
    while(ptr!=NULL)
    {
        total = total + ptr->price;
        ptr = ptr->next ;
    }

    // Display total order amount
    printf("Total Order Amount: %f", total);

    // Read address of the customer
    printf("Enter your address: ");
    scanf("%s", address);

    // Choose payment mode
    printf("\nChoose payment mode: ");
    printf("\n1. Pay on delivery\n2. Credit/Debit card\n3. Net Banking\n4. Unified Payment Interface (UPI)\n5. Easy Monthly Installments (EMI) ");
    scanf("%d", &pay_mode);

    // For Pay on delivery
    if( pay_mode == 1)
    {
        printf("Payment mode: Pay on delivery");
    }

    // For Credit/Debit card
    else if(pay_mode == 2)
    {
        printf("Payment mode: Credit/Debit card");
        printf("Enter card number: ");
        scanf("%d", &c_no);
        printf("Enter name of the card holder: ");
        scanf("%s", card_name);
        printf("Enter validity: ");
        scanf("%s", validity);
        printf("Enter CVV: ");
        scanf("%d", &cvv);
        printf("Enter OTP: ");
        scanf("%d", &otp);
        printf("Payment successful");
    }

    // For Net Banking
    else if(pay_mode == 3)
    {
        printf("Payment mode: Net Banking");
        printf("Enter bank name: ");
        scanf("%s", bank_name);
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);
        printf("Enter OTP: ");
        scanf("%d", &otp);
        printf("Payment successful");
    }

    // For Unified Payment Interface (UPI)
    else if(pay_mode == 4)
    {
        printf("Payment mode: Unified Payment Interface (UPI)");
        printf("Enter UPI ID: ");
        scanf("%s", upi);
        printf("Payment successful");
    }

    // For Easy Monthly Installments (EMI)
    else
    {
        printf("Payment mode: Easy Monthly Installments (EMI)");
        printf("Enter name: ");
        scanf("%s", card_name);
        printf("Enter card number: ");
        scanf("%d", &c_no);
        printf("Enter validity: ");
        scanf("%s", validity);
        printf("Enter card tenure: ");
        scanf("%s", tenure);
        printf("Enter CVV: ");
        scanf("%d", &cvv);
        printf("Payment successful");
    }

    // Display end result
    printf("============ORDER SUCCESSFUL!==============");
}

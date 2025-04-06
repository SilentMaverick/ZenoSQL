#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_STR_LEN 50

// Structure declarations
struct Cell {
    char str_value[MAX_STR_LEN];
    int int_value;
    float float_value;
    char data_type;
};

struct Table {
    char name[50];
    int rows;
    int columns;
    char row_names[MAX_ROWS][50];
    char column_names[MAX_COLS][50];
    struct Cell data[MAX_ROWS][MAX_COLS];
    char column_types[MAX_COLS];
};

int compare_float(const void* a, const void* b) {
    float diff = (*(float*)a - *(float*)b);
    return (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
}

int compare_string(const void* a, const void* b) {
    return strcmp((char*)a, (char*)b);
}

void pre_made_libraries(){
    int choice;
    printf("1. Library Managment Database\n");
    printf("2. Ticket Managment Database\n");
    printf("3. Student Managment Database\n");
    printf("4. Employee Managment Database\n");
    printf("5. Book Managment Database\n");
    printf("6. Movie Managment Database\n");
    printf("7. Music Managment Database\n");
    printf("8. Restaurant Managment Database\n");
    printf("9. Hotel Managment Database\n");
    printf("10. Car Managment Database\n");
    printf("11. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            Library_Managment();
            break;
        case 2:
            Ticket_Managment();
            break;
        case 3:
            Student_Managment();
            break;
        case 4:
            Employee_Managment();
            break;
        case 5:
            Book_Managment();
            break;
        case 6:
            Movie_Managment();
            break;
        case 7:
            Music_Managment();
            break;
        case 8:
            Restaurant_Managment();
            break;
        case 9:
            Hotel_Managment();
            break;
        case 10:
            Car_Managment();
            break;
        case 11:
            printf("Exiting program...\n");
            break;   
        default:
            printf("Invalid choice\n");
    }
}
void Employee_Managment() {
    struct Employee {
        char name[50];
        int id;
        char position[50];
        float salary;
    };

    void add_employee() {
        struct Employee employee;
        FILE *fptr;
        fptr = fopen("EmployeeDatabase.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter employee name: ");
        scanf("%s", employee.name);
        printf("Enter employee ID: ");
        scanf("%d", &employee.id);
        printf("Enter employee position: ");
        scanf("%s", employee.position);
        printf("Enter employee salary: ");
        scanf("%f", &employee.salary);

        fprintf(fptr, "Name: %s\nID: %d\nPosition: %s\nSalary: %.2f\n\n", 
                employee.name, employee.id, employee.position, employee.salary);
        fclose(fptr);
        printf("Employee record added successfully\n");
    }

    void access_employee_database() {
        struct Employee employee;
        FILE *fptr;
        fptr = fopen("EmployeeDatabase.txt", "r");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Employees in the database:\n");
        while (fscanf(fptr, "Name: %s\nID: %d\nPosition: %s\nSalary: %f\n\n", 
                      employee.name, &employee.id, employee.position, &employee.salary) != EOF) {
            printf("Name: %s, ID: %d, Position: %s, Salary: %.2f\n", 
                   employee.name, employee.id, employee.position, employee.salary);
        }

        fclose(fptr);
    }

    void display_employee_database() {
        access_employee_database();
    }

    int choice;
    printf("Employee Managment Database\n");
    printf("1. Add Employee\n");
    printf("2. Access Employee Database\n");
    printf("3. Display Employee Database\n");
    printf("4. Exit\n");
    printf("5. Return to Pre Made Libraries\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_employee();
            break;
        case 2:
            access_employee_database();
            break;
        case 3:
            display_employee_database();
            break;
        case 4:
            printf("Exiting Employee Managment...\n");
            break;
        case 5:
            pre_made_libraries();
            break;
        default:
            printf("Invalid choice\n");
    }
}

void Book_Managment() {
    struct Book {
        char title[50];
        char author[50];
        int available;
        char due_date[20];
    };

    void add_book() {
        struct Book book;
        FILE *fptr;
        fptr = fopen("BookDatabase.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter book title: ");
        scanf("%s", book.title);
        printf("Enter book author: ");
        scanf("%s", book.author);
        book.available = 1;
        strcpy(book.due_date, "N/A");

        fprintf(fptr, "Title: %s\nAuthor: %s\nAvailable: %d\nDue Date: %s\n\n", 
                book.title, book.author, book.available, book.due_date);
        fclose(fptr);
        printf("Book record added successfully\n");
    }

    void access_book_database() {
        struct Book book;
        FILE *fptr;
        fptr = fopen("BookDatabase.txt", "r");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Books in the database:\n");
        while (fscanf(fptr, "Title: %s\nAuthor: %s\nAvailable: %d\nDue Date: %s\n\n", 
                      book.title, book.author, &book.available, book.due_date) != EOF) {
            printf("Title: %s, Author: %s, Available: %d, Due Date: %s\n", 
                   book.title, book.author, book.available, book.due_date);
        }

        fclose(fptr);
    }

    void display_book_database() {
        access_book_database();
    }

    int choice;
    printf("Book Managment Database\n");
    printf("1. Add Book\n");
    printf("2. Access Book Database\n");
    printf("3. Display Book Database\n");
    printf("4. Exit\n");
    printf("5. Return to Pre Made Libraries\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_book();
            break;
        case 2:
            access_book_database();
            break;
        case 3:
            display_book_database();
            break;
        case 4:
            printf("Exiting Book Managment...\n");
            break;
        case 5:
            pre_made_libraries();
            break;
        default:
            printf("Invalid choice\n");
    }
}

void Movie_Managment() {
    struct Movie {
        char title[50];
        char director[50];
        int available;
        char release_date[20];
    };

    void add_movie() {
        struct Movie movie;
        FILE *fptr;
        fptr = fopen("MovieDatabase.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter movie title: ");
        scanf("%s", movie.title);
        printf("Enter movie director: ");
        scanf("%s", movie.director);
        movie.available = 1;
        strcpy(movie.release_date, "N/A");

        fprintf(fptr, "Title: %s\nDirector: %s\nAvailable: %d\nRelease Date: %s\n\n", 
                movie.title, movie.director, movie.available, movie.release_date);
        fclose(fptr);
        printf("Movie record added successfully\n");
    }

    void access_movie_database() {
        struct Movie movie;
        FILE *fptr;
        fptr = fopen("MovieDatabase.txt", "r");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Movies in the database:\n");
        while (fscanf(fptr, "Title: %s\nDirector: %s\nAvailable: %d\nRelease Date: %s\n\n", 
                      movie.title, movie.director, &movie.available, movie.release_date) != EOF) {
            printf("Title: %s, Director: %s, Available: %d, Release Date: %s\n", 
                   movie.title, movie.director, movie.available, movie.release_date);
        }

        fclose(fptr);
    }

    void display_movie_database() {
        access_movie_database();
    }

    int choice;
    printf("Movie Managment Database\n");
    printf("1. Add Movie\n");
    printf("2. Access Movie Database\n");
    printf("3. Display Movie Database\n");
    printf("4. Exit\n");
    printf("5. Return to Pre Made Libraries\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_movie();
            break;
        case 2:
            access_movie_database();
            break;
        case 3:
            display_movie_database();
            break;
        case 4:
            printf("Exiting Movie Managment...\n");
            break;
        case 5:
            pre_made_libraries();
            break;
        default:
            printf("Invalid choice\n");
    }
}

void Music_Managment() {
    struct Music {
        char title[50];
        char artist[50];
        int available;
        char release_date[20];
    };

    void add_music() {
        struct Music music;
        FILE *fptr;
        fptr = fopen("MusicDatabase.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter music title: ");
        scanf("%s", music.title);
        printf("Enter music artist: ");
        scanf("%s", music.artist);
        music.available = 1;
        strcpy(music.release_date, "N/A");

        fprintf(fptr, "Title: %s\nArtist: %s\nAvailable: %d\nRelease Date: %s\n\n", 
                music.title, music.artist, music.available, music.release_date);
        fclose(fptr);
        printf("Music record added successfully\n");
    }

    void access_music_database() {
        struct Music music;
        FILE *fptr;
        fptr = fopen("MusicDatabase.txt", "r");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Music in the database:\n");
        while (fscanf(fptr, "Title: %s\nArtist: %s\nAvailable: %d\nRelease Date: %s\n\n", 
                      music.title, music.artist, &music.available, music.release_date) != EOF) {
            printf("Title: %s, Artist: %s, Available: %d, Release Date: %s\n", 
                   music.title, music.artist, music.available, music.release_date);
        }

        fclose(fptr);
    }

    void display_music_database() {
        access_music_database();
    }

    int choice;
    printf("Music Managment Database\n");
    printf("1. Add Music\n");
    printf("2. Access Music Database\n");
    printf("3. Display Music Database\n");
    printf("4. Exit\n");
    printf("5. Return to Pre Made Libraries\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_music();
            break;
        case 2:
            access_music_database();
            break;
        case 3:
            display_music_database();
            break;
        case 4:
            printf("Exiting Music Managment...\n");
            break;
        case 5:
            pre_made_libraries();
            break;
        default:
            printf("Invalid choice\n");
    }
}


void Contact_Managment() {
    struct Contact {
        char name[50];
        char phone[15];
        char email[50];
    };
    void delete_contact() {
        struct Contact contact;
        FILE *fptr, *temp;
        char name[50];
        int found = 0;

        fptr = fopen("ContactDatabase.txt", "r");
        temp = fopen("TempContactDatabase.txt", "w");
        if (fptr == NULL || temp == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter the name of the contact to delete: ");
        scanf("%s", name);

        while (fscanf(fptr, "Name: %s\nPhone: %s\nEmail: %s\n\n", 
                      contact.name, contact.phone, contact.email) != EOF) {
            if (strcmp(contact.name, name) != 0) {
                fprintf(temp, "Name: %s\nPhone: %s\nEmail: %s\n\n", 
                        contact.name, contact.phone, contact.email);
            } else {
                found = 1;
            }
        }

        fclose(fptr);
        fclose(temp);

        remove("ContactDatabase.txt");
        rename("TempContactDatabase.txt", "ContactDatabase.txt");

        if (found) {
            printf("Contact deleted successfully\n");
        } else {
            printf("Contact not found\n");
        }
    }

    void update_contact() {
        struct Contact contact;
        FILE *fptr, *temp;
        char name[50];
        int found = 0;

        fptr = fopen("ContactDatabase.txt", "r");
        temp = fopen("TempContactDatabase.txt", "w");
        if (fptr == NULL || temp == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter the name of the contact to update: ");
        scanf("%s", name);

        while (fscanf(fptr, "Name: %s\nPhone: %s\nEmail: %s\n\n", 
                      contact.name, contact.phone, contact.email) != EOF) {
            if (strcmp(contact.name, name) == 0) {
                found = 1;
                printf("Enter new phone: ");
                scanf("%s", contact.phone);
                printf("Enter new email: ");
                scanf("%s", contact.email);
            }
            fprintf(temp, "Name: %s\nPhone: %s\nEmail: %s\n\n", 
                    contact.name, contact.phone, contact.email);
        }

        fclose(fptr);
        fclose(temp);

        remove("ContactDatabase.txt");
        rename("TempContactDatabase.txt", "ContactDatabase.txt");

        if (found) {
            printf("Contact updated successfully\n");
        } else {
            printf("Contact not found\n");
        }
    }

    void merge_contacts() {
        struct Contact contact1, contact2, merged_contact;
        FILE *fptr, *temp;
        char name1[50], name2[50];
        int found1 = 0, found2 = 0;

        fptr = fopen("ContactDatabase.txt", "r");
        temp = fopen("TempContactDatabase.txt", "w");
        if (fptr == NULL || temp == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter the name of the first contact to merge: ");
        scanf("%s", name1);
        printf("Enter the name of the second contact to merge: ");
        scanf("%s", name2);

        while (fscanf(fptr, "Name: %s\nPhone: %s\nEmail: %s\n\n", 
                      contact1.name, contact1.phone, contact1.email) != EOF) {
            if (strcmp(contact1.name, name1) == 0) {
                found1 = 1;
                merged_contact = contact1;
            } else if (strcmp(contact1.name, name2) == 0) {
                found2 = 1;
                strcpy(merged_contact.phone, contact1.phone);
                strcpy(merged_contact.email, contact1.email);
            } else {
                fprintf(temp, "Name: %s\nPhone: %s\nEmail: %s\n\n", 
                        contact1.name, contact1.phone, contact1.email);
            }
        }

        if (found1 && found2) {
            fprintf(temp, "Name: %s\nPhone: %s\nEmail: %s\n\n", 
                    merged_contact.name, merged_contact.phone, merged_contact.email);
            printf("Contacts merged successfully\n");
        } else {
            printf("One or both contacts not found\n");
        }

        fclose(fptr);
        fclose(temp);

        remove("ContactDatabase.txt");
        rename("TempContactDatabase.txt", "ContactDatabase.txt");
    }

    void add_contact() {
        struct Contact contact;
        FILE *fptr;
        fptr = fopen("ContactDatabase.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter contact name: ");
        scanf("%s", contact.name);
        printf("Enter contact phone: ");
        scanf("%s", contact.phone);
        printf("Enter contact email: ");
        scanf("%s", contact.email);

        fprintf(fptr, "Name: %s\nPhone: %s\nEmail: %s\n\n", 
                contact.name, contact.phone, contact.email);
        fclose(fptr);
        printf("Contact record added successfully\n");
    }

    void access_contact_database() {
        struct Contact contact;
        FILE *fptr;
        fptr = fopen("ContactDatabase.txt", "r");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Contacts in the database:\n");
        while (fscanf(fptr, "Name: %s\nPhone: %s\nEmail: %s\n\n", 
                      contact.name, contact.phone, contact.email) != EOF) {
            printf("Name: %s, Phone: %s, Email: %s\n", 
                   contact.name, contact.phone, contact.email);
        }

        fclose(fptr);
    }

    void display_contact_database() {
        access_contact_database();
    }

    int choice;
    printf("Contact Managment Database\n");
    printf("1. Add Contact\n");
    printf("2. Access Contact Database\n");
    printf("3. Display Contact Database\n");
    printf("4. Exit\n");
    printf("5. Return to Pre Made Libraries\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_contact();
            break;
        case 2:
            access_contact_database();
            break;
        case 3:
            display_contact_database();
            break;
        case 4:
            printf("Exiting Contact Managment...\n");
            break;
        case 5:
            pre_made_libraries();
            break;
        default:
            printf("Invalid choice\n");
    }
}
void Restaurant_Managment() {
    struct Restaurant {
        char name[50];
        char location[50];
        char cuisine[50];
        int rating;
    };

    void add_restaurant() {
        struct Restaurant restaurant;
        FILE *fptr;
        fptr = fopen("RestaurantDatabase.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter restaurant name: ");
        scanf("%s", restaurant.name);
        printf("Enter restaurant location: ");
        scanf("%s", restaurant.location);
        printf("Enter restaurant cuisine: ");
        scanf("%s", restaurant.cuisine);
        printf("Enter restaurant rating (1-5): ");
        scanf("%d", &restaurant.rating);

        fprintf(fptr, "Name: %s\nLocation: %s\nCuisine: %s\nRating: %d\n\n", 
                restaurant.name, restaurant.location, restaurant.cuisine, restaurant.rating);
        fclose(fptr);
        printf("Restaurant record added successfully\n");
    }

    void access_restaurant_database() {
        struct Restaurant restaurant;
        FILE *fptr;
        fptr = fopen("RestaurantDatabase.txt", "r");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Restaurants in the database:\n");
        while (fscanf(fptr, "Name: %s\nLocation: %s\nCuisine: %s\nRating: %d\n\n", 
                      restaurant.name, restaurant.location, restaurant.cuisine, &restaurant.rating) != EOF) {
            printf("Name: %s, Location: %s, Cuisine: %s, Rating: %d\n", 
                   restaurant.name, restaurant.location, restaurant.cuisine, restaurant.rating);
        }

        fclose(fptr);
    }

    void display_restaurant_database() {
        access_restaurant_database();
    }

    int choice;
    printf("Restaurant Managment Database\n");
    printf("1. Add Restaurant\n");
    printf("2. Access Restaurant Database\n");
    printf("3. Display Restaurant Database\n");
    printf("4. Exit\n");
    printf("5. Return to Pre Made Libraries\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_restaurant();
            break;
        case 2:
            access_restaurant_database();
            break;
        case 3:
            display_restaurant_database();
            break;
        case 4:
            printf("Exiting Restaurant Managment...\n");
            break;
        case 5:
            pre_made_libraries();
            break;
        default:
            printf("Invalid choice\n");
    }
}

void Hotel_Managment() {
    struct Hotel {
        char name[50];
        char location[50];
        int rooms_available;
        float price_per_night;
    };

    void add_hotel() {
        struct Hotel hotel;
        FILE *fptr;
        fptr = fopen("HotelDatabase.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter hotel name: ");
        scanf("%s", hotel.name);
        printf("Enter hotel location: ");
        scanf("%s", hotel.location);
        printf("Enter number of rooms available: ");
        scanf("%d", &hotel.rooms_available);
        printf("Enter price per night: ");
        scanf("%f", &hotel.price_per_night);

        fprintf(fptr, "Name: %s\nLocation: %s\nRooms Available: %d\nPrice per Night: %.2f\n\n", 
                hotel.name, hotel.location, hotel.rooms_available, hotel.price_per_night);
        fclose(fptr);
        printf("Hotel record added successfully\n");
    }

    void access_hotel_database() {
        struct Hotel hotel;
        FILE *fptr;
        fptr = fopen("HotelDatabase.txt", "r");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Hotels in the database:\n");
        while (fscanf(fptr, "Name: %s\nLocation: %s\nRooms Available: %d\nPrice per Night: %f\n\n", 
                      hotel.name, hotel.location, &hotel.rooms_available, &hotel.price_per_night) != EOF) {
            printf("Name: %s, Location: %s, Rooms Available: %d, Price per Night: %.2f\n", 
                   hotel.name, hotel.location, hotel.rooms_available, hotel.price_per_night);
        }

        fclose(fptr);
    }

    void display_hotel_database() {
        access_hotel_database();
    }

    int choice;
    printf("Hotel Managment Database\n");
    printf("1. Add Hotel\n");
    printf("2. Access Hotel Database\n");
    printf("3. Display Hotel Database\n");
    printf("4. Exit\n");
    printf("5. Return to Pre Made Libraries\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_hotel();
            break;
        case 2:
            access_hotel_database();
            break;
        case 3:
            display_hotel_database();
            break;
        case 4:
            printf("Exiting Hotel Managment...\n");
            break;
        case 5:
            pre_made_libraries();
            break;
        default:
            printf("Invalid choice\n");
    }
}

void Car_Managment() {
    struct Car {
        char model[50];
        char manufacturer[50];
        int year;
        float price;
    };

    void add_car() {
        struct Car car;
        FILE *fptr;
        fptr = fopen("CarDatabase.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter car model: ");
        scanf("%s", car.model);
        printf("Enter car manufacturer: ");
        scanf("%s", car.manufacturer);
        printf("Enter car year: ");
        scanf("%d", &car.year);
        printf("Enter car price: ");
        scanf("%f", &car.price);

        fprintf(fptr, "Model: %s\nManufacturer: %s\nYear: %d\nPrice: %.2f\n\n", 
                car.model, car.manufacturer, car.year, car.price);
        fclose(fptr);
        printf("Car record added successfully\n");
    }

    void access_car_database() {
        struct Car car;
        FILE *fptr;
        fptr = fopen("CarDatabase.txt", "r");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Cars in the database:\n");
        while (fscanf(fptr, "Model: %s\nManufacturer: %s\nYear: %d\nPrice: %f\n\n", 
                      car.model, car.manufacturer, &car.year, &car.price) != EOF) {
            printf("Model: %s, Manufacturer: %s, Year: %d, Price: %.2f\n", 
                   car.model, car.manufacturer, car.year, car.price);
        }

        fclose(fptr);
    }

    void display_car_database() {
        access_car_database();
    }

    int choice;
    printf("Car Managment Database\n");
    printf("1. Add Car\n");
    printf("2. Access Car Database\n");
    printf("3. Display Car Database\n");
    printf("4. Exit\n");
    printf("5. Return to Pre Made Libraries\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_car();
            break;
        case 2:
            access_car_database();
            break;
        case 3:
            display_car_database();
            break;
        case 4:
            printf("Exiting Car Managment...\n");
            break;
        case 5:
            pre_made_libraries();
            break;
        default:
            printf("Invalid choice\n");
    }
}



struct Book {
    char title[50];
    char author[50];
    int available;
    char due_date[20];
    };

void create_library_database() {
    struct Book book;
    FILE *fptr;
    fptr = fopen("LibraryDatabase.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file");
        return;
    }

    printf("Enter the title of the book: ");
    scanf("%49s", book.title);
    printf("Enter the author of the book: ");
    scanf("%49s", book.author);
    book.available = 1;
    strcpy(book.due_date, "N/A");

    fprintf(fptr, "Title: %s\n", book.title);
    fprintf(fptr, "Author: %s\n", book.author);
    fprintf(fptr, "Available: %d\n", book.available);
    fprintf(fptr, "Due Date: %s\n", book.due_date);
    fprintf(fptr, "\n");

    fclose(fptr);
}
void access_library_database() {
    struct Book book;
    FILE *fptr;
    fptr = fopen("LibraryDatabase.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    printf("Books available in the library:\n");
    while (fscanf(fptr, "Title: %s\n", book.title) != EOF) {
        fscanf(fptr, "Author: %s\n", book.author);
        fscanf(fptr, "Available: %d\n", &book.available);
        fscanf(fptr, "Due Date: %s\n", book.due_date);
        printf("Title: %s, Author: %s, Available: %d, Due Date: %s\n", book.title, book.author, book.available, book.due_date);
    }

    fclose(fptr);
}
void issue_book() {
    struct Book book;
    FILE *fptr;
    FILE *temp;
    char title[50];
    int found = 0;

    fptr = fopen("LibraryDatabase.txt", "r");
    temp = fopen("TempLibraryDatabase.txt", "w");
    if (fptr == NULL || temp == NULL) {
        printf("Error opening file\n");
        return;
    }

    printf("Enter the title of the book to issue: ");
    scanf("%s", title);

    while (fscanf(fptr, "Title: %s\n", book.title) != EOF) {
        fscanf(fptr, "Author: %s\n", book.author);
        fscanf(fptr, "Available: %d\n", &book.available);
        fscanf(fptr, "Due Date: %s\n", book.due_date);

        if (strcmp(book.title, title) == 0 && book.available == 1) {
            book.available = 0;
            printf("Enter the due date (dd-mm-yyyy): ");
            scanf("%s", book.due_date);
            found = 1;
        }

        fprintf(temp, "Title: %s\n", book.title);
        fprintf(temp, "Author: %s\n", book.author);
        fprintf(temp, "Available: %d\n", book.available);
        fprintf(temp, "Due Date: %s\n", book.due_date);
        fprintf(temp, "\n");
    }

    fclose(fptr);
    fclose(temp);

    remove("LibraryDatabase.txt");
    rename("TempLibraryDatabase.txt", "LibraryDatabase.txt");

    if (found) {
        printf("Book issued successfully\n");
    } else {
        printf("Book not available or already issued\n");
    }
}
void Library_Managment() {
    int choice;
    printf("Library Managment Database\n");
    printf("1. Access Library Database\n");
    printf("2. Issue Book\n");
    printf("3. Exit\n");
    printf("4. Return to Pre Made Libraries\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            access_library_database();
            break;
        case 2:
            issue_book();
            break;
        case 3:
            printf("Exiting Library Managment...\n");
            break;
        case 4:
            pre_made_libraries();
            break;
        default:
            printf("Invalid choice\n");
    }
}

    struct Train {
        char name[50];
        int number;
        char time[20];
        char date[20];
        char location[50];
    };

    struct Ticket {
        char personal_id[20];
        char train_name[50];
        float ticket_price;
    };

void create_or_modify_train_chart() {
        FILE *fptr;
        struct Train train;
        int choice;
        char modify_name[50];
        int modify_number;
        int found = 0;

        fptr = fopen("TicketDatabase.txt", "a+");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("1. Create new train chart\n2. Modify existing train chart\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter train name: ");
            scanf("%s", train.name);
            printf("Enter train number: ");
            scanf("%d", &train.number);
            printf("Enter time: ");
            scanf("%s", train.time);
            printf("Enter date: ");
            scanf("%s", train.date);
            printf("Enter location: ");
            scanf("%s", train.location);

            fprintf(fptr, "Name: %s\nNumber: %d\nTime: %s\nDate: %s\nLocation: %s\n\n", train.name, train.number, train.time, train.date, train.location);
            printf("Train chart created successfully\n");
        } else if (choice == 2) {
            FILE *temp = fopen("TempTicketDatabase.txt", "w");
            if (temp == NULL) {
                printf("Error opening temporary file\n");
                fclose(fptr);
                return;
            }

            printf("Enter train name or number to modify: ");
            scanf("%s", modify_name);

            while (fscanf(fptr, "Name: %s\nNumber: %d\nTime: %s\nDate: %s\nLocation: %s\n\n", train.name, &train.number, train.time, train.date, train.location) != EOF) {
                if (strcmp(train.name, modify_name) == 0 || train.number == atoi(modify_name)) {
                    found = 1;
                    printf("Enter new train name: ");
                    scanf("%s", train.name);
                    printf("Enter new train number: ");
                    scanf("%d", &train.number);
                    printf("Enter new time: ");
                    scanf("%s", train.time);
                    printf("Enter new date: ");
                    scanf("%s", train.date);
                    printf("Enter new location: ");
                    scanf("%s", train.location);
                }
                fprintf(temp, "Name: %s\nNumber: %d\nTime: %s\nDate: %s\nLocation: %s\n\n", train.name, train.number, train.time, train.date, train.location);
            }

            fclose(fptr);
            fclose(temp);

            remove("TicketDatabase.txt");
            rename("TempTicketDatabase.txt", "TicketDatabase.txt");

            if (found) {
                printf("Train chart modified successfully\n");
            } else {
                printf("Train not found\n");
            }
        } else {
            printf("Invalid choice\n");
        }
    }

void access_ticket_database() {
        FILE *fptr;
        struct Train train;
        fptr = fopen("TicketDatabase.txt", "r");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Train Chart:\n");
        while (fscanf(fptr, "Name: %s\nNumber: %d\nTime: %s\nDate: %s\nLocation: %s\n\n", train.name, &train.number, train.time, train.date, train.location) != EOF) {
            printf("Name: %s\nNumber: %d\nTime: %s\nDate: %s\nLocation: %s\n\n", train.name, train.number, train.time, train.date, train.location);
        }

        fclose(fptr);
    }

void search_train() {
        FILE *fptr;
        struct Train train;
        char search_name[50];
        int search_number;
        int choice;
        int found = 0;

        fptr = fopen("TicketDatabase.txt", "r");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Search by:\n1. Train Name\n2. Train Number\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter train name: ");
            scanf("%s", search_name);
            while (fscanf(fptr, "Name: %s\nNumber: %d\nTime: %s\nDate: %s\nLocation: %s\n\n", train.name, &train.number, train.time, train.date, train.location) != EOF) {
                if (strcmp(train.name, search_name) == 0) {
                    printf("Name: %s\nNumber: %d\nTime: %s\nDate: %s\nLocation: %s\n\n", train.name, train.number, train.time, train.date, train.location);
                    found = 1;
                }
            }
        } else if (choice == 2) {
            printf("Enter train number: ");
            scanf("%d", &search_number);
            while (fscanf(fptr, "Name: %s\nNumber: %d\nTime: %s\nDate: %s\nLocation: %s\n\n", train.name, &train.number, train.time, train.date, train.location) != EOF) {
                if (train.number == search_number) {
                    printf("Name: %s\nNumber: %d\nTime: %s\nDate: %s\nLocation: %s\n\n", train.name, train.number, train.time, train.date, train.location);
                    found = 1;
                }
            }
        } else {
            printf("Invalid choice\n");
        }

        if (!found) {
            printf("Train not found\n");
        }

        fclose(fptr);
    }

    void buy_ticket() {
        FILE *fptr;
        struct Ticket ticket;

        fptr = fopen("TicketDatabase.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter personal ID: ");
        scanf("%s", ticket.personal_id);
        printf("Enter train name: ");
        scanf("%s", ticket.train_name);
        printf("Enter ticket price: ");
        scanf("%f", &ticket.ticket_price);

        fprintf(fptr, "Personal ID: %s\nTrain Name: %s\nTicket Price: %.2f\n\n", ticket.personal_id, ticket.train_name, ticket.ticket_price);

        fclose(fptr);
        printf("Ticket bought successfully\n");
    }

    void cancel_ticket() {
        FILE *fptr, *temp;
        struct Ticket ticket;
        char personal_id[20];
        int found = 0;

        fptr = fopen("TicketDatabase.txt", "r");
        temp = fopen("TempTicketDatabase.txt", "w");
        if (fptr == NULL || temp == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter personal ID to cancel ticket: ");
        scanf("%s", personal_id);

        while (fscanf(fptr, "Personal ID: %s\nTrain Name: %s\nTicket Price: %f\n\n", ticket.personal_id, ticket.train_name, &ticket.ticket_price) != EOF) {
            if (strcmp(ticket.personal_id, personal_id) == 0) {
                found = 1;
            } else {
                fprintf(temp, "Personal ID: %s\nTrain Name: %s\nTicket Price: %.2f\n\n", ticket.personal_id, ticket.train_name, ticket.ticket_price);
            }
        }

        fclose(fptr);
        fclose(temp);

        remove("TicketDatabase.txt");
        rename("TempTicketDatabase.txt", "TicketDatabase.txt");

        if (found) {
            printf("Ticket cancelled successfully\n");
        } else {
            printf("Ticket not found\n");
        }
    }

    void Ticket_Managment() {
        int choice;
        printf("Ticket Managment Database\n");
        printf("1. Create or Modify Train Chart\n");
        printf("2. Access Ticket Database\n");
        printf("3. Search Train\n");
        printf("4. Buy Ticket\n");
        printf("5. Cancel Ticket\n");
        printf("6. Exit\n");
        printf("7. Return to Pre Made Libraries\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_or_modify_train_chart();
                break;
            case 2:
                access_ticket_database();
                break;
            case 3:
                search_train();
                break;
            case 4:
                buy_ticket();
                break;
            case 5:
                cancel_ticket();
                break;
            case 6:
                printf("Exiting Ticket Managment...\n");
                break;
            case 7:
                pre_made_libraries();
                break;
            default:
                printf("Invalid choice\n");
        }
    }


void Student_Managment() {
    struct Attendance {
        char class_name[50];
        char student_name[50];
        int roll_no;
        char date[20];
        char attendance[10];
    };

    struct MarksRecord {
        char name[50];
        char subject[50];
        int marks_obtained;
        char exam_name[50];
    };

    struct Fees {
        char name_student[50];
        char fees_details[20];
    };

    void add_attendance() {
        struct Attendance attendance;
        FILE *fptr;
        fptr = fopen("AttendanceDatabase.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter class name: ");
        scanf("%s", attendance.class_name);
        printf("Enter student name: ");
        scanf("%s", attendance.student_name);
        printf("Enter roll number: ");
        scanf("%d", &attendance.roll_no);
        printf("Enter date (dd-mm-yyyy): ");
        scanf("%s", attendance.date);
        printf("Enter attendance (Present/Absent): ");
        scanf("%s", attendance.attendance);

        fprintf(fptr, "Class: %s\nStudent: %s\nRoll No: %d\nDate: %s\nAttendance: %s\n\n", 
                attendance.class_name, attendance.student_name, attendance.roll_no, 
                attendance.date, attendance.attendance);
        fclose(fptr);
        printf("Attendance record added successfully\n");
    }

    void add_marks_record() {
        struct MarksRecord marks;
        FILE *fptr;
        fptr = fopen("MarksDatabase.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter student name: ");
        scanf("%s", marks.name);
        printf("Enter subject: ");
        scanf("%s", marks.subject);
        printf("Enter marks obtained: ");
        scanf("%d", &marks.marks_obtained);
        printf("Enter exam name: ");
        scanf("%s", marks.exam_name);

        fprintf(fptr, "Name: %s\nSubject: %s\nMarks Obtained: %d\nExam Name: %s\n\n", 
                marks.name, marks.subject, marks.marks_obtained, marks.exam_name);
        fclose(fptr);
        printf("Marks record added successfully\n");
    }

    void add_fees_record() {
        struct Fees fees;
        FILE *fptr;
        fptr = fopen("FeesDatabase.txt", "a");
        if (fptr == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter student name: ");
        scanf("%s", fees.name_student);
        printf("Enter fees details (Paid/Left to pay): ");
        scanf("%s", fees.fees_details);

        fprintf(fptr, "Name: %s\nFees Details: %s\n\n", fees.name_student, fees.fees_details);
        fclose(fptr);
        printf("Fees record added successfully\n");
    }

    void modify_fees() {
        struct Fees fees;
        FILE *fptr, *temp;
        char student_name[50];
        int found = 0;

        fptr = fopen("FeesDatabase.txt", "r");
        temp = fopen("TempFeesDatabase.txt", "w");
        if (fptr == NULL || temp == NULL) {
            printf("Error opening file\n");
            return;
        }

        printf("Enter the name of the student to modify fees: ");
        scanf("%s", student_name);

        while (fscanf(fptr, "Name: %s\nFees Details: %s\n\n", fees.name_student, fees.fees_details) != EOF) {
            if (strcmp(fees.name_student, student_name) == 0) {
                found = 1;
                printf("Enter new fees details: ");
                scanf("%s", fees.fees_details);
            }
            fprintf(temp, "Name: %s\nFees Details: %s\n\n", fees.name_student, fees.fees_details);
        }

        fclose(fptr);
        fclose(temp);

        remove("FeesDatabase.txt");
        rename("TempFeesDatabase.txt", "FeesDatabase.txt");

        if (found) {
            printf("Fees details modified successfully\n");
        } else {
            printf("Student not found\n");
        }
    }

    int choice;
    do {
        printf("\nStudent Managment System\n");
        printf("1. Add Attendance Record\n");
        printf("2. Add Marks Record\n");
        printf("3. Add Fees Record\n");
        printf("4. Modify Fees Record\n");
        printf("5. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_attendance();
                break;
            case 2:
                add_marks_record();
                break;
            case 3:
                add_fees_record();
                break;
            case 4:
                modify_fees();
                break;
            case 5:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);
}

// Function to sort table based on a column
void sort_table(struct Table* table, int column_index, int ascending) {
    if (column_index < 0 || column_index >= table->columns) {
        printf("Invalid column index for sorting!\n");
        return;
    }

    struct Cell* temp_column = malloc(table->rows * sizeof(struct Cell));
    int* indices = malloc(table->rows * sizeof(int));
    
    if (temp_column == NULL || indices == NULL) {
        printf("Memory allocation failed!\n");
        free(temp_column);
        free(indices);
        return;
    }
    
    for (int i = 0; i < table->rows; i++) {
        indices[i] = i;
        temp_column[i] = table->data[i][column_index];
    }

    char data_type = table->column_types[column_index];
    
    for (int i = 0; i < table->rows - 1; i++) {
        for (int j = 0; j < table->rows - i - 1; j++) {
            int swap = 0;
            
            switch(data_type) {
                case 'i':
                    swap = ascending ? 
                        (temp_column[j].int_value > temp_column[j+1].int_value) :
                        (temp_column[j].int_value < temp_column[j+1].int_value);
                    break;
                case 'f':
                    swap = ascending ? 
                        (temp_column[j].float_value > temp_column[j+1].float_value) :
                        (temp_column[j].float_value < temp_column[j+1].float_value);
                    break;
                case 's':
                    swap = ascending ? 
                        (strcmp(temp_column[j].str_value, temp_column[j+1].str_value) > 0) :
                        (strcmp(temp_column[j].str_value, temp_column[j+1].str_value) < 0);
                    break;
            }
            
            if (swap) {
                struct Cell temp_cell = temp_column[j];
                temp_column[j] = temp_column[j+1];
                temp_column[j+1] = temp_cell;
                
                int temp_index = indices[j];
                indices[j] = indices[j+1];
                indices[j+1] = temp_index;
            }
        }
    }

    struct Table temp_table = *table;
    
    for (int i = 0; i < table->rows; i++) {
        strcpy(temp_table.row_names[i], table->row_names[indices[i]]);
        for (int j = 0; j < table->columns; j++) {
            temp_table.data[i][j] = table->data[indices[i]][j];
        }
    }
    
    *table = temp_table;
    
    free(temp_column);
    free(indices);
    
    printf("Table sorted successfully based on column %s (%s)\n", 
           table->column_names[column_index], 
           ascending ? "ascending" : "descending");
}

// Function to display sorted table
void display_sorted_table(struct Table* table) {
    // Display column headers
    printf("\nTable: %s\n", table->name);
    for (int i = 0; i < table->columns; i++) {
        printf("%-15s", table->column_names[i]);
    }
    printf("\n");
    
    // Display separator
    for (int i = 0; i < table->columns * 15; i++) {
        printf("-");
    }
    printf("\n");
    
    // Display data
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->columns; j++) {
            switch(table->column_types[j]) {
                case 'i':
                    printf("%-15d", table->data[i][j].int_value);
                    break;
                case 'f':
                    printf("%-15.2f", table->data[i][j].float_value);
                    break;
                case 's':
                    printf("%-15s", table->data[i][j].str_value);
                    break;
            }
        }
        printf("\n");
    }
}

// Function to test the sorting functionality
void test_table_sorting() {
    struct Table test_table;
    strcpy(test_table.name, "Test Table");
    test_table.rows = 5;
    test_table.columns = 3;
    
    // Set column names and types
    strcpy(test_table.column_names[0], "ID");
    strcpy(test_table.column_names[1], "Name");
    strcpy(test_table.column_names[2], "Score");
    
    test_table.column_types[0] = 'i';  // Integer
    test_table.column_types[1] = 's';  // String
    test_table.column_types[2] = 'f';  // Float
    
    // Add sample data
    for (int i = 0; i < test_table.rows; i++) {
        // ID column
        test_table.data[i][0].int_value = 5 - i;
        
        // Name column
        sprintf(test_table.data[i][1].str_value, "Person%d", i+1);
        
        // Score column
        test_table.data[i][2].float_value = (float)(rand() % 100);
    }
    
    printf("Original Table:\n");
    display_sorted_table(&test_table);
    
    printf("\nSorting by ID (ascending):\n");
    sort_table(&test_table, 0, 1);
    display_sorted_table(&test_table);
    
    printf("\nSorting by Name (ascending):\n");
    sort_table(&test_table, 1, 1);
    display_sorted_table(&test_table);
    
    printf("\nSorting by Score (descending):\n");
    sort_table(&test_table, 2, 0);
    display_sorted_table(&test_table);
}

void Modify_Table(){
    struct Table table;
    FILE *fptr;
    fptr = fopen("Database.txt", "r+");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    printf("Enter the name of the table to modify: ");
    scanf("%s", table.name);

    // Read the table details from the file
    while (fscanf(fptr, "Table Name: %s\n", table.name) != EOF) {
        fscanf(fptr, "Rows: %d, Columns: %d\n", &table.rows, &table.columns);
        fscanf(fptr, "Row Names: ");
        for (int i = 0; i < table.rows; i++) {
            fscanf(fptr, "%s", table.row_names[i]);
        }
        fscanf(fptr, "Column Names: ");
        for (int i = 0; i < table.columns; i++) {
            fscanf(fptr, "%s", table.column_names[i]);
        }

        // Check if this is the table to modify
        if (strcmp(table.name, table.name) == 0) {
            break;
        }
    }

    // Modify the table
    int row_index, column_index;
    char new_value[50];
    printf("Enter the row index to modify (0-%d): ", table.rows - 1);
    scanf("%d", &row_index);
    printf("Enter the column index to modify (0-%d): ", table.columns - 1);
    scanf("%d", &column_index);
    printf("Enter the new value: ");
    scanf("%s", new_value);

    // Update the table in memory
    strcpy(table.row_names[row_index], new_value);
    strcpy(table.column_names[column_index], new_value);

    // Write the updated table back to the file
    fseek(fptr, 0, SEEK_SET);
    fprintf(fptr, "Table Name: %s\n", table.name);
    fprintf(fptr, "Rows: %d, Columns: %d\n", table.rows, table.columns);
    fprintf(fptr, "Row Names: ");
    for (int i = 0; i < table.rows; i++) {
        fprintf(fptr, "%s ", table.row_names[i]);
    }
    fprintf(fptr, "\nColumn Names: ");
    for (int i = 0; i < table.columns; i++) {
        fprintf(fptr, "%s ", table.column_names[i]);
    }
    fprintf(fptr, "\n");

    fclose(fptr);
}

void show_existing_databases() {
    FILE *fptr;
    char database_name[50];
    int count = 0;
    
    printf("\nExisting Databases:\n");
    printf("------------------\n");
    
    // Open the directory listing file
    fptr = fopen("databases.txt", "r");
    if (fptr == NULL) {
        printf("No databases found\n");
        return;
    }
    
    while (fscanf(fptr, "%s", database_name) != EOF) {
        count++;
        printf("%d. %s\n", count, database_name);
    }
    
    if (count == 0) {
        printf("No databases found\n");
    }
    
    fclose(fptr);
}

void create_table_in_database(char *database_name) {
    struct Table table;
    FILE *fptr;
    fptr = fopen(database_name, "a");
    if (fptr == NULL) {
        printf("Error opening file");
        return;
    }

    printf("Enter the name of the table: ");
    scanf("%s", table.name);
    printf("Enter the number of rows: ");
    scanf("%d", &table.rows);
    printf("Enter the number of columns: ");
    scanf("%d", &table.columns);

    for (int i = 0; i < table.rows; i++) {
        printf("Enter the name of row %d: ", i + 1);
        scanf("%s", table.row_names[i]);
    }

    for (int i = 0; i < table.columns; i++) {
        printf("Enter the name of column %d: ", i + 1);
        scanf("%s", table.column_names[i]);
    }

    fprintf(fptr, "Table Name: %s\n", table.name);
    fprintf(fptr, "Rows: %d, Columns: %d\n", table.rows, table.columns);
    fprintf(fptr, "Row Names: ");
    for (int i = 0; i < table.rows; i++) {
        fprintf(fptr, "%s ", table.row_names[i]);
    }
    fprintf(fptr, "\nColumn Names: ");
    for (int i = 0; i < table.columns; i++) {
        fprintf(fptr, "%s ", table.column_names[i]);
    }
    fprintf(fptr, "\n");

    fclose(fptr);
}

void create_database() {
    char database_name[50];
    FILE *fptr, *list_fptr;

    printf("Enter the name of the database to create: ");
    scanf("%s", database_name);

    fptr = fopen(database_name, "w");
    if (fptr == NULL) {
        printf("Error creating database");
        return;
    }
    
    // Add to databases list
    list_fptr = fopen("databases.txt", "a");
    if (list_fptr != NULL) {
        fprintf(list_fptr, "%s\n", database_name);
        fclose(list_fptr);
    }
    
    printf("Database created successfully\n");
    fclose(fptr);
}

int show_tables_in_database(char *database_name) {
    FILE *fptr;
    char line[256];
    int table_count = 0;
    
    fptr = fopen(database_name, "r");
    if (fptr == NULL) {
        printf("Error opening database\n");
        return;
    }
    
    printf("\nTables in database %s:\n", database_name);
    printf("-------------------------\n");
    
    while (fgets(line, sizeof(line), fptr)) {
        if (strstr(line, "Table Name: ") != NULL) {
            table_count++;
            printf("%d. %s", table_count, line + 11); // Skip "Table Name: "
        }
    }
    
    if (table_count == 0) {
        printf("No tables found in database\n");
    }
    
    fclose(fptr);
    return table_count;
}

void modify_existing_table(char *database_name) {
    FILE *fptr, *temp;
    char line[256], table_name[50];
    int found = 0;
    
    printf("Enter the name of the table to modify: ");
    scanf("%s", table_name);
    
    fptr = fopen(database_name, "r");
    temp = fopen("temp.txt", "w");
    
    if (fptr == NULL || temp == NULL) {
        printf("Error opening files\n");
        return;
    }
    
    // Copy content until we find the table
    while (fgets(line, sizeof(line), fptr)) {
        if (strstr(line, "Table Name: ") != NULL && strstr(line, table_name) != NULL) {
            found = 1;
            fprintf(temp, "%s", line); // Write the table name line
            
            // Read and write rows and columns line
            fgets(line, sizeof(line), fptr);
            fprintf(temp, "%s", line);
            
            // Read row names line
            fgets(line, sizeof(line), fptr);
            printf("\nCurrent row names: %s", line);
            printf("Enter new row names (space-separated): ");
            getchar(); // Clear input buffer
            fgets(line, sizeof(line), stdin);
            fprintf(temp, "Row Names: %s", line);
            
            // Read column names line
            fgets(line, sizeof(line), fptr);
            printf("Current column names: %s", line);
            printf("Enter new column names (space-separated): ");
            fgets(line, sizeof(line), stdin);
            fprintf(temp, "Column Names: %s", line);
        } else {
            fprintf(temp, "%s", line);
        }
    }
    
    fclose(fptr);
    fclose(temp);
    
    if (found) {
        remove(database_name);
        rename("temp.txt", database_name);
        printf("Table modified successfully\n");
    } else {
        remove("temp.txt");
        printf("Table not found\n");
    }
}

void access_database() {
    char database_name[50];
    FILE *fptr;
    int choice;

    printf("Enter the name of the database to access: ");
    scanf("%s", database_name);

    fptr = fopen(database_name, "r");
    if (fptr == NULL) {
        printf("Database does not exist\n");
        return;
    }
    printf("Database accessed successfully\n");
    fclose(fptr);

    do {
        printf("\nDatabase Operations:\n");
        printf("1. Show existing tables\n");
        printf("2. Create new table\n");
        printf("3. Modify existing table\n");
        printf("4. Return to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                show_tables_in_database(database_name);
                break;
            case 2:
                create_table_in_database(database_name);
                break;
            case 3:
                show_tables_in_database(database_name);
                modify_existing_table(database_name);
                break;
            case 4:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);
}

void Delete_Database() {
    char database_name[50];
    FILE *list_fptr, *temp_fptr;
    char temp_name[50];
    int found = 0;
    
    printf("Enter the name of the database to delete: ");
    scanf("%s", database_name);
    
    // Remove the database file
    if (remove(database_name) == 0) {
        // Remove from databases list
        list_fptr = fopen("databases.txt", "r");
        temp_fptr = fopen("temp.txt", "w");
        
        if (list_fptr != NULL && temp_fptr != NULL) {
            while (fscanf(list_fptr, "%s", temp_name) != EOF) {
                if (strcmp(temp_name, database_name) != 0) {
                    fprintf(temp_fptr, "%s\n", temp_name);
                } else {
                    found = 1;
                }
            }
            
            fclose(list_fptr);
            fclose(temp_fptr);
            
            remove("databases.txt");
            rename("temp.txt", "databases.txt");
        }
        
        if (found) {
            printf("Database deleted successfully\n");
        }
    } else {
        printf("Error deleting database\n");
    }
}

void Table_sorting() {
    struct Table table;
    char database_name[50];
    int column_index, ascending;
    
    printf("Enter database name: ");
    scanf("%s", database_name);
    
    FILE *fptr = fopen(database_name, "r");
    if (fptr == NULL) {
        printf("Error opening database\n");
        return;
    }
    
    // Read table details
    fscanf(fptr, "Table Name: %s\n", table.name);
    fscanf(fptr, "Rows: %d, Columns: %d\n", &table.rows, &table.columns);
    
    printf("Enter column index to sort (0-%d): ", table.columns - 1);
    scanf("%d", &column_index);
    
    printf("Sort order (1-ascending, 0-descending): ");
    scanf("%d", &ascending);
    
    sort_table(&table, column_index, ascending);
    display_sorted_table(&table);
    
    fclose(fptr);
}

int main() {
    int choice;
    do {
        printf("\nDatabase Managment System\n");
        printf("1. Show Existing Databases\n");
        printf("2. Create Database\n");
        printf("3. Access Database\n");
        printf("4. Delete Database\n");
        printf("5. Sort Table\n");
        printf("6. Student Managment\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                show_existing_databases();
                break;
            case 2:
                create_database();
                break;
            case 3:
                access_database();
                break;
            case 4:
                Delete_Database();
                break;
            case 5:
                Table_sorting();
                break;
            case 6:
                Student_Managment();
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 7);
    
    return 0;
}

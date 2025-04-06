#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_STR_LEN 50

// Forward declarations
void create_table_in_database(char *database_name);
void create_or_access_database();
void sort_table(struct Table* table, int column_index, int ascending);
void display_table(struct Table* table);

// Structure for storing cell data
struct Cell {
    char str_value[MAX_STR_LEN];
    int int_value;
    float float_value;
    char data_type; // 's' for string, 'i' for integer, 'f' for float
};

// Structure for table data
struct Table {
    char name[50];
    int rows;
    int columns;
    char row_names[MAX_ROWS][50];
    char column_names[MAX_COLS][50];
    struct Cell data[MAX_ROWS][MAX_COLS];
    char column_types[MAX_COLS]; // Store data type for each column
};

// Comparison functions for different data types
int compare_int(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compare_float(const void* a, const void* b) {
    float diff = (*(float*)a - *(float*)b);
    return (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
}

int compare_string(const void* a, const void* b) {
    return strcmp((char*)a, (char*)b);
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

void create_table_in_database(char *database_name) {
    struct Table table;
    FILE *fptr;
    fptr = fopen(database_name, "a");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    printf("Enter the name of the table: ");
    scanf("%s", table.name);
    
    do {
        printf("Enter the number of rows (1-%d): ", MAX_ROWS);
        scanf("%d", &table.rows);
    } while(table.rows <= 0 || table.rows > MAX_ROWS);
    
    do {
        printf("Enter the number of columns (1-%d): ", MAX_COLS);
        scanf("%d", &table.columns);
    } while(table.columns <= 0 || table.columns > MAX_COLS);

    while (getchar() != '\n');

    for (int i = 0; i < table.columns; i++) {
        printf("Enter the name of column %d: ", i + 1);
        scanf("%49s", table.column_names[i]);
        
        do {
            printf("Enter data type for column %s (s-string/i-integer/f-float): ", table.column_names[i]);
            scanf(" %c", &table.column_types[i]);
        } while(table.column_types[i] != 's' && table.column_types[i] != 'i' && table.column_types[i] != 'f');
    }

    for (int i = 0; i < table.rows; i++) {
        printf("Enter row %d name: ", i + 1);
        scanf("%49s", table.row_names[i]);
        
        for (int j = 0; j < table.columns; j++) {
            printf("Enter value for %s: ", table.column_names[j]);
            switch(table.column_types[j]) {
                case 'i':
                    scanf("%d", &table.data[i][j].int_value);
                    break;
                case 'f':
                    scanf("%f", &table.data[i][j].float_value);
                    break;
                case 's':
                    scanf("%49s", table.data[i][j].str_value);
                    break;
            }
        }
    }

    fprintf(fptr, "TABLE_START\n");
    fprintf(fptr, "Table Name: %s\n", table.name);
    fprintf(fptr, "Rows: %d\nColumns: %d\n", table.rows, table.columns);
    
    fprintf(fptr, "Column Types: ");
    for (int i = 0; i < table.columns; i++) {
        fprintf(fptr, "%c ", table.column_types[i]);
    }
    fprintf(fptr, "\n");
    
    fprintf(fptr, "Column Names: ");
    for (int i = 0; i < table.columns; i++) {
        fprintf(fptr, "%s ", table.column_names[i]);
    }
    fprintf(fptr, "\n");

    for (int i = 0; i < table.rows; i++) {
        fprintf(fptr, "Row %d: %s ", i, table.row_names[i]);
        for (int j = 0; j < table.columns; j++) {
            switch(table.column_types[j]) {
                case 'i':
                    fprintf(fptr, "%d ", table.data[i][j].int_value);
                    break;
                case 'f':
                    fprintf(fptr, "%.2f ", table.data[i][j].float_value);
                    break;
                case 's':
                    fprintf(fptr, "%s ", table.data[i][j].str_value);
                    break;
            }
        }
        fprintf(fptr, "\n");
    }
    fprintf(fptr, "TABLE_END\n\n");

    fclose(fptr);
    printf("Table created successfully!\n");
}

void display_table(struct Table* table) {
    printf("\nTable: %s\n", table->name);
    
    for (int i = 0; i < table->columns; i++) {
        printf("%-15s", table->column_names[i]);
    }
    printf("\n");
    
    for (int i = 0; i < table->columns * 15; i++) {
        printf("-");
    }
    printf("\n");
    
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

void create_or_access_database() {
    char database_name[50];
    FILE *fptr;

    printf("Enter the name of the database (with .txt extension): ");
    scanf("%s", database_name);

    fptr = fopen(database_name, "r");
    if (fptr == NULL) {
        fptr = fopen(database_name, "w");
        if (fptr == NULL) {
            printf("Error creating database\n");
            return;
        }
        printf("Database created successfully\n");
        fclose(fptr);
    } else {
        fclose(fptr);
        printf("Database accessed successfully\n");
    }
    
    printf("Do you want to create a table? (1-yes/0-no): ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        create_table_in_database(database_name);
    }
}

void Delete_Database(){
    FILE *fptr;
    fptr = fopen("Database.txt", "r");
    char database_name[50];
    char temp_name[50];
    int database_count = 0;
    int delete_index;
    int current_index = 0;

    // Count the number of databases
    while(fscanf(fptr, "%s", database_name) != EOF){
        database_count++;
    }
    fclose(fptr);

    // Prompt user for the index of the database to delete
    printf("Enter the index of the database to delete (1 to %d): ", database_count);
    scanf("%d", &delete_index);

    if(delete_index < 1 || delete_index > database_count) {
        printf("Invalid index! No database deleted.\n");
        return;
    }

    // Reopen the file to read and write
    fptr = fopen("Database.txt", "r");
    FILE *temp_fptr = fopen("TempDatabase.txt", "w");

    // Copy all databases except the one to delete to a temporary file
    while(fscanf(fptr, "%s", database_name) != EOF){
        current_index++;
        if(current_index != delete_index) {
            fprintf(temp_fptr, "%s\n", database_name);
        }
    }

    fclose(fptr);
    fclose(temp_fptr);

    // Replace the original file with the temporary file
    remove("Database.txt");
    rename("TempDatabase.txt", "Database.txt");

    printf("Database at index %d deleted successfully.\n", delete_index);
    fclose(fptr);
}

void Table_sorting(){
    FILE *fptr;
    fptr = fopen("Database.txt", "r");
    struct Table table;
    int row_to_modify;
    char sort_order[10];
    char rows[10][50];
    int row_count = 0;

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

        // Read all rows into an array
        for (int i = 0; i < table.rows; i++) {
            strcpy(rows[i], table.row_names[i]);
        }
        row_count = table.rows;

        // Prompt user for the row to modify
        printf("Enter the row number to modify (1 to %d): ", row_count);
        scanf("%d", &row_to_modify);

        if (row_to_modify < 1 || row_to_modify > row_count) {
            printf("Invalid row number! No modification done.\n");
            fclose(fptr);
            return;
        }

        // Prompt user for the sort order
        printf("Enter the sort order (ascending/descending): ");
        scanf("%s", sort_order);

        // Sort the selected row and move the table index accordingly
        for (int i = 0; i < table.columns - 1; i++) {
            for (int j = i + 1; j < table.columns; j++) {
                if ((strcmp(sort_order, "ascending") == 0 && strcmp(table.column_names[i], table.column_names[j]) > 0) ||
                    (strcmp(sort_order, "descending") == 0 && strcmp(table.column_names[i], table.column_names[j]) < 0)) {
                    // Swap the columns
                    char temp[50];
                    strcpy(temp, table.column_names[i]);
                    strcpy(table.column_names[i], table.column_names[j]);
                    strcpy(table.column_names[j], temp);
                }
            }
        }

        // Write the sorted rows back to the file
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
        fprintf(fptr, "\n\n");

        printf("Row %d sorted in %s order successfully.\n", row_to_modify, sort_order);
    }
        fclose(fptr);
}

int main() {
    int choice;
    
    do {
        printf("\nDatabase Management System\n");
        printf("1. Create/Access Database\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_or_access_database();
                break;
            case 2:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 2);

    return 0;
}
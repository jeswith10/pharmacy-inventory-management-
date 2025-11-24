#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "pharmacy.dat"
#define MAX_NAME_LEN 100
#define MAX_MANU_LEN 100
#define MAX_EXP_LEN 20
#define MAX_CAT_LEN 50

// ------------------ STRUCT DEFINITION ------------------
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
    char manufacturer[MAX_MANU_LEN];
    char expiry[MAX_EXP_LEN];
    char category[MAX_CAT_LEN];
} Medicine;

// ------------------ FUNCTION DECLARATIONS ------------------
void addMedicine();
void viewMedicines();
void searchMedicine();
void updateMedicine();
void deleteMedicine();

int idExists(int id);
void saveMedicine(Medicine m);
void loadMedicines(Medicine meds[], int *count);
void writeAllMedicines(Medicine meds[], int count);

// ------------------ MAIN MENU ------------------
int main() {
    int choice;
    do {
        printf("\n==============================\n");
        printf(" PHARMACY INVENTORY SYSTEM\n");
        printf("==============================\n");
        printf("1. Add New Medicine\n");
        printf("2. View All Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // remove leftover newline

        switch (choice) {
            case 1: addMedicine(); break;
            case 2: viewMedicines(); break;
            case 3: searchMedicine(); break;
            case 4: updateMedicine(); break;
            case 5: deleteMedicine(); break;
            case 6: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// ------------------ ADD MEDICINE ------------------
void addMedicine() {
    Medicine m;

    printf("\n--- Add New Medicine ---\n");
    printf("Enter Medicine ID: ");
    scanf("%d", &m.id);
    getchar();

    if (idExists(m.id)) {
        printf("Error: Medicine ID already exists!\n");
        return;
    }

    printf("Enter Medicine Name: ");
    fgets(m.name, sizeof(m.name), stdin);
    m.name[strcspn(m.name, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &m.quantity);
    getchar();

    printf("Enter Price: ");
    scanf("%f", &m.price);
    getchar();

    printf("Enter Manufacturer: ");
    fgets(m.manufacturer, sizeof(m.manufacturer), stdin);
    m.manufacturer[strcspn(m.manufacturer, "\n")] = '\0';

    printf("Enter Expiry Date (DD/MM/YYYY): ");
    fgets(m.expiry, sizeof(m.expiry), stdin);
    m.expiry[strcspn(m.expiry, "\n")] = '\0';

    printf("Enter Category: ");
    fgets(m.category, sizeof(m.category), stdin);
    m.category[strcspn(m.category, "\n")] = '\0';

    saveMedicine(m);
    printf("Medicine added successfully!\n");
}

// ------------------ SAVE MEDICINE TO FILE ------------------
void saveMedicine(Medicine m) {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(&m, sizeof(Medicine), 1, fp);
    fclose(fp);
}

// ------------------ CHECK IF ID EXISTS ------------------
int idExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    Medicine m;
    while (fread(&m, sizeof(Medicine), 1, fp)) {
        if (m.id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// ------------------ VIEW ALL MEDICINES ------------------
void viewMedicines() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No Records Found.\n");
        return;
    }

    Medicine m;
    printf("\n%-10s %-20s %-10s %-10s %-20s %-15s %-20s\n",
           "ID", "Name", "Qty", "Price", "Manufacturer", "Expiry", "Category");
    printf("-------------------------------------------------------------------------------------------\n");

    while (fread(&m, sizeof(Medicine), 1, fp)) {
        printf("%-10d %-20s %-10d %-10.2f %-20s %-15s %-20s\n",
               m.id, m.name, m.quantity, m.price,
               m.manufacturer, m.expiry, m.category);
    }
    fclose(fp);
}

// ------------------ SEARCH MEDICINE ------------------
void searchMedicine() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    Medicine m;

    printf("\nEnter Medicine ID to search: ");
    scanf("%d", &id);

    while (fread(&m, sizeof(Medicine), 1, fp)) {
        if (m.id == id) {
            printf("\nMedicine Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\nManufacturer: %s\nExpiry: %s\nCategory: %s\n",
                   m.id, m.name, m.quantity, m.price,
                   m.manufacturer, m.expiry, m.category);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No medicine found with ID %d.\n", id);

    fclose(fp);
}

// ------------------ UPDATE MEDICINE ------------------
void updateMedicine() {
    Medicine meds[100];
    int count = 0, id, found = 0;

    loadMedicines(meds, &count);

    printf("\nEnter Medicine ID to update: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (meds[i].id == id) {
            found = 1;

            printf("Enter new quantity: ");
            scanf("%d", &meds[i].quantity);
            getchar();

            printf("Enter new price: ");
            scanf("%f", &meds[i].price);
            getchar();

            printf("Enter new expiry date: ");
            fgets(meds[i].expiry, sizeof(meds[i].expiry), stdin);
            meds[i].expiry[strcspn(meds[i].expiry, "\n")] = '\0';

            printf("Enter new category: ");
            fgets(meds[i].category, sizeof(meds[i].category), stdin);
            meds[i].category[strcspn(meds[i].category, "\n")] = '\0';

            break;
        }
    }

    if (found) {
        writeAllMedicines(meds, count);
        printf("Record updated successfully.\n");
    } else {
        printf("Medicine ID not found.\n");
    }
}

// ------------------ DELETE MEDICINE ------------------
void deleteMedicine() {
    Medicine meds[100];
    int count = 0, id, found = 0;

    loadMedicines(meds, &count);

    printf("\nEnter Medicine ID to delete: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (meds[i].id == id) {
            found = 1;

            printf("Are you sure you want to delete %s (ID %d)? (y/n): ",
                   meds[i].name, id);

            char confirm = getchar();
            getchar();

            if (confirm == 'y' || confirm == 'Y') {
                for (int j = i; j < count - 1; j++)
                    meds[j] = meds[j + 1];
                count--;

                writeAllMedicines(meds, count);
                printf("Medicine deleted successfully.\n");
            } else {
                printf("Deletion cancelled.\n");
            }
            break;
        }
    }

    if (!found)
        printf("Medicine ID not found.\n");
}

// ------------------ LOAD & WRITE ALL MEDICINES ------------------
void loadMedicines(Medicine meds[], int *count) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return;
    *count = 0;

    while (fread(&meds[*count], sizeof(Medicine), 1, fp))
        (*count)++;

    fclose(fp);
}

void writeAllMedicines(Medicine meds[], int count) {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    fwrite(meds, sizeof(Medicine), count, fp);
    fclose(fp);
}

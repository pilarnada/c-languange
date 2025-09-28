// LIBRARY
#include <stdio.h> // Library input output
#include <stdlib.h>  // Library alokasi memori
#include <stdbool.h> // Library fungsi boolean
#include <string.h> // Library modifikasi bentuk string

// CONST CHAR: Digunakan untuk inisialisasi size dari array
#define ALPHABET_SIZE 26
#define MAX_WORD 100

// VARIABEL GLOBAL
int globalNum = 1; 
char globalPrefix[50];

// STRUKTUR DATA TRIENODE: fondasi trie || representasi isi dari setiap node dalam trie
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE]; // array anak-anak node || node-node yang terhubung
    bool terminal; // akhir node dari sebuah slangword
    char meaning[100]; // menyimpan makna slang word
} TrieNode;

// MEMBUAT NODE BARU
TrieNode* createNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode)); // alokasi memori
    if (newNode) { // inisialisasi nilai default 
        newNode->terminal = false; // memastikan bahwa newNode yang terbentuk bukan merupakan terminal
        int i;
        for (i = 0; i < ALPHABET_SIZE; ++i)
            newNode->children[i] = NULL;
        newNode->meaning[0] = '\0';
    }
    return newNode; // mengembalikan newNode
}

// MEMASUKAN MAKNA SLANGWORD KE DALAM TRIE
void insert(TrieNode* root, const char* word, const char* meaning) {
    TrieNode* curr = root; // inisialisasi curr sebagai root (memudahkan dan meminimalisir kesalahan)
    int len = strlen(word);
  	
  	int i;
    for (i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a'; // menghitung indeks untuk setiap huruf dalam slang word
        if (!curr->children[index])
            curr->children[index] = createNode(); // jika node belum ada, buat node baru
        curr = curr->children[index];
    }
    curr->terminal = true; // tandai node terakhir sebagai terminal node
    strcpy(curr->meaning, meaning); // simpan makna dari slang word
}

// MENCARI SLANGWORD DALAM TRIE
bool search(TrieNode* root, const char* word, char* meaning) {
    TrieNode* curr = root;
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a'; // menghitung indeks untuk setiap huruf dalam slang word
        if (!curr->children[index])
            return false; // jika node tidak ditemukan, slang word tidak ada dalam trie
        curr = curr->children[index];
    }
    if (curr && curr->terminal) {
        strcpy(meaning, curr->meaning); // mengambil makna dari node akhir
        return true; // return true: slang word ditemukan
    }
    return false; // return false: slang word tidak ditemukan
}

// MENANDAKAN SEMUA SLANG WORD DENGAN AWAL TERTENTU SEHINGGA NANTINYA AKAN DI PRINT
void printWordsWithPrefixUtil(TrieNode* node, char* buffer, int depth, char** words, int* count, const char* prefix) {
    if (node->terminal) { 
        buffer[depth] = '\0'; // mengakhiri string buffer
        words[*count] = strdup(buffer); //salin buffer ke array words
        (*count)++;
    }
	
	int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            buffer[depth] = i + 'a'; // Tambahkan huruf ke buffer
            printWordsWithPrefixUtil(node->children[i], buffer, depth + 1, words, count, prefix); //rekursif
        }
    }
}

// MENCETAK SEMUA SLANG WORD DENGAN PREFIX TERTENTU
void printWordsWithPrefix(TrieNode* root, const char* prefix) {
    TrieNode* temp = root;
    int length = strlen(prefix);
    int level;

    for (level = 0; level < length; level++) {
        int index = prefix[level] - 'a';
        if (!temp->children[index]) { // Periksa apakah setiap karakter ada dalam trie
            printf("\nThere is no prefix \"%s\" in the dictionary.", prefix);
            return;
        }
        temp = temp->children[index]; // Lanjut ke node berikutnya
    }

    char* words[MAX_WORD]; 
    int count = 0;
    char buffer[1000]; // Asumsikan panjang maksimum kata 1000
    strcpy(buffer, prefix); // Salin prefixnya ke buffer
    printWordsWithPrefixUtil(temp, buffer, length, words, &count, prefix);

    if (count == 0) {
        printf("\nThere is no prefix \"%s\" in the dictionary.", prefix);
        return;
    }
	
	// Jika tidak ada kata slang yang sesuai, cetak pesan bahwa tidak ada kata slang dengan prefix tersebut
    printf("\nWords starts with \"%s\":\n", prefix);
    int i;
    for (i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, words[i]);
        free(words[i]); // Free memori yang dialokasikan untuk setiap kata
    }
}

// SAMBUNGAN DARI VIEWALL
void viewAllHelper(TrieNode* node, char* buffer, int depth, int* number) {
    if (node->terminal) { // Cek jika merupakan terminal node
        buffer[depth] = '\0';
        printf("%d. %s\n", (*number)++, buffer); // Print complete wordnya
    }
	
	int i;
    for (i = 0; i < ALPHABET_SIZE; i++) { // Iterasi rekursif berdasarkan semua anak node A - Z
        if (node->children[i]) {
            buffer[depth] = i + 'a';
            viewAllHelper(node->children[i], buffer, depth + 1, number);
        }
    }
}

// PRINT SEMUA SLANG WORD YANG SUDAH DIINPUT
void viewAll(TrieNode* root) {
    bool isEmpty = true; // Boolean untuk cek apakah trie kosong
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != NULL) {
            isEmpty = false;
            break;
        }
    }
	
    if (isEmpty) { // Jika trie kosong, cetak pesan bahwa tidak ada kata slang dalam trie
        printf("\nThere is no slang word yet in the dictionary.");
    } 
    
	else { // Jika trie tidak kosong, panggil viewAllHelper untuk mencetak semua kata slang dalam trie
        printf("\nList of all slang words in the dictionary:\n");
        int number = 1; 
        char buffer[MAX_WORD];
        viewAllHelper(root, buffer, 0, &number);
    }
}


int main() {
    TrieNode* root = createNode(); // inisialisasi root node
    
    // Variabel-variabel yang digunakan untuk menunjang algoritma program
    int choice; int countSpace = 0;
    char newWord[50], meaning[100]; char word[50];
    bool alreadyPrinted = false;
    
    do { // SWITCH CASE TITLE
        printf("1. Release a new slang word\n");
        printf("2. Search a slang word\n");
        printf("3. View all slang words starting with a certain prefix word\n");
        printf("4. View all slang words\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) { // SWITCH CASE NUMBERING
			case 1: // INPUT SLANGWORD DAN MEANING
			    printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
			    scanf("%s", newWord);
			    
			    // Membersihkan newline character dari input buffer
			    getchar();
			    
			    while (strlen(newWord) <= 1 || strchr(newWord, ' ') != NULL) {
			        printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
			        scanf("%s", newWord);
			        while (getchar() != '\n'); // Membersihkan input buffer
			    }
			    
			    // Input untuk meaning
			    printf("Input a new slang word description [Must be more than 2 words]: ");
				scanf(" %[^\n]", meaning);
				
				// Loop sampai input untuk meaning valid
				while (1) {
				    // Hitung jumlah spasi di meaning
				    int i;
				    for (i = 0; meaning[i] != '\0'; i++) {
				        if (meaning[i] == ' ')
				            countSpace++;
				    }
				    
				    // Jika jumlah spasi lebih dari 2, maka input valid
				    if (countSpace >= 2)
				        break;
				    
				    // Membersihkan input buffer
				    while (getchar() != '\n');
				    
				    // Jika tidak, minta input baru
				    printf("Input a new slang word description [Must be more than 2 words]: ");
				    scanf(" %[^\n]", meaning);
				    countSpace = 0; // Reset countSpace
				}
				
				// Menghapus newline character jika ada di meaning
				if (strlen(meaning) > 0 && meaning[strlen(meaning) - 1] == '\n')
				    meaning[strlen(meaning) - 1] = '\0';
			
			    insert(root, newWord, meaning); // masukkan slang word baru ke dalam trie
			    
			    printf("\n");
			    printf("Successfully released new slang word.\n");
			    printf("Press enter to continue... "); 
			    getchar(); getchar();
			    printf("\n");
			    break;

                
            case 2: // CARI SLANGWORDNYA
			    printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
			    char searchWord[50];
			    scanf("%s", searchWord);
			    
			    while (strlen(searchWord) <= 1 || strchr(searchWord, ' ') != NULL) {
				    printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
				    scanf("%s", searchWord);
				    while (getchar() != '\n'); // Membersihkan input buffer
				}
				
			    if (search(root, searchWord, meaning)){
			    	printf("\nSlang Word  : %s\n", searchWord); // Jika slang word ditemukan, cetak maknanya
			        printf("Description : %s\n\n", meaning);
			        
			        printf("Press enter to continue... "); 
                	getchar(); getchar();
                	printf("\n");
				}
			        
			    else{ // Slangword tidak ditemukan
			    	printf("\nThere is no word \"%s\" in the dictionary.\n", searchWord);
			        printf("Press enter to continue... "); 
                	getchar(); getchar();
                	printf("\n");
				}
			    break;

            case 3: // CARI BERDASARKAN AWALAN KATA SECARA PREFIX
                printf("Input a prefix to be searched: ");
			    char prefix[50]; 
			    scanf("%s", prefix); // Masukan starting word
			    strcpy(globalPrefix, prefix);
			    printWordsWithPrefix(root, prefix); // Cetak semua slang words dengan prefix tertentu
			    printf("\nPress enter to continue... "); globalNum = 1; alreadyPrinted = false; // Reset globalNum dan alreadyPrinted
			    getchar(); getchar();
			    printf("\n");
				break;
			                
            case 4: // CARI ATAU MELIHAT SEMUA SLANGWORD YANG SUDAH DIINPUT
                viewAll(root);
    			printf("\nPress enter to continue... "); 
			    getchar(); getchar();
			    printf("\n");
                break;
                
            case 5: // EXIT PROGRAM
                printf("Thank you... Have a nice day :)\n");
                exit(0);
                
            default: // DEFAULT (SELAIN 1,2,3,4,5)
                printf("Please choose a valid number!\n\n");
        }
    } while (choice != 5);

    return 0; // AKHIR KODE
}

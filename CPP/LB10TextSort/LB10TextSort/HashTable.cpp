#include "HashTable.h"

unsigned long HashTable::hash_function(char* str)
{
    unsigned int key;
    for (int i = 0; str[i]; i++)
        key += str[i];
    return key % capasity;
}

Ht_item* HashTable::create_item(char* key, char* value) {
    // Creates a pointer to a new hash table item
    Ht_item* item = (Ht_item*)malloc(sizeof(Ht_item));
    item->key = (char*)malloc(strlen(key) + 1);
    item->value = (char*)malloc(strlen(value) + 1);

    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

HashTable* HashTable::create_table(int size) {
    // Creates a new HashTable
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item**)calloc(table->size, sizeof(Ht_item*));
    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;
    return table;
}

void HashTable::free_item(Ht_item* item) {
    // Frees an item
    free(item->key);
    free(item->value);
    free(item);
}

void HashTable::free_table(HashTable* table) {
    // Frees the table
    for (int i = 0; i < table->size; i++) {
        Ht_item* item = table->items[i];
        if (item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);
}

void HashTable::ht_insert(HashTable* table, char* key, char* value)
{
    // Create the item
    Ht_item* item = create_item(key, value);

    // Compute the index
    int index = hash_function(key);

    Ht_item* current_item = table->items[index];
    if (current_item == NULL) {
        // Key does not exist.
        if (table->count == table->size) {
            // Hash Table Full
            printf("Insert Error: Hash Table is full\n");
            free_item(item);
            return;
        }

        // Insert directly
        table->items[index] = item;
        table->count++;
    }
}

void HashTable::print_table(HashTable* table) {
    printf("\nHash Table\n-------------------\n");
    for (int i = 0; i < table->size; i++) {
        if (table->items[i]) {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }
    printf("-------------------\n\n");
}

std::string* read_file( std::string& fn, int words_count)
{

	std::ifstream ifs(fn, std::ifstream::binary);
	char* ch;
	std::string* words;
	
	while( ifs.eof())
	{
		 ifs.read(ch,1);
		if (  *ch >= (unsigned char)65 && *ch <= (unsigned char)90
		   || *ch >= (unsigned char)97 && *ch <= (unsigned char)122
		   || *ch >= (unsigned char)192 && *ch <= (unsigned char)255)
        { 
	   	    words[words_count] += ch;    
        }	
           
        if( *ch = 32) words_count++;
    }
    ifs.close();
    return words;		
}


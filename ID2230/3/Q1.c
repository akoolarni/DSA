#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct AVLNode{
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};


struct Hash_Table_Entry{
    struct AVLNode *avlRoot;
};


struct AVLNode *new_Node(int key){
    struct AVLNode *node = (struct AVLNode *)malloc(sizeof(struct AVLNode));
    node -> key = key;
    node -> left = NULL;
    node -> right = NULL;
    node -> height = 1;
    return node;
}


int height(struct AVLNode *node){
    if(node == NULL){
        return 0;
    }
    return node -> height;
}


int get_Balance(struct AVLNode *node){
    if(node == NULL){
        return 0;
        }
    return height(node -> left) - height(node -> right);
}


void update_height(struct AVLNode *node){
    if(node != NULL){
        node -> height = 1 + (height(node -> left) > height(node -> right) ? height(node -> left) : height(node -> right));
    }
}


struct AVLNode *right_rotate(struct AVLNode *y) {
    struct AVLNode *x = y -> left;
    struct AVLNode *T2 = x -> right;

    x -> right = y;
    y -> left = T2;

    update_height(y);
    update_height(x);

    return x;
}


struct AVLNode *left_rotate(struct AVLNode *x){
    struct AVLNode *y = x -> right;
    struct AVLNode *T2 = y -> left;

    y -> left = x;
    x -> right = T2;

    update_height(x);
    update_height(y);

    return y;
}


struct AVLNode *insert(struct AVLNode *node, int key){
    if(node == NULL){
        return new_Node(key);
        }

    if(key < node -> key){
        node -> left = insert(node -> left, key);
        }
    else if(key > node->key){
        node -> right = insert(node -> right, key);
        }
    
    else{
        return node;
        } 

    update_height(node);

    int balance = get_Balance(node);


    if(balance > 1){
        if(key < node -> left -> key){
            return right_rotate(node);
    }
        else{
            node->left = left_rotate(node -> left);
            return right_rotate(node);
        }
    }


    if(balance < -1){
        if(key > node -> right -> key){
            return left_rotate(node);
    }
        else{
            node -> right = right_rotate(node -> right);
            return left_rotate(node);
        }
    }

    return node;
}


struct AVLNode *search(struct AVLNode *node, int key){
    if(node == NULL || node->key == key)
        return node;

    if(key < node -> key)
        return search(node -> left, key);

    return search(node -> right, key);
}


struct AVLNode *min_val_Node(struct AVLNode *node){
    struct AVLNode *current = node;
    while(current -> left != NULL)
        current = current -> left;
    return current;
}


struct AVLNode *delete_Node(struct AVLNode *root, int key){
    if(root == NULL)
        return root;

    if(key < root -> key)
        root -> left = delete_Node(root -> left, key);
    else if(key > root -> key)
        root -> right = delete_Node(root -> right, key);
    else{
        
        if(root -> left == NULL || root -> right == NULL){
            struct AVLNode *temp = root -> left ? root -> left : root -> right;

       
            if(temp == NULL){
                temp = root;
                root = NULL;
            } 
            else 
                *root = *temp;

            free(temp);
        } 
        else{
          
            struct AVLNode *temp = min_val_Node(root -> right);

           
            root -> key = temp -> key;

            
            root -> right = delete_Node(root -> right, temp -> key);
        }
    }

 
    if(root == NULL){
        return root;
        }

    update_height(root);

    int balance = get_Balance(root);

 
    if(balance > 1){
        if(get_Balance(root -> left) >= 0)
            return right_rotate(root);
        else{
            root -> left = left_rotate(root -> left);
            return right_rotate(root);
        }
    }

 
    if(balance < -1){
        if(get_Balance(root -> right) <= 0)
            return left_rotate(root);
        else{
            root -> right = right_rotate(root -> right);
            return left_rotate(root);
        }
    }

    return root;
}




struct Hash_Table_Entry *create_Hash_Table(int size){
    struct Hash_Table_Entry *table = (struct Hash_Table_Entry *)malloc(sizeof(struct Hash_Table_Entry) * size);
    for(int i = 0 ; i < size ; i++){
        table[i].avlRoot = NULL;
    }
    return table;
}


int hash(int key, int size){
    return key % size;
}


void insert_Student(struct Hash_Table_Entry *table, int size, int key){
    int index = hash(key, size);
    table[index].avlRoot = insert(table[index].avlRoot, key);
}


struct AVLNode *search_student(struct Hash_Table_Entry *table, int size, int key){
    int index = hash(key, size);
    return search(table[index].avlRoot, key);
}


void delete_student(struct Hash_Table_Entry *table, int size, int key){
    int index = hash(key, size);
    table[index].avlRoot = delete_Node(table[index].avlRoot, key);
}


void inorder_traversal(struct AVLNode *node){
    if(node == NULL){
        return;
    }



    inorder_traversal(node -> left);
    printf("%d ", node -> key);
    inorder_traversal(node -> right);
}


void display_Hash_Table(struct Hash_Table_Entry* table, int size){
    for (int i = 0 ; i < size ; i++){
        struct AVLNode *root = table[i].avlRoot;
        printf("Hash Table Entry %d:\n", i);
        if (root != NULL){
            
            printf("Aadhar Numbers: ");
            inorder_traversal(root);
        } 
        else {
            printf("-1");
        }
        printf("\n");
    }
}

int main(){
    int size = 1000; 
    struct Hash_Table_Entry *table = create_Hash_Table(size);

   
    srand(time(NULL));

    
    for (int i = 0 ; i < 1000 ; i++){
        int random_aadhar;
        do{
            random_aadhar = rand() % 10000000 + 1;
        } 
        while(search_student(table, size, random_aadhar) != NULL);
        insert_Student(table, size, random_aadhar);
    }

    freopen("output1.txt", "w", stdout);   
    display_Hash_Table(table, size);

	//dry run
    //printf("hello \n\n\n ");
   
    //here the key is entered and the search function checks for it
    //key can be randomly changed here
    
    int search_key = 9809999; 
    
    struct AVLNode *search_result = search_student(table, size, search_key);
    if (search_result != NULL){
        printf("Student with Aadhar number %d found.\n", search_key);

       
        delete_student(table, size, search_key);
        printf("Student with Aadhar number %d deleted.\n", search_key);
    } 

    else{
        printf("Student with Aadhar number %d not found.\n", search_key);
    }

    
    display_Hash_Table(table, size);
    fclose(stdout);

    return 0;
}

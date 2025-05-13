#include <iostream>
using namespace std;



struct Node
{
    int  noMhs;
    string name;


    Node *next;
    Node *prev;
};

Node *START = NULL;


void addNode()
{
    Node *newNode = new Node();
    cout << "\nEnter the roll number of thhe student: ";
    cin >> newNode->noMhs;
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name;


    if (START == NULL || newNode ->noMhs <= START->noMhs)
    {
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return;
        }

        newNode->next = START;
        if (START != NULL)
        {
            START->prev = newNode;
        }

        // memberi nilai prev = null dan start = node baru 
        newNode->prev = NULL; // step 5: mode the new node point to NULL
        START = newNode;   // step 6: make the new node the first node
    }
    //kondisi jika semua kondisi if untuk terpenuhi
    else
    {

        // insert the new node in the middle or at the end
        // set nilai current = strat dan nilai previous = null
        Node *current = START; // step 1.a: step from the first node
        Node *previous = NULL; // step 1.b: previoud node is Null inotially

        // looping selama current != null dan noMhs dari current lebih kecil dari
        while (current != NULL && current->noMhs < newNode->noMhs)
        {                     // step 1.c: traverse the list to find the
        previous = current;   // step 1.d: move the previous to the current
        current = current->next // stepp1.e: move the current to the next
        }

        // set nilai next node baru = current dan prev node baru= pprevious
        newNode-> next = current; // step 4: make teh next filed of the new node
        newNode-> prev = previous;  // step 5: make the previous filed of the new node

        // kondisi jika current tidak sama dengan null
        if (current != NULL)
        {
            current ->prev = newNode; // step 6 make the previous filed of the
        }

        // kondisi jika previous tidak sama dengan null
        if (previous != NULL)
        {
            previous->next = newNode; // step 7: make the next filed of the prev
        }
        // kondisi jika if previous sama dengan null
        else
        {
            // if prev is still NULL, it means newNode is now the first node
            START = newNode;
        }



    

    
}


// pembuatan function seaarch untuk mencari data
bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current !=  NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);

}

// pembuatan prosedur delete untuk menghapus data
void deleteNode()
{
    Node *previous, *current;
    int rollNo; 

    cout << "\nEnter the roll number of the student whose record is to be delete: ";
    cin >> rollNo; // step 3: get the roll number number to be delete

    if (START == NULL)
    {
        cout << " List is empaty" << endl;
        return;
    }

    current = START; // step 1: start from the first node
    previous = NULL; 

    // locate the node to be delete
    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->nextp;
    }

    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m " << endl;
        return;
    }

    // Node to be delete in the first node
    if (current = START)
      {
        START = START->next; // step 2: update the START pointer
        if (START != NULL)
        {
            START->prev = NULL;
        }

      }
      else
      {
        // node to be deleted is not the first node
        previous->next = current->next;
        if (current-> != NULL)
        {
            // if 
            current->next->prev = previous;

        }
      }
      // release the memory of the node marked as current
      delete current;
      cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\x1b[0m" << endl;
      }

      // method untuk mengecek apakah list kosong
      bool listEmpaty()
      {
        return (START == NULL);
      }

      // prosedur traverse untuk menampilkan data urutan terbalik
      void revtraverse()
      {
        if (listEmpaty)
        cout <<"\nRecords in descending order of roll number are:" << endl;
        Node *currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next

            while (currentNode !=  NULL)
            {
                cout << currentNode->noMhs << " " << currentNode->name << endl;
                currentNode = currentNode->prev;
            }
      }

}

// prosedur untuk mencari data dan menapilkan data yang dicari jika ada
void searchData()
{
    if (listEmpaty() == true)
    {
        cout << "\nList is empaty" << endl;
    }
    Node *prev, *curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to search: " ;
    int num;
    cin >> num;
    if (search(num,&prev, &curr) == false)
       cout << "\nRecord not found" << endl;

    else
    {
        cout << "\nRecord found" << endl;
        cout << "\nRoll number:" << curr->noMhs << endl;
        cout << "\nName: " << curr->name << endl;
    }
}

int main()
{
    // perulangan selama bernilai benar untuk program utama double likedlist
    while (true)
    {
        try
        {
            cout << "\nMenu" << endl;
            cout << "1. Add a record to the list" << endl;
            cout << "2. Delete a record from the list " << endl;
            cout << "3. view all record in the ascending order of roll numbers"  << endl;
            cout << "4. view all record in the ascending order of roll numbers" << endl;
            cout << "5. search for a record in the list" << endl;
            cout << "6. keluar" << endl;
            cout << " Masukkan pilihan (1-6):";
            char ch;
            cin >> ch;

            switch (ch)
            {
                case '1':
                addNode();
                break;
                case '2':
                deleteNode();
                break;
                case '3'
                traverse();
                break;
                case '4':
                revtraverse();
                break;
                case '5':
                searchData();
                break;
                case '6':
                return 0;
                default:
                cout << "\nInvalid option" << endl;
                break;


            }
        }
        catch (exception &e)
        {
            cout << " Check for the values entered." << endl;
        }
        
    }

}

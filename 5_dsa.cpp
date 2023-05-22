#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <string.h>
using namespace std;

class node
{
public:
    char word[20];
    char meaning[20];
    node *lptr;
    node *rptr;
};

class Dictionary
{
public:
    node *create_root(char word[20], char meaning[20])
    {
        node *root = new node;
        strcpy(root->word, word);
        strcpy(root->meaning, meaning);
        root->lptr = NULL;
        root->rptr = NULL;
        return root;
    }

    void insert(char word[20], char meaning[20], node *root)
    {
        node *newnode = new node;
        strcpy(newnode->word, word);
        strcpy(newnode->meaning, meaning);
        newnode->lptr = NULL;
        newnode->rptr = NULL;

        if (strcmp(word, root->word) < 0)
        {
            if (root->lptr == NULL)
            {
                root->lptr = newnode;
            }
            else
            {
                insert(word, meaning, root->lptr);
            }
        }
        else if (strcmp(word, root->word) > 0)
        {
            if (root->rptr == NULL)
            {
                root->rptr = newnode;
            }
            else
            {
                insert(word, meaning, root->rptr);
            }
        }
        else
        {
            cout << "Duplicate Values not Allowed";
        }
    }

    node *del(char word[20], node *root)
    {
        node *temp;
        if (root == NULL)
        {
            cout << "Not found";
            return root;
        }
        if (strcmp(root->word, word) == 0)
        {
            if (root->lptr == NULL && root->rptr == NULL)
            {
                temp = root;
                delete temp;
                return NULL;
            }
            else if (root->lptr == NULL)
            {
                temp = root;
                root = root->rptr;
                delete temp;
                return root;
            }
            else if (root->rptr == NULL)
            {
                temp = root;
                root = root->lptr;
                delete temp;
                return root;
            }
        }
        else if (strcmp(word, root->word) < 0)
        {
            if (root->lptr == NULL)
            {
                cout << "Word Not Found!!!!" << endl;
                return NULL;
            }
            else
            {
                root->lptr = del(word, root->lptr);
                return root;
            }
        }
        else if (strcmp(word, root->word) > 0)
        {
            if (root->rptr == NULL)
            {
                cout << "Word Not Found!!!!" << endl;
                return NULL;
            }
            else
            {
                root->rptr = del(word, root->rptr);
                return root;
            }
        }
        node *min;
        min = root->rptr;
        while (min->lptr != NULL)
        {
            min = min->lptr;
        }
        temp = min;
        strcpy(root->word, temp->word);
        strcpy(root->meaning, temp->meaning);
        root->rptr = del(temp->word, root->rptr);
        return root;
    }

    void search(char word[20], node *root)
    {
        if (strcmp(root->word, word) == 0)
        {
            cout << "Word Found!!!!" << endl;
            cout << "Word :" << root->word << endl;
            cout << "Meaning :" << root->meaning << endl;
        }
        else if (strcmp(word, root->word) < 0)
        {
            if (root->lptr == NULL)
            {
                cout << "Word Not Found!!!!" << endl;
                return;
            }
            else
            {
                search(word, root->lptr);
            }
        }
        else if (strcmp(word, root->word) > 0)
        {
            if (root->rptr == NULL)
            {
                cout << "Word Not Found!!!!" << endl;
                return;
            }
            else
            {
                search(word, root->rptr);
            }
        }
    }

    void update(char word[20], node *root)
    {
        if (strcmp(root->word, word) == 0)
        {
            char meaning[20];
            cout << "Enter Meaning of the word " << root->word;
            cin >> root->meaning;
            return;
        }
        else if (strcmp(word, root->word) < 0)
        {
            if (root->lptr == NULL)
            {
                cout << "Word Not Found!!!!" << endl;
                return;
            }
            else
            {
                update(word, root->lptr);
            }
        }
        else if (strcmp(word, root->word) > 0)
        {
            if (root->rptr == NULL)
            {
                cout << "Word Not Found!!!!" << endl;
                return;
            }
            else
            {
                update(word, root->rptr);
            }
        }
    }

    void ascorder(node *root)
    {
        if (root != NULL)
        {
            ascorder(root->lptr);
            cout << root->word << "=>" << root->meaning << endl;
            ascorder(root->rptr);
        }
    }

    void descorder(node *root)
    {
        if (root != NULL)
        {
            descorder(root->rptr);
            cout << root->word << "=>" << root->meaning << endl;
            descorder(root->lptr);
        }
    }
};

int main()
{
    int choice;
    node *root = NULL;
    Dictionary dict;
    char word[20], meaning[20], searchword[20], updateword[20], deleteword[20];

    while (1)
    {
        cout << "\n-------MENU--------" << endl;
        cout << "1) Insert " << endl;
        cout << "2) Search " << endl;
        cout << "3) Delete" << endl;
        cout << "4) Update" << endl;
        cout << "5) Ascending Order" << endl;
        cout << "6) Descending Order" << endl;
        cout << "7) Exit" << endl;

        cout << "\nYour choice is: ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
            cout << "Enter Word : ";
            cin >> word;
            cout << "Enter Meaning : ";
            cin >> meaning;
            if (root == NULL)
            {
                root = dict.create_root(word, meaning);
            }
            else
            {
                dict.insert(word, meaning, root);
            }
            break;
        case 2:
            cout << "Enter Word to be searched : ";
            cin >> searchword;
            dict.search(searchword, root);
            break;
        case 3:
            cout << "Enter Word to be deleted : ";
            cin >> deleteword;
            dict.del(deleteword, root);
            break;
        case 4:
            cout << "Enter Word to be Updated : ";
            cin >> updateword;
            dict.update(updateword, root);
            break;
        case 5:
            dict.ascorder(root);
            break;
        case 6:
            dict.descorder(root);
            break;
        case 7:
            break;
        default:
            cout << "Invalid Choice";
        }
    }
    return 0;
}

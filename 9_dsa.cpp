#include <iostream>
#include <string.h>

using namespace std;

class dict
{
    dict *root, *node, *left, *right, *tree1;
    string s1, s2;
    int flag, flag1, flag2, flag3, cmp;

public:
    dict()
    {
        flag = 0, flag1 = 0, flag2 = 0, flag3 = 0, cmp = 0;
        root = NULL;
    }

    void input();
    void create_root(dict *, dict *);
    void check_same(dict *, dict *);
    void input_display();
    void display(dict *);
    void input_remove();
    dict *remove(dict *, string);
    dict *findmin(dict *);
    void input_find();
    dict *find(dict *, string);
    void input_update();
    dict *update(dict *, string);
};

void dict::input()
{
    node = new dict;
    cout << "\nEnter the keyword: ";
    cin >> node->s1;
    cout << "Enter the meaning of the keyword: ";
    cin.ignore();
    getline(cin, node->s2);
    create_root(root, node);
}

void dict::create_root(dict *tree, dict *node1)
{
    int i = 0, result;
    char a[20], b[20];

    if (root == NULL)
    {
        root = new dict;
        root = node1;
        root->left = NULL;
        root->right = NULL;
        cout << "\nRoot node created successfully" << endl;
        return;
    }

    for (i = 0; node1->s1[i] != '\0'; i++)
    {
        a[i] = node1->s1[i];
    }

    for (i = 0; tree->s1[i] != '\0'; i++)
    {
        b[i] = tree->s1[i];
    }

    result = strcmp(b, a);
    check_same(tree, node1);

    if (flag == 1)
    {
        cout << "The word you entered already exists.\n";
        flag = 0;
    }
    else
    {
        if (result > 0)
        {
            if (tree->left != NULL)
            {
                create_root(tree->left, node1);
            }
            else
            {
                tree->left = node1;
                (tree->left)->left = NULL;
                (tree->left)->right = NULL;
                cout << "Node added to the left of " << tree->s1 << "\n";
                return;
            }
        }
        else if (result < 0)
        {
            if (tree->right != NULL)
            {
                create_root(tree->right, node1);
            }
            else
            {
                tree->right = node1;
                (tree->right)->left = NULL;
                (tree->right)->right = NULL;
                cout << "Node added to the right of " << tree->s1 << "\n";
                return;
            }
        }
    }
}

void dict::check_same(dict *tree, dict *node1)
{
    if (tree->s1 == node1->s1)
    {
        flag = 1;
        return;
    }
    else if (tree->s1 > node1->s1)
    {
        if (tree->left != NULL)
        {
            check_same(tree->left, node1);
        }
    }
    else if (tree->s1 < node1->s1)
    {
        if (tree->right != NULL)
        {
            check_same(tree->right, node1);
        }
    }
}

void dict::input_display()
{
    if (root != NULL)
    {
        display(root);
    }
    else
    {
        cout << "\nNo elements in the tree to display" << endl;
    }
}

void dict::display(dict *tree1)
{
    if (tree1->left != NULL)
    {
        display(tree1->left);
    }

    cout << "\nKeyword: " << tree1->s1 << endl;
    cout << "Meaning: " << tree1->s2 << endl;

    if (tree1->right != NULL)
    {
        display(tree1->right);
    }
}

void dict::input_remove()
{
    string key;
    cout << "\nEnter the keyword you want to delete: ";
    cin >> key;
    root = remove(root, key);
}

dict *dict::remove(dict *tree1, string x)
{
    dict *temp;
    if (tree1 == NULL)
    {
        return tree1;
    }

    if (x < tree1->s1)
    {
        tree1->left = remove(tree1->left, x);
    }
    else if (x > tree1->s1)
    {
        tree1->right = remove(tree1->right, x);
    }
    else
    {
        if (tree1->right && tree1->left)
        {
            temp = findmin(tree1->right);
            tree1->s1 = temp->s1;
            tree1->right = remove(tree1->right, temp->s1);
        }
        else
        {
            temp = tree1;
            if (tree1->left == NULL)
            {
                tree1 = tree1->right;
            }
            else if (tree1->right == NULL)
            {
                tree1 = tree1->left;
            }
            delete temp;
        }
    }
    return tree1;
}

dict *dict::findmin(dict *tree1)
{
    if (tree1->left != NULL)
    {
        return findmin(tree1->left);
    }
    else
    {
        return tree1;
    }
}

void dict::input_find()
{
    string key;
    cout << "\nEnter the keyword you want to find: ";
    cin >> key;
    dict *temp = find(root, key);

    if (temp != NULL)
    {
        cout << "\nKeyword found!" << endl;
        cout << "\nKeyword: " << temp->s1 << endl;
        cout << "Meaning: " << temp->s2 << endl;
    }
    else
    {
        cout << "\nKeyword not found!" << endl;
    }
}

dict *dict::find(dict *tree1, string x)
{
    if (tree1 == NULL)
    {
        return tree1;
    }

    if (x < tree1->s1)
    {
        return find(tree1->left, x);
    }
    else if (x > tree1->s1)
    {
        return find(tree1->right, x);
    }
    else
    {
        return tree1;
    }
}

void dict::input_update()
{
    string key;
    cout << "\nEnter the keyword you want to update: ";
    cin >> key;
    root = update(root, key);
}

dict *dict::update(dict *tree1, string x)
{
    if (tree1 == NULL)
    {
        return tree1;
    }

    if (x < tree1->s1)
    {
        tree1->left = update(tree1->left, x);
    }
    else if (x > tree1->s1)
    {
        tree1->right = update(tree1->right, x);
    }
    else
    {
        cout << "Enter the new meaning of the keyword: ";
        cin.ignore();
        getline(cin, tree1->s2);
    }
    return tree1;
}

int main()
{
    dict d;
    int choice;

    do
    {
        cout << "\n\n***** MENU *****" << endl;
        cout << "1. Add a keyword" << endl;
        cout << "2. Display all keywords" << endl;
        cout << "3. Remove a keyword" << endl;
        cout << "4. Find a keyword" << endl;
        cout << "5. Update the meaning of a keyword" << endl;
        cout << "6. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            d.input();
            break;
        case 2:
            d.input_display();
            break;
        case 3:
            d.input_remove();
            break;
        case 4:
            d.input_find();
            break;
        case 5:
            d.input_update();
            break;
        case 6:
            cout << "\nThank you for using the program! Goodbye!" << endl;
            break;
        default:
            cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

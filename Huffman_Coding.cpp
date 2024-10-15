#include <bits/stdc++.h>
using namespace std;

struct node
{
    int f;
    char a;
    node *next;
    node *left;
    node *right;
    node()
    {
        next = NULL;
        left = NULL;
        right = NULL;
        a = '*';
    }
};

struct node *arr[100];
node *brr[100];

void marge(int low, int high)
{
    if (low == high)
    {
        return;
    }
    int mid = (low + high) / 2;
    marge(low, mid);
    marge((mid + 1), high);
    int i = low, j = mid + 1, k = low;
    while (1)
    {
        if (i > mid)
            break;
        if (j > high)
            break;
        if (arr[i]->f > arr[j]->f)
        {
            brr[k] = arr[j];
            k++;
            j++;
        }
        else
        {
            brr[k] = arr[i];
            k++;
            i++;
        }
    }
    if (j > high)
    {
        while (i <= mid)
        {
            brr[k] = arr[i];
            k++;
            i++;
        }
    }
    if (i > mid)
    {
        while (j <= high)
        {
            brr[k] = arr[j];
            k++;
            j++;
        }
    }
    k = low;
    for (i = low; i <= high; i++)
    {
        arr[i] = brr[k];
        k++;
    }
    return;
}

void fin(node *root, char s[], int x)
{
    // cout<<"end"<<endl;
    if (root->left == NULL)
    {
        s[x] = '\0';
        cout << root->a << ' ' << s << endl;
        return;
    }
    s[x] = '0';
    fin(root->left, s, x + 1);
    s[x] = '1';
    fin(root->right, s, x + 1);
    return;
}

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        arr[i] = new node();

        cin >> arr[i]->a;
        cin >> arr[i]->f;
    }
    marge(0, n - 1);

    node *root = new node();

    root = arr[0];
    // cout<<root->f;
    // cout<<endl<<'a';
    // node* temp=root;
    for (int i = 0; i < n - 1; i++)
    {
        arr[i]->next = arr[i + 1];
    }
    while (root->next != NULL)
    {
        node *a = new node();
        a->f = root->f + root->next->f;
        a->left = root;
        a->right = root->next;
        root = root->next->next;
        node *cur = root;
        // cout<<cur->f<<' '<<cur->a<<endl;
        if (cur == NULL)
        {
            root = a;
            break;
        }
        if (cur->f > a->f)
        {
            a->next = cur;
            root = a;
        }
        else
        {
            while (1)
            {
                if (cur->next == NULL)
                {
                    cur->next = a;
                    break;
                }
                if (cur->next->f > a->f)
                {
                    a->next = cur->next;
                    cur->next = a;
                    break;
                }
                cur = cur->next;
            }
        }
    }
    char s[100];
    int x = 0;
    // cout<<root->right->f<<' '<<root->left->f;
    cout << "Generated codes are " << endl;
    fin(root, s, x);
    return 0;
}
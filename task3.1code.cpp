#include<iostream>
using namespace std;

struct Node
{
  int key;
  int row_position;
  int col_postion;
  struct Node *Next;
};

void create_new_node(struct Node** head, int non_zero_element,
          int row_index, int col_index )
{
  struct Node *temp, *r;
  temp = *head;
  if (temp == NULL)
  {
    temp = (struct Node *) malloc (sizeof(struct Node));
    temp->key = non_zero_element;
    temp->row_position = row_index;
    temp->col_postion = col_index;
    temp->Next = NULL;
    *head = temp;

  }
  else
  {
    while (temp->Next != NULL)
      temp = temp->Next;
    r = (struct Node *) malloc (sizeof(struct Node));
    r->key = non_zero_element;
    r->row_position = row_index;
    r->col_postion = col_index;
    r->Next = NULL;
    temp->Next = r;

  }
}

void Print_list(struct Node* head)
{
  struct Node *temp, *r, *s;
  temp = r = s = head;

  cout << "row: ";
  while(temp != NULL)
  {

    cout << temp->row_position;
    temp = temp->Next;
  }
  cout << endl;

  cout << "col: ";
  while(r != NULL)
  {
    cout << r->col_postion;
    r = r->Next;
  }
  cout << endl;
  cout << "Val: ";
  while(s != NULL)
  {
    cout << s->key;
    s = s->Next;
  }
  cout << endl;
}

int main()
{
int row =4, col =5;
  int sparse_matric[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };
int size = 0;
  struct Node* start = NULL;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      if (sparse_matric[i][j] != 0)
        create_new_node(&start, sparse_matric[i][j], i, j);
    size++;

  Print_list(start);
         if (size > ((row * col)/ 2))
          cout<<"not sparse matrix"<<endl;
       else
          cout<<"sparse matrix"<<endl;


  return 0;
}

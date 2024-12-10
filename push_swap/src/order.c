void order(t_stack *a, t_stack *b, int size)
{
  if(size == 3)
    order_3(a);
  else if(size == 4)
    order_4(a, b);
  else if(size == 5)
    order_5(a, b);
  else
    order_radix(a, b, size);
}

void order_3(t_stack *stack)
{
  int a = stack->head->data;
  int b = stack->head->next->data;
  int c = stack->head->next->next->data;

  if(a > b && a > c)
    rotate(a, 'a');
  if(b > a && b > c)
    reverse_rotate(a, 'a');
  if(a > b)
    swap(a, 'a');
}

void order_4(t_stack *a, t_stack *b)
{
  /*t_node *current;
  int min;
  int pos;

  current = a->head;
  min = find_min(a);
  pos =*/
}

void order_5(t_stack *a, t_stack *b)
{

}

void order_radix(t_stack *a, t_stack *b, int size)
{
  
}

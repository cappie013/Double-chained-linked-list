// Copyright 2012 Sebastien Loyer

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include	<stdlib.h>
#include	"linkedlist.h"

static	void	pop_from_tail(t_list *list, int index)
{
  int		i;
  t_node	*tmp;

  i = list->size;
  tmp = list->tail;
  while (i > 0)
    {
      if ((i - 1) == index)
	{
	  tmp->next->prev = tmp->prev;
	  tmp->prev->next = tmp->next;
	  list->size -= 1;
	  if (list->del_data)
            list->del_data(&tmp->data);
	  free(tmp);
	  return ;
	}
      tmp = tmp->prev;
      i--;
    }
}

static	void	pop_from_front(t_list *list, int index)
{
  int		i;
  t_node	*tmp;

  i = 0;
  tmp = list->head;
  while (i < list->size)
    {
      if (i == index)
	{
	  tmp->next->prev = tmp->prev;
          tmp->prev->next = tmp->next;
	  list->size -= 1;
	  if (list->del_data)
	    list->del_data(&tmp->data);
          free(tmp);
	  return ;
	}
      tmp = tmp->next;
      i++;
    }
}

void		list_remove_at(t_list *list, int index)
{
  if (list && list->size != 0 &&
      index < list->size && index >= 0)
    {
      if (index == (list->size - 1))
	list_pop_back(list);
      else if (index == 0)
	list_pop_front(list);
      else
	{
	  if (index < (list->size / 2))
	    pop_from_front(list, index);
	  else
	    pop_from_tail(list, index);
	}
    }
}

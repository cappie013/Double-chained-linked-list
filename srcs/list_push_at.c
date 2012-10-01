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

static	void	push_idx(t_list *list, t_node **node, int index)
{
  t_node	*tmp;
  int		i;

  i = 0;
  tmp = list->head;
  while (i < list->size)
    {
      if (i == (index))
	{
	  (*node)->next = tmp;
	  (*node)->prev = tmp->prev;
	  tmp->prev->next = (*node);
	  tmp->prev = (*node);
	  list->size += 1;
	  return ;
	}
      tmp = tmp->next;
      i++;
    }
}

int             list_push_at(t_list *list, void *data, int index)
{
  t_node        *new_node;

  if (list && data && index >= 0)
    {
      if (index == 0)
  	return (list_push_front(list, data));
      else if (index >= list->size)
        return (list_push_back(list, data));
      else
        {
  	  if ((new_node = malloc(sizeof(*new_node))))
  	    {
  	      new_node->data = data;
  	      push_idx(list, &new_node, index);
  	      return (1);
  	    }
        }
    }
  return (0);
}

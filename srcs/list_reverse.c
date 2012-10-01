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

#include	<stdio.h>
#include	<stdlib.h>
#include	"linkedlist.h"

static	void	reverse_node(t_node *node)
{
  t_node	*tmp;

  if (node)
    {
      tmp = node->next;
      node->next = node->prev;
      node->prev = tmp;
    }
}

void		list_reverse(t_list *list)
{
  int		index;
  t_node	*current;
  t_node	*tmp;

  index = 0;
  if (list && list->size > 1)
    {
      current = list->head;
      while (index < list->size)
  	{
  	  tmp = current->next;
  	  reverse_node(current);
  	  current = tmp;
  	  index++;
  	}
      tmp = list->head;
      list->head = list->tail;
      list->tail = tmp;
    }
}

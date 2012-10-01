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

static	t_node	*get_node_at(t_list *list, int index)
{
  t_node	*tmp;

  tmp = list->head;
  while (index > 0)
    {
      tmp = tmp->next;
      index--;
    }
  return (tmp);
}

int             list_concat_at(t_list *dest, t_list *src, int index)
{
  t_list	*new_list;
  t_node        *current;
  t_node	*tmp;

  if (dest && src && src->dup_data && index >= 0)
    {
      if (index == 0)
	list_concat_front(dest, src);
      else if (index >= dest->size)
	list_concat_back(dest, src);
      else if ((new_list = list_dup(src)))
	{
	  current = get_node_at(dest, index - 1);
	  tmp = current->next;
	  current->next = new_list->head;
	  new_list->head->prev = current;
	  new_list->tail->next = tmp;
	  tmp->prev = new_list->tail;
	  dest->size += new_list->size;
	  free(new_list);
	  return (0);
	}
    }
  return (1);
}

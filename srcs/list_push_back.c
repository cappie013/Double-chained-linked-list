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

static	void	add_to_empty_list(t_list *list, t_node **new_node)
{
  (*new_node)->next = (*new_node);
  (*new_node)->prev = (*new_node);
  list->head = (*new_node);
  list->tail = (*new_node);
}

static	void	add_to_list(t_list *list, t_node **new_node)
{
  list->tail->next = (*new_node);
  list->head->prev = (*new_node);
  (*new_node)->prev = list->tail;
  (*new_node)->next = list->head;
  list->tail = (*new_node);
}

int		list_push_back(t_list *list, void *data)
{
  t_node	*new_node;

  if (list && data && (new_node = malloc(sizeof(*new_node))))
    {
      new_node->data = data;
      if (list->size == 0)
	add_to_empty_list(list, &new_node);
      else
	add_to_list(list, &new_node);
      list->size += 1;
      return (1);
    }
  return (0);
}

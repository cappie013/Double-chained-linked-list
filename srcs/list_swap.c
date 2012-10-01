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
#include	"linkedlist.h"

static	t_node	*get_node_at(t_list *list, int index)
{
  int		i;
  t_node	*tmp;

  i = 0;
  tmp = list->head;
  while (i < list->size)
    {
      if (i == index)
	return (tmp);
      i++;
      tmp = tmp->next;
    }
  return (NULL);
}

static	void	swap_value(t_node *first, t_node *second)
{
  void		*tmp;

  tmp = first->data;
  first->data = second->data;
  second->data = tmp;
}

void            list_swap(t_list *list, int idx_first,
			  int idx_second)
{
  if (idx_first < list->size &&
      idx_second < list->size &&
      idx_first != idx_second &&
      idx_second >= 0 && idx_first >= 0)
    {
      swap_value(get_node_at(list, idx_first),
		 get_node_at(list, idx_second));
    }
}

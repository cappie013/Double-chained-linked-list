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

void		*list_get_at(t_list *list, int index)
{
  int		idx;
  t_node	*tmp;

  if (list && index >= 0 && index < list->size)
    {
      if (index == 0)
	return (list_get_front(list));
      else if (index == (list->size - 1))
	return (list_get_back(list));
      else
	{
	  idx = 0;
	  tmp = list->head;
	  while (idx < list->size)
	    {
	      if (idx == index)
		return (tmp->data);
	      tmp = tmp->next;
	      idx++;
	    }
	}
    }
  return (NULL);
}

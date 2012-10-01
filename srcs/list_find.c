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

int		list_find(t_list *list, int (*to_compare)(void*, void*),
			  void *to_find)
{
  t_node	*tmp;
  int		index;

  index = 0;
  if (list && to_compare)
    {
      tmp = list->head;
      while (index < list->size)
	{
	  if (to_compare(tmp->data, to_find))
	    return (index);
	  tmp = tmp->next;
	  index++;
	}
    }
  return (-1);
}

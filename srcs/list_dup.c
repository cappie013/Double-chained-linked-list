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

t_list		*list_dup(t_list *list)
{
  int		i;
  t_node	*tmp;
  t_list	*new_list;

  if (list && (new_list = list_init(list->del_data, list->dup_data)))
    {
      i = 0;
      tmp = list->head;
      while (i < list->size)
	{
	  if (!list_push_back(new_list, new_list->dup_data(tmp->data)))
	    {
	      list_delete(new_list);
	      return (NULL);
	    }
	  tmp = tmp->next;
	  i++;
	}
    }
  return (new_list);
}

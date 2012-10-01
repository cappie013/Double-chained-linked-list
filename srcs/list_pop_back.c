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

void            list_pop_back(t_list *list)
{
  t_node        *tmp;

  tmp = NULL;
  if (list && list->size > 0)
    {
      if (list->size == 1)
        {
          tmp = list->tail;
          list->head = NULL;
          list->tail = NULL;
        }
      else
        {
          tmp = list->tail;
          list->tail->prev->next = list->tail->next;
          list->tail->next->prev = list->tail->prev;
          list->tail = list->tail->prev;
        }
      if (list->del_data)
	list->del_data(&tmp->data);
      list->size -= 1;
      free(tmp);
    }
}

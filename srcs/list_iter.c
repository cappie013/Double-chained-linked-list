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

#include	"linkedlist.h"

static	void	it_real(t_list *list, void (*to_apply)(void**), int limit)
{
  int		i;
  t_node	*tmp;

  if (list && to_apply)
    {
      i = 0;
      tmp = list->head;
      if (limit == 0 || limit > list->size)
	limit = list->size;
      while (i < list->size && i < limit)
	{
	  to_apply(&tmp->data);
	  tmp = tmp->next;
	  i++;
	}
    }
}

void		list_iter(t_list *list, void (*to_apply)(void**))
{
  it_real(list, to_apply, 0);
}

void            list_niter(t_list *list, void (*to_apply)(void**),
			   int limit)
{
  if (limit <= 0)
    return ;
  it_real(list, to_apply, limit);
}

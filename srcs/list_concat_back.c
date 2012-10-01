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

int		list_concat_back(t_list *dest, t_list *src)
{
  int		i;
  t_node	*tmp;

  i = 0;
  if (dest && src && src->dup_data)
    {
      tmp = src->head;
      while (i < src->size)
      	{
      	  if (!list_push_back(dest, src->dup_data(tmp->data)))
      	    return (0);
      	  tmp = tmp->next;
      	  i++;
      	}
    }
  return (1);
}

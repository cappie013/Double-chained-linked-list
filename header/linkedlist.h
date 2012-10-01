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

#ifndef		LINKEDLIST_H_
# define	LINKEDLIST_H_

typedef	struct	s_node
{
  void		*data;
  struct s_node	*next;
  struct s_node	*prev;
}		t_node;

typedef	struct	s_list
{
  int		size; // Size of the list
  t_node	*head; // Point to the first node of the list
  t_node	*tail; // Point to the last node of the list
  void		(*del_data)(void**); // Destroy the data value that is initialized with list_init
  void		*(*dup_data)(void*); // Duplicate the data value that is initialized with list_init
}		t_list;


///////////////////////////////////////////////////////////
//  This function initialize the list
//  and allocate memory using malloc syscall
//  del_data : This function destroy the data from the node
//  dub_data : This function duplicate the data from the node
// Warning : If both del_data and dup_data are NULL you wont 
// be abble to use most of the basics functions
///////////////////////////////////////////////////////////
t_list          *list_init(void (*del_data)(void**),
			   void *(*dup_data)(void*));


///////////////////////////////////////////////////////////
// This function add a node at the end of the list
// with a data value
///////////////////////////////////////////////////////////
int		list_push_back(t_list *list, void *data);

///////////////////////////////////////////////////////////
// This function add a node at front of the list
// with a data value
///////////////////////////////////////////////////////////
int		list_push_front(t_list *list, void *data);

///////////////////////////////////////////////////////////
// This function add a node at the index in the list   
///////////////////////////////////////////////////////////
int             list_push_at(t_list *list, void *data, int index);

///////////////////////////////////////////////////////////
// This function copy the full content from src list
// and add it at the end of the dest content list
///////////////////////////////////////////////////////////
int             list_concat_back(t_list *dest, t_list *src);

///////////////////////////////////////////////////////////
// This function copy the full content from src list
// and add it at the top of the dest content list
///////////////////////////////////////////////////////////
int             list_concat_front(t_list *dest, t_list *src);

///////////////////////////////////////////////////////////
// This function copy the full content from src list
// and add it at the index of the dest content list
///////////////////////////////////////////////////////////
int             list_concat_at(t_list *dest, t_list *src, int index);

///////////////////////////////////////////////////////////
// This function delete the last node of the list
///////////////////////////////////////////////////////////
void		list_pop_back(t_list *list);

///////////////////////////////////////////////////////////
// This function delete the first node of the list
///////////////////////////////////////////////////////////
void		list_pop_front(t_list *list);

///////////////////////////////////////////////////////////
// This function delete the node at the index of the list
///////////////////////////////////////////////////////////
void            list_remove_at(t_list *list, int index);

///////////////////////////////////////////////////////////
// This function delete a range of "amount" node using 
// "from" as the index in the list
///////////////////////////////////////////////////////////
void            list_remove_range(t_list *list, int from, int amount);

///////////////////////////////////////////////////////////
// This function destroy and free all node but list is not NULL
///////////////////////////////////////////////////////////
void		list_clear(t_list *list);

///////////////////////////////////////////////////////////
// This function return the void *data from the first node 
// of the list
///////////////////////////////////////////////////////////
void		*list_get_front(t_list *list);

///////////////////////////////////////////////////////////
// This function return the void *data from the last node 
// of the list
///////////////////////////////////////////////////////////
void		*list_get_back(t_list *list);


///////////////////////////////////////////////////////////
// This function return the void *data from the index node 
// of the list
///////////////////////////////////////////////////////////
void		*list_get_at(t_list *list, int index);

///////////////////////////////////////////////////////////
// This function allow set your data using a function pointed 
// with (*to_apply)
// Warning: This will set all node's datas !
///////////////////////////////////////////////////////////
void		list_iter(t_list *list, void (*to_apply)(void**));

///////////////////////////////////////////////////////////
// Same as list_iter but from the last node
///////////////////////////////////////////////////////////
void            list_iter_rev(t_list *list, void (*to_apply)(void**));

///////////////////////////////////////////////////////////
// This function allow set your data using a function pointed 
// with (*to_apply)
// Warning: The int "limit" will make data set on "limit" node's datas
///////////////////////////////////////////////////////////
void		list_niter(t_list *list, void (*to_apply)(void**), int limit);

///////////////////////////////////////////////////////////
// Same as list_niter but from the last node
///////////////////////////////////////////////////////////
void		list_niter_rev(t_list *list, void (*to_apply)(void**), int limit);

///////////////////////////////////////////////////////////
// This function destroy / free all nodes including list pointer
///////////////////////////////////////////////////////////
void            list_delete(t_list *list);

///////////////////////////////////////////////////////////
// This function duplicate all list and return the new copy
///////////////////////////////////////////////////////////
t_list		*list_dup(t_list *list);

///////////////////////////////////////////////////////////
// This function reverse nodes from first to last
///////////////////////////////////////////////////////////
void		list_reverse(t_list *list);

///////////////////////////////////////////////////////////
// This function compare and search for simalar nodes in the list
// Return index of the first occurence found in the list
///////////////////////////////////////////////////////////
int		list_find(t_list *list, int (*to_cmp)(void *data, void *to_find),
			  void *to_find);

///////////////////////////////////////////////////////////
// This function swap 2 nodes data in the list at idx_first
// and idx_second node
///////////////////////////////////////////////////////////
void		list_swap(t_list *list, int idx_first, int idx_second);

#endif		/* !LINKEDLIST_H_ */
